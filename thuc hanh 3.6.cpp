#include <bits/stdc++.h>
using namespace std;

int N, M;
vector<vector<int>> adj, rev_adj;
vector<bool> visited;
vector<int> order;

void dfs1(int start) {
    stack<pair<int, int>> st;
    st.push({start, 0});

    while (!st.empty()) {
        auto &[u, idx] = st.top();

        if (!visited[u]) visited[u] = true;

        if (idx < adj[u].size()) {
            int v = adj[u][idx++];
            if (!visited[v]) {
                st.push({v, 0});
            }
        } else {
            order.push_back(u);
            st.pop();
        }
    }
}

void dfs2(int start) {
    stack<int> st;
    st.push(start);
    visited[start] = true;

    while (!st.empty()) {
        int u = st.top(); st.pop();
        for (int v : rev_adj[u]) {
            if (!visited[v]) {
                visited[v] = true;
                st.push(v);
            }
        }
    }
}

int main() {
    int T;
    cin >> T;

    while (T--) {
        cin >> N >> M;

        adj.assign(N + 1, {});
        rev_adj.assign(N + 1, {});
        visited.assign(N + 1, false);
        order.clear();

        for (int i = 0; i < M; i++) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
            rev_adj[v].push_back(u);
        }
        for (int i = 1; i <= N; i++) {
            if (!visited[i]) dfs1(i);
        }

        fill(visited.begin(), visited.end(), false);

        int scc = 0;

        reverse(order.begin(), order.end());

        for (int u : order) {
            if (!visited[u]) {
                dfs2(u);
                scc++;
            }
        }

        cout << scc << '\n';
    }

    return 0;
}