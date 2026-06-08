#include <signal.h>
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {
    int bitstring = extractbs(argv[1]);

    if (argc < 2) {
        printf("Usage: ./finalq2 <bitstring>\n");
        return EXIT_FAILURE;

    }

    printf("Bitstring is %d.", (int)bitstring);
    return EXIT_SUCCESS;
}

char extractbs(unsigned char bitstring) { /*unsigned char is 1 byte -- 8 bits*/
    int count=0;
    unsigned char mask;
    for (mask = 1; mask != 0; mask <<=1) {
        if (bitstring & mask) {
            count=count+1;
        }
    }
    if ((count %2) == 0) { return (0x7F & (int)bitstring); }
    return EOF;

}