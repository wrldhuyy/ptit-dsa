#include<bits/stdc++.h>
using namespace std;
int main(){
	int t;
	cin >> t;
	while(t--){
		int n,m,k;
		cin >> n >> m >> k;
		vector<long long> a(n),b(m),c(k);
		for(int i = 0; i < n ; i++) cin >> a[i];
		for (int i = 0; i < m; i++) cin >> b[i];
        for (int i = 0; i < k; i++) cin >> c[i];

        int i = 0, j = 0, t = 0;
        bool found = false;
        while(i < n && j < m && t < k){
        	if(a[i] == b[j] && b[j] == c[t]){
        		cout << a[i] << " ";
        		found = true;
        		i++,j++,t++;
			}
			else{
				long long mn = min({a[i], b[j], c[t]});
                if (a[i] == mn) i++;
                else if (b[j] == mn) j++;
                else t++;
			}
		}
		if (!found) cout << "NO";

        cout << endl;
	}
	return 0;
}