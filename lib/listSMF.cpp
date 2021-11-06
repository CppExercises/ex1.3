#include "list.hpp"
#include <algorithm>
#include <iostream>

// you task it to implement the four currently defaulted SMFs (1,2,3,4) below
// according to the needs of this resource owning class

// copy constructor
List::List(const List &other): _size(other._size)
{
  // because of I am going to use the function push and pop which came with the ex1.3
  // pop remove a head element
  // push add a head element
  // so I need to define a list to reverse the order.
  List::value_type *value = new List::value_type[_size];

  // foreach the other list add the elements into the list
  Node *p = other._head;
  std::size_t i = _size;
  while(p != nullptr)
  {
      value[i - 1] = p->value;
      p = p->next;
      i --;
  }

  // foreach the list we are going to construct add the elements into it
  for(i = 0;i < _size; i ++)
  {
    push_front(value[i]);
    _size -- ;
  }

  // release memory
  delete p;
  delete []value;

}

// move constructor
List::List(List &&other): _size(0)
{
  // pointer initialize
  _size = other._size;
  _head = other._head;

  // release memory
  other._head = nullptr;
  other._size = 0;
}

// copy assignment operator
List &List::operator=(const List &other)
{
  // this and parameter do not point to the same one object
  if( this != &other)
  {
    // empty this object
    while (_size > 0)
    {
      pop_front();
    }

    // because of I am going to use the function push and pop which came with the ex1.3
    // pop remove a head element
    // push add a head element
    // so I need to define a list to reverse the order.
    _size = other._size;
    List::value_type *value = new List::value_type[_size];
    Node *p = other._head;
    std::size_t i = _size;

    // foreach the other list add the elements into the list
    while(p != nullptr)
    {
      value[i - 1] = p->value;
      p = p->next;
      i --;
    }

    // foreach the list we are going to construct add the elements into it
    for(i = 0;i < _size; i ++)
    {
      push_front(value[i]);
      _size -- ;
    }

    // release memory
    delete p;
    delete []value;
  }
  return *this;
}

// move assignment operator
List &List::operator=(List &&other)
{
  // this and parameter do not point to the same one object
  if( this != &other)
  {
    // empty this object
    while (_size > 0)
    {
      pop_front();
    }
    // pointer initialize
    _size = other._size;
    _head = other._head;

    // release memory
    other._head = nullptr;
    other._size = 0;
    while (other._size > 0)
    {
      other.pop_front();
    }
  }

  return *this;
}
