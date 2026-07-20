#include <bits/stdc++.h>
using namespace std;

int n,k;
int a[20], b[20];
int cnt;
bool found;

void Try(int i, int start){
    for(int j=start;j<=n;j++){
        a[i]=j;

        if(i==k){
            cnt++;

            bool ok=true;
            for(int t=1;t<=k;t++){
                if(a[t]!=b[t]){
                    ok=false;
                    break;
                }
            }

            if(ok){
                cout<<cnt<<endl;
                found=true;
            }
        }
        else if(!found){
            Try(i+1, j+1);
        }
    }
}

int main(){
    int T;
    cin>>T;

    while(T--){
        cin>>n>>k;

        for(int i=1;i<=k;i++){
            cin>>b[i];
        }

        cnt=0;
        found=false;

        Try(1,1);
    }
}