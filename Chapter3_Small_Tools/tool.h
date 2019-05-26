#include "stdio.h"
#include <stdlib.h>
#include <string.h>
#include "unistd.h"


// [Doc: this function is an implementation of Standard Input, Standard Output, and Standard Error]
// Some Useful notes: The printf() function sends data to the Standard Output.
// The Standard Output goes to the display by default.
// You can redirect the Standard Output to a file by using > on the command line.
// scanf() reads data from the Standard Input.
// The Standard Input reads data from the keyboard by default.
// You can redirect the Standard Input to read a file by using < on the command line.
// The Standard Error is reserved for outputting error messages.
// You can redirect the Standard Error using 2>.
//

int pocket() {
    float latitude;
    float longtitude;
    char info[80];
    int started = 0;

    puts("data =[");
    while (scanf("%f, %f, %79[^\n]", &latitude, &longtitude, info) == 3) {
        if (started) {
            printf(",\n");
        } else {
            started = 1;
        }
        if ((latitude < -90.0) || (latitude > 90.0)) {
            fprintf(stderr, "Invalid latitude: %f\n", latitude);
            // if you don't return 2 at here, then there is nothing shown to the Standard Error and the redirected Standard Output
            // kind of weird because this is just an if plus print statement, the original code [code: printf("Invalid latitude: %f\n", latitude);],
            // and without typing [code: return 2], the print statement will show in the output.jason method.
            return 2;
        }
        if ((longtitude < -180.0) || (longtitude > 180.0)) {
            fprintf(stderr, "Invalid longitude: %f\n", longtitude);
            return 2;
        }
        printf("{latitude: %f, longtitude: %f, info: '%s'}", latitude, longtitude, info);
    }
    puts("\n]");
}

// this function sends the odd string to stdout, and the even string to stderr
void secrets() {
    char word[10];
    int i = 0;
    while (scanf("%9s", word) == 1) {
        i = i + 1;
        if (i % 2)
            fprintf(stdout, "%s\n", word);
        else
            fprintf(stderr, "%s\n", word);
    }

}

// this function will filter some data and send them to its Standard Output, then we will use a tool called pipe with
// symbol '|', which will send that data from the Standard Output of the bermuda tool to Standard Input
// of the geo2json tool.
// [Ques: on textbook[131] it says, The operating system will run both programs at the same time.] This would be really
// cool cause this 'pipe' sounds like a Go channel.
void bermuda() {
    float latitude;
    float longitude;
    char info[80];
    while (scanf("%f, %f, %79[^\n]", &latitude, &longitude, info) == 3) {
        if (latitude > 26 && latitude < 34) {
            if (longitude > -76 && longitude < -64) {
                printf("%f, %f, %s\n", latitude, longitude, info);
            }
        }
    }
}


// below deal with data streams:
// [code: FILE *in_file = fopen("input.txt", "r");] this creates a data stream to read from a file.
// [code: FILE *out_file = fopen("output.txt", "w");] this creates a data stream to write to a file.
// the "w" is a mode: The fopen() function takes two parameters: a filename and a mode.
// The mode can be w to write to a file, r to read from a file, or a to append data to the end of a file.
// you can now send you print statement to a specific output stream you created by using:
// [code: fprintf(out_file, "Don't wear %s with %s", "red", "green");]
// Similarly: you can read from a file stream and store it in a pointer using:
// [code: fscanf(in_file, "%79[^\n]\n", sentence);]
// Finally, don't forget to close your data stream bu using:
// [code: fclose(in_file); and/or fclose(out_file);], which is similar like free a memory in C or close a channel in GO.
// Some notes:
// 1. It depends on the operating system, but usually a process can have up to 256. The key thing is there’s
// a limited number of them, so make sure you close them when you’re done using them.
// 2. It’s historic. FILE used to be defined using a macro. Macros are usually given uppercase names.
// You’ll hear about macros later on.

void read_write_stream() {
    char line[80];
    FILE *in = fopen("spooky.csv", "r");
    FILE *file1 = fopen("ufos.csv", "w");
    FILE *file2 = fopen("disappearances.csv", "w");
    FILE *file3 = fopen("others.csv", "w");
    while (fscanf(in, "%79[^\n]\n", line) == 1) {
        if (strstr(line, "UFO"))
            fprintf(file1, "%s\n", line);
        else if (strstr(line, "Disappearance"))
            fprintf(file2, "%s\n", line);
        else
            fprintf(file3, "%s\n", line);
    }
    fclose(file1);
    fclose(file2);
    fclose(file3);

}

// below is an update of the above function that users can determine which word to search at running by passing
// arguments to the main function
int read_write_stream_augment(int argc, char *argv[]){
    char line[80];
    // argc includes the first one!
    if(argc != 6){
        fprintf(stderr, "You need to give 5 arguments\n");
        return 1;
    }
    // note: we can add a safety check to "spooky.csv", by changing the following code,
    // [code: FILE *in = fopen("spooky.csv", "r");] to:
    FILE *in;
    if(!(in = fopen("spooky.csv", "r"))){
        fprintf(stderr, "Can't open spooky.csv");
        return 1;
    }

    FILE *file1 = fopen(argv[2], "w");
    FILE *file2 = fopen(argv[4], "w");
    FILE *file3 = fopen(argv[5], "w");
    while (fscanf(in, "%79[^\n]\n", line) == 1) {
        if (strstr(line, argv[1]))
            fprintf(file1, "%s\n", line);
        else if (strstr(line, argv[3]))
            fprintf(file2, "%s\n", line);
        else
            fprintf(file3, "%s\n", line);
    }
    // it seems like the book forget to close the in data stream, so add this:
    fclose(in);
    fclose(file1);
    fclose(file2);
    fclose(file3);
}

// the command-line options is really cool and well explained in TB[149]

int order_pizza(int argc, char *argv[]){
    char *delivery = "";
    int thick = 0;
    int count = 0;
    char ch;

    while ((ch = getopt(argc, argv, "d:t")) != EOF){
        switch(ch){
            case'd':
                delivery = optarg;
                break;
            case 't':
                thick = 1;
                break;
            default:
                fprintf(stderr, "Unknown option: '%s'\n", optarg);
                return 1;
        }
    }
    argc -= optind;
    argv += optind;

    if(thick){
        puts("Thick crust.");
    }
    if(delivery[0]){
        printf("To be delivered %s.\n", delivery);
    }
    puts("Ingredients:");
    for (count = 0; count < argc; count++){
        puts(argv[count]);
    }

}

// some back notes:
// 1. In order to avoid ambiguity, you can split your main arguments from the options using --.
// So you would write set_temperature -c -- -4. getopt() will stop reading options when it sees the --,
// so the rest of the line will be read as simple arguments.
// 2. Because of the way we read the options, it won’t matter if you type in -d now -tor-t -d now or-td now.
// However, if there are one argument needed to be passed in to -d. and -t, I think you will have to write your options
// in a more formal way like [-d now -t 1][not sure, haven't checked yet]











