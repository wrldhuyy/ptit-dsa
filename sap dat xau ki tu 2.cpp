#include<bits/stdc++.h>
using namespace std;
int main(){
	int t;
	cin >> t;
	while(t--){
		int D;
		cin >> D;
		string s;
		cin >> s;
		vector<int> count(26,0);
		for(char c : s){
			count[c-'A']++;
		}
		int max_freq =* max_element(count.begin(), count.end());
		int n = s.length();
		if ((max_freq - 1) * D + 1 <= n)
            cout << 1 << endl;
        else
            cout << -1 << endl;
		
	}
}