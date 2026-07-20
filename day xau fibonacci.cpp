#include<bits/stdc++.h>
using namespace std;

long long length[100];

char solve(long long n, long long i){
    if(n == 1) return 'A';
    if(n == 2) return 'B';

    if(i <= length[n-2]){
        return solve(n-2, i);
    } else {
        return solve(n-1, i - length[n-2]);
    }
}

int main(){
    int t;
    cin >> t;

    length[1] = 1;
    length[2] = 1;
    for(int i = 3; i <= 92; i++){
        length[i] = length[i-1] + length[i-2];
    }

    while(t--){
        long long n, i;
        cin >> n >> i;

        cout << solve(n, i) << endl;
    }
}