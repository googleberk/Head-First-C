#include "stdio.h"
// All the code to handle variadic functions is in stdarg.h
#include "stdarg.h"

int sports_no_bieber(char *s);

int sports_or_workout(char *s);

int ns_theater(char *s);

int arts_theater_or_dining(char *s);


void find(char *ADS[], int NUM_ADS) {
    int i;
    puts("Search results:");
    puts("------------------------------------------------------------");
    for (i = 0; i < NUM_ADS; i++) {
        if (strstr(ADS[i], "sports") && !strstr(ADS[i], "bieber")) {
            printf("%s\n", ADS[i]);
        }
    }
    puts("------------------------------------------------------------");
}

int sports_no_bieber(char *s) {
    return strstr(s, "sports") && !strstr(s, "bieber");
}

int sports_or_workout(char *s) {
    return strstr(s, "sports") || strstr(s, "working out");
}

int ns_theater(char *s) {
    return strstr(s, "NS") && strstr(s, "theater");
}

int arts_theater_or_dining(char *s) {
    return strstr(s, "arts") || strstr(s, "theater") || strstr(s, "dining");
}

// 1. whenever you create a function, you also create a function pointer with
// the same name. for example: [int go_to_warp_speed(int speed){}] creates a
// function name "go_to_warp_speed" and this pointer is stored in the constant part of
// the memory. The pointer contains the address of the function.


// 2. C doesn't have a function data type because there's not just one type of function


// this function takes a function pointer [code: int(*match)(char*)]
void findA1(int(*match)(char *), char *ADS[], int NUM_ADS) {
    int i;
    puts("Search results:");
    puts("------------------------------------------------------------");
    for (i = 0; i < NUM_ADS; i++) {
        // [Q: If function pointers are just pointers,
        // why don’t you need to prefix them with a * when you call the function?]
        // [A: You can. In the program, instead of writing match(ADS[i]),
        // you could have written (*match)(ADS[i]).]

        if (match(ADS[i])) {
            printf("%s\n", ADS[i]);
        }
    }
    puts("------------------------------------------------------------");

}


// sort integer scores, with the smallest first
int compare_scores(const void *score_a, const void *score_b) {
    int a = *(int *) score_a;
    int b = *(int *) score_b;
    return a - b;
}

// sort integer scores, with the largest first
int compare_scores_desc(const void *score_a, const void *score_b) {
    int a = *(int *) score_a;
    int b = *(int *) score_b;
    return b - a;
}

// this is the rectangle type
typedef struct {
    int width;
    int height;
} rectangle;

// sort the rectangles in area order smallest first.
int compare_areas(const void *a, const void *b) {
    rectangle ar = *(rectangle *) a;
    rectangle br = *(rectangle *) b;
    int a_area = ar.width * ar.height;
    int b_area = br.width * br.height;
    return a_area - b_area;
}

int compare_areasV1(const void *a, const void *b) {
    rectangle *ar = (rectangle *) a;
    rectangle *br = (rectangle *) b;
    int area_a = ar->height * ar->width;
    int area_b = br->height * br->width;
    return area_a - area_b;
}


// sort a list of names in alphabetical order. Case-sensitive
// because a string is a pointer to a char, so a is a pointer to a string,
// which is then a pointer to a pointer to a char.
// We know that each item in a string array is a char pointer (char*).
// When qsort() calls the comparator function, it sends pointers to two
// elements in the arrays, that means the comparator receives two pointers-to-pointers-to-char.
// In C notation, each value is a char**.

int compare_names(const void *a, const void *b) {
    char **sa = (char **) a;
    char **sb = (char **) b;
    return strcmp(*sa, *sb);
}

// sort the rectangles in area order, largest first
int compare_areas_desc(const void *a, const void *b) {
    return compare_areas(b, a);
}

// sort a list of names in reverse alphabetical order. Case-sensitive
int compare_names_desc(const void *a, const void *b) {
    return compare_names(b, a);
}

