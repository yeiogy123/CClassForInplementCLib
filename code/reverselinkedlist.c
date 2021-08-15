#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define MAX 1024
typedef struct list * lpt ;
typedef struct list{
    char data[MAX];
    lpt next;
}list;
int main(){
    char input[MAX];
    lpt head = NULL;
    while(fgets(input,MAX,stdin)!=NULL){
        if(input[strlen(input)-1]=='\0'){
            input[strlen(input)-1]='\n';
            input[strlen(input)] = '\0';
        }
        if(head == NULL){
            head = (lpt)malloc(sizeof(list));
            head->next = NULL;
            strcpy(head->data,input);
        }else
        {
            lpt node = (lpt)malloc(sizeof(list));
            node->next = head;
            strcpy(node->data,input);
            head = node;
        }
    }
    lpt current = head;
    while(current){
        printf("%s",current->data);
        current = current->next;
    }
    current = head;
    lpt Nnode = NULL;
    lpt now = NULL;
    while(current->next != NULL){
        lpt front;
        while(current->next != NULL){
            front = current;
            current = current->next;
        }
        if(Nnode == NULL){
            Nnode = (lpt)malloc(sizeof(list));
            strcpy(Nnode->data,current->data);
            Nnode->next = NULL;
            now = Nnode;
        }else{
            lpt lqt = (lpt)malloc(sizeof(list));
            lqt->next = NULL;
            strcpy(lqt->data,current->data);
            //printf("%s\n",lqt->data);
            now->next = lqt;
            now = lqt;
        }
        front->next = NULL;
        current = head;
    }
    lpt lqt = (lpt)malloc(sizeof(list));
    lqt->next = NULL;
    strcpy(lqt->data,current->data);
    now->next = lqt;
    now = lqt;
    while(Nnode){
        printf("%s",Nnode->data);
        Nnode = Nnode->next;
    }
    free(Nnode);
}