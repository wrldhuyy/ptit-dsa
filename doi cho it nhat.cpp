#include<bits/stdc++.h>
using namespace std;
int main(){
	int t;
	cin >> t;
	while(t--){
		int n;
		cin >> n;
		vector<pair<int,int>> a(n);
		for(int i = 0; i < n; i++){
			cin >> a[i].first;
			a[i].second = i;
		} 
		sort(a.begin(),a.end());
		vector<bool> visited(n,false);
		int ans = 0;
		for(int i = 0; i < n; i++){
			if(visited[i] || a[i].second == i) 
			continue;
			int cycle_size = 0;
			int j = i;
			while(!visited[j]){
				visited[j] = true;
				j = a[j].second;
				cycle_size++;
			} 
			ans += cycle_size-1;
			
		}
		cout << ans << "\n";
	}
	return 0;
}