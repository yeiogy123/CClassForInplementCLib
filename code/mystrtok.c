#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define MAX 1024
int Strtok(char string[], char word[], char token[]){
    char *ptr = string, *qtr = token, *last = string, *pivot;
    int found = 0, found2 = 0;
    pivot = strstr(ptr, word);
    if(pivot == NULL){
        return 2;
    }
    else{
        while(pivot != NULL){
            found = 0;
            while(last != pivot){
                *qtr++ = *last++;
                ptr++;
                found = 1;
                found2 = 1;
            }
            if(found){
                *qtr++ = ',';
            }
            last = last + strlen(word);
            ptr = ptr + strlen(word);
            pivot = strstr(ptr, word);
        }

        if(*last == '\0'){
            if(!found2){
                return 0;
            }
            *--qtr = '\0';
            return 1;
        }
        while(*last != '\0'){
            *qtr++ = *last++;
        }
        *qtr = '\0';
        return 1;
    }
}
int main(){
    char line[MAX], string[MAX], word[MAX], token[MAX];
    char *ptr;
    int i = 0;
    while(fgets(line,MAX, stdin) != NULL){
        ptr = line;
        while(*ptr != ' '){
            string[i] = *ptr;
            ptr++;
            i++;
        }
        string[i] = '\0';
        i = 0;
        ptr++;
        while(*ptr != '\n' && *ptr != '\0'){
            word[i] = *ptr;
            ptr++;
            i++;
        }
        word[i] = '\0';
        i = 0;
        if(Strtok(string, word, token) == 0){
            printf("empty string\n");
        }
        else if (Strtok(string, word, token) == 1){
            printf("%s\n", token);
        }
        else{
            printf("%s\n", string);
        }
    }
    return 0;
}