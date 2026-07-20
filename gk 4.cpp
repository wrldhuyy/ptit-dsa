#include<bits/stdc++.h>
using namespace std;
int n,m;
vector<int> a;
bool check(int t){
	int truoc = 0;
	for(int i = 0; i < n ; i++){
		if(a[i] < truoc){
			if(a[i] + t < truoc) return false;
		} else {
			if(a[i] + t >= m){
				
			} else {
				truoc = a[i];
			}
		}
	}
	return true;
}
int main(){
	cin >> n >> m;
	a.resize(n);
	for(int i = 0; i < n; i++) cin >> a[i];
	int l = 0, r  = m, kq = m;
	while(l <= r){
		int giua = (l + r)/2;
		if(check(giua)){
			kq = giua;
			r = giua - 1;
		}
		else l = giua +1;
	}
	cout << kq;
	
}