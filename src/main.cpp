#include "unitTester.hpp"
#include <iostream>
#include <unistd.h>

int test() { return 1; }

int main(int argc, char *argv[]) {

  UTester::UTest<int>(0, "Returns void", test());

  UTester::UTest<int>(0, "Returns void", test());
  return 0;
}
