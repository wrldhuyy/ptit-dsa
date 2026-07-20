#include<bits/stdc++.h>
using namespace std;

int main(){
    int t;
    cin >> t;
    while(t--){
        int n;
        long long x;
        cin >> n >> x;

        vector<long long> a(n);
        for(auto &i : a) cin >> i;

        int l = 0, r = n - 1;
        int ans = -1;

        while(l <= r){
            int mid = (l + r) / 2;

            if(a[mid] <= x){
                ans = mid;     
                l = mid + 1;   
            }
            else{
                r = mid - 1;
            }
        }

        if(ans == -1) cout << -1 << endl;
        else cout << ans + 1 << endl; 
    }
}