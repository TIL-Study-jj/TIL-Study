#include <iostream>
#include <string>
using namespace std;
int main(){
    int tc;
    cin >> tc;
    int stack; // using stack by int type zz
    int piece;
    for(int i = 1; i < tc + 1; i++){
        string s;
        cin >> s;
        stack = 0;
        piece = 0;
        for(int j = 0; j < s.size(); j++){
            if (s[j] == '('){
                stack += 1;
            }
            else{
                stack -= 1;
                if (s[j-1] == '('){
                    piece += stack;    
                }
                else{
                    piece += 1;    
                }
            }
        }
        cout << "#" << i << " " << piece << endl;
    }
}