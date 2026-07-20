#include<bits/stdc++.h>
using namespace std;

int n,k;
vector<string> a;
string x[20];

void backtrack(int i,int start){
	for(int j = start; j < a.size(); j++){
		x[i] = a[j];
		if(i == k-1){
			for(int t = 0; t < k; t++){
				cout << x[t];
				if(t < k-1) cout << " ";
			}
			cout << endl;
		} 
		else{
			backtrack(i+1,j+1);
		}
	}
}

int main(){
    cin >> n >> k;

    set<string> s;
    for(int i = 0; i < n; i++){
        string tmp;
        cin >> tmp;
        s.insert(tmp);
    }

    for(auto i : s) a.push_back(i);

    sort(a.begin(), a.end());

    backtrack(0,0);
}