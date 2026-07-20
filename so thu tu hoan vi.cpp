#include <bits/stdc++.h>
using namespace std;

int n;
int a[20], b[20];
bool used[20];
int cnt;
bool found;

void Try(int i){
    for(int j=1;j<=n;j++){
        if(!used[j]){
            a[i]=j;
            used[j]=true;

            if(i==n){
                cnt++;

                bool ok=true;
                for(int k=1;k<=n;k++){
                    if(a[k]!=b[k]){
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
                Try(i+1);
            }

            used[j]=false;
        }
    }
}

int main(){
    int T;
    cin>>T;

    while(T--){
        cin>>n;

        for(int i=1;i<=n;i++){
            cin>>b[i];
            used[i]=false;
        }

        cnt=0;
        found=false;

        Try(1);
    }
}