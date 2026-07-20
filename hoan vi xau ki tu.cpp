#include<bits/stdc++.h>
using namespace std;
string s;
bool used[100];
string cur;
void backtrack(int i){
	if(i == s.length()){
		cout << cur << " ";
		return;
	}
	for(int j = 0; j < s.length(); j++){
		if(!used[j]){
			used[j] = true;
			cur += s[j];
			backtrack(i + 1);
			used[j] = false;
			cur.pop_back();
		}
	}
}
int main(){
    int t;
    cin >> t;
    while(t--){
        cin >> s;

        memset(used, false, sizeof(used));
        cur = "";

        backtrack(0);

        cout << "\n";
    }
}