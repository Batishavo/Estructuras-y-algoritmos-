#include<stdio.h>
const int lim=1e6;
int tmp[lim];
void merges(int arr[],int ini,int fin,int mid){
    for(int i=ini;i<=fin;i++){
        tmp[i]=arr[i];
    }
    int i=ini;
    int j=mid+1;
    int k=ini;
    while(i<=mid && j<=fin){
        if(tmp[i]<tmp[j]){
            arr[k++]=tmp[i++];
        }
        else{
            arr[k++]=tmp[j++];
        }
    }
    while(i<=mid){
        arr[k++]=tmp[i++];
    }
    while(j<=fin){
        arr[k++]=tmp[j++];
    }
}
void mergesort(int arr[],int ini,int fin){
    if(ini==fin){
        return;
    }
    int mid=(ini+fin)/2;
    mergesort(arr,ini,mid);
    mergesort(arr,mid+1,fin);
    merges(arr,ini,fin,mid);
}
int main(){
    int cad[400];
    int n;
    scanf("%d",&n);
    for(int i=0;i<n;i++){
        scanf("%d",&cad[i]);
    }
    mergesort(cad,0,n-1);
    for(int i=0;i<n;i++){
        printf("%d ",cad[i]);
    }
    return 0;
}
