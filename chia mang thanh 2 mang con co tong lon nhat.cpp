#include<bits/stdc++.h>
using namespace std;
int main(){
	int t;
	cin >> t;
	while(t--){
		int n,k;
		cin >> n >> k;
		vector<int> a(n);
		int sum = 0;
		for(int i = 0; i < n; i++){
			cin >> a[i];
			sum += a[i];
			
		}
		sort(a.begin(), a.end());
		k = min(k,n-k);
		int x = 0; 
		for(int i = 0; i < k; i++){
			x+=a[i];
		}
		cout << abs(sum-2*x) << endl;
	}
}