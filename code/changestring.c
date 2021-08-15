#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <ctype.h>
#include <stdlib.h>
#define SubStringMode false
#define FullStringMode true
#define Data 10000
void FullString(char [], char []) ;
void SubString(char [], char []) ;
char * get_word(char * ,char * );
int main(int argc, char * argv[]) {
    bool compare_mode =  SubStringMode ;
    char old_pattern[Data], new_pattern[Data] ;
    if(argc == 4)
    {
        if (strcmp(argv[1], "-e") == 0)
            compare_mode = FullStringMode;
        else if(strcmp(argv[1], "-s") == 0)
            compare_mode = SubStringMode;
        else
        {
            printf("選項錯誤\n");
            exit(0);
        }
        strcpy(old_pattern,argv[2]) ;
        strcpy(new_pattern,argv[3]) ;
    }
    else if(argc == 3)
    {
        compare_mode = SubStringMode ;
        strcpy(old_pattern,argv[1]) ;
        strcpy(new_pattern,argv[2]) ;
    }
    else
    {
        printf("選項錯誤\n");
        exit(0);
    }
    if(compare_mode == FullStringMode)
        FullString(new_pattern,old_pattern) ;
    else
        SubString(new_pattern,old_pattern) ;

    return 0;
}
void SubString(char new_pattern[],char old_pattern[])
{
    char input[Data] ;
    while(fgets(input,Data,stdin) != NULL)
    {
        if(input[strlen(input)-1]=='\0')
        {
            input[strlen(input)-1]='\n';
            input[strlen(input)]='\0';
        }
        char *ptr = input ;
        char *front = strstr(ptr,old_pattern);
        char *newPattern = new_pattern;
        char ans[Data] ;
        int i = 0 ;
        while(front)
        {
            while(ptr != front)
            {
                ans[i++] = *ptr++ ;
            }
            while(*newPattern != '\0')
            {
                ans[i++] = *newPattern++;
            }
            ptr = ptr + strlen(old_pattern);
            front = strstr(ptr,old_pattern);
            newPattern = new_pattern;
        }
        while(*ptr!='\0')
            ans[i++] = *ptr++;
        ans[i] = '\0';
        printf("%s",ans);
    }

}
char * get_word(char * out,char * src)
{
    char *ptr = src ;
    char *qtr = out ;
    while(*ptr && isspace(*ptr))
        ptr++ ;
    while(*ptr && !isspace(*ptr) && *ptr != '\n')
        *qtr++ = *ptr++ ;
    *qtr = '\0';
    if(qtr - out == 0)
        return NULL ;
    return ptr ;
}
void FullString(char new_pattern[],char old_pattern[])
{
    char input[Data] ;
    while(fgets(input,Data,stdin) != NULL)
    {
        if(input[strlen(input)-1]=='\0')
        {
            input[strlen(input)-1]='\n';
            input[strlen(input)]='\0';
        }
        char *ptr = input ;
        while(*ptr!='\0')
        {
            if(isspace(*ptr))
                printf("%c",*ptr++);
            else 
            {
                char word[Data];
                ptr = get_word(word,ptr);
                if(strcmp(word,old_pattern)==0)
                {
                    printf("%s",new_pattern);
                }
                else
                {
                    printf("%s",word);
                }
            }
        }
    }
}
