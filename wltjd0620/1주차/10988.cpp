#include <bits/stdc++.h>
using namespace std;

string word;
string temp;

int main(){
    cin >> word;
    temp = word;
    reverse ( word.begin(),word.end());
    if ( temp == word ){
        cout << "1";
    }
    else cout << "0";
    return 0;
}