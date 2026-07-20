#include<bits/stdc++.h>
using namespace std;

int main(){
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        int a[100];
        for(int i = 0; i < n; i++) cin >> a[i];
        int res[100][100];
        int row = 0;
        for(int len = n; len >= 1; len--){
            for(int i = 0; i < len; i++){
                res[row][i] = a[i];
            }
            row++;
            for(int i = 0; i < len - 1; i++){
                a[i] = a[i] + a[i+1];
            }
        }
        for(int i = 0; i < row; i++){
            cout << "[";
            for(int j = 0; j < n - i; j++){
                cout << res[i][j];
                if (j != n - i - 1) cout << " ";
            }
            cout << "]\n";
        }
    }
}