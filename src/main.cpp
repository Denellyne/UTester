#include "uTester.h"

int test() {
  for (int i = 0; i < 10; i++) {

    int *x = new int;
    delete x;
  }
  return 15;
}

int main(int argc, char *argv[]) {

  UTester::TestStatus status;
  status.newTest(12, test());
  return 0;
}
