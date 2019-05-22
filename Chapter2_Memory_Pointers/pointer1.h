#include "stdio.h"

void go_south_east(int *lat, int *lon){
    *lat = *lat - 1;
    *lon = *lon + 1;
}

// note: %s denotes string, in this case, msg is actually a pointer
// and the second print is asking the size of a pointer to a string named msg,
// not the size of the string msg itself.
// Very Important: the msg in this case is ACTUALLY a pointer, and it
// is called a pointer decay! (Every time you pass an array to a function, you’ll decay to a pointer)
// Additionally, passing an array variable to a pointer decays it.
void fortune_cookie(char msg[]){
    printf("Message reads: %s\n", msg);
    printf("msg occupies %i bytes\n", sizeof(msg));
    // this should print out 8 bytes.
    // On 32-bit operating systems, a pointer takes 4 bytes of memory
    // and on 64-bit operating systems, a pointer takes 8 bytes.
}

void test1(){
    int contestants[] = {1, 4, 9};
    int *choice = contestants;
    printf("the address of 1 is: %p\n", contestants);
    printf("the address of 2 is: %p\n", &contestants[1]);
    printf("the address of 3 is: %p\n", &contestants[2]);
    // note *(choice + 1) means that value that choice + 1 points to, choice is the address
    // of the array, the same as the first element in the array. 1 in this case is basically saying
    // go to the next element, suppose choice is 0x7ffee877187c, then 1 means the
    // sizeof(int) * 1 = 4[hex], so choice + 1 is 0x7ffee8771880.
    printf("I'm going to pick contestant number %i\n", *(choice + 1));
}

// Note: An array variable can be used as a pointer to the first element in an array.
void equivalent(){
    int drinks[] = {4, 2, 3};
    printf("1st order: %i drinks\n", drinks[0]);
    printf("1st order: %i drinks\n", *drinks);

    // this is funny: (new syntax I've never seen before)
    // drinks[2] = *(drinks + 2) = *(2 + drinks) = 2[drinks]
    printf("3st order: %i drinks\n", 2[drinks]);
}

// This function will skip the first six characters of the text message.
void skip(char *msg){
    puts(msg + 6);
}

// data entry:
void data_entry(){

    // enter a string
    char name[40];
    printf("Enter your name: ");
    // scanf will rea dup to 9 chars plus the string terminator \0.
    // Important: name should be a pointer since scanf will update some
    // variables and it need an address
    scanf("%39s", name);

    // enter a number(int for %i); %f for a floating-point number
    int age;
    printf("Enter your age: ");
    scanf("%i", &age);

}

// fgets() is an alternative to scanf()
// fgets() come from the gets(), which is dangerous to use: demo[
// char dangerous[10]; gets(dangerous)]
// Say it again: (Remember: sizeof returns the amount of space occupied by a variable.
// In the code above, food is an array variable, so sizeof returns the size of the array.
// If food was just a simple pointer variable, the sizeof operator would have just returned the size of a pointer.)
// HeadFirstC[68] haven't read yet ^^
void demo_fgets(){
    char food[5];
    printf("Enter favorite food: ");
    // food is a pointer to a buffer; next, takes a maximum size of the string[in scanf(), you have to subtract 1, since
    // scanf() doesn't count the last '\0', stdin means data will be coming from the keyboard
    fgets(food, sizeof(food), stdin);

}

// Important: char *cards = "JQK"; VS char cards[] = "JQK" -- [
// A variable that points to a string literal can’t be used to change the contents of the string]
// When the computer loads the program into memory,
// it puts all of the constant values—like the string literal “JQK”—into the constant memory block.
// I think "JQK" is called a string constant, and it should be in the [?read-only static part of the memory].
// ^^Important: picture on the bottom of HeadFirstC[74]

// There’s nothing wrong with setting a pointer to a string literal—the problems only happen when you try to
// modify a string literal. Instead, if you want to set a pointer to a literal, always
// make sure you use the const keyword: That way, if the compiler sees some code that tries to modify the string,
// it will give you a compile error: assignment of read-only location
void string_literal(){
    const char *s = "some String";
    // s[0] = 'S'; [uncomment this line and you will see [Read-Only variable is not assignable]
}















