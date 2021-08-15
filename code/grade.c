#include<stdio.h>
#include<stdbool.h>
#define MAX 1000
typedef struct student{
    char name[MAX];
    int hw1,hw2,hw3,hw4,hw5,total;
    bool status;
}student;
int main(){
    student Classstudent[MAX];
    int i = 0;
    while(scanf("%s",Classstudent[i].name)!=EOF){
        scanf("%d",&Classstudent[i].hw1);
        scanf("%d",&Classstudent[i].hw2);    
        scanf("%d",&Classstudent[i].hw3);     
        scanf("%d",&Classstudent[i].hw4);     
        scanf("%d",&Classstudent[i].hw5);  
        Classstudent[i].total = Classstudent[i].hw5+Classstudent[i].hw4+Classstudent[i].hw3+Classstudent[i].hw2+Classstudent[i].hw1;
        i++;
    }
    for(int a = 0 ; a < i ; a++ ){
        Classstudent[a].status = false;
    }
    for(int a = 0 ; a < i ; a++){
        int index = 0; 
        int max = 0 ;
        for(int b = 0 ; b < i ; b++){
            if(max <= Classstudent[b].total && !Classstudent[b].status ){
                max = Classstudent[b].total;
                index = b;
            }
        }
        printf("%s\t%d\t%d\t%d\t%d\t%d\n",Classstudent[index].name,Classstudent[index].hw1,Classstudent[index].hw2,Classstudent[index].hw3,Classstudent[index].hw4,Classstudent[index].hw5);
        Classstudent[index].status = true;
    }
}