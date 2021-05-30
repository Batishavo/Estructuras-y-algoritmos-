#include<cstdio>
struct nodo{
    nodo * anterior;
    int valor;
    nodo(){
        anterior=NULL;
    }
    nodo(int valor){
        this->valor=valor;
    }
};
struct pila{
    nodo *actual;
    pila(){
        actual=NULL;
    }
    bool IsEmpty(){
        return actual==NULL;
    }
    int top(){
        return actual->valor;
    }
    void push(int valor){
        nodo* tmp=new nodo(valor);//Creamos el nuevo actual
        tmp->anterior=actual;// asignamos el actual al anterior del nuevo
        actual=tmp;//Asignamos el temporar como nuevo actual
       // delete tmp;//Borramos el temproal
    }
    void pop(){
        nodo* tmp=actual;//Guardamos el actual
        actual=actual->anterior;//Remplazamos el actual con el anteriro
        delete tmp;//Borra el viejo axtyual

    }
};
int main(){
    pila p;
    for(int i=0;i<10;i++){
        p.push(i);
    }
    while(!p.IsEmpty()){
        printf("top  %d\n",p.top());
        p.pop();
    }
    return 0;
}
