#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>
#include <signal.h>
#include <stdio.h>

int main(void) {
    int status;
    pid_t child;

    if ((child = fork()) ==0) { /*fork and assign PID to child*/
        /*if PID is 0, we are in the child process, otherwise we are in the parent.
         *if we are in the parent, child is assigned the child process's PID*/


        /*NOTE: replacing the child process with the contents of another executable
         *makes it so the child is no longer limited to executing only the code it
         *inherited from its parent. by convention, the first argument to exec should
         *be the name of the executable. */

        execlp("./child", "child", NULL);

         /* NOTE: Assuming "exec" succeeds, the current process is replaced with
          * the contents of another executable, which means any code below "exec"
          * ceases to exist. Effectively, "exec" is called once and, if it succeeds, 
          * it *never returns at all*.
         */

        perror("execlp"); /*this only runs if the process was not replaced (FAILURE)*/
        return EXIT_FAILURE;
    }

    else { /*if we are in the parent process upon forking:*/
        printf("%ld is the parent of %ld.\n", (long)getpid(), (long)child);

        sleep(1);
        kill(child, SIGINT);
        sleep(1);
        kill(child, SIGQUIT);
        sleep(1);
        kill(child, SIGSTOP);
        kill(child, SIGKILL);
        child = wait(&status); /*wait for the child process to finish and assign its PID to child*/
        
        if (WIFEXITED(status)) { /*if the child process exited normally, print its exit status*/
            printf("%ld exited status %d.\n", (long)child, WEXITSTATUS(status));
        }
        else {
            printf("%ld exited abnormally.\n", (long)child);
        }

    }

    return EXIT_SUCCESS;


}