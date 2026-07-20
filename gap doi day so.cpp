#include<bits/stdc++.h>
using namespace std;

long long solve(long long n, long long k){
    if(n == 1) return 1;

    long long mid = (1LL << (n-1)); 

    if(k == mid) return n;
    else if(k < mid) return solve(n-1, k);
    else return solve(n-1, k - mid);
}

int main(){
    int t;
    cin >> t;
    while(t--){
        long long n, k;
        cin >> n >> k;
        cout << solve(n, k) << endl;
    }
}