#include "uTester.h"

class cpu {
public:
  cpu() {
    ram[idx] = 3;
    execute();
  }
  void execute() {
    while (true) {
      if (idx < 5) {
        ram[idx] = 3;
        idx++;
        continue;
      }
      return;
    }
  }

  int functionBeingTested() { return ram[--idx]; }

private:
  char ram[5]{};
  short idx = 0;
};

int main(int argc, char *argv[]) {
  cpu cpu;
  UTester::TestStatus Status(true);
  Status.newTest(3, cpu.functionBeingTested());
  Status.newTest(1, cpu.functionBeingTested());
  return 0;
}
