#include <cstddef>
#include <cstdlib>
#include <list.hpp>
#include <string>

#include "testasserts.hpp"

int main() {
  constexpr std::size_t numberOfElements = 42;
  constexpr List::value_type value = 1.6180;

  List list(numberOfElements, value);
  const auto originalData = list.data();
  const auto originalSize = list.size();
  
  List newList(numberOfElements, value/2.);   // default construct new List object
  newList = std::move(list); // invoking move-assign

  // check validity of new list
  TEST_ASSERT(newList.data() == originalData, "Data was not moved from old list");
  TEST_ASSERT(newList.size() == originalSize, "Size was changed during move");
  std::size_t counter = 0;
  auto currentElement = newList.data();
  while(currentElement != nullptr) {
    TEST_ASSERT(currentElement->value == value, "Values of list have changed during move");
    currentElement = currentElement->next;
    ++counter;
  }
  TEST_ASSERT(counter == numberOfElements, "List has wrong size after move");

  // check validity of old list
  TEST_ASSERT(list.data() != originalData, "Old list still holds reference to the moved data");
  TEST_ASSERT(list.data() == nullptr, "Old list has invalid data reference after move");
  TEST_ASSERT(list.size() == 0, "Old list has non-zero size " + std::to_string(list.size()) + " after move");

  return EXIT_SUCCESS;
}