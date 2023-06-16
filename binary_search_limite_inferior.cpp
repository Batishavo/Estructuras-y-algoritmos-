#include<bits/stdc++.h>

using namespace std;

int arr[100];

int my_binary_search(int n , int num){

    int ini = 0,
        fin = n-1;

    while(ini<fin){

        int mid = ((ini+fin) /2)+1;

        if(arr[mid]==num){

            return mid+1;
        }
        else if(arr[mid]>num){

            fin = mid-1;

        }
        else{
            ini = mid;
        }
    }

    return -1;

}

/*ejemplo
    15
    1 3 4 5 10 100 101 200 204 300 1000 1050 2500 9999 10000
    1050
 */
int main(){

    int n,
        num;

    scanf("%d",&n);

    for(int i=0;i<n;i++){

        scanf("%d",&arr[i]);

    }

    scanf("%d",&num);

    printf("%d\n",my_binary_search(n,num));

    return 0;

}
