#include <stdio.h>
#include <unistd.h>
#include <errno.h>
int main(int argc, char *argv[]){
    FILE* fptr1;
    FILE* fptr2;

    char c;
    int k=0;

    fptr1 = fopen(argv[1],"r");
    fptr2 = fopen(argv[2],"w");

    if(fptr1 == NULL){
        printf("Source file cannot be read");
        return 0;
    }
    if(fptr2 == NULL){
        printf("Destination file cannot be written");
        return 0;
    }

    while(c!=EOF){
        c = fgetc(fptr1);
        // If a char in source file is '1', changes it to 'a' 
        if(c == '1'){
            c ='a';
        }
        putc(c, fptr2);
        // Prints string "xyz" every 100 chars
        if(k==100){
            fprintf(fptr2,"xyz");
            k=-1;
        }
        k++;
    }

    fclose(fptr1);
    fclose(fptr2);

    printf("Content of %s copied to %s\n", argv[1], argv[2]);

    return 0;
}