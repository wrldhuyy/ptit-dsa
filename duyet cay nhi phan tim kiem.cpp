#include <bits/stdc++.h>
using namespace std;

const int MAX = 1005;

int leftC[MAX], rightC[MAX], val[MAX];
int nNode;
int newNode(int x) {
    nNode++;
    val[nNode] = x;
    leftC[nNode] = rightC[nNode] = 0;
    return nNode;
}
int insertNode(int root, int x) {
    if (root == 0) return newNode(x);

    if (x < val[root])
        leftC[root] = insertNode(leftC[root], x);
    else
        rightC[root] = insertNode(rightC[root], x);

    return root;
}
void preorder(int root) {
    if (root == 0) return;

    cout << val[root] << " ";
    preorder(leftC[root]);
    preorder(rightC[root]);
}

int main() {
    int T; cin >> T;
    while (T--) {
        int n; cin >> n;

        nNode = 0;
        int root = 0;

        for (int i = 0; i < n; i++) {
            int x; cin >> x;
            root = insertNode(root, x);
        }

        preorder(root);
        cout << endl;
    }
}