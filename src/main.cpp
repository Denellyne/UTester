#include "uTester.h"
#include <numeric>
#include <vector>

int test() {
  std::vector<int> arr = {1, 2, 3, 4, 5};
  return std::accumulate(arr.begin(), arr.end(), 0);
}

int main(int argc, char *argv[]) {

  UTester::TestStatus status;
  status.newTest(12, test());
  return 0;
}
