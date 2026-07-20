#include<bits/stdc++.h>
using namespace std;
int n,k;
char x[20];
void Try(int i, char start){
	for(char c = start; c<='A'+n-1;c++){
		x[i] = c;
		if(i==k){
			for(int j = 1; j <=k;j++) cout << x[j];
			cout << endl;
				
			
		}else{
			Try(i+1,c+1);
		}
	}
}
int main(){
	int t;
	cin >> t;
	while(t--){
		cin >> n >> k;
		Try(1,'A');
	}
	
}