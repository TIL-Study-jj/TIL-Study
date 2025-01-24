#include <iostream>
#include <string>
using namespace std;
int main(){
    string s;
    cin >> s;
    bool ispall = true;
    for(int i = 0; i < s.size()/2; i++){
        if(s[i] != s[s.size()-i-1]){
            ispall = false;
            break;
        }
    }
    if(ispall){
        cout << "1";
    }
    else{
        cout << "0";
    }
}