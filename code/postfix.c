#include<stdio.h>
#include<ctype.h>
#include<stdlib.h>
#include<string.h>
#define MAX 4097
double pop(int top, double stack[]){
    return stack[top];
}
void push(int top, double stack[], double item){
    stack[++top] = item;
}
double calculation( double num1, double num2,char c){
    switch(c){
        case '+':
        return num2+num1;
        case '-':
        return num2-num1;
        case '*':
        return num2*num1;
        case '/':
        return num2/num1;
    }
}
int main(){
    char input[MAX];
    while(fgets(input,MAX,stdin)!=NULL){
        
        if(input[strlen(input)-1] == '\0'){
            input[strlen(input)-1] = '\n';
            input[strlen(input)] = '\0'; 
        }
        
        if(input[0] == '\n')
            continue;
        double stack[1501];
        int top = -1;
        char * ptr = input;
        ptr = strtok(input," ");
        while(ptr!=NULL){
            if(isdigit(*ptr)){
                double num;
                num = atof(ptr);
                push(top,stack,num);
                top++;
            }else if(*ptr == '+' || *ptr == '-' || *ptr == '*' || *ptr == '/'){
                double num1 = pop(top,stack);
                top--;
                double num2 = pop(top,stack);                            
                top--;
                double result = calculation(num1,num2,*ptr);
                push(top,stack,result);
                top++;
            }
            ptr = strtok(NULL," ");
        }
        printf("%.2f\n",pop(top,stack));
    }
    return 0;
}