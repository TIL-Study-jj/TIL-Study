#include <iostream>
#include <string>
#include <map>
using namespace std;

int main(){
   string s;
   cin >> s;
   map<char, int> alp;
   for(int i = 0; i < s.size(); i++){
       alp[s[i]] += 1;
   }
   int sorry = 0;
   for(auto i = alp.begin(); i != alp.end(); i++){
       if (i->second % 2 == 1){
           if (sorry == 0){
               sorry += 1;
           }
           else{
               sorry += 1;
               cout << "I'm Sorry Hansoo";
               break;
           }
       }
   }
   if(sorry != 2){ // make pallindrome
        s = "";
        char uniq;
        for(auto i = alp.begin(); i != alp.end(); i++){
            if (i->second % 2 == 1){
                    uniq = i->first;        
           }
            for(int j = 0; j < (int) i->second / 2; j++){
                s += i->first;
            }
        }
        cout << s;
        if(sorry == 1){
            cout << uniq;
        }
        for(int i = s.size() - 1; i >= 0; i--){
            cout << s[i];    
        }
    }
}