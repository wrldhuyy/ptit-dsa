#include<bits/stdc++.h>
using namespace std;
int main(){
	int t;
	cin >> t;
	while(t--){
		int n;
		cin >> n;
		vector<int> a(n);
		for(auto &x : a) cin >> x;
		int l = 0, r = n -1;
		int ans = n;
		while(l <= r){
			int mid = (l + r) / 2;
			if(a[mid] == 1){
				ans = mid;
				r = mid - 1;
			} else{
				l = mid + 1;
			}
		}
		cout << ans << endl;
	}
}