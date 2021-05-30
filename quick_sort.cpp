
#include<stdio.h>
int part(int arr[],int piv,int l,int r){
    while(l<=r){
        while(arr[l]<piv){
            l++;
        }
        while(arr[r]>piv){
            r--;
        }
        if(l<=r){
            int temp=arr[l];
            arr[l]=arr[r];
            arr[r]=temp;
            l++;
            r--;
        }
    }
    return l;
}
void quicksort(int arr[],int l,int r){
    if(l>=r){
        return;
    }
    int pivote=arr[(l+r)/2];
    int pos=part(arr,pivote,l,r);
    quicksort(arr,l,pos-1);
    quicksort(arr,pos,r);
}
int main(){
    int cad[300];
    int n;
    scanf("%d",&n);
    for(int i=0;i<n;i++){
        scanf("%d",&cad[i]);
    }
    quicksort(cad,0,n-1);
    for(int i=0;i<n;i++){
        printf("%d ",cad[i]);
    }
    return 0;
}
