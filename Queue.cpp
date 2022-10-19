// Queue.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>

using namespace std;

/* Link list node */
struct Node {
    int data;
    struct Node* next;
    Node(int data)
    {
        this->data = data;
        next = NULL;
    }
};

struct QueueNode {
    Node* begin;
    int size;
    QueueNode() { begin = NULL; size = 0; }

    //reverse
    void reverse()
    {
        // Initialize current, previous and next pointers
        Node* current = begin;
        Node* prev = NULL, * next = NULL;

        while (current != NULL) {
            // Store next
            next = current->next;
            // Reverse current node's pointer
            current->next = prev;
            // Move pointers one position ahead.
            prev = current;
            current = next;
        }
        begin = prev;
    }

    //remove at
    void remove_at(int index) 
    {
        if (index == 0) {
            pop_front();
        }
        else {
            Node* previous = this->begin;
            for (int i = 0; i < index - 1; i++) {
                previous = previous->next;
            }
            Node* to_delete = previous->next;
            previous->next = to_delete->next;
            delete to_delete;
            size--;

        }
    }

    //pop
    void pop() 
    {
        remove_at(size - 1);
    }


    //print
    void print()
    {
        struct Node* temp = begin;
        while (temp != NULL) {
            cout << "= " << temp->data << " =" ;
            temp = temp->next;
        }
        cout << endl;
    }
    // add element
    void push(int data)
    {
        if (begin == nullptr) {
            begin = new Node(data);
        }
        else {
            Node* curr = this->begin;
            while (curr->next != nullptr) {
                curr = curr->next;
            }
            curr->next = new Node(data);
        }
        size++;
    }
    //delete element
    void pop_front()
    {
        Node* temp = begin;
        begin = begin->next;
        delete temp;
        size--;
    }
    //method for clear
    void clear() {
        while (size) {
            pop_front();
        }
    }
    //method for search element
    bool search(int sdata) {
        Node* temp = begin;
        while (temp != NULL) {
            if (temp->data == sdata) {
                return true;
            }
            temp = temp->next;
        }
        return false;
    }
    //method for swap
    void swap() {
        Node* current = begin;
        Node* temp = NULL;
        Node* index = NULL;
        if (begin == NULL) {
            return;
        }
        else {
            while (current->next != NULL) {
                index = current;
                current = current->next;
            }
            if (begin == current) {
                return;
            }
            else if (begin->next == current) {
                temp = begin;
                begin = current;
                begin->next = temp;
                temp->next = NULL;
            }
            else {
                temp = begin;
                begin = current;
                begin->next = temp->next;
                index->next = temp;
                temp->next = NULL;
            }
        }



    }
};

// menu
int menu() {
    cout << "Choose action for Queue from list :" << endl;
    cout << "1. Push to Queue " << endl;
    cout << "2. Pop from Queue " << endl;
    cout << "3. Clear all Queue " << endl;
    cout << "4. Swap first and last elements in Queue " << endl;
    cout << "5. Reverse Queue " << endl;
    cout << "6. Does element belongs to Queue " << endl;
    cout << "7. Print Queue " << endl;
    int result;
    cin >> result;
    return result;
}


int main()
{

    QueueNode ll;
    ll.push(1);
    ll.push(2);
    ll.push(3);
    ll.push(4);
    ll.push(5);

    while (true)
    {
        switch (menu())
        {
        case 1:
        {
            system("cls");
            int case1;
            cout << "Add element: ";
            cin >> case1;
            ll.push(case1);
            cout << "Element pushed" << endl;
        }
        break;
        case 2:
        {
            system("cls");
            ll.pop();
            cout << "Element poped" << endl;
        }
        break;
        case 3:
        {
            system("cls");
            ll.clear();
            cout << "Queue cleared" << endl;
        }
        break;
        case 4:
        {
            system("cls");
            ll.swap();
            cout << "Elements swapped" << endl;
        }
        break;
        case 5:
        {
            system("cls");
            ll.reverse();
            cout << "Queue reversed upside down " << endl;

        }
        break;
        case 6:
        {
            system("cls");
            cout << "Enter element to find out if it belongs to Queue " << endl;
            int case6;
            cin >> case6;
            bool find_elem = ll.search(case6);
            if (find_elem) {
                cout << "Element ('" << case6 << "') is in the Queue" << endl;
            }
            else {
                cout << "This element does not belong to the Queue" << endl;
            }
        }
        break;
        case 7:
        {
            system("cls");
            ll.print();
        }
        break;
        }



    }
}
