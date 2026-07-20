#include <bits/stdc++.h>
using namespace std;

int main() {
    int T;
    cin >> T;

    while (T--) {
        string s;
        cin >> s;

        stack<char> st;

        for (char c : s) {
            if (c == '(') {
                st.push(c);
            } else {
                if (!st.empty() && st.top() == '(') {
                    st.pop(); // triệt tiêu cặp đúng
                } else {
                    st.push(c);
                }
            }
        }

        int open = 0, close = 0;

        while (!st.empty()) {
            if (st.top() == '(') open++;
            else close++;
            st.pop();
        }

        int ans = (open + 1) / 2 + (close + 1) / 2;
        cout << ans << endl;
    }

    return 0;
}