#include <stdio.h>
#include <string.h> 
#include <unistd.h>


void fun_c(char*buf){
    if(getwd(buf)==NULL){
        perror("getwd");
    }else{
        printf("Current working directory: %s\n", buf);
    }
}

void fun_b(char *input) {
    char copied[10];
    strcpy(copied, input);
    printf("Copied string: %s\n", copied);
    fun_c(copied);
}

void fun_a(char *input) {
    char str[10];
    strcpy(str,input);
    printf("Copied string in fun_a: %s\n", str);
    fun_b(str);
}

int main(int argc, char **argv) {
    char buffer[256];
    if (argc < 2) {
        printf("argv error\n");
        return 1;

    }
    fun_a(argv[1]);
    return 0;
}