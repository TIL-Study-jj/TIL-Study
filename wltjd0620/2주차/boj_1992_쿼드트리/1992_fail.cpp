// 1992 쿼드트리
#include <bits/stdc++.h>
using namespace std;

// 쿼드 트리
// 주어진 영상이 모두 0으로 되어있으면 압축결과는 0, 1로만 되어 있으면 1
// 0과 1이 섞여있으면 왼위, 오위, 왼아, 오아 4개의 영상으로 나누어 압축되고, 

// 재귀로 풀어야 할 것 같은 느낌..?
// 재귀 안에 로직
// 내부 모든 값이 0이나 1인지 확인, 아니라면 4개로 나누기
bool a[68][68];
string s;
int y[4] = {-1,0,1,0};
int x[4] = {0,1,0,-1};
int dy, dx, ny, nx;

void go(int y, int x, int size){

}


int main(){
    cin >> n; // 1<= n <= 64 / n은 언제나 2의 제곱수3
    for( int i = 0 ; i < n ; i++){
        cin >> s;
        for(int j = 0; j < n ; j++){
            a[i][j] = s[j] -'0';
        }
    }
    go(0,0,n);
    return 0;
}

// 분할정복 ( Divide conquer )
// 문제를 쪼개서 하위 문제해결을 바탕으로 상위 문제 해결
// 재귀 또는 스택으로 해결