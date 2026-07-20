#include<bits/stdc++.h>
using namespace std;

int n;
int a[25];
vector<int> cur;
vector<string> res;

void backtrack(int start){
    for(int i = start; i < n; i++){
        // di?u ki?n tang d?n
        if(cur.empty() || a[i] > cur.back()){
            cur.push_back(a[i]);

            if(cur.size() >= 2){
                string s = "";
                for(int j = 0; j < cur.size(); j++){
                    s += to_string(cur[j]);
                    if(j < cur.size() - 1) s += " ";
                }
                res.push_back(s);
            }

            backtrack(i + 1);

            cur.pop_back();
        }
    }
}

int main(){
    cin >> n;
    for(int i = 0; i < n; i++) cin >> a[i];

    backtrack(0);

    sort(res.begin(), res.end());

    for(auto s : res) cout << s << endl;
}