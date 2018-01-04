# correct_cpp_is_prime

Branch|[Travis CI](https://travis-ci.org)|[Codecov](https://www.codecov.io)
---|---|---
master|[![Build Status](https://travis-ci.org/CarmenIJsebaart/correct_cpp_is_prime.svg?branch=master)](https://travis-ci.org/CarmenIJsebaart/correct_cpp_is_prime)|[![codecov.io](https://codecov.io/github/CarmenIJsebaart/correct_cpp_is_prime/coverage.svg?branch=master)](https://codecov.io/github/CarmenIJsebaart/correct_cpp_is_prime/branch/master)

[Correct C++](https://github.com/richelbilderbeek/correct_cpp) chapter 'is_prime'.

## Goal

 * Refactor an application to lower cyclomatic complexity

## Prerequisites

 * Understand [how this course works](https://github.com/richelbilderbeek/correct_cpp/blob/master/how_this_course_works.md)
 * Have written [a correct 'int_to_word' program](https://github.com/richelbilderbeek/correct_cpp_int_to_word)

## Exercise

Write a command-line interface (CLI) program that determines if a number is a prime (see 'What is a prime?').

Here are the outputs and exit statuses the program should give:

Call to `is_prime`|Output|Exit status
---|---|---
`./is_prime`|Any|1
`./is_prime X`, where X is a number that is not prime|`false` (with newline)|0
`./is_prime Y`, where Y is a number that is prime|`true` (with newline)|0
`./is_prime nonsense`|Any|1
`./is_prime 7 42`|Any|1

In this exercise, you start with the code below. Yes, that code works perfectly. 

```c++
#include <string>
#include <iostream>

int main(int argc, char* argv[]) 
{
  if (argc != 2) return 1;
  try
  {
    const int i{std::stoi(argv[1])};
    if (i < 2)
    {
      std::cout << "false\n"; return 0;
    }
    if (i == 2)
    {
      std::cout << "true\n"; return 0;
    }
    for (int j=2; j!=i-1; ++j)
    {
      if (i % j == 0)
      {
        std::cout << "false\n";
        return 0;
      }
    }
    std::cout << "true\n";
  }
  catch (const std::exception&)
  {
    return 1;
  }
}
```

 * The code has a too high cyclomatic complexity. Simplify it. See [how to lower cyclomatic complexity](https://github.com/richelbilderbeek/correct_cpp/blob/master/lower_cyclomatic_complexity.md). 
   Tips:
     * put the content of the `main` function in a seperate function, e.g. `do_main`
     * a possible function prototype: `bool is_prime(const int i) noexcept`
     * a possible function prototype: `void test() noexcept`
 * Your code needs to have 100% code coverage, regardless how the executable is called (that is, with zero, one or more arguments), 
   see [how to get 100 percent code coverage](https://github.com/richelbilderbeek/correct_cpp/blob/master/get_100_percent_code_coverage.md)

## What is a prime?

Any number is a prime if it:
 * is more than 1
 * can only be divided by 1 and itself

Number|Is prime?
---|---
-1|No
0|No
1|No
2|Yes
3|Yes
4|No
5|Yes
6|No
7|Yes

## External links

 * [Wikipedia's page about primes](https://en.wikipedia.org/wiki/Prime_number)
 * [Download the Qt Creator file `main.pro`](https://raw.githubusercontent.com/richelbilderbeek/correct_cpp/master/shared/main.pro)


