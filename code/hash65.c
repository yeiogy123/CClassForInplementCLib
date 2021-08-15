#include<stdio.h>
#include<string.h>
#define MAX 10
void hash65(char * input){
    unsigned long long a = 0;
    for(int i = 0 ; i < strlen(input) ; i++){
        unsigned long long data = 1;
        for(int j = i ; j < strlen(input)-1 ; j++){
            data = data * 65;
        }
        a = a + (int)input[i]*data;
    }
    printf("%llu\n",a);
}
int main(){
    char input[MAX];
    while(fgets(input,MAX,stdin)!=NULL){
        if(input[strlen(input)-1]=='\n')
            input[strlen(input)-1] = '\0';
        hash65(input);
    }
}