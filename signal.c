/* hello_signal.c */
#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <unistd.h>

int handler_done;
void handler(int signum)
{ //signal handler
  printf("Hello World!\n");
  handler_done = 1;
//   exit(1); //exit after printing
}

int main(int argc, char * argv[])
{
  handler_done = 0;
  signal(SIGALRM,handler); //register handler to handle SIGALRM
  alarm(1); //Schedule a SIGALRM for 1 second
  while(1) {
    while(!handler_done); //busy wait for signal to be delivered
    printf("Turing was right!\n");
    handler_done = 0;
    alarm(1);
  }
  return 0; //never reached
}