#include <bits/stdc++.h>
using namespace std;


int N, cnt[26];
string name, result;

int main(){
    // 입력
    cin >> N;
    for (int i = 0; i<N;i++){
        cin >> name;
        cnt[name[0] -'a']++;
    }
    // 각 성의 앞글자 잘라서 'a' 빼서 아스키로 변환
    // 해당 코드에 해당하는 cnt[k] ++ 해주기
    
    //cnt 배열 중 값이 5가 이상인 알파벳은 모아서 출력
    for (int i = 0; i < 26; i++){
        if(cnt[i]>=5){
            //result.push_back(i+"a");
            result += (i + 'a');
        }
    }
    if(result.size()){
        cout << result << "\n";
    }else cout << "PREDAJA";

    return 0;
}