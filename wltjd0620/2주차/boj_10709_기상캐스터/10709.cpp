#include <bits/stdc++.h>
using namespace std;

// 무조건 오버플로우 생각해서 자료형 만큼 더 크게 선언
int n, m, a[104][104]; 

string s;

int main(){
    cin >> n >> m;
    for(int i = 0; i < n; i++){
        cin >> s;
        // s.size() 식으로 함수보다는 최대한 복잡도 줄이기
        for(int j = 0;j < m ; j++){
            // map 생성시에 조건에 따른 초기화를 해주는것으로
            // 추가 초기화 소요 줄이기
            if(s[j]=='.') a[i][j] = -1;
            else a[i][j] = 0;
        }
    }

    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            // 구름이 있는 경우
            if(a[i][j]==0){
                // 들어갈 숫자 선언
                int cnt = 1;
                // 기존에 구름이 있던 자리가 나오기 전까지 대입
                while(a[i][j+1]==-1){
                    a[i][j+1] = cnt++;
                    j++;
                }
            }
        }
    }

    for(int i = 0; i<n;i++){
        for(int j = 0; j<m; j++) cout << a[i][j] << " ";
        cout << "\n";
    }
    return 0;
}


// 문제가 주어졌을 때 map을 통채로 변경할 생각 하지 말고
// 초기화시에는 조건에 맞는 값이 들어갈 수 있도록 생성시에 값을 넣고
// 최대한 간단하게 풀 수 있는 방식으로 풀어주기 ( 속도 )