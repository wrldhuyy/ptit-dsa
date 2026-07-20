#include<bits/stdc++.h>
using namespace std;

char c;
int k;
string cur;

void backtrack(int pos, int start){
    if(pos == k){
        cout << cur << endl;
        return;
    }

    for(int i = start; i <= c - 'A'; i++){
        cur.push_back('A' + i);
        backtrack(pos + 1, i); 
        cur.pop_back();
    }
}

int main(){
    cin >> c >> k;
    backtrack(0, 0);
}