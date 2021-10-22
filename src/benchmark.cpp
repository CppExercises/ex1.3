#include <iostream>

#include <list.hpp>


int main() {
  List myList;

  myList.push_front(3.1415);
  myList.push_front(3.1415);
  myList.push_front(3.1415);
  myList.push_front(3.);
  myList.push_front(3.1415);

  std::cout << myList.front() << std::endl;
  
  myList.pop_front();

  std::cout << myList.front() << std::endl;  

  return 0;
}