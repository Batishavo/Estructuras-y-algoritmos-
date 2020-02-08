#include<bits/stdc++.h>
using namespace std;
struct Node{
    int valor;
    Node* sig;
    Node(int valor){
        this->valor=valor;
        this->sig=NULL;
    }
};
struct Lista{
    Node* head;
    void push(int x){
        Node* nuevo=new Node(x);
        nuevo->sig=head;
        head=nuevo;
    }
    void pop(){
        if(!isEmpty()){
            head=head->sig;
        }

    }
    int getHead(){
        if(!isEmpty())
            return head->valor;
        else{
            return -1;
        }

    }
    bool isEmpty(){
        return (head==NULL);
    }
    void print(){
        Node* tmp=head;
        while(tmp!=NULL){
            printf("%d\n",tmp->valor);
            tmp=tmp->sig;
        }
    }
    bool exist(int n){
        Node* tmp=head;
        while(tmp!=NULL){
            if(tmp->valor==n)return true;
            tmp=tmp->sig;
        }
        return false;
    }
    void borrar(int n){
        Node* tmp;
        int cont=0;
        while(!isEmpty()){
            Node* nuevo=new Node(getHead());
            if(head->valor==n){
                pop();
                break;
            }
            pop();
            nuevo->sig=tmp;
            tmp=nuevo;
            cont++;
        }
        while(cont--){
            Node* nuevo=new Node(tmp->valor);
            nuevo->sig=head;
            head=nuevo;
            tmp=tmp->sig;
        }
    }
    void borra2(int m){
        Node* nuevo=head;
        Node* ant=head;
        if(!isEmpty()){
            while(nuevo!=NULL){
                if(nuevo->valor==valor){
                    if(nuevo==ant){
                        head=nuevo->sig;
                    }
                    else{
                        ant->sig=nuevo->sig;
                    }
                    delete nuevo;
                }
                ant=nuevo;
                nuevo=nuevo->sig;
                
            }
        }
    }
     void agregar(int i,int n){
        Node* tmp;
        int cont=0;
        int cant=0;
        Node* aux=head;
        int m=
        while(aux!=NULL){
            cant++;
            aux=tmp->sig;
        }
        while(true){
            Node* nuevo=new Node(getHead());
            if(cont==m){
                nuevo->valor=n;
                nuevo->sig=tmp;
                tmp=nuevo;
                break;
            }
            pop();
            nuevo->sig=tmp;
            tmp=nuevo;
            cont++;
        }
        while(cont--){
            Node* nuevo=new Node(tmp->valor);
            nuevo->sig=head;
            head=nuevo;
            tmp=tmp->sig;
        }
    }
};
int main(){
    Lista* lista=new Lista();
    for(int i=0;i<5;i++){
        lista->push(i);
    }
    lista->print();
    printf("_____\n");
    lista->borrar(0);
    //printf("_____");
    lista->print();

   // cout<<lista->exist(6);
    //    lista->print();

    /*for(int i=0;i<5;i++){
        printf("%d\n",lista->getHead());
        lista->pop();
    }*/
    return 0;
}
