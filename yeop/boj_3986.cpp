#include <iostream>
#include <string>
#include <vector>
using namespace std;

int main(){
    int n;
    cin >> n;
    int goodword = 0;
    string s;
    for(int i = 0; i < n; i++){
        cin >> s;
        vector<char> vc; // using stack
        for(int j = 0; j < s.size(); j++){
            if (s[j] == 'A'){
                if (vc.size() > 0 && vc.back() == 'A'){
                    vc.pop_back();
                }
                else{
                    vc.push_back('A');
                }
            }
            else{
                if (vc.size() > 0 && vc.back() == 'B'){
                    vc.pop_back();
                }
                else{
                    vc.push_back('B');
                }
            }
        }
        if (vc.size() == 0){
            goodword += 1;
        }
    }
    cout << goodword;
}