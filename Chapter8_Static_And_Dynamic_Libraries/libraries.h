#include <stdio.h>
#include "encrypt.h"
#include "checksum.h"
#include "encrypt.c"
#include "checksum.c"

void encrycheck() {
    char s[] = "Speak friend and enter";
    printf("The original message is: %s\n", s);
    encrypt(s);
    printf("Encrypted to '%s'\n", s);
    printf("Checksum is %i\n", checksum(s));
    encrypt(s);
    printf("Decrypted back to '%s'\n", s);
    printf("Checksum is %i\n", checksum(s));
}




// ar -rcs libhfsecurity.a encrypt.o checksum.o

// Compile your other programs:
// if you've installed your archive in a standard directory,
// like /usr/local/lib, then you can compile your code using the -l switch
// [code: gcc test_code.c -lhfsecurity -o test_code]
// 1. remember to list your source files before your -l libraries.
//
// If you put your archive somewhere else, like /my_lib, then you should use -L option
// [code: gcc test_code.c -L/my_lib -lhfsecurity -o test_code]


















