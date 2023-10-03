#include <iostream>
#include <vector>
#include "LinkedList.h"

using std::cout, std::cin, std::endl, std::vector;

// Part 1
LinkedList::LinkedList() : head(head), tail(tail) {} // Part 1

void LinkedList::print() { // Part 1
    if (head == nullptr && tail == nullptr) {
        cout << "Empty List";
    }
    Node* curr = head;
    while(curr) {
        cout << curr->num << " ";
        curr = curr->next;
    }
    cout << endl;
}

bool LinkedList::hasValue(int val) { // optional practice / challenge (Part 1)
    Node* curr = head;
    while(curr) {
        if (curr->num != val) {
            curr = curr->next;
        }
        else if (curr->num == val) {
            return true;
        }
    }
    return false; // update to provide correct boolean value
}

void LinkedList::printReverse(){ // optional practice / challenge (Part 1)
    Node* curr = head;
    Node* prev = nullptr;
    Node* next = nullptr;
    vector<int> vect;

    while(curr != nullptr) {
        vect.push_back(curr->num);
        next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
    }
    head = prev;

    for (int i = 4; i > 0; i--) {
        cout << vect[i - 1] << " ";
    }
    cout << endl;
}

// Part 2
void LinkedList::insertHead(int val) { // Part 2
    Node* new_node = new Node(val);

    if (head != nullptr) {
        new_node->next = head;
    }

    head = new_node;
    if (tail == nullptr) {
        tail = new_node;
    }

}

void LinkedList::insertAfter(int val, int valToInsertAfter) { // Part 2
    Node* newNode = new Node(val);

    // If the list is empty, simply add the new node as the head and tail
    if (head == nullptr) {
        head = newNode;
        tail = newNode;
        return;
    }

    Node* curr = head;
    bool inserted = false;

    while (curr != nullptr) {
        if (curr->num == valToInsertAfter) {
            newNode->next = curr->next;
            curr->next = newNode;

            // Update tail if the new node is inserted at the end
            if (curr == tail) {
                tail = newNode;
            }

            inserted = true;
            break;
        }
        curr = curr->next;
    }

    // If valToInsertAfter is not found, add the new node to the tail
    if (!inserted) {
        tail->next = newNode;
        tail = newNode;
    }

}

void LinkedList::insertTail(int val) { // optional practice / challenge (Part 2)
    Node* new_node = new Node(val);
    //inserts value at end of ll (tail)
    if (tail != nullptr) {
        tail->next = new_node;
    }

    if (head == nullptr) {
        head = new_node;
    }

    tail = new_node;
}  

LinkedList::LinkedList(int val) { // optional practice / challenge (Part 2)
    //constructor that takes in a val, ex: passing in 8 as value for empty ll -> prints 8
    head = new Node(val);
    tail = head;
}

LinkedList::LinkedList(std::vector<int> nums) { // optional practice / challenge (Part 2)
    //constructor that takes in a vector: prints out the vector elements
    if (!nums.empty()) {
        head = new Node(nums[0]);
        Node* current = head;
        
        for (size_t i = 1; i < nums.size(); ++i) {
            current->next = new Node(nums[i]);
            current = current->next;
        }

        tail = current;
    }
}

// Part 3
void LinkedList::insertBefore(int val, int valToInsertBefore) { // Part 3
    Node* newNode = new Node(val);
    if (head == nullptr) {
        head = newNode;
        tail = newNode;
        return;
    }

    if (head->num == valToInsertBefore) {
        newNode->next = head;
        head = newNode;
        return;
    }

    Node* current = head;
    bool inserted = false;

    while (current->next != nullptr) {
        if (current->next->num == valToInsertBefore) {
            newNode->next = current->next;
            current->next = newNode;

            inserted = true;
            break;
        }
        current = current->next;
    }

    if (!inserted) {
        newNode->next = head;
        head = newNode;
    }

}

