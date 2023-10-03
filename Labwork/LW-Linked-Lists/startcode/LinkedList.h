#ifndef LINKEDLIST
#define LINKEDLIST

#include <vector>
#include "Node.h"

class LinkedList {
  private:
    Node* head;
    Node* tail;
    void printr(Node*); // not provided
  public:
  // Part 1
  // Required
    LinkedList(); // default constructor (Part 1)
    void print(); // print list (Part 1)
  // Optional
    bool hasValue(int val); // optional practice / challenge (Part 1)
    void printReverse(); // optional practice / challenge (Part 1)

  // Part 2
  // Required
    void insertHead(int val);
    void insertAfter(int val, int valToInsertAfter);
  // Optional
    void insertTail(int val); // optional practice / challenge (Part 2)
    LinkedList(int val); // optional practice / challenge (Part 2)
    LinkedList(std::vector<int> vals); // optional practice / challenge (Part 2)

  // Part 3
  // Required
    void insertBefore(int val, int valToInsertBefore);
    void remove(int val);
  // Optional
    void removeAfter(int valToFindAndRemoveValAfter); // optional practice / challenge (Part 3)
    void removeBefore(int valToFindAndRemoveValBefore); // optional practice / challenge (Part 3)
    void removeAll(int val); // optional practice / challenge (Part 3)

  // Part 4
  // Required
    void clear();
    virtual ~LinkedList();
    LinkedList(const LinkedList& src);
    LinkedList& operator=(const LinkedList& src);

    // for auto-grading, do not use these functions in your functions
    const Node* dataH() const { return head; }
    const Node* dataT() const { return tail; }

    // hack to make a list so you can learn to print before dealing with adding nodes to a list
    void makeTestList(); // Provided, do not change
};

#endif