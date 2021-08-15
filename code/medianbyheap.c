#include<stdio.h>
#define SWAP(X,Y,T)((T)=(X),(X)=(Y),(Y)=(T))
int minHeap[2<<15];
int maxHeap[2<<15];
int min = -1 , max = -1;
int MAXHEAP = 1;
int MINHEAP = 0;
void heapify(int i, int flags){
    if(flags == MAXHEAP){
        int target = i;
        int left = 2*i+1;
        int right = 2*i+2;
        if(left <= max && maxHeap[target]<maxHeap[left])
            target = left;
        if(right <= max && maxHeap[target]<maxHeap[right])
            target = right;
        if(i != target){
            int temp;
            SWAP(maxHeap[i],maxHeap[target],temp);
            heapify(target,flags);
        }
    }else if(flags == MINHEAP){
        int target = i;
        int left = 2*i+1;
        int right = 2*i+2;
        if(left <= min && minHeap[target]>minHeap[left]){
            target = left;
        }
        if(right <= min && minHeap[target]>minHeap[right])
            target = right;
        if(target != i){
            int temp;
            SWAP(minHeap[i],minHeap[target],temp);
            heapify(target,flags);
        }
    }
}
int isBalanced(){
    if(min == max)
        return 1;
    else if(min > max)
        return min-max>1 ? 0:1;
    else
        return max-min>1 ? 0:1;
}
int nodeparent(int node){
    if(node == 0) 
        return -1;
    else
        return (node-1)/2;
}
void insertmin(int input){
    min++;
    int nodeindex = min;
    //如果比parent大 就把parent往下推 自己往上推
    //printf("%d",min);
    while(nodeindex>0&&input<minHeap[nodeparent(nodeindex)]){
        minHeap[nodeindex] = minHeap[nodeparent(nodeindex)];
        nodeindex = nodeparent(nodeindex);
    }
    //自己推到最後的位置
    minHeap[nodeindex] = input;
}
void insertmax(int input){
    max++;
    int nodeindex = max;
    //如果比parent大 就把parent往下推 自己往上推
    while(nodeindex>0&&input>maxHeap[nodeparent(nodeindex)]){
        maxHeap[nodeindex] = maxHeap[nodeparent(nodeindex)];
        nodeindex = nodeparent(nodeindex);
    }
    //自己推到最後的位置
    maxHeap[nodeindex] = input;
}
void balence(){
    if(min > max){
        int top = minHeap[0];
        minHeap[0] = minHeap[min];
        min --;
        heapify(0,MINHEAP);
        insertmax(top);
    } else{
        int top = maxHeap[0];
        maxHeap[0] = maxHeap[max];
        max--;
        heapify(0,MAXHEAP);
        insertmin(top);
    }
}
int main(){
    int input ,median = 0;
    while(scanf("%d",&input)!=EOF){
        if(input > median){
            insertmin(input);
            if(!isBalanced())
                balence();
        }else{
            insertmax(input);
            if(!isBalanced())
                balence();
        }
        if(min > max){
            median = minHeap[0];
            printf("%d\n",median);
        }else if(min < max){
            median = maxHeap[0];
            printf("%d\n",median);
        }else{
            median = (maxHeap[0]+minHeap[0])/2;
            printf("%d\n",median);
        }/*
        printf("MAX");
         for(int i = 0 ; i <= max ; i++)
            printf("%d",maxHeap[i]);
        printf("\nMIN");
        for(int i = 0 ; i <= min ; i++)
            printf("%d",minHeap[i]);
        printf("\n");*/
    }
}