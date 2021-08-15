#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#define MAX 64000
typedef struct node* node_p;
typedef struct node{
    char data[MAX];
    node_p left;
    node_p right;
}node;
void postorder(node_p tree){
    if(tree !=NULL){
        postorder(tree->left);
        postorder(tree->right);
        printf("%s",tree->data);
    }
}
void preorder(node_p tree){
    if(tree != NULL){
        printf("%s",tree->data);
        preorder(tree->left);
        preorder(tree->right);
    }
}
void inorder(node_p tree){
    if(tree != NULL){
        inorder(tree->left);
        printf("%s\n",tree->data);
        inorder(tree->right);
    }
}
node_p insert(char *input,node_p tree){

    if(tree == NULL){
        tree = (node_p)malloc(sizeof(node));
        tree->left = tree->right=NULL;
        strcpy(tree->data,input);
    }else if(strcmp(input,tree->data)<0){
        tree->left = insert(input,tree->left);
    }else if(strcmp(input,tree->data)>0){
        tree->right = insert(input,tree->right);
    }
    return tree;
}
int main(int argc, char **argv){
    char input[MAX];
    node_p tree = NULL;
    while(fgets(input,MAX,stdin)!=NULL){
        if(input[strlen(input)-1]=='\n')
            input[strlen(input)-1] = '\0';
        tree = insert(input,tree);
    }
    inorder(tree);
}