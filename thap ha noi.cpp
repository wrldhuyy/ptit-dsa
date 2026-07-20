#include<bits/stdc++.h>
using namespace std;

void thap(int n, char A, char B, char C){
    if(n == 1){
        cout << A << " -> " << C << endl;
        return;
    }

    thap(n-1, A, C, B); 
    cout << A << " -> " << C << endl; 
   thap(n-1, B, A, C); 
}

int main(){
    int n;
    cin >> n;
   thap(n, 'A', 'B', 'C');
}