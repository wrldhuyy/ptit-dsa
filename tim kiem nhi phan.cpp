#include<bits/stdc++.h>
using namespace std;
int main(){
	int t;
	cin >> t;
	while(t--){
		int n,k;
		cin >> n >> k;
		vector<int> a(n);
		for(auto &x : a) cin >> x;
		int l = 0, r = n - 1;
		int vitri = -1;
		while(l <= r){
			int mid = ( l + r) / 2;
			if(a[mid] == k){
				vitri = mid;
				break;
			}
			else if(a[mid] < k){
				l = mid + 1;
			}
			else{
				r = mid - 1;
			}
				
			
		}
		if(vitri == -1) cout << "NO" << "\n";
		else cout << vitri + 1 << endl;
	}
}