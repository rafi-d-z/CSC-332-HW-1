#include <stdio.h>
#include <unistd.h>
#include <errno.h>
int main(int argc, char *argv[]){
    FILE* fptr1;
    FILE* fptr2;

    char c;
    // Takes both given files as variables,
    // source file set to read,
    // destination file set to write
    fptr1 = fopen(argv[1],"r");
    fptr2 = fopen(argv[2],"w");
    //Checks if source file can be read
    if(fptr1 == NULL){
        printf("Source file cannot be read");
        return 0;
    }
    //Checks if destination file can be written
    if(fptr2 == NULL){
        printf("Destination file cannot be written");
        return 0;
    }
    //Puts each char from source file to destination file
    while(c!=EOF){
        c = fgetc(fptr1);
        putc(c, fptr2);
    }

    fclose(fptr1);
    fclose(fptr2);

    printf("Content of %s copied to %s\n", argv[1], argv[2]);

    return 0;
}