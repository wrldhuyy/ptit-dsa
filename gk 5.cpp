#include<bits/stdc++.h>
using namespace std;
int main(){
	int n;
    long long k;
	cin >> n >> k;
	vector<long long> a(n+1), prefix(n+1,0);
	for(int i = 0; i <= n; i++){
		cin >> a[i];
		a[i] -= k;
		prefix[i] = prefix[i-1] + a[i];
	}
	vector<int> st;
	for(int i = 0; i <= n; i++){
		if(st.empty() || prefix[i] < prefix[st.back()]){
			st.push_back(i);
		}
	}
	int res = 0;
	for(int j = n; j >= 0;j--){
		while(!st.empty() && prefix[j] >= prefix[st.back()]){
			res = max(res, j - st.back());
		}
	}
	cout << res << "\n";
	return 0;
}