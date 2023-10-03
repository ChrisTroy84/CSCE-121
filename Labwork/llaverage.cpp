#include <iostream>

struct Node {
  int value;
  Node* next;
  Node(int num = 0) : value{num}, next{nullptr} {}
};

class LinkedList {
private:
  Node* head;

public:
  LinkedList() : head{nullptr} {}
  
  // Add a new element to the linked list
  void addElement(int num) {
    Node* newNode = new Node(num);
    if (!head) {
      head = newNode;
    } else {
      Node* current = head;
      while (current->next) {
        current = current->next;
      }
      current->next = newNode;
    }
  }
  
  // Calculate and return the average of the elements in the linked list
  double calculateAverage() const {
    if (!head) {
      throw std::runtime_error("LinkedList is empty");
    }
    
    Node* current = head;
    int sum = 0;
    int count = 0;
    
    while (current) {
      sum += current->value;
      ++count;
      current = current->next;
    }
    
    return static_cast<double>(sum) / count;
  }
  
  // Remove all occurrences of the maximum element in the linked list
  void removeMaxOccurrences() {
    if (!head) {
      return;  // Empty list, nothing to remove
    }
    
    int maxVal = head->value;
    Node* current = head->next;
    
    while (current) {
      if (current->value > maxVal) {
        maxVal = current->value;
      }
      current = current->next;
    }
    
    while (head && head->value == maxVal) {
      Node* temp = head;
      head = head->next;
      delete temp;
    }
    if (head) {
      current = head;
      while (current->next) {
        if (current->next->value == maxVal) {
          Node* temp = current->next;
          current->next = current->next->next;
          delete temp;
        } else {
          current = current->next;
        }
      }
    }
  }
  
  // Destructor to clean up memory
  ~LinkedList() {
    while (head) {
      Node* temp = head;
      head = head->next;
      delete temp;
    }
  }

  Node* getHead() const {
    return head;
  }

  // Reverse the linked list
  void reverse() {
    Node* prev = nullptr;
    Node* current = head;
    Node* nextNode = nullptr;
    
    while (current) {
      nextNode = current->next;
      current->next = prev;
      prev = current;
      current = nextNode;
    }
    
    head = prev;
  }
  // finds middle element
  Node* findMiddleElement() const {
    if (!head) {
      return nullptr;
    }
    
    Node* slowPtr = head;
    Node* fastPtr = head;
    
    while (fastPtr && fastPtr->next) {
      slowPtr = slowPtr->next;
      fastPtr = fastPtr->next->next;
    }
    
    return slowPtr;
  }

  // Check if a cycle exists in the linked list
  bool hasCycle() const {
    if (!head) {
      return false;  // Empty list, no cycle
    }
    
    Node* slowPtr = head;
    Node* fastPtr = head;
    
    while (fastPtr && fastPtr->next) {
      slowPtr = slowPtr->next;
      fastPtr = fastPtr->next->next;
      
      if (slowPtr == fastPtr) {
        return true;  // Cycle detected
      }
    }
    
    return false;  // No cycle found
  }
};

int main() {
  LinkedList list;
  list.addElement(4);
  list.addElement(23);
  list.addElement(11);
  list.addElement(34);
  list.addElement(11);
  
  try {
    double average = list.calculateAverage();
    std::cout << "Average: " << average << std::endl;
  } catch (const std::runtime_error& e) {
    std::cerr << "Error: " << e.what() << std::endl;
  }

  list.removeMaxOccurrences();
  
  Node* current = list.getHead();
  while (current) {
    std::cout << current->value << " ";
    current = current->next;
  }

  list.reverse();
  
  std::cout << "Reversed List: ";
  current = list.getHead();
  while (current) {
    std::cout << current->value << " ";
    current = current->next;
  }
  std::cout << std::endl;

  Node* middle = list.findMiddleElement();
  if (middle) {
    std::cout << "Middle Element: " << middle->value << std::endl;
  } else {
    std::cout << "List is empty." << std::endl;
  }

  // Create a cycle (for testing purposes)
  list.getHead()->next->next->next->next->next = list.getHead()->next;
  
  bool hasCycle = list.hasCycle();
  if (hasCycle) {
    std::cout << "Cycle exists in the linked list." << std::endl;
  } else {
    std::cout << "No cycle in the linked list." << std::endl;
  }
  
  return 0;
}
