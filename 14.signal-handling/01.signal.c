#include <signal.h>
#include <stdio.h>

void sigIntHandler(int signum) { printf("SIGINT received."); }

// This function only print not kill process
// so need to use the uncatchable SIGKILL
// kill -SIGKILL pid
void sigTermHandler(int signum) { printf("SIGTERM received."); }

int main() {
  // press Ctr-c for SIGINT -> signal interrupt
  signal(SIGINT, sigIntHandler);

  // kill pid for SIGTERM -> signal terminate
  signal(SIGTERM, sigTermHandler);

  while (1) {
    printf("Program Running\n");
  }
  return 0;
}
