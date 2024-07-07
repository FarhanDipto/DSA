#include<bits/stdc++.h>
using namespace std;

int w[100], x[100];
int m;

void sumOfSubset(int s, int k, int r){

    x[k]=1;
    if(s+w[k]==m){
        cout<<"Subset: ";
        for(int i=0; i<=k; i++){
            if(x[i] == 1) cout<<w[i]<<",";
        }
        cout<<endl;
    }
    else if(s+w[k]+w[k+1]<=m) 
        sumOfSubset(s+w[k], k+1, r-w[k]);

    if((s+r-w[k]>=m) && (s+w[k+1]<=m)){
        x[k]=0;
        sumOfSubset(s,k+1,r-w[k]);
    }
}

int main(){
    int n, i=0, r=0, value;
    cout<<"Define the set size: ";
    cin>>n;

    cout<<"Input the set: ";
    while(i<n){
        cin>>w[i];
        r=r+w[i];
        i++;
    }
    
    cout<<"Input the value of m: ";
    cin>>m;

    if(r<m||w[0]>m){
        cout<<"No subset found";
        exit(0);
    }
    else sumOfSubset(0,0,r);
    return 0;
}