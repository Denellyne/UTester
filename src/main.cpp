#include "core/unitTester/unitTester.hpp"

int add(int x, int y) { return x + y; }

std::string toLower(std::string str) {
  for (char &ch : str) {
    if (ch >= 'A' && ch <= 'Z')
      ch += 32;
  }
  return str;
}

int main(int argc, char *argv[]) {

  UTester::UTest<int>(6, "Adds 2+3 == 5", add(2, 3));
  UTester::UTest<int>(99, "Adds 77+22 == 99", add(77, 22));
  UTester::UTest<std::string>("aab", "Turns AAb to aab", toLower("AAb"));
  return 0;
}
