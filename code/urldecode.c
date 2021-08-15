#include<stdio.h>
#include<string.h>
#include<ctype.h>
#define MAX 4096
int hex2num(char c){
    if(c >='0' && c <='9')
        return c-'0';
    if(c >= 'A' && c <= 'F')
        return c-'A'+10;
    return '0';
}
int urldecode(char out[],int olen,char src[],int slen){
    char  c,ch1,ch2;
    int j = 0;
    for(int i = 0 ; i < slen && j < olen ; i++){
        c = src[i];
        switch(c){
            case'%':
                if(i + 2 < slen){
                    ch1 = hex2num(src[i+1]);
                    ch2 = hex2num(src[i+2]);
                    if((ch1!='0') && ch2!='0'){
                            out[j++] = (char)((ch1<<4)|ch2);
                    }else if(ch1 == '0' || ch2 =='0')
                        return -1;
                    i+=2;
                    break;
                }else{
                    break;
                }
            default:
                out[j++] = c;
                break;
        }
    }
    out[j]='\0';
    return j;
}
int main(){
    char input[MAX];
    while(fgets(input,MAX,stdin)!=NULL){
        char output[MAX];
        if (urldecode(output,MAX,input,strlen(input))==-1)
            printf("error format\n");
        else
            printf("%s",output);
    }
}