#include<bits/stdc++.h>

using namespace std;

const int limit =(10e6)+10;

int p[limit];

vector<int>primes;

void criba(){
    p[0]=1;
	p[1]=1;
    for(int i=2; i<=limit-10; i++){
        if(p[i]==0){
            for(int j=i+i; j<=limit-10; j+=i){
                p[j]=1;
            }
            primes.push_back(i);
        }
    }
}

int main(){

    criba();

    for(auto& x : primes){

        cout<<x<<' ';


    }


    return 0;
}
