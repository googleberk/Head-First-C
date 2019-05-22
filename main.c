#include <stdio.h>
#include "pointer1.h"

int main() {
//    int latitude = 32;
//    int longitude = -64;
//    go_south_east(&latitude, &longitude);
//    printf("Avast! Now at: [%i, %i]\n", latitude, longitude);

    char quote[] = "Cookies make you fat";
    char s[] = "How big is it?";
    char *t = s;

    // Question and Important notes here: HeadFirstC[59]the third paragraph: I don't know what "the
    // compiler simply plugs in the address of the start of the array." means.
    // I guess it just uses the memory address of[char a[] = "cc";] a, just right there at address a, so
    // the compiler doesn't store a reference kind of saying this is a, and it is &a, it just use the address, which is a.
    // Take a loot at HeadFirstC[73 && 75]; Also this Q&A:[When the program is compiled, all the references to array
    // variables are replaced with the addresses of the array. So the truth is that the array variable won’t
    // exist in the final executable. That’s OK because the array variable will never be needed to point anywhere else.]


    printf("the size of string s is: %i\n", sizeof(s));
    printf("the size of the string s's pointer t is: %i\n", sizeof(t));

    printf("The quote string is stored at: %p\n", quote);
    fortune_cookie(quote);
    test1();

    char *msg_from_amy = "Don't call me";
    skip(msg_from_amy);

    equivalent();

    data_entry();

    return 0;
}