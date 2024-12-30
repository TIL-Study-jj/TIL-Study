
#include <bits/stdc++.h>
using namespace std;

// a부터 z까지 들어있는 배열 만들기
vector <char> abc= { 'a','b','c','d','e','f','g','h','i','j','k','l','m','n','o','p','q','r','s','t','u','v','w','x','y','z'};
vector <int> cnt;
string c;

int main(){
    //입력 받기
    cin >> c;
    // count 함수로 원소 개수 세서 새 vector에 넣기
    for (int i = 0; i < abc.size(); i++){
        cnt.push_back(count(c.begin(),c.end(),abc[i]));
        // cout << abc[i] << "\n";
    }
    // 공백으로 구분해서 출력
    for (int i = 0; i< cnt.size(); i++){
        cout << cnt[i] << " ";
    }
    
}