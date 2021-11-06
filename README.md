# Exercise EX1.3
This exercise is part **3** of three parts of EX1. See also [Item 000](https://cppitems.github.io/#/item/000) for an overview and deadlines. The submission deadline for EX1 (all three parts) is **Mo 08.11.2021, 4pm**. The sources related to EX1.3 are available at [https://github.com/cppitems/ex1.3](https://github.com/cppitems/ex1.3).

Make sure that all your solutions are uploaded to our [Gitea Server](tea.iue.tuwien.ac.at) before the deadline and are each contained in their correct repositoriy **ex1.1**, **ex1.2**, **ex1.3**, respectively.

## Running Result

```bash
wang@wang-virtual-machine:~/Documents/ex1.3/build$ ./benchmark 
Copy:
Old data before  | New data after   | Old Data after
  0x602002191bf0 |   0x6020033e13f0 | 0x602002191bf0

Move:
Old data before  | New data after   | Old Data after
  0x6020043237f0 |   0x6020043237f0 | 0

Copy Assign:
Old data before  | New data after   | Old Data after
  0x602005572ff0 |   0x6020067c27f0 | 0x602005572ff0

Move Assign:
Old data before  | New data after   | Old Data after
  0x602007704bf0 |   0x602007704bf0 | 0


Runtimes of constructing list objects:

Copy constructor List(const List&)      called as List(list)                1.16e-02 s
Move constructor List(List&&)           called as List(std::move(list))     8.33e-07 s
Copy assignment operator=(const List&)  called as listB = listA             1.85e-02 s
Move assignment operator=(List&&)       called as listB = std::move(listA)  7.05e-03 s
```

## Task description

In this exercise, it is your task to extend a basic implementation `List` of a single-linked-list declared in `include/list.hpp`.
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
List::List(const List &other) = default;

// move constructor
List::List(List &&other) = default;

// copy assignment operator
List &List::operator=(const List &other) = default;

// move assignment operator
List &List::operator=(List &&other) = default;
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
**Note: Without reasonable implementations of the SMF (1) (2) (3) and (4) the benchmark will fail at run time, i.e., the sanitizer will detect incorrect memory access with errors like "double free" or "use after free".**

The executable also measures the runtime of all 4 special member functions. Prepare yourself for a discussion on the runtimes of the different SMFs and why this is the case.

## Sanitizing
The provided `CMakeLists.txt` builds the benchmark and turns on the AddressSanitizer (gcc/clang) to detect memory related problems (e.g., leaks and out-of-bound access). 
We will use this to detect problems in your submitted implementation and it is recommended that you also use the AddressSanitizer (or a equivalent tool on you platform) for tests during development. Note that these tools are available by default in the online IDE at [https://advcpp.ide.iue.tuwien.ac.at](https://advcpp.ide.iue.tuwien.ac.at) , but should also work with any standard gcc or clang install.

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
