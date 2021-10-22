#include <bits/thread-shared-types.h>
#include <cstddef>
#include <utility>

#include <list.hpp>

List::Node::Node(const List::value_type &val) : value(val) {}

// default constructor
List::List() {}

// user-defined constructor
List::List(size_type count, const value_type &value) : dataSize(count) {
  dataHead = new Node(value);
  Node *lastNode = dataHead; // root node
  for (size_type i = 1; i < dataSize; ++i) {
    Node *newNode = new Node(value);
    lastNode->next = newNode;
    lastNode = newNode;
  }
}

// destructor
List::~List() {
  Node *currentNode = dataHead;
  Node *nextNode;
  while (currentNode != nullptr) {
    nextNode = currentNode->next;
    delete currentNode;
    currentNode = nextNode;
  }
  dataSize = 0;
}

// access current number of nodes in list 
List::size_type List::size() { return dataSize; }

// obtain root element pointer
List::Node *List::data() { return dataHead; }

// access front element
List::value_type &List::front() { return dataHead->value; }

// push new list element at the front
void List::push_front(const value_type &value) {
  Node *nextDataHead = new Node(value);
  nextDataHead->next = dataHead;
  dataHead = nextDataHead;
  ++dataSize;
}

// pop element at the front
void List::pop_front() {
  if (dataHead != nullptr) {
    Node *oldDataHead = dataHead;
    dataHead = oldDataHead->next;
    delete oldDataHead;
    --dataSize;
  }
}