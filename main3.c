#include  <stdio.h>
#include  <sys/types.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <time.h>

#define   MAX_COUNT  3

void  ChildProcess(void);                /* child process prototype  */
void  ParentProcess(void);               /* parent process prototype */
void  ChildProcess2(void);                /* child process prototype  */

void main(void){

    pid_t  pid;
    pid_t  pid2;

//. child processes have pid of 0
// parent process id is 0
    pid = fork(); // first child process

    if(pid != 0){
       pid2 = fork(); // creates second child processes
       //printf("this is the second child process %d \n", pid);
    }
  
    int status;

    int lower = 1;
    int upper = 30;
    int loop_iterations;
    loop_iterations = rand() % 30;
    int sleep_timer;
    sleep_timer = rand() % 10;

    pid_t current_pid;
    pid_t parent_pid;
    current_pid = getpid();
    parent_pid = getppid();

    int i;
    
    if (pid != 0 && pid2 != 0){
      waitpid(pid, &status, 0);     
      //printf("this is parent process %d %d\n", current_pid, pid);
      printf("Child Pid: %d has completed\n", pid);
      waitpid(pid2, &status, 0);     
      printf("Child Pid: %d has completed\n", pid2);
    }
    else{
    for (i = 0; i < loop_iterations; i++) {
      //printf("this is child process %d %d \n", current_pid, parent_pid);
        printf("Child process: %d is going to sleep\n", current_pid);
        sleep(sleep_timer);
        printf("Child process: %d is awake. Where is my parent: %d \n",current_pid, parent_pid);
      }
      exit(0) ;
    }
}

