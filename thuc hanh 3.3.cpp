#include <bits/stdc++.h>
using namespace std;

int N, M;
vector<vector<int>> adj;
vector<bool> visited;

int dfs(int u) {
    stack<int> st;
    st.push(u);
    visited[u] = true;
    int cnt = 0;

    while (!st.empty()) {
        int x = st.top(); st.pop();
        cnt++;

        for (int v : adj[x]) {
            if (!visited[v]) {
                visited[v] = true;
                st.push(v);
            }
        }
    }

    return cnt;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> N >> M;
    adj.assign(N + 1, {});
    visited.assign(N + 1, false);

    for (int i = 0; i < M; i++) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    vector<int> compSizes;

    for (int i = 1; i <= N; i++) {
        if (!visited[i]) {
            compSizes.push_back(dfs(i));
        }
    }
    visited.assign(N + 1, false);
    int size1 = dfs(1);

    int max_other = 0;
    for (int s : compSizes) {
        if (s != size1) {
            max_other = max(max_other, s);
        }
    }

    if (max_other == 0) {
        cout << N;
    } else {
        cout << size1 + max_other;
    }

    return 0;
}