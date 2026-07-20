#include <bits/stdc++.h>
using namespace std;

int main(){
    int t; cin >> t;
    while(t--){
        int n, S;
        cin >> n >> S;

        int a[205];
        for(int i = 1; i <= n; i++) cin >> a[i];

        bool dp[40005] = {false};
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