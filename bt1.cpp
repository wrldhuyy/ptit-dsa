#include<bits/stdc++.h>
using namespace std;
int n,k;
int a[25];
bool check(){
	int dem = 0, max_dem = 0;
	for(int i = 1; i <= n; i++){
		if(a[i] == 1){
				dem++;
		max_dem = max(max_dem,dem);
	} else{
		dem = 0;
		}
	
	}
	return max_dem > k;
}
void Try(int i){
	for(int j = 0; j <= 1; j++){
		a[i] = j;
		if(i == n){
			if(check()){
				for(int k = 1; k <= n; k++) cout << a[k];
				cout << endl;
			}
		} else {
			Try(i+1);
		}
	}
}
int main(){
	cin >> n >> k;
	Try(1);
}