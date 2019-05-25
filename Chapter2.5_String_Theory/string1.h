// stdio.h lets you use the standard input/output functions like printf and scanf.
#include <stdio.h>
#include "string.h"

// Here briefly list some string functions in string.h, which is one of the header files in C Standard Library
// 1. strchr(): Find the location of a character inside a string.
// 2. strcmp(): Compare two strings.
// 3. strstr(): Find the location of a string inside another string.
// 4. strcpy(): Copy one string to another.
// 5,strlen(): Find the length of a string.
// 6. strcat(): Concatenate two strings.

// To fix a problem called implicit declaration of a function [don't know why currently]
void find_track(char search_for[], char tracks[][80]);


// create an array of arrays:
void array_of_arrays() {
    // you know that track names will never get longer than 79 chars, so set the value to 80.
    char tracks[][80] = {
            "I left my heart in Harvard Med School",
            "Newark, Newark - a wonderful town",
            "Dancing with a Dork",
            "From here to maternity",
            "The girl from Iwo Jima",
    };

    char search_for[80];
    printf("Search for: ");
//    fgets(search_for, 80, stdin);
    // this line of code is useful: [The sample code for the jukebox
    // application uses the "fgets" function to get the user's search string. However, fgets will add the
    // newline (\n) character to the end of the string when the user presses the enter key to submit their search
    // string. This newline character must be removed and replaced with the null character (\0) in order for it to
    // actually match one of the song titles in the tracks[] array.] or,[fgets(search_for, 80, stdin);] and [
    // search_for[strlen(search_for) - 1] = '\0';] can be replaced by one line of code using scanf(), seems like
    // scanf() doesn't have this problem.
//    search_for[strlen(search_for) - 1] = '\0';
    scanf("%79s", search_for);
    find_track(search_for, tracks);
}

// The strstr() function will search for the second string in the first string.
// If it finds the string, it will return the address of the located string in memory.
// if the strstr() can’t find the substring, it will return the value 0.
// C treats zero as false.
void find_track(char search_for[], char tracks[][80]) {
    int i;
    for (i = 0; i < 5; i++) {
        if (strstr(tracks[i], search_for)) {
            printf("Track %i: '%s'\n", i, tracks[i]);
        }
    }
}

void print_reverse(char *s){
    // size_t is an integer that will return the size of a thing, in that thing's unit.
    // haven't confirmed formally.
    // strlen would just return the length of the array without the null terminator:
    // for example: strlen("ABC") would return 3.
    size_t len = strlen(s);
    char *t = s + len - 1;
    while(t >= s){
        //Question: would printf takes in a pointer variable's address or the value itself
        // in this case, can I write printf("%c", t);
        printf("%c", *t);
        t = t - 1;
    }
    puts("");
}


















