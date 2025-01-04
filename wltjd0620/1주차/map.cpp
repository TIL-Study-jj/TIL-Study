#include <bits/stdc++.h>
using namespace std;

map<string, int> mp;
string a[] = {"주홍철", "이승철", "박종선"};

int main(){
    for(int i = 0; i<3;i++){
        //mp.insert({a[i],i + 1}); // map 요소 추가
        mp[a[i]] = i + 1; // map 요소 추가
    }
    auto it = mp.find("kundol");
    if(it == mp.end()){
        cout << "none";
    }
    // mp.end()는 맵의 끝을 나타내는 이터레이터 ( 경계 이터레이터 )
    // 검색한 키가 존재하지 않을 때 반환되는 위치
    it = mp.find("kundol");
    if(it !=mp.end()){
        cout << (*it).first << " : " << (*it).second << "\n";
        cout << it->first << " : " << it -> second << "\n";
    }



    // for (int i = 0; i<3; i++){
    //     cout << mp[a[i]];
    // }

    return 0;
}