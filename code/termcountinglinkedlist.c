#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<stdbool.h>
typedef struct  list* lpt;
typedef struct list{
    char term[128];
    int count ;
    lpt next;
}list;
int main(){
    char input[128];
    lpt head = NULL;
    while(fgets(input,128,stdin)!=NULL){
        if(input[strlen(input)-1] == '\n')
            input[strlen(input)-1] = '\0';
        bool status = 0;
        if(head == NULL){
            head = (lpt)malloc(sizeof(list));
            strcpy(head->term,input);
            head->count = 1;
            head->next = NULL;
        }else{
            lpt lqt = head;
                if(input[0] == '-'){
                    char *ptr = &input[1];
                    while(lqt!= NULL){
                        if(strcmp(lqt->term,ptr)==0){
                        lqt->count--;
                        status = 1;
                        break;
                    }
                    else{
                        lqt = lqt->next;
                    }
                }
            }else{
                while(lqt!= NULL){
                    if(strcmp(lqt->term,input)==0){
                        lqt->count++;
                        status = 1;
                        break;
                    }
                    else{
                        lqt = lqt->next;
                    }
                }
            }
            if(status == 1)
                continue;
            else{
                lpt node = (lpt)malloc(sizeof(list));
                strcpy(node->term,input);
                node->count = 1;
                node->next = NULL;
                lqt = head;
                while(lqt->next != NULL)
                    lqt = lqt->next;
                lqt->next = node;
            }
        }
    }
    while(head!=NULL){
            printf("%s: %d\n",head->term,head->count);
            head = head->next;
    }
}