#include<bits/stdc++.h>
using namespace std;

int main(){
    int t;
    cin >> t;
    while(t--){
        int m, n, k;
        cin >> m >> n >> k;

        vector<int> a(m), b(n);
        for(int &x : a) cin >> x;
        for(int &x : b) cin >> x;

        int i = 0, j = 0, cnt = 0;
        int ans;

        while(i < m && j < n){
            if(a[i] < b[j]){
                ans = a[i++];
            } else {
                ans = b[j++];
            }
            cnt++;
            if(cnt == k) break;
        }
        while(cnt < k && i < m){
            ans = a[i++];
            cnt++;
        }

        while(cnt < k && j < n){
            ans = b[j++];
            cnt++;
        }

        cout << ans << endl;
    }
}