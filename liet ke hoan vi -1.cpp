#include <iostream>
using namespace std;

int N;
int a[20];        
bool used[20];    
int cnt = 0;      

void backtrack(int i) {
    if (i > N) {
        cnt++;
        cout << cnt << ": ";
        for (int j = 1; j <= N; j++) {
            cout << a[j] << " ";
        }
        cout << "\n";
        return;
    }
    for (int v = 1; v <= N; v++) {
        if (!used[v]) {
            a[i] = v;
            used[v] = true;

            backtrack(i + 1);

            used[v] = false;
        }
    }
}
int main() {
    cin >> N;

    for (int i = 1; i <= N; i++)
        used[i] = false;

    backtrack(1);
    return 0;
}