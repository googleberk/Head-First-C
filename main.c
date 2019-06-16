#include <stdio.h>
#include "string.h"
// #include "pointer1.h"
// #include "string1.h"
//#include "tool.h"
//#include "break.h"
//#include "structure.h"
//#include "bridge.h"
//#include "advance.h"
#include "libraries.h"




int main(int argc, char *argv[]) {
//    int latitude = 32;
//    int longitude = -64;
//    go_south_east(&latitude, &longitude);
//    printf("Avast! Now at: [%i, %i]\n", latitude, longitude);

//    char quote[] = "Cookies make you fat";
//    char s[] = "How big is it?";
//    char *t = s;

    // Question and Important notes here: HeadFirstC[59]the third paragraph: I don't know what "the
    // compiler simply plugs in the address of the start of the array." means.
    // I guess it just uses the memory address of[char a[] = "cc";] a, just right there at address a, so
    // the compiler doesn't store a reference kind of saying this is a, and it is &a, it just use the address, which is a.
    // Take a loot at HeadFirstC[73 && 75]; Also this Q&A:[When the program is compiled, all the references to array
    // variables are replaced with the addresses of the array. So the truth is that the array variable won’t
    // exist in the final executable. That’s OK because the array variable will never be needed to point anywhere else.]


//    printf("the size of string s is: %i\n", sizeof(s));
//    printf("the size of the string s's pointer t is: %i\n", sizeof(t));
//
//    printf("The quote string is stored at: %p\n", quote);
//    fortune_cookie(quote);
//    test1();
//
//    char *msg_from_amy = "Don't call me";
//    skip(msg_from_amy);
//
//    equivalent();
//
//    data_entry();

    //array_of_arrays();

    //char *s = "ABC";
    //print_reverse(s);

    //Chapter3_Calls below:
    //pocket();
    //secrets();
    //order_pizza(argc, argv);

    // Chapter4_Function_Calls below:
    //data();

    // Chapter5_Function_Calls below:
//    struct fish snappy = {"Snappy", "Piranha", 69, 4};
//    catalog(snappy);
//    pointer_struct(&snappy);
//    printf("My age is now: %i\n", snappy.age);

    // in java this is different?(a can change to 4?) I am confused, will take a look at it later.
//    int a = 3;
//    test_int(a);
//    printf("a is now: %i\n", a);

    //fruit();

    //Chapter6_Function_Calls below:


//    island amity = {"Amity", "09:00", "17:00", NULL};
//    island craggy = {"Craggy", "09:00", "17:00", NULL};
//    island isla_nublar = {"Isla Nublar", "09:00", "17:00", NULL};
//    island shutter = {"Shutter", "09:00", "17:00", NULL};
//
//    amity.next = &craggy;
//    craggy.next = &isla_nublar;
//    isla_nublar.next = &shutter;

    // displayA(&amity);
    // char name[5];
    // if you write the following code, you will get an error:
    // [definition of variable with array type needs an explicit size of an initializer]
    // and there are two ways you can do: [first, is just put the size in the square bracket;
    // second, you have to set this array immediately to a value, such as
    // [code: char pig[] = "JQK"]
    // char pig[];
    // I say the following point a second time because it is important. see TB[74]
    // if you see [void stack_deck(char cards[]), then 'cards' is not an array, it
    // actually is a char pointer(the address of an array named cards), so void stack_deck(char cards[]) is
    // the same as void stack_deck(char *cards). also see TB[59]

    // the following are some points about the sizeof() function:
    // first, sizeof(a pointer) will return the value 4 or 8, because that's the size
    // of pointers on 32- and 64-bit systems.
    // But, if you call sizeof on an array variable, you will actually get how big the
    // array is in memory.
    // char s[] = "How big is it?";
    // char *t = s;
    // when you create a pointer variable, the machine will allocate 4 or 8 bytes of space in the stack to store it.
    // But, when you create an array, such as char s[] = "How big is it?", the computer
    // will allocate space on the heap to store the array(this array is a copy of the string literals
    // "How big is it?" created on the read-only memory on the static/global part of the memory
    // BUT it won't allocate any memory to store the array variable, which is s itself.
    // [The compiler simply plugs in the address of the start of the array]
    // So because array variables don’t have allocated storage, it means you can’t point them at anything else.
    // [code: s = t] gives a compile error


//    fgets(name, 5, stdin);
//    island *p_island0 = create(name);
//    displayA(p_island0);
//
//    fgets(name, 5, stdin);
//    island *p_island1 = create(name);
//    displayA(p_island0);
//    displayA(p_island1);

    // below are calls for Chapter7:
    int NUM_ADS = 7;
    char *ADS[] = {
            "William: SBM GSOH likes sports, TV, dining",
            "Matt: SWM NS likes art, movies, theater",
            "Luis: SLM ND likes books, theater, art",
            "Mike: DWM DS likes trucks, sports and bieber",
            "Peter: SAM likes chess, working out and art",
            "Josh: SJM likes sports, movies and theater",
            "Jed: DBM likes theater, books and dining"
    };
    // find(ADS, NUM_ADS);
//    findA1(sports_no_bieber, ADS, NUM_ADS);
//    findA1(sports_or_workout, ADS, NUM_ADS);
//    findA1(ns_theater, ADS, NUM_ADS);
//    findA1(arts_theater_or_dining, ADS, NUM_ADS);
    //qsortExample();
    //list_response();
    //list_responseA1();
    // print_ints(3, 12, 23, 45);
    // printf("Price is %.2f\n", total(3, MONKEY_GLAND, MUDSLIDE, FUZZY_NAVEL));


    // calls for Chapter 8
    encrycheck();

    return 0;

}