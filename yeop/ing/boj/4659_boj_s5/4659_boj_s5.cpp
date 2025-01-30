#include <iostream>
#include <map>
#include <string>
using namespace std;

bool threeaeiou(string st, int idx){
    int aeioucnt = 0;
    for(int i = idx; i >= idx - 2; i--){
        if(st[i] == 'a' || st[i] == 'e' || st[i] == 'i' || st[i] == 'o' || st[i] == 'u'){
            aeioucnt++;
        }
    }
    if (aeioucnt == 3){
        return true;    
    }
    return false;
}
bool threenotaeiou(string st, int idx){
    int notaeioucnt = 0;
    for(int i = idx; i >= idx - 2; i--){
        if(st[i] != 'a' && st[i] != 'e' && st[i] != 'i' && st[i] != 'o' && st[i] != 'u'){
            notaeioucnt++;
        }
    }
    if (notaeioucnt == 3){
        return true;    
    }
    return false;
}


int main(){
    string s;
    map<char, int> alphabetmap;
    bool isacceptable;
    while(true){
        cin >> s;
        if(s == "end"){
            break;
        }
        isacceptable = true;
        for(char a = 'a'; a <= 'z'; a++){
            alphabetmap[a] = 0;
        }
        for(int i = 0; i < s.size(); i++){ // check continuous two condition
            alphabetmap[s[i]]++;
            if((i >= 1) && (s[i] == s[i-1]) && (s[i] != 'e') && (s[i] != 'o')){ // check condition 3
                isacceptable = false;
                break;
            }
            
            if((i >= 2) && (threeaeiou(s,i) || threenotaeiou(s, i))){ // check condition 2
                isacceptable = false;
                break;
            }
        }
        if ((alphabetmap['a'] + alphabetmap['e'] + alphabetmap['i'] + alphabetmap['o'] + alphabetmap['u']) == 0){ // check condition 1
            isacceptable = false;
        }
        if(isacceptable){
            cout << "<" << s << ">" << " is acceptable.\n";
        }
        else{
            cout << "<" << s << ">" << " is not acceptable.\n";
        }
    }
    return 0;
}