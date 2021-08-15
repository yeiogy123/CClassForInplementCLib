#include<stdio.h>
#define MAXS 2048
#define MAXP 1024
int compare(char * source,char * pattern){
    while(*source && *pattern){
        if(*source != *pattern){
            return 0;
        }
        source++;
        pattern++;
    }
    return (*pattern == '\0');
}
char * strstr(char * source, char * pattern){
    char * ptr = NULL;
    while(*source != '\0'){
        if((*source == *pattern) && compare(source,pattern)){
            ptr = source;
        }
        source++;
    }
    return ptr;
}
int main(){
    char input[MAXS],source[MAXS],pattern[MAXP];
    while(fgets(input,MAXS,stdin)){ 
        int ori = 0;
        while(input[ori]!='\n')
            ori++;
        input[ori] = '\0';
        int i = 0;
        char * ptr = source;
        while(input[i]!=','){
            source[i] = input[i];
            i++;
        }
        source[i] = '\0';
        i++;
        int a = 0;
        while( input[i] != '\0' ){
            pattern[a++] = input[i++];
        }
        pattern[a] = '\0';

        if(strstr(ptr,pattern) != NULL){
            long int b = strstr(ptr,pattern)-source;
            printf("%ld,%ld\n",b,b+a-1);
        }else
            printf("-1\n");
    }
}