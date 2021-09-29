#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <unistd.h>

unsigned int runtime;

void sigalarm_handler(int signum) {
  runtime++;
  alarm(1);
}

void sigint_handler(int signum) {
  printf("\n%d alarm(s) occurred i.e the program ran for approximately %d seconds\n", runtime, runtime);
  exit(1);
}

int main() {
  runtime = 0;
  signal(SIGALRM, sigalarm_handler);
  signal(SIGINT, sigint_handler);
  alarm(1);
  while(1);
}