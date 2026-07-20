#include<bits/stdc++.h>
using namespace std;
int n;
int a[10], used[10], b[10];
void in(){
	for(int i = 1;i<= n;i++) cout << a[i] <<" ";
	cout << endl;
	
	
}
void Try(int i){
	for(int j = 1; j <=n;j++){
		if(!used[j]){
			a[i] = b[j];
			used[j] = 1;
			if(i == n) in();
			else Try(i+1);
			used[j] = 0;
		}
	}
}
int main(){
    cin>>n;
    for(int i=1;i<=n;i++) cin>>b[i];

    sort(b+1,b+n+1);

    Try(1);
}