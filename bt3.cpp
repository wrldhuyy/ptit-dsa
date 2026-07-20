#include<bits/stdc++.h>
using namespace std;
int main(){
	string s;
	cin >> s;
	int n = s.size();
	int vitri = 0;
	for(int i = 0; i < n; i++){
		stack<char>  st;
		int dem = 0;
		for(int j = i; j < n; j++){
			char c = s[j];
			if(c == '(' || c == '['){
				st.push(c);
				if(c == '[') dem++;
			}else{
				if(st.empty()) break;
				if(c ==')'){
					if(st.top() == '(') st.pop();
					else break;
				} else{
					if(st.top() == '['){
						st.pop();
					} else break;
				}
			}
			if(st.empty()){
				vitri = max(vitri,dem);
			}
		}
	}
	cout << vitri;

}