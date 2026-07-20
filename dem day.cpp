#include<bits/stdc++.h>
using namespace std;
const long long MOD = 123456789;
long long mu(long long a, long long b){
	long long kq = 1;
	a %= MOD;
	while(b > 0){
		if(b % 2 == 1){
			kq = (kq * a) % MOD;
			
		}
		a = a * a % MOD;
		b /= 2;
	}
	return kq;
}
int main(){
    int t;
    cin >> t;
    while(t--){
        long long n;
        cin >> n;

        cout << mu(2, n-1) << endl;
    }
}