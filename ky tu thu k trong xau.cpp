#include<bits/stdc++.h>
using namespace std;
char solve(int n, long long k){
	if(n == 1) return 'A';
	long long mid = 1LL << (n-1);
	if(k == mid) return 'A' + n - 1;
	if(k < mid) return solve(n-1,k);
	return solve(n - 1, (1LL << n) - k);
}
int main(){
	int t;
	cin >> t;
	while(t--){
		int n;
		long long k;
		cin >> n >> k;
		cout << solve(n,k) << endl;
	}
}