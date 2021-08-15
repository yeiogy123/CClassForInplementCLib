#include<stdio.h>
#include<string.h>
#define MAX 3072
char pop(char stack[],int top){
    return stack[top];
}
void push(char stack[],int top,char item){
    stack[top] = item;
}
int priority(char item){
    switch(item){
        case '*': case'/':
        return 2;
        case '+': case '-':
        return 1;
        default :
        return 0;
    }
}
int main()
{
    char input[MAX];
    while(scanf("%s",input)!=EOF){
        char stack[MAX];
        memset(stack,0,MAX);
        int top = -1;
        for(int i = 0 ; i < strlen(input) ; i++){
            if(input[i] == '('){
                top++;
                push(stack,top,input[i]);
            }
            else if(input[i] == ')'){
                    while(stack[top] != '('){
                            printf(" ");
                        printf("%c",pop(stack,top));
                        top--;
                    }
                    pop(stack,top);
                    top--;
            }else if(input[i] == '+' || input[i] == '-' || input[i] == '*' || input[i] == '/'){
                    printf(" ");
                    int num1 = priority(input[i]);
                    int num2 = priority(stack[top]);
                    while(num2 >= num1){
                        printf("%c ",pop(stack,top));
                        top--;
                        num2 = priority(stack[top]);
                    }
                    top++;
                    push(stack,top,input[i]);
            }else{
                printf("%c",input[i]);
            }
        }
        while(top != -1){
            if(top != -1)
                printf(" ");
            printf("%c",pop(stack,top));
            top --;
        }
        printf("\n");
    }
}