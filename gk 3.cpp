#include<bits/stdc++.h>
using namespace std;
const int MAX = 100000;
int TSNTLN[MAX + 1];
int main(){
	for(int i = 2; i <= MAX ; i++){
		if(TSNTLN[i] == 0){
			for(int j = i; j <= MAX; j+=i){
				TSNTLN[j] = i;
			}
		}
	}
	int t;
	cin >> t;
	while(t--){
		int L,R;
		cin >> L >> R;
		long long sum  = 0;
		for(int i = L; i <= R; i++){
			sum += TSNTLN[i];
		}
		cout << sum << endl;
	}
	
}