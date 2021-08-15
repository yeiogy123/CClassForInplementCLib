#include<stdio.h>
#include<string.h>
#include<ctype.h>
#define MAX 4096
int mystrlen(const unsigned char * src){
    int len=0;
    while(*src){
        len++;
        src++;
    }
    return len;
}
unsigned char * getword(unsigned char *dest, unsigned char *src){
    unsigned char * ptr = src, *qtr = dest, *ttr;
    unsigned char string[4];
    if(*ptr >= 240){
        memcpy(string,ptr,4);
        string[4]='\0';
    }
    else if(*ptr >= 224 ){//第一個字中文
        memcpy(string,ptr,3);
        string[3]='\0';
    }
    else if(*ptr >= 192){
        memcpy(string,ptr,2);
        string[2]='\0';
    }else{
        memcpy(string,ptr,1);
        string[1]='\0';
    }
    int flag = 0,flag2 = 0;
    while(*ptr){
        if(strcmp((char*)string,(char*)"「")==0||
                strcmp((char*)string,(char*)"『")==0){
            flag = 1;
            if(*ptr >= 240){
                ptr+=4;
            }else if(*ptr >= 224 ){
                ptr+=3;
            }else if(*ptr >= 192){
                ptr+=2;
            }else{
                ptr+=1;
            }
            break;
        }
        if(*ptr >= 240){
            ptr+=4;
        }else if(*ptr >= 224 ){
            ptr+=3;
        }else if(*ptr >= 192){
            ptr+=2;
        }else{
            ptr+=1;
        }
        if(*ptr >= 240){
            strncpy((char*)string,(char*)ptr,4);
            string[4]='\0';
        }else if(*ptr >= 224 ){
            strncpy((char*)string,(char*)ptr,3);
            string[3]='\0';
        }else if(*ptr >= 192){
            strncpy((char*)string,(char*)ptr,2);
            string[2]='\0';
        }else{
            strncpy((char*)string,(char*)ptr,1);            
            string[1]='\0';
        }
    }
    ttr = ptr;//從ptr後面開始找關鍵字
    while(*ttr){
        if((strcmp((char*)string,(char*)"」")==0)||(
                strcmp((char*)string,(char*)"』")==0)){
            flag2 = 1;
            break;
        }
        if(*ttr >= 240){
            ttr+=4;
        }else if(*ttr >= 224 ){
            ttr+=3;
        }else if(*ttr >= 192){
            ttr+=2;
        }else{
            ttr+=1;
        }
        if(*ttr >= 240){
            strncpy((char*)string,(char*)ttr,4);
            string[4]='\0';
        }else if(*ttr >= 224 ){
            strncpy((char*)string,(char*)ttr,3);
            string[3]='\0';
        }else if(*ttr >= 192){
            strncpy((char*)string,(char*)ttr,2);
            string[2]='\0';
        }else{
            strncpy((char*)string,(char*)ttr,1);            
            string[1]='\0';
        }
    }
    string[0]='\0';
    while(*ptr && (strcmp((char*)string,(char*)"」")!=0&&
                strcmp((char*)string,(char*)"』")!=0) && flag && flag2) {
        if(*ptr >= 240 ){
           *qtr++=*ptr++;
           *qtr++=*ptr++;
           *qtr++=*ptr++;
           *qtr++=*ptr++;
        }else if(*ptr >= 224 ){
            *qtr++=*ptr++;
            *qtr++=*ptr++;
            *qtr++=*ptr++;
        }else if(*ptr>=192){
            *qtr++=*ptr++;
            *qtr++=*ptr++;
        }else{
            *qtr++=*ptr++;
        }
        if(*ptr >= 240 ){
            strncpy((char*)string,(char*)ptr,4);
            string[4]='\0';
        }else if(*ptr >= 224 ){
            strncpy((char*)string,(char*)ptr,3);
            string[3]='\0';
        }else if(*ptr>=192){
            strncpy((char*)string,(char*)ptr,2);
            string[2]='\0';
        }else{
            strncpy((char*)string,(char*)ptr,1);
            string[1]='\0';
        }
    }
    if(strcmp((char*)string,(char*)"」")==0||
                strcmp((char*)string,(char*)"』")==0){
                    if(*ptr >= 240){
                        ptr+=3;
                    }else if(*ptr >= 224 ){
                        ptr+=3;
                    }else if(*ptr >= 192){
                        ptr+=2;
                    }else{
                        ptr+=1;
                    }
                } 
    if(dest==qtr) return NULL;
    *qtr = '\0';
    //printf("final=%s\n",dest);
    return ptr;
}
int main(){
    char input[MAX];
    int max=0;
    unsigned char foutput[MAX];
    while(fgets(input,MAX,stdin)!=NULL){
        unsigned char * ptr =(unsigned char *) input;
        unsigned char output[MAX];
        while((ptr = getword(output,ptr))!=NULL){
            if(max==0){
                strcpy((char*)foutput,(char*)output);
                max = 1;
            }else{
                if(mystrlen(foutput)<mystrlen(output)){
                    strcpy((char*)foutput,(char*)output);
                }
            }
        }
    }
    printf("%s\n",(unsigned char*)foutput);
}