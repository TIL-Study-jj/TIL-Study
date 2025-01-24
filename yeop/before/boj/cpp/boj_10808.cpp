#include <iostream>
#include <string>
#include <map>
using namespace std;
int main(){
    map<char, int> alpahbetcnt;
    for(int i = 97; i < 123; i++){
        alpahbetcnt[char(i)] = 0;
    }
    string s;
    cin >> s;
    for(int i = 0; i < s.size(); i++){
        alpahbetcnt[char(s[i])]++;
    }
    for(int i = 97; i < 123; i++){
        cout << alpahbetcnt[char(i)] << " ";
    }
}