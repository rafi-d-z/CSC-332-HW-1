#include <stdio.h>
#include <unistd.h>
#include <errno.h>
int main(){
    FILE* ptr;
    char c;

    ptr = fopen("file.txt", "r");

    if(NULL == ptr){
        printf("file can't be opened \n");
    }

    do{
        c = fgetc(ptr);
        putchar(c);
    }while(c!=EOF);

    fclose(ptr);
    return 0;
}