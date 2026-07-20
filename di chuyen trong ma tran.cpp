#include <bits/stdc++.h>
using namespace std;

int main() {
    int t; cin >> t;
    while (t--) {
        int m, n; cin >> m >> n;
        vector<vector<int>> a(m, vector<int>(n));
        
        for (int i = 0; i < m; i++)
            for (int j = 0; j < n; j++)
                cin >> a[i][j];
        
        vector<vector<bool>> vis(m, vector<bool>(n, false));
        queue<tuple<int,int,int>> q;
        
        q.push({0,0,0});
        vis[0][0] = true;
        
        int ans = -1;
        
        while (!q.empty()) {
            auto [i, j, step] = q.front(); q.pop();
            
            if (i == m-1 && j == n-1) {
                ans = step;
                break;
            }
            
            int k = a[i][j];
            
            if (j + k < n && !vis[i][j+k]) {
                vis[i][j+k] = true;
                q.push({i, j+k, step+1});
            }
            
            if (i + k < m && !vis[i+k][j]) {
                vis[i+k][j] = true;
                q.push({i+k, j, step+1});
            }
        }
        
        cout << ans << endl;
    }
}