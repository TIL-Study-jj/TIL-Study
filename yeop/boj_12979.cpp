#include <string>
#include <iostream>

using namespace std;

int main(){
    string s;
    cin >> s;
    int cnt = 0;
    for(int i = 0; i < s.size(); i++){
        if (s[i] == 'Y'){
            cnt += 1;
            for(int j = i+1; j < s.size()+1; j += i+1){
                if(s[j-1] == 'Y'){
                    s[j-1] = 'N';
                }
                else{
                    s[j-1] = 'Y';
                }
            }
        }
    }
    cout << cnt;
}