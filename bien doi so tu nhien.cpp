#include <bits/stdc++.h>
using namespace std;

int main() {
    int t; cin >> t;
    while (t--) {
        int n; cin >> n;
        
        unordered_set<int> vis;
        queue<pair<int,int>> q;
        
        q.push({n,0});
        vis.insert(n);
        
        while (!q.empty()) {
            auto [x, step] = q.front(); q.pop();
            
            if (x == 1) {
                cout << step << endl;
                break;
            }
            
            if (!vis.count(x-1)) {
                vis.insert(x-1);
                q.push({x-1, step+1});
            }
            
            for (int i = 2; i * i <= x; i++) {
                if (x % i == 0) {
                    int y = max(i, x/i);
                    if (!vis.count(y)) {
                        vis.insert(y);
                        q.push({y, step+1});
                    }
                }
            }
        }
    }
}