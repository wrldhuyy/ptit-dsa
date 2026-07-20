#include<bits/stdc++.h>
using namespace std;
int n;
vector <char> a;
string s;
void backtrack(int i){
	if(i == n){
		cout << s << '\n';
		return;
	}
	for(int j = 0; j < 3; j++){
		if(j > 0 && a[j] == a[j-1]) continue;
		s.push_back(a[j]);
		backtrack(i+1);
		s.pop_back();
	}
}
int main(){
	cin >> n;
	a.resize(3);
	for(int i = 0; i < 3; i++) cin >> a[i];
	sort(a.begin(), a.end());
	backtrack(0);
	return 0;	
}