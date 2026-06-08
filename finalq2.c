#include <signal.h>
#include <stdio.h>

int main(int argc, char *argv[]) {
    int bitstring = extractbs(argv[1]);
    printf("Bitstring is %d.", (int)bitstring);

}

int extractbs(char *bitstring) {
    int count=0;
    for (int i=1; bitstring[i] != '\0'; i++) {
        if (bitstring[i] == '1') {
            count=count+1;
        }
    }
    if ((count %2) == 0) { return (0x7F & (int)bitstring); }
    return EOF;

}