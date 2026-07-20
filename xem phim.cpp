#include<bits/stdc++.h>
using namespace std;
int main(){
	int c,n;
	cin >> c >> n;
	vector<int> w(n);
	for(int i = 0; i < n; i++) cin >> w[i];
	vector<int> dp(c+1,0);
	for(int i = 0; i < n; i++){
		for(int j = c; j >= w[i]; j--){
			dp[j] = max(dp[j], dp[j-w[i]] + w[i]);
		}
	}
		
	cout << dp[c] << "\n";
}