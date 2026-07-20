#include<bits/stdc++.h>
using namespace std;
int main(){
	int t;
	cin >> t;
	while(t--){
		int n;
		cin >> n;
		vector<int> s(n), f(n);
		for(int i = 0; i < n; i++) cin >> s[i];
		for(int i = 0; i < n; i++) cin >> f[i];
		vector<pair<int,int>> a;
		for(int i = 0; i < n; i++){
			a.push_back({f[i],s[i]});
			
		}
		sort(a.begin(),a.end());
		int count = 1;
        int last_end = a[0].first;
        for(int i = 1; i < n; i++){
        	if(a[i].second >= last_end){
        		count++;
        		last_end = a[i].first;
			}
		}
		cout << count << endl;
	}
	
}