#include <bits/stdc++.h>
using namespace std;

string s;
int main(){
    //getline으로 입력
    getline(cin, s);

    //10 이상 96 이하인 경우 대문자
    for(int i = 0;i<size(s);i++){
        //대문자인 경우
        if(s[i]>=65 && s[i]<65+26){
            if(s[i]+13>= 65+26){
                s[i] = s[i]+13 - 26;
            }else s[i] = s[i]+13;
        }
        //소문자인 경우
        if(s[i]>=97 && s[i]<97+26){
            if(s[i]+13 >= 97+26){
                s[i] = s[i]-13;
            }else s[i] = s[i] + 13;
        }
        
        cout << s[i];
    }
    return 0;
    
}