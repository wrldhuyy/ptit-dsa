#include<bits/stdc++.h>
using namespace std;

int n;
int a[100][100];
vector<string> res;

void backtrack(int i, int j, string path){
    if(i == n - 1 && j == n - 1){
        res.push_back(path);
        return;
    }

    if(i + 1 < n && a[i+1][j] == 1){
        backtrack(i+1, j, path + "D");
    }

    if(j + 1 < n && a[i][j+1] == 1){
        backtrack(i, j+1, path + "R");
    }
}

int main(){
    int t;
    cin >> t;
    while(t--){
        cin >> n;

        for(int i = 0; i < n; i++){
            for(int j = 0; j < n; j++){
                cin >> a[i][j];
            }
        }

        res.clear();

        if(a[0][0] == 1){
            backtrack(0, 0, "");
        }

        if(res.empty()){
            cout << -1;
        } else {
            sort(res.begin(), res.end());
            for(string s : res){
                cout << s << " ";
            }
        }

        cout << "\n";
    }
}