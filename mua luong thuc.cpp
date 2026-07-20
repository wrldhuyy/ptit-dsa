#include<bits/stdc++.h>
using namespace std;
int main(){
	int t;
	cin >> t;
	while(t--){
		int n,s,m;
		cin >> n >> s >> m;
		int total_food = s*m;
		int sundays = s/7;
		int buy_days = s - sundays;
		if(buy_days * n < total_food){
			cout << -1 << endl;
		}else{
			int days = (total_food + n - 1)/n;
			cout << days << endl;
		}
	}
	return 0;
}