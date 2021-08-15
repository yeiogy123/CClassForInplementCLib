#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include<ctype.h>
#define MAX 4096
char* encode(char ori)
{  
    int aa = (int) ori;
    if(aa<0){
        aa+=256;
    }
    static char buffer[3];
    if(aa/16 < 10){
        buffer[0] = aa/16 +'0';
    }else
        buffer[0] = aa/16 - 10 +'A';
    if(aa%16<10){
        buffer[1] = aa%16 + '0';
    }else
        buffer[1] = aa%16 -10 +'A';
    buffer[2]='\0';
    return buffer;
}

int main()
{
    char input[MAX];
    while(fgets(input,MAX,stdin)!=NULL){
        char *out;
        out = input;
        char *real;
        while(*out){
            if(!isdigit(*out) && !isalpha(*out) && *out != '.' && *out != '\n'){
              real = encode(*out);
              printf("%%%s",real);
              out++;
            }else{
                printf("%c",*out);
                out++;
            }
        }
    }

    return 0;
}