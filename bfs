#include<stdio.h>
#include<iostream>
#include<queue>
using namespace std;
struct cordenada{
    int i;
    int j;
};
int mat[100][100];
int di[5]={1,0,-1,0};
int dj[5]={0,1,0,-1};
int main(){
    queue<cordenada> q;
    int n,m;
    scanf("%d%d",&n,&m);
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            scanf("%d",&mat[i][j]);
        }
    }
    int a,b;
    int x,y;
    scanf("%d%d",&a,&b);
    scanf("%d%d",&x,&y);
    cordenada nv;
    nv.i=a;
    nv.j= b;
    q.push(nv);
    while(!q.empty()){
        cordenada act=q.front();
        q.pop();
        int num=mat[act.i][act.j];
        for(int k=0;k<4;k++){
            int pi=act.i+di[k];
            int pj=act.j+dj[k];
            if(pi>=0 && pi<n && pj>=0 && pj<m){
                if(mat[pi][pj]==0){
                    mat[pi][pj]=num+1;
                    cordenada nueva;
                    nueva.i=pi;
                    nueva.j=pj;
                    q.push(nueva);
                }
            }
        }
    }
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            printf("%d",mat[i][j]);
        }
        printf("\n");
    }
    return 0;
}
