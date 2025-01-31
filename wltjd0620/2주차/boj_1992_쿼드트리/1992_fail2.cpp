// 1992 쿼드트리
#include <bits/stdc++.h>
using namespace std;

// 분할정복
// 작은 문제를 통해 큰 문제를 해결하는 방식

// 주어진 2차원 배열을 4분면으로 나누어 
// 각 분면이 모두 0 또는 1이면 해당 분면은 0 또는 1
// 아니면 또 4분면으로 나누는 재귀 함수

int x,y,n,temp;

// vector<vector<int>> a;

void findd(int y, int x, int size){
    for(int i = 0; i < )
}

void go(int y, int x, int size){
    // 주어진 2차원 배열을 4분면으로 나눔
    // n/2
    // 0,0부터 시작해서
    int half = size/2
    ny = half;
    nx = half;
    
}

int main(){
    cin >> n;
    vector<vector<int>> a(n,vector<int>(n,0));
    for(int i = 0; i<n; i++){
        for(int j = 0; j < n ; j++){
            cin >> temp;
            a[i][j] = temp;
            // cout << a[i][j];
        }
        // cout << "\n";
    }
    go(0,0,n);
    
    return 0;

}

// resize 함수
// vector <int> a;
// a.resize(n,vector<int>(n));

// main 함수 내에서 초기화 하는게 더 빠르다
// vector<vector<int>> a(n,vector<int>(n));

