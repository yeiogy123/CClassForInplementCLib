#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#define MAX 100000
typedef struct hash{
    char *word;
    int count;
}hash;
hash hashTable[100000];
long long int flag[100000];
long long int hash70(char *word){
    long long int finalindex=0;
    char *ptr = word;
    while(*ptr != '\0'){
        finalindex = finalindex*70+abs(*ptr);//轉成unsigned
        ptr++;
    }
    finalindex = abs(finalindex)%100000;
    return finalindex;
}
int compare(const void *a, const void *b){
    hash h1 = (*(hash*)a);
    hash h2 = (*(hash*)b);
    if(h2.count != h1.count)
        return h2.count - h1.count;
    else if(!h2.count && !h1.count)
        return 0;
    else
        return strcmp(h1.word,h2.word);
}
int main(){
    char word[MAX];
    while(fgets(word,MAX,stdin)!=NULL){
        word[strcspn(word,"\n")] = '\0';
        char *ptr = strtok(word," ");
        while(ptr){
            int len = strlen(ptr);
            long long int index = hash70(ptr);
            if(!hashTable[index].count){
                //printf("%lld\n",index);
                hashTable[index].word = malloc(sizeof(char)*len+1);
                strcpy(hashTable[index].word,ptr);
                hashTable[index].count=1;
                flag[index] = 1;
            }else{
                if(strcmp(ptr,hashTable[index].word)==0){
                    if(flag[index]==1){
                        ptr = strtok(NULL," ");
                        continue;
                    }
                    hashTable[index].count++;
                    flag[index]=1;
                }
            }
            ptr = strtok(NULL," ");
        }
        for(int i = 0 ; i < 100000; i++){
            flag[i] = 0;
        }
    }
    qsort(hashTable,100000,sizeof(hashTable[0]),compare);
    for(int i = 0 ; i < 10 ; i++)
            printf("%s\n",hashTable[i].word);
}