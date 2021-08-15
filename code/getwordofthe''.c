#include<stdio.h>
#include<string.h>
#include<ctype.h>
#define MAX 2048
char * getword(char *dest, char *src){
    char * ptr = src, *qtr = dest;
    while(*ptr && *ptr != '"') {
        ptr++;
    }
    if(*ptr == '"') ptr++;
    while(*ptr && *ptr != '"') {*qtr++=*ptr++;}
    if(*ptr == '"') ptr++;
    if(dest - qtr == 0) return NULL;
    *qtr = '\0';
    return ptr;
}
int main(){
    char input[MAX];
    while(fgets(input,MAX,stdin)!=NULL){
        char * ptr = input;
        char output[MAX];
        while((ptr = getword(output,ptr))!=NULL){
            printf("%s\n",output);
        }
    }
}