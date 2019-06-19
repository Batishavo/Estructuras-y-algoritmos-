#include<stdio.h>
using namespace std;

struct nodo{
    nodo * next;
    int val;
    nodo(){
        next=NULL;
        val=0;
    }
    nodo(int x){
        next=NULL;
        val=x;
    }
};
struct cola{
    nodo* head;
    nodo* tail;
    cola(){
        head=NULL;
        tail=NULL;
    }
    ///Empty
    bool empty1(){
        return head==NULL;
    }
    ///front
    int front1(){
        return head->val;
    }
    ///push
    void push1(int val){
        nodo* nd=new nodo(val);
        if(tail!=NULL){
            tail->next=nd;
        }
        tail=nd;
        if(head==NULL){
            head=nd;
        }

    }
    ///pop
    void pop(){
        nodo* tmp=head;
        head=head->next;
        if(head==NULL){
            tail=NULL;

        }
        delete tmp;
    }

};
int main(){
    cola q;
    for(int i=0;i<10;i++){
        q.push1(i);
    }
    while(!q.empty1()){
        printf("cabeazal %d\n",q.front1());
        q.pop();

    }
    printf("%d\n",q.empty1());
    return 0;
}
