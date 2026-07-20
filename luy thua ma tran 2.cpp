#include <bits/stdc++.h>
using namespace std;

const long long MOD = 1e9+7;
int n;

void mul(long long A[][11], long long B[][11]){
    long long C[11][11]={0};
    for(int i=0;i<n;i++)
        for(int j=0;j<n;j++)
            for(int k=0;k<n;k++)
                C[i][j]=(C[i][j]+A[i][k]*B[k][j])%MOD;

    for(int i=0;i<n;i++)
        for(int j=0;j<n;j++)
            A[i][j]=C[i][j];
}

void poww(long long A[][11], long long k){
    if(k==1) return;

    long long T[11][11];
    for(int i=0;i<n;i++)
        for(int j=0;j<n;j++)
            T[i][j]=A[i][j];

    poww(A,k/2);
    mul(A,A);

    if(k%2) mul(A,T);
}

int main(){
    int t; cin>>t;
    while(t--){
        long long k;
        cin>>n>>k;

        long long A[11][11];
        for(int i=0;i<n;i++)
            for(int j=0;j<n;j++)
                cin>>A[i][j];

        poww(A,k);

        long long ans=0;
        for(int i=0;i<n;i++)
            ans=(ans+A[i][n-1])%MOD;

        cout<<ans<<"\n";
    }
}