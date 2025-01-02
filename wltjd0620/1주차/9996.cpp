#include <bits/stdc++.h>
using namespace std;

int N,l;
string pattern,k, pattern_prefix, pattern_suffix, name_prefix, name_suffix;

int main(){
    // 입력 파일의 개수 N( 1<= N <= 100)
    cin >> N;
    // 입력 : 패턴
    cin >> pattern;
    // 입력 : N개줄에 걸쳐서 파일 이름
    l = pattern.find('*');
    pattern_prefix = pattern.substr(0,l);
    pattern_suffix = pattern.substr(l+1);
    for(int i = 0; i<N; i++){
        cin >> k;
        // pattern과 name[i]의 pre,suf 구하기
        
        name_prefix = k.substr(0,l);
        name_suffix = k.substr(k.size()-pattern_suffix.size());

        //cout << pattern_prefix << " " << pattern_suffix << " " << name_prefix << " " << name_suffix << "\n";
        // 패턴이랑 맞는지 확인
        // 맞으면 "DA" 출력, 틀렸으면 "NE" 출력
        if(pattern_prefix.size() + pattern_suffix.size() > k.size()){
            cout << "NE" << "\n";
        }
        else{
            if(pattern_prefix == name_prefix && pattern_suffix == name_suffix){
                cout << "DA" << "\n";
            }else cout << "NE" << "\n";
        }
    }
    return 0;
}