#include <iostream>
#include <string>
using namespace std;

int main() {
    int iter;
    cin >> iter;
    for(int i = 0; i < iter; i++){
        string s;
        cin >> s;
        int lp, rp;
        lp = 0;
        rp = s.length() - 1;
        bool ispal = true;
        while(lp <= rp){ // checking pallindrome
            if(s[lp] != s[rp]){
                ispal = false;
                break;
            }
            lp += 1;
            rp -= 1;
        }
        if (ispal){
            cout << "#" << i+1 << " 1\n";
        }
        else{
            cout << "#" << i+1 << " 0\n";
        }
    }
}
