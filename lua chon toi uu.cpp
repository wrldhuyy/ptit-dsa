#include<bits/stdc++.h>
using namespace std;
bool cmp(pair<int,int> x, pair<int,int> y) {
    return x.second < y.second;
}
int main(){
	int t;
	cin >> t;
	while(t--){
		int n;
		cin >> n;
		vector<pair<int,int>> a(n);
		for(int i = 0;i < n; i++){
			cin >> a[i].first >> a[i].second;
			
		}
		sort(a.begin(),a.end(), cmp);
		int count = 0;
		int last_end = -1;
		for(int i = 0; i < n; i++){
			if(a[i].first >= last_end){
				count++;
				last_end = a[i].second;
			}
		}
		cout << count << endl;
	}
	return 0;
}