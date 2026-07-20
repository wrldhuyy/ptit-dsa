#include<bits/stdc++.h>
using namespace std;

int main(){
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;

        vector<long long> a(n), b(n-1);
        for(auto &x : a) cin >> x;
        for(auto &x : b) cin >> x;

        int l = 0, r = n-2;
        int ans = n-1;

        while(l <= r){
            int mid = (l + r) / 2;

            if(a[mid] == b[mid]){
                l = mid + 1;
            } else {
                ans = mid;
                r = mid - 1;
            }
        }

        cout << ans + 1 << endl;
    }
}