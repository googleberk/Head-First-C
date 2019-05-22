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

    // Question here: don't know the difference between allocate space and
    // allocate memory? HeadFirstC[59]the third paragraph

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