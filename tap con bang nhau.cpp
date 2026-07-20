#include <bits/stdc++.h>
using namespace std;

int main(){
    int t; cin >> t;
    while(t--){
        int n; cin >> n;
        int a[105];

        int sum = 0;
        for(int i = 1; i <= n; i++){
            cin >> a[i];
            sum += a[i];
        }
        if(sum % 2 != 0){
            cout << "NO\n";
            continue;
        }

        int S = sum / 2;

        bool dp[10005] = {false};
        dp[0] = true;

        for(int i = 1; i <= n; i++){
            for(int j = S; j >= a[i]; j--){
                if(dp[j - a[i]])
                    dp[j] = true;
            }
        }

        if(dp[S]) cout << "YES\n";
        else cout << "NO\n";
    }
}