#include <bits/stdc++.h>
using namespace std;

int main() {
    int T;
    cin >> T;
    cin.ignore();

    while (T--) {
        string s, word;
        getline(cin, s);

        stringstream ss(s);
        stack<string> st;

        while (ss >> word) {
            st.push(word);
        }

        while (!st.empty()) {
            cout << st.top();
            st.pop();
            if (!st.empty()) cout << " ";
        }
        cout << endl;
    }
}