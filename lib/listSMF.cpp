#include "list.hpp"
#include <algorithm>
#include <iostream>

// you task it to implement the four currently defaulted SMFs (1,2,3,4) below
// according to the needs of this resource owning class

// copy constructor
List::List(const List &other) = default;

// move constructor
List::List(List &&other) = default;

// copy assignment operator
List &List::operator=(const List &other) = default;

// move assignment operator
List &List::operator=(List &&other) = default;