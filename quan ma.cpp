#include <bits/stdc++.h>
using namespace std;

int dx[] = {-2,-2,-1,-1,1,1,2,2};
int dy[] = {-1,1,-2,2,-2,2,-1,1};

int main() {
    int t; cin >> t;
    while (t--) {
        string s, e;
        cin >> s >> e;
        
        int sx = s[0] - 'a', sy = s[1] - '1';
        int ex = e[0] - 'a', ey = e[1] - '1';
        
        vector<vector<bool>> vis(8, vector<bool>(8,false));
        queue<tuple<int,int,int>> q;
        
        q.push({sx, sy, 0});
        vis[sx][sy] = true;
        
        while (!q.empty()) {
            auto [x, y, step] = q.front(); q.pop();
            
            if (x == ex && y == ey) {
                cout << step << endl;
                break;
            }
            
            for (int i = 0; i < 8; i++) {
                int nx = x + dx[i];
                int ny = y + dy[i];
                
                if (nx >= 0 && ny >= 0 && nx < 8 && ny < 8 && !vis[nx][ny]) {
                    vis[nx][ny] = true;
                    q.push({nx, ny, step+1});
                }
            }
        }
    }
}