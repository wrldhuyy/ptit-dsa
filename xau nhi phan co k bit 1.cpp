#include <bits/stdc++.h>
using namespace std;

int n, k;
int a[20];

void Try(int i){
    for(int j = 0; j <= 1; j++){
        a[i] = j;

        if(i == n){
            int cnt = 0;
            for(int t = 1; t <= n; t++)
                if(a[t] == 1) cnt++;

            if(cnt == k){
                for(int t = 1; t <= n; t++)
                    cout << a[t];
                cout << endl;
            }
        }
        else{
            Try(i+1);
        }
    }
}

int main(){
    int T;
    cin >> T;

    while(T--){
        cin >> n >> k;
        Try(1);
    }
}