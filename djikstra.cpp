#include<bits/stdc++.h>
using namespace std;
int C[1005][1005];
int n,m,s;
void Dijkstra(int s){
	bool daxet[n+1] = {false};
	int d[n+1] = {0},t = n-1,min,u,i;
	daxet[s] = true;
	for(int i = 1; i <=n; i++) d[i] = C[s][i];
	while(t--){
		min = INT_MAX; u = 0;
		for(int i = 1; i <= n;i++){
			if(!daxet[i] && min > d[i]){
				min = d[i];
				u = i;
			}
		}
		daxet[u] = true;
		for(int i = 1; i <=n;i++){
			if(d[i] > d[u] + C[u][i]){
				d[i] = d[u] + C[u][i];
			}
		}
	}
	for(int i = 1; i <=n; i++) cout << d[i] << " ";
}
int main(){
    int t;
    cin >> t;

    while(t--){
        cin >> n >> m >> s;
        for(int i = 1; i <= n; i++){
            for(int j = 1; j <= n; j++){
                if(i == j) C[i][j] = 0;
                else C[i][j] = INT_MAX;
            }
        }
        for(int i = 0; i < m; i++){
            int u, v, w;
            cin >> u >> v >> w;
            C[u][v] = w;
            C[v][u] = w; 
        }

        Dijkstra(s);
    }

    return 0;
}