void qsortExample() {
    int scores[] = {543, 323, 32, 554, 11, 3, 112};
    int i;
    qsort(scores, 7, sizeof(int), compare_scores_desc);
    // qsort just changes the order of the elements in the array.
    // qsort mutates them
    puts("These are the scores in order: ");
    for (i = 0; i < 7; i++) {
        printf("Score = %i\n", scores[i]);
    }
    char *names[] = {"Karen", "Mark", "Brett", "Molly"};
    // remember: an array of names is just an array of char pointers, so
    // the size of each item is sizeof(char*).
    // qsort() accepts a pointer to a comparator function that can test for (in)equality.
    // so compare_names is a pointer to the function named compare_names,
    // you could also use &compare_names
    qsort(names, 4, sizeof(char *), compare_names);
    puts("These are the names in order: ");
    for (i = 0; i < 4; i++) {
        printf("%s\n", names[i]);
    }

}

enum response_type {
    DUMP, SECOND_CHANCE, MARRIAGE
};
typedef struct {
    char *name;
    enum response_type type;
} response;

void dump(response r) {
    printf("Dear %s, \n", r.name);
    puts("Unfortunately your last date contacted us to");
    puts("say that they will not be seeing you again");
}

void second_chance(response r) {
    printf("Dear %s,\n", r.name);
    puts("Good news: your last date has asked us to");
    puts("arrange another meeting. Please call ASAP.");

}

void marriage(response r) {
    printf("Dear %s,\n", r.name);
    puts("Congratulations! Your last date has contacted");
    puts("us with a proposal of marriage.");
}

void list_response() {
    response r[] = {
            {"Mike",    DUMP},
            {"Luis",    SECOND_CHANCE},
            {"Matt",    SECOND_CHANCE},
            {"William", MARRIAGE}
    };
    int i;
    for (i = 0; i < 4; i++) {
        switch (r[i].type) {
            case DUMP:
                dump(r[i]);
                break;
            case SECOND_CHANCE:
                second_chance(r[i]);
                break;
            default:
                marriage(r[i]);
        }
    }

}

// this is a augmented version, we create an array of function pointers
// the syntax is [Return Type(* Pointer Variable Name)(Parameters Types)
void (*replies[])(response) = {dump, second_chance, marriage};
// when C creates an enum, it gives each of the symbols a number starting at 0.
// So DUMP == 0, SECOND_CHANCE==1, andMARRIAGE==2.

void list_responseA1() {
    response r[] = {
            {"Mike",    DUMP},
            {"Luis",    SECOND_CHANCE},
            {"Matt",    SECOND_CHANCE},
            {"William", MARRIAGE}
    };
    int i;
    for (i = 0; i < 4; i++) {
        replies[r[i].type](r[i]);
        // you could also do this, but it is optional
        // replies[r[i].type] would return a pointer to a function,
        // so you need to dereference that to get that function.
        // but C is smart in this case, you don't have to do this.
        (*replies[r[i].type])(r[i]);
    }
}

// Arrays of function pointers can make your code much easier to manage.
// They are designed to make your code scalable by making it shorter and easier to extend.
// Even though they are quite difficult to understand at first,
// function pointer arrays can really crank up your C programming skills.

enum drink {
    MUDSLIDE, FUZZY_NAVEL, MONKEY_GLAND, ZOMBIE
};

double price(enum drink d) {
    switch (d) {
        case MUDSLIDE:
            return 6.79;
        case FUZZY_NAVEL:
            return 5.31;
        case MONKEY_GLAND:
            return 4.82;
        case ZOMBIE:
            return 5.89;
    }
}

double total(int args, ...){
    double total = 0;
    va_list ap;
    va_start(ap, args);
    int i;
    for(i = 0; i< args; i++){
        enum drink d = va_arg(ap, enum drink);
        total += price(d);
    }
    va_end(ap);
    return total;
}


// The following is a variadic function.
// A macro is used to rewrite your code before it’s compiled.
// The macros you’re using here (va_start, va_arg, and va_end) might look
// like functions, but they actually hide secret instructions that tell
// the preprocessor how to generate lots of extra smart code inside your program, just before compiling it.
void print_ints(int args, ...){
    va_list ap;
    va_start(ap, args);
    int i;
    for(i = 0; i < args; i++){
        printf("arguments: %i\n", va_arg(ap, int));
    }
    va_end(ap);
}
// [Q: Wait, why are va_end and va_start called macros? Aren’t they just normal functions?]
// [A: No, they are designed to look like ordinary functions, but they actually are replaced by the preprocessor with other code.]













