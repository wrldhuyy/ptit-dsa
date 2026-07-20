#include<bits/stdc++.h>
using namespace std;

char c;
string s;
bool used[20];
vector<char> a;

bool isVowel(char x){
    return x == 'A' || x == 'E';
}

bool check(){
    for(int i = 1; i < s.size() - 1; i++){
        if(isVowel(s[i]) && !isVowel(s[i-1]) && !isVowel(s[i+1])){
            return false;
        }
    }
    return true;
}

void backtrack(){
    if(s.size() == a.size()){
        if(check()) cout << s << endl;
        return;
    }

    for(int i = 0; i < a.size(); i++){
        if(!used[i]){
            used[i] = true;
            s.push_back(a[i]);

            backtrack();

            s.pop_back();
            used[i] = false;
        }
    }
}

int main(){
    cin >> c;

    for(char ch = 'A'; ch <= c; ch++){
        a.push_back(ch);
    }

    backtrack();
}