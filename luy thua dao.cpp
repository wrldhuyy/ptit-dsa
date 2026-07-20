#include<bits/stdc++.h>
using namespace std;
const long long MOD = 1e9+7;
long long reverseNum(long long n){
	long long r = 0;
	while(n > 0){
		r = r * 10 + n % 10;
		n/=10;
	}
	return r;
}
long long mu (long long n, long long k){
	long long kq = 1;
	n %= MOD;
	while(k > 0){
		if(k % 2 == 1){
			kq = (kq * n) % MOD;
			
		}
		n = (n*n)%MOD;
		k /= 2;	
	}
	return kq;
}
int main(){
	int t;
	cin >> t;
	while(t--){
		long long n;
		cin >> n;
		long long r = reverseNum(n);
		cout << mu(n,r) << "\n";
	}
}