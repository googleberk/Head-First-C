#include "stdio.h"
#include "limits.h"
#include "float.h"

// something about data types:
// 1. Each character is stored in the computer’s memory as a character code. And that’s just a number.
// So when the computer sees A, to the computer it’s the same as seeing the literal number 65.
// 1.1 The exact maximum size of an int can vary, but it’s guaranteed to be at least 16 bits.
// 1.2 The maximum size of a long is guaranteed to be at least 32 bits.
// 1.3 %hi is the proper code to format a short value.
// 1.4 In fact, if the compiler sees you are adding, subtracting, multiplying, or dividing a floating-point
// value with a whole number, it will automatically cast the numbers for you.
// 1.5 long long is C99 and C11 only.

// this function returns the sizeof(int, long, etc), and the corresponding max and min value of each of them.
// What if you want to know the details for chars or doubles? Or longs? No problem. Just replace INT and FLT
// with CHAR (chars), DBL(doubles), SHRT (shorts), or LNG (longs).
void data(){
    printf("The value of INT_MAX is %i\n", INT_MAX);
    printf("The value of INT_MIN is %i\n", INT_MIN);
    printf("An int takes %zu bytes\n", sizeof(int));

    printf("The value of FLT_MAX is %f\n", FLT_MAX);
    printf("The value of FLT_MIN is %.50f\n", FLT_MIN);
    printf("A float takes %zu bytes\n", sizeof(float));



}

// Here is a little bit interesting thing about the header file, which I haven't put a notice on it before.
// 2. When you write the name of the header file, make sure you surround it with double quotes
// rather than angle brackets. Why the difference? When the compiler sees an include line with angle brackets,
// it assumes it will find the header file somewhere off in the directories where the library code lives.
// But your header file is in the same directory as your .c file.
// By wrapping the header filename in quotes, you are telling the compiler to look for a local file.
// 3. Q: So I don’t need to have declarations for int functions? A: Not necessarily, unless you are sharing code.
// 4. If the compiler finds a call to a function it hasn’t heard of, it will assume the function returns an int.

// 5. [Ques: I don't understand the words "Remember, you can call the same function to decrypt text." on TB[187]]

