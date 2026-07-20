#include <bits/stdc++.h>
using namespace std;

int main(){
    int t;
    cin >> t;

    while(t--){
        int n, k;
        cin >> n >> k;

        int a[50];
        bool used[50] = {0};

        for(int i = 1; i <= k; i++){
            cin >> a[i];
            used[a[i]] = true;
        }

        int i = k;

        while(i >= 1 && a[i] == n - k + i)
            i--;

        if(i == 0){
            cout << k << endl;
            continue;
        }

        a[i]++;
        for(int j = i + 1; j <= k; j++)
            a[j] = a[j - 1] + 1;

        int cnt = 0;

        for(int j = 1; j <= k; j++)
            if(!used[a[j]])
                cnt++;

        cout << cnt << endl;
    }
}