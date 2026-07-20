#include <bits/stdc++.h>
using namespace std;

int n;
char a[20];

void Try(int i){
    for(char c : {'A','H'}){
        a[i] = c;

        if(i == n){
            if(a[1] == 'H' && a[n] == 'A'){
                bool ok = true;
                for(int j = 1; j < n; j++){
                    if(a[j] == 'H' && a[j+1] == 'H'){
                        ok = false;
                        break;
                    }
                }
                if(ok){
                    for(int j = 1; j <= n; j++)
                        cout << a[j];
                    cout << endl;
                }
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
        cin >> n;
        Try(1);
    }
}