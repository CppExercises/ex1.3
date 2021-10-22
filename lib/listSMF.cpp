#include <list.hpp>

// you task it to implement the four currently defaulted SMFs (1,2,3,4) below
// according to the needs of this resource owning class

// copy constructor
List::List(const List &list) = default;

// move constructor
List::List(List &&list) = default;

// copy assignment operator
List &List::operator=(const List &list) = default;

// move assignment operator
List &List::operator=(List &&list) = default;