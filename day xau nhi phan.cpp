#include<bits/stdc++.h>
using namespace std;

long long len[100];

char solve(long long n, long long k){
    if(n == 1) return '0';
    if(n == 2) return '1';

    if(k <= len[n-2])
        return solve(n-2, k);
    else
        return solve(n-1, k - len[n-2]);
}

int main(){
    int t;
    cin >> t;

    len[1] = 1;
    len[2] = 1;
    for(int i = 3; i <= 92; i++){
        len[i] = len[i-1] + len[i-2];
    }

    while(t--){
        long long n, k;
        cin >> n >> k;

        cout << solve(n, k) << endl;
    }
}