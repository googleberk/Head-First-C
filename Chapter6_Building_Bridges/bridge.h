#include "stdio.h"
#include "stdlib.h" // this library can pick up malloc() and free() function
#include "string.h"

typedef struct island{
    // there are two things to notice here:
    // [Q: If the island struct had a name array rather than a character pointer, would I need to use strdup() here?]
    // [A: No. Each island struct would store its own copy, so you wouldn’t need to make your own copy.] [remember that
    // array variable will always make a NEW copy of the string on the heap]
    // [Q:  So why would I want to use char pointers rather than char arrays in my data structures?]
    // [A: char pointers won’t limit the amount of space you need to set aside for strings.
    // If you use char arrays, you will need to decide in advance exactly how long your strings might need to be.]

    char *name;
    char *opens;
    char *closes;
    struct island *next;
} island;


void displayA(island *start){
    island *i = start;
    for(; i != NULL; i = i->next){
        printf("Name: %s open: %s-%s\n", i->name, i->opens, i->closes);

    }
}

// note 1. The malloc() function sets aside a chunk of memory for you, then
// returns a pointer containing the start address. But what kind of pointer will that be? malloc()
// actually returns a general-purpose pointer, with type void*.



island* create(char *name){
    island *i = malloc(sizeof(island));
    char *newName = malloc(sizeof(char) * strlen(name) + 1);
    strcpy(newName, name);
    // i->name = newName;
    // or you can just use the strdup() function, which always create space on the heap
    // the formal using is here: char* strdup(const char *str1) [Returns a pointer to a null-terminated byte string,
    // which is a duplicate of the string pointed to by str1. The returned pointer must be passed to free to avoid a memory leak.]

    i->name = strdup(name);

    i->opens = "09:00";
    i->closes = "17:00";
    i->next = NULL;

    // free the i->name
    // free(i->name);
    return i;
}


void connectToLinkedList(){
    island *start = NULL;
    island *i = NULL;
    island *next = NULL;
    char name[80];
    for(; fgets(name, 80, stdin) != NULL; i = next){
        next = create(name);
        if (start == NULL){
            start = next;
        }
        if(i!= NULL){
            i->next = next;
        }
    }
}


void release(island *start){
    island *i = start;
    island *next = NULL;
    for(; i != NULL; i = next){
        next = i->next;
        // free(i);
        // free(i->name);
        // first you need to free the name string that you created with strdup()
        // only AFTER freeing the name should you free the island struct
        free(i->name);
        free(i);
    }
}

// something about memory leak:
// 1. Leaks don’t happen when data is created; they happen when the program loses all references to the data.



