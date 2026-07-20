#include <bits/stdc++.h>
using namespace std;

int main() {
    int t;
    cin >> t;
    
    while (t--) {
        int S, T;
        cin >> S >> T;
        
        queue<pair<int, int>> q; 
        vector<bool> visited(10001, false);
        
        q.push({S, 0});
        visited[S] = true;
        
        while (!q.empty()) {
            auto [x, step] = q.front(); q.pop();
            
            if (x == T) {
                cout << step << endl;
                break;
            }
            if (x - 1 >= 0 && !visited[x - 1]) {
                visited[x - 1] = true;
                q.push({x - 1, step + 1});
            }
            if (x * 2 <= 10000 && !visited[x * 2]) {
                visited[x * 2] = true;
                q.push({x * 2, step + 1});
            }
        }
    }
    
    return 0;
}