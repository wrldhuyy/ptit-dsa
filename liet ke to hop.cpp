#include<bits/stdc++.h>
using namespace std;

int n,k;
int A[100], B[100], a[100];

void in(){
    for(int i=1;i<=k;i++)
        cout<<B[a[i]]<<" ";
    cout<<endl;
}

void Try(int i,int start){
    for(int j=start;j<=n;j++){
        a[i]=j;
        if(i==k) in();
        else Try(i+1,j+1);
    }
}

int main(){
    cin>>n>>k;

    for(int i=1;i<=n;i++)
        cin>>A[i];

    sort(A+1,A+n+1);

    int m=0;
    for(int i=1;i<=n;i++){
        if(i==1 || A[i]!=A[i-1])
            B[++m]=A[i];
    }

    n=m;

    Try(1,1);
}