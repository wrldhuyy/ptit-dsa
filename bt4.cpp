#include<bits/stdc++.h>
using namespace std;
map<string, vector<string>> mp;
map<string, int> da_tham;
bool ok = 0;
void dfs(string u){
	da_tham[u] = 1;
	for(string v : mp[u]){
		if(da_tham[v] == 0){
			dfs(v);
			if(ok) return;
		}
		else if(da_tham[v] == 1){
			ok = 1;
			return;
		}
	}
	da_tham[u] = 2;
}
int main(){
	int n;
	cin >> n;
	vector<string> s;
	for(int i = 0; i < n; i++){
		string u,o,v;
		cin >> u >> o >> v;
		if(o == ">"){
			mp[u].push_back(v);
			s.push_back(u);
			s.push_back(v);
		}else{
			mp[v].push_back(u);
			s.push_back(u);
			s.push_back(v);
		}
	}
	for(string k : s){
		if(da_tham[k] == 0){
			dfs(k);
			if(ok) break;
		} 
	}
	if(ok) cout << "impossible" << endl;
	else cout << "possible" << endl;
}