#include<bits/stdc++.h>
using namespace std;

int n;
bool used[20];
int a[20];

void backtrack(int pos){
    if(pos == n){
        for(int i = 0; i < n; i++) cout << a[i];
        cout << endl;
        return;
    }

    for(int i = 1; i <= n; i++){
        if(!used[i]){
            if(pos > 0 && abs(i - a[pos - 1]) == 1) continue;

            a[pos] = i;
            used[i] = true;

            backtrack(pos + 1);

            used[i] = false; 
        }
    }
}

int main(){
    int t;
    cin >> t;
    while(t--){
        cin >> n;
        memset(used, false, sizeof(used));
        backtrack(0);
    }
}