void LinkedList::remove(int val) { // Part 3
    if (head->num == val) {
        Node* temp = head;
        head = head->next;
        delete temp;
        if (head == nullptr) {
            tail = nullptr;
        }
        return;
    }

    Node* current = head;
    while (current->next != nullptr) {
        if (current->next->num == val) {
            Node* temp = current->next;
            current->next = current->next->next;
            delete temp;

            if (temp == tail) {
                tail = current;
            }
            return;
        }
        current = current->next;
    }

}

void LinkedList::removeAfter(int valToFindAndRemoveValAfter) { // optional practice / challenge (Part 3)
    Node* current = head;
    //removes val after valToFindAndRemoveAfter
    while (current != nullptr && current->num != valToFindAndRemoveValAfter) {
        current = current->next;
    }

    if (current != nullptr && current->next != nullptr) {
        Node* temp = current->next;
        current->next = current->next->next;
        
        if (temp == tail) {
            tail = current;
        }

        delete temp;
    }
}

void LinkedList::removeBefore(int valToFindAndRemoveValBefore) { // optional practice / challenge (Part 3)
    if (head == nullptr || head->num == valToFindAndRemoveValBefore) {
        return; // Nothing to remove before the head or if the list is empty
    }
    //removes val before valToFindAndRemoveBefore
    if (head->next != nullptr && head->next->num == valToFindAndRemoveValBefore) {
        Node* temp = head;
        head = head->next;
        delete temp;
        return;
    }

    Node* current = head;
    while (current->next != nullptr && current->next->next != nullptr) {
        if (current->next->next->num == valToFindAndRemoveValBefore) {
            Node* temp = current->next;
            current->next = current->next->next;
            delete temp;
            return;
        }
        current = current->next;
    }
}

void LinkedList::removeAll(int val) { // optional practice / challenge (Part 3)
    while (head != nullptr && head->num == val) {
        Node* temp = head;
        head = head->next;
        delete temp;
    }

    if (head == nullptr) {
        tail = nullptr;
        return;
    }

    Node* current = head;
    while (current->next != nullptr) {
        if (current->next->num == val) {
            Node* temp = current->next;
            current->next = current->next->next;
            delete temp;
        } else {
            current = current->next;
        }
    }
    tail = current;
}

// Part 4
void LinkedList::clear() { // Part 4
    while (head != nullptr) {
        Node* temp = head;
        head = head->next;
        delete temp;
    }
    tail = nullptr;
}

LinkedList::~LinkedList() { // Part 4
    clear();
}

LinkedList::LinkedList(const LinkedList& src) { // Part 4
    head = nullptr;
    tail = nullptr;
    //copy constructor
    Node* srcCurr = src.head;
    Node* prev = nullptr;

    while (srcCurr != nullptr) {
        Node* newNode = new Node(srcCurr->num);
        if (prev == nullptr) {
            head = newNode;
        } else {
            prev->next = newNode;
        }
        prev = newNode;

        srcCurr = srcCurr->next;
    }

    tail = prev;
}

LinkedList& LinkedList::operator=(const LinkedList& src) { // Part 4
    if (this == &src) {
        return *this; // Self-assignment check
    }
    //copy assignment constructor
    clear();

    Node* srcCurr = src.head;
    Node* prev = nullptr;

    while (srcCurr != nullptr) {
        Node* newNode = new Node(srcCurr->num);
        if (prev == nullptr) {
            head = newNode;
        } else {
            prev->next = newNode;
        }
        prev = newNode;

        srcCurr = srcCurr->next;
    }

    tail = prev;

    return *this;
}

// Provided
void LinkedList::makeTestList() {
    // a really bad way to create a list, 
    //    but it will let you practice traversing before building your own list.
    Node* x = new Node(5);
    head = x;
    x = new Node(14);
    head->next = x;
    x = new Node(8);
    head->next->next = x;
    x = new Node(33);
    head->next->next->next = x;
    tail = x;
} 
