#include <bits/stdc++.h>
using namespace std;

int main(){
    int T;
    cin >> T;

    while(T--){
        string s;
        cin >> s;

        int i = s.length() - 1;

        while(i >= 0 && s[i] == '0'){
            s[i] = '1';
            i--;
        }

        if(i >= 0) s[i] = '0';

        cout << s << endl;
    }
}