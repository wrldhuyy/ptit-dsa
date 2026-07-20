#include <bits/stdc++.h>
using namespace std;

int n, k;
string s;

void solve(int pos) {
    if (pos == n) {
        if (s.find(string(k + 1, '1')) != string::npos) {
            cout << s << "\n";
        }
        return;
    }

    s.push_back('0');
    solve(pos + 1);
    s.pop_back();

    s.push_back('1');
    solve(pos + 1);
    s.pop_back();
}

int main() {
    cin >> n >> k;
    solve(0);
    return 0;
}