#include <bits/stdc++.h>
using namespace std;

int N;
int a[11];
bool used[11];

void Try(int i){
    for(int j = N; j >= 1; j--){
        if(!used[j]){
            a[i] = j;
            used[j] = true;

            if(i == N){
                for(int k = 1; k <= N; k++)
                    cout << a[k];
                cout << " ";
            }
            else{
                Try(i + 1);
            }

            used[j] = false;
        }
    }
}

int main(){
    int T;
    cin >> T;
    while(T--){
        cin >> N;
        memset(used,false,sizeof(used));
        Try(1);
        cout << endl;
    }
}