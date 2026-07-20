#include<bits/stdc++.h>
using namespace std;
int main(){
	int n;
	cin >> n;
	vector<int> a(n);
	vector<int> b(n+1,0);
	for(int i = 0; i < n;i++){
		cin >> a[i];
		b[a[i]]++;
	}
	int ak =  INT_MAX;
	for(int i = 0; i < n; i++){
		if(b[a[i]] == 1){
			ak = min(ak,a[i]);
		}
	}
	if(ak == INT_MAX){
		cout << -1 << endl;
		return 0;
	}
	for(int i = 0; i < n; i++){
		if(a[i] == ak){
			cout << i+1 << endl;
			return 0;
		}
	}
}