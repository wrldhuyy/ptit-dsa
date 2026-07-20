#include <bits/stdc++.h>
using namespace std;

int main(){
    int t; cin >> t;
    while(t--){
        int n; cin >> n;
        int a[1005], dp[1005];

        for(int i = 1; i <= n; i++){
            cin >> a[i];
            dp[i] = 1;
        }

        int lis = 1;

        for(int i = 1; i <= n; i++){
            for(int j = 1; j < i; j++){
                if(a[j] <= a[i]){ 
                    dp[i] = max(dp[i], dp[j] + 1);
                }
            }
            lis = max(lis, dp[i]);
        }

        cout << n - lis << "\n";
    }
}