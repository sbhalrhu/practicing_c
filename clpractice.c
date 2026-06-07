/* Consider the following command, which pipes the output of foo into the input of bar, 
 * then redirects the output of bar into tmp.txt:
 * >$ ./foo | ./bar > tmp.txt
 * Give a program that takes as command line arguments paths to two executables and a file, 
 * and replicates the behavior of the above command.
*/



/*
#include <stdio.h>

int main(int argc, char *argv[]) {
    
    printf("argc: %d\n", argc);
    for (int i=0; i<argc; i++) {
        printf("argv[%d]=%s\n", i, argv[i]);
    }
    return 0;
}

*/