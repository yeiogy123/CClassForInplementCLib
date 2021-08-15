#include<stdio.h>
#include<string.h>
#include<ctype.h>
#define MAX 2048
unsigned char * getword(unsigned char *dest, unsigned char *src){
    unsigned char * ptr = src, *qtr = dest;
    if(*ptr>= 240){
        *qtr++=*ptr++;
        *qtr++=*ptr++;
        *qtr++=*ptr++;
        *qtr++=*ptr++;
        *qtr = '\0';
    }else if(*ptr >= 224 ){
        *qtr++=*ptr++;
        *qtr++=*ptr++;
        *qtr++=*ptr++;
        *qtr = '\0';
    }else if(*ptr >= 192){
        *qtr++=*ptr++;
        *qtr++=*ptr++;
        *qtr = '\0';
    }else{
        while(*ptr && isspace(*ptr)) {ptr++;}
        while(*ptr && !isspace(*ptr)) {*qtr++=*ptr++;}
        if(dest==qtr) return NULL;
    *qtr = '\0';
    }
    return ptr;
}
int main(){
    char input[MAX];
    while(fgets(input,MAX,stdin)!=NULL){
        unsigned char * ptr =(unsigned char *) input;
        unsigned char output[MAX];
        while((ptr = getword(output,ptr))!=NULL){
            printf("%s\n",output);
        }
    }
}