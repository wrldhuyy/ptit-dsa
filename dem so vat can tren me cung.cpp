#include <iostream>
#include <vector>
#include <string>
using namespace std;

int main() {

    int N, M;
    cin >> N >> M;
    vector<string> a(N);
    for (int i = 0; i < N; i++) cin >> a[i];

    int ans = 0;
    vector<int> st; 
    st.reserve((size_t)N * M);

    int dr[4] = {-1, 1, 0, 0};
    int dc[4] = {0, 0, -1, 1};

    for (int r = 0; r < N; r++) {
        for (int c = 0; c < M; c++) {
            if (a[r][c] == '#') {
                ans++;                
                a[r][c] = '.';        
                st.push_back(r * M + c);
                while (!st.empty()) {
                    int cur = st.back();
                    st.pop_back();
                    int x = cur / M;
                    int y = cur % M;

                    for (int k = 0; k < 4; k++) {
                        int nx = x + dr[k], ny = y + dc[k];
                        if (0 <= nx && nx < N && 0 <= ny && ny < M && a[nx][ny] == '#') {
                            a[nx][ny] = '.';    
                            st.push_back(nx * M + ny);
                        }
                    }
                }
            }
        }
    }

    cout << ans;
    return 0;
}
