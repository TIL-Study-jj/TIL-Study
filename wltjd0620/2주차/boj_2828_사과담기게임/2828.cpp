#include <bits/stdc++.h>
using namespace std;

// j줄만큼 사과 떨어지는 위치 출력
// m은 어짜피 10보다 작으니까


int apple[11]; // 사과가 떨어지는 순서
int n,m,j,ret,temp,te;
int basket[2];


int main(){
    cin >> n >> m; // n이 스크린 칸 크기, m이 바구니 칸 크기
    cin >> j;
    // vector <int> basket(m,0);
    for ( int i = 0; i < j ; i++){
        cin >> apple[i];
    }
    basket[0] = 1;
    basket[1] = m;

    // 사과가 떨어지는 숫자만큼 반복
    for(int i = 0; i < j; i++){
        // 바구니보다 사과가 왼쪽에 있을 때
        if(basket[0] > apple[i]){
            // 바구니 왼쪽으로 이동
            temp = basket[0]-apple[i];
            basket[0] -= temp;
            basket[1] -= temp;
            ret += temp;
            
        }
        // 바구니보다 사과가 오른쪽에 있을 때
        else if(basket[1] < apple[i]){
            // 바구니 오른쪽으로 이동
            temp = apple[i]-basket[1];
            basket[0] += temp;
            basket[1] += temp;
            // 이동한만큼 ret 추가
            ret += temp;
            
        }
        // 바구니 속에 사과가 들어올 때 ( 바구니 안 움직여도 된다 )
        else{
            continue;
        }
    }
    cout << ret;
    return 0;    
    
}

// 바구니 이동을 어떻게 구현?
// 바구니 크기만한 배열 선언 후 해당 배열 안에 인덱스의 위치로 판단?