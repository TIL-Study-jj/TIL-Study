#include <bits/stdc++.h>
using namespace std;

int n;
vector <string> s; // 50 이하
string a;

bool cmp(string a, string b){
    // 길이가 짧은 것부터
    if(a.size() < b.size()){
        return true;
    }
    else if(b.size() < a.size()){
        return false;
    }
    
    // 길이가 같으면 사전 순으로
    else{
        return a<b;   
    }
}

int main(){
    cin >> n;
    for(int i = 0 ; i < n ; i++){
        cin >> a;
        s.push_back(a);
    }
    // 중복제거
    // for(int i = 0; i < n; i++){
    //     cout << s[i] << "\n";
    // }
    
    // 조건에 맞게 정렬
    sort(s.begin(),s.end(),cmp);
    // for(int i = 0; i < n; i++){
    //     cout << s[i] << " ";
    // }
    s.erase(unique(s.begin(),s.end()),s.end());
    for(int i = 0; i < s.size(); i++){
        cout << s[i] << "\n";
    }
    return 0;
}