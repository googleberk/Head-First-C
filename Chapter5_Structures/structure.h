#include "stdio.h"

typedef struct fish {
    const char *name;
    const char *species;
    int teeth;
    int age;
} fish_kind;



void catalog(struct fish f){
    printf("%s is a %s with %i teeth. He is %i\n", f.name, f.species, f.teeth, f.age);
}

// [Ques: I don't understand what "No. The computer leaves gaps only to prevent fields from splitting
// across word boundaries. If it can fit several fields into a single word, it will." this means on TB[235]

void pointer_struct(fish_kind *f){
    // note "->" is used after a pointer, and "." is to access the attribute of a struct.
    // 1. there is a thing to remember: So the expression *t.age is really the same as *(t.age).
    // Think about that expression for a moment. It means “the contents of the memory location given by t.age.”
    // But t.age isn’t a memory location.
    // so the correct usage is shown below. [code: (*f).age]
    // pointer->field is the same as (*pointer).field. I see, the attribute of a struct is called a field of that struct.
    (*f).age += 1;
    //f->age += 1;
}

void test_int(int a){
    a += 1;
}

// Q: Why does the C89 notation only set the first field? Why not set it to the first float if I pass it a float value?
// A: To avoid ambiguity. If you had, say, a float and a double field, should the computer store {2.1} as
// a float or a double? By always storing the value in the first field, you know exactly how the data will be initialized.


// this function reveals how to use enum to store the info with regards to union

typedef enum {
    COUNT, POUNDS, PINTS
} unit_of_measure;

typedef union {
    short count;
    float weight;
    float volume;
} quantity;

typedef struct {
    const char *name;
    const char *country;
    quantity amount;
    unit_of_measure units;
} fruit_order;

void display(fruit_order order){
    printf("This order contains: ");
    if(order.units == PINTS){
        printf("%2.2f pints of %s from %s\n", order.amount.volume, order.name, order.country);
    }
    // Important note: I should use [else if] here.
    else if(order.units == POUNDS){
        printf("%2.2f lbs of %s from %s\n", order.amount.weight, order.name, order.country);
    }
    else{
        printf("%i %s from %s\n", order.amount.count, order.name, order.country);
    }
}

void fruit(){
    fruit_order apples = {"apples", "England", .amount.count= 144, COUNT};
    fruit_order strawberries = {"strawberries", "Spain", .amount.weight= 17.6, POUNDS};
    fruit_order oj = {"orange juice", "U.S.A.", .amount.volume= 10.5, PINTS};
    display(apples);
    display(strawberries);
    display(oj);

}

// 2. Bitfields should be declared as unsigned int.


