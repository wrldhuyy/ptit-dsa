#include<bits/stdc++.h>
using namespace std;
const long long MOD = 1e9 + 7;
long long mu (long long n, long long k){
	long long kq = 1;
	n %= MOD;
	while(k > 0){
		if(k % 2 == 1){
			kq = (kq * n) % MOD;
			
		}
		n = n*n%MOD;
		k /= 2;	
	}
	return kq;
}
int main() {
	int t;
	cin >> t; 
	while(t--){
		long long n, k;
    	cin >> n >> k;
    	cout << mu(n, k) << endl;
	}
}