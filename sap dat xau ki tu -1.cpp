#include<bits/stdc++.h>
using namespace std;
int main(){
	int t;
	cin >> t;
	while(t--){
		string s;
		cin >> s;
		vector<int> count(26,0);
		for(char c : s){
			count[c-'a']++;
		}
		int max_freq =* max_element(count.begin(), count.end());
		int n = s.length();
		if (max_freq <= (n + 1) / 2)
            cout << 1 << endl;
        else
            cout << -1 << endl;
		
	}
}