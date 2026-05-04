#include <stdio.h>
#include <string.h>

int heap[100000];
int size = 0;

void heapifyUp(int i){
    while(i>0){
        int p=(i-1)/2;
        if(heap[p]>heap[i]){
            int t=heap[p];
            heap[p]=heap[i];
            heap[i]=t;
            i=p;
        }else break;
    }
}

void heapifyDown(int i){
    while(1){
        int l=2*i+1,r=2*i+2,s=i;
        if(l<size && heap[l]<heap[s]) s=l;
        if(r<size && heap[r]<heap[s]) s=r;
        if(s!=i){
            int t=heap[i];
            heap[i]=heap[s];
            heap[s]=t;
            i=s;
        }else break;
    }
}

void insert(int x){
    heap[size]=x;
    heapifyUp(size);
    size++;
}

void extractMin(){
    if(size==0){
        printf("-1\n");
        return;
    }
    printf("%d\n",heap[0]);
    heap[0]=heap[size-1];
    size--;
    if(size>0) heapifyDown(0);
}

void peek(){
    if(size==0) printf("-1\n");
    else printf("%d\n",heap[0]);
}

int main(){
    int n,x;
    char op[20];
    scanf("%d",&n);
    for(int i=0;i<n;i++){
        scanf("%s",op);
        if(strcmp(op,"insert")==0){
            scanf("%d",&x);
            insert(x);
        }else if(strcmp(op,"extractMin")==0){
            extractMin();
        }else if(strcmp(op,"peek")==0){
            peek();
        }
    }
    return 0;
}
