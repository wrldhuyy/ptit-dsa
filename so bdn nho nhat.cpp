#include <bits/stdc++.h>
using namespace std;

int main() {
    int t;
    cin >> t;
    
    while (t--) {
        int n;
        cin >> n;
        
        queue<pair<string, int>> q;
        q.push({"1", 1 % n});
        
        while (!q.empty()) {
            auto top = q.front(); q.pop();
            string s = top.first;
            int mod = top.second;
            
            if (mod == 0) {
                cout << s << endl;
                break;
            }
            q.push({s + "0", (mod * 10) % n});
            q.push({s + "1", (mod * 10 + 1) % n});
        }
    }
    
    return 0;
}