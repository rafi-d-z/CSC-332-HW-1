#include <stdio.h>
#include <unistd.h>
#include <errno.h>
int main(int argc, char *argv[]){
    FILE* ptr;
    char c;
    
    //Takes given file as variable, set to read
    ptr = fopen(argv[1], "r");
    //Checks if file and read permissions exists
    if(NULL == ptr){
        printf("file can't be opened \n");
    }
    //Prints each char to console until EOF
    while(c!=EOF){
        c = fgetc(ptr);
        putchar(c);
    }

    fclose(ptr);
    return 0;
}