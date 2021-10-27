# Exercise EX1.3
This exercise is part **3** of three parts of EX1. See also [Item 000](https://cppitems.github.io/#/item/000) for an overview and deadlines. The submission deadline for EX1 (all three parts) is **Mo 08.11.2021, 4pm**. The sources related to EX1.3 are available at [https://github.com/cppitems/ex1.3](https://github.com/cppitems/ex1.3).

Make sure that all your solutions are uploaded to our [Gitea Server](tea.iue.tuwien.ac.at) before the deadline and are each contained in their correct repositoriy **ex1.1**, **ex1.2**, **ex1.3**, respectively.

## Task description

In this exercise, it is your task to extended a basic implementation `List` of a single-linked-list declared in `include/list.hpp`.
More specifically, the provided implementation in `include/list.hpp` contains a user-defined constructor and correct user-defined destructor.

It is your task to implement the remaining special member functions for this resource owning class `List`, which are **defaulted** in the provided implementation:
- (1) the copy constructor,
- (2) the move constructor,
- (3) the copy assignment operator, and
- (4) the move assignment operator.

Their *declarations* are contained in `include/list.hpp`:
```C++
  List(const List &);
  List(List &&);
  List &operator=(const List &);
  List &operator=(List &&);
```

Your task is to implement the *definitions* of these functions in `lib/listSMF.cpp` which already contains the defaulted special member functions:
```C++
// copy constructor
List::List(const List &list) = default;

// move constructor
List::List(List &&list) = default;

// copy assignment operator
List &List::operator=(const List &list) = default;

// move assignment operator
List &List::operator=(List &&list) = default;
```

**Your implementation must strictly be confined to `lib/listSMF.cpp` and you must not change any other files.**

Prepare yourself for a discussion of your implementation. 

## Tests

As usual, you are provided with several tests to check the correct funcitonality of your implementation. There is no specific order in which the tests should be executed, as they are independent of each other. There is one test for each SMF:
- Test_copyAssign
- Test_copyConstruct
- Test_moveAssign
- Test_moveConstruct

## Benchmarking
For testing your implementation and its performance, a benchmark is provided in `src/benchmark.cpp`.
Similar to the last exercise it will inform you about the memory location of the *head* of the list before and after each operation.

The executable also measures the runtime of all 4 special member functions. Prepare yourself for a discussion on the runtimes of the different SMFs and why this is the case.

## Sanitizing
The provided `CMakeLists.txt` builds the benchmark and turns on the AddressSanitizer (gcc/clang) to detect memory related problems (e.g., leaks and out-of-bound accesses, see [Item 001](https://cppitems.github.io/#/item/001)). 
We will use this to detect problems in your submitted implementation and it is recommended that you also use the AddressSanitizer (or a equivalent tool on you platform) for tests during development.

## Sanitizing
The provided `CMakeLists.txt` builds the benchmark and turns on the AddressSanitizer (gcc/clang) to detect memory related problems (e.g., leaks and out-of-bound access). 
We will use this to detect problems in your submitted implementation and it is recommended that you also use the AddressSanitizer (or a equivalent tool on you platform) for tests during development. Note that these tools are available by default in the online IDE at [https://advcpp.ide.iue.tuwien.ac.at](https://advcpp.ide.iue.tuwien.ac.at) , but should also work with any standard gcc  or clang install.

CMake will check if there is an address sanitizer available and notify you when executing `cmake ..`:
```
-----> Congratulations, you are using the address sanitizer
```
**NOTE**: The sanitizer will only be turned on when the cmake build type is `Debug`. If you changed the build type to something different, the sanitizer will not be used.

**In case the address sanitizer cannot be turned on, you will receive a warning**:
```
-----> WARNING: ADDRESS SANITIZER IS NOT AVAILABLE
```

You are not required to work with the sanitizer, although we strongly encourage it to avoid memory related errors. If you cannot get sanitizers to work on your local machine, you can use the provided online IDE at [https://advcpp.ide.iue.tuwien.ac.at](https://advcpp.ide.iue.tuwien.ac.at) .
