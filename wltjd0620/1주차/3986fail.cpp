#include <bits/stdc++.h>
using namespace std;

// 입력
// 첫줄 : 단어의 수 n ( 1<= n <= 100)
// 이후 n개 줄에는 A와 B로만 이뤄진 단어가 한줄에 하나씩 주어짐
// 단어의 길이는 2와 100,000 사이, 모든 단어 길이의 합은 1,000,000을 넘지 않음

// 출력
// 좋은 단어의 수

// 일단 짝수개여야 한다.
// 번갈아가면서 나오면 안 되고,
// 좌우 대칭이거나 같은 문자가 연속돼야 한다.


int n,cnt;
// string word[104];
vector<string> word;
string k;


int main(){
    cin >> n;
    for(int i = 0; i<n ; i++){ // 입력받기
        int daec = 0;
        cin >> k;
        // 여기서 받아서 바로 처리하는게 제일 좋을듯?
        if(k.size()%2 == 1){ // 홀수개수인 경우
            continue;
        } 
        else{
            // 일단 크기가 2면 두개 똑같아야 하니까
            if(k.size()==2){
                if(k[0]==k[1]){
                    cnt++;
                }
                else{
                    continue;
                }
            }
            else{ // 크기 3 이상인 경우
                // 붙어있는 문자 먼저 빼기
                for(int m = 0; m<k.size()-1 ; m++){
                    if(k[m]==k[m+1]){
                        k[m] = 1;
                        k[m+1] = 1;
                    }
                }
                k.erase(remove(k.begin(),k.end(), 1),k.end());
                cout << k << "\n";

                if(k.size()==0){
                    cnt++;
                    continue;
                }

                // 좌우 대칭인지 확인
                for(int j = 0; j<(k.size()/2);j++){ 
                    if(k[j]==k[k.size()-j]){
                        daec++;
                    }
                } 
                cout << daec;
                if( daec >= 1){
                    cnt++;
                }
                else{
                    continue;
                }
            }
        }
    }
    cout << cnt << "\n";
}