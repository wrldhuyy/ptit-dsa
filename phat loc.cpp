#include <bits/stdc++.h>
using namespace std;

int N;
int a[20];

bool check(int i){
    if(i > 1 && a[i] == 8 && a[i-1] == 8) return false;

    if(i >= 4 && a[i] == 6 && a[i-1] == 6 && a[i-2] == 6 && a[i-3] == 6)
        return false;

    return true;
}

void in(){
    for(int i = 1; i <= N; i++)
        cout << a[i];
    cout << endl;
}

void Try(int i){
    for(int j : {6,8}){
        a[i] = j;

        if(i == 1 && j != 8) continue;
        if(i == N && j != 6) continue;

        if(check(i)){
            if(i == N) in();
            else Try(i+1);
        }
    }
}

int main(){
    cin >> N;
    Try(1);
}