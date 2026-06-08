#include <signal.h>
#include <stdio.h>

int main(int argc, char *argv[]) {


}

int extractbs(char *bitstring) {
    int count=0;
    char *buf[8];
    for (int i=1; bitstring[i] != '\0'; i++) {
        buf[i] = bitstring[i];
        if (bitstring[i] == '1') {
            count=count+1;
        }
    }
    buf[7] = '\0';
    if ((count %2) == 0) { return (bitstring = buf); }
    return EOF;

}