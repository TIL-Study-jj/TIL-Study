#include <bits/stdc++.h>
using namespace std;

// n은 온도를 측정한 전체 날짜 수 2<=n <=100,000
// k는 합을 구하기 위한 연속적인 날짜의 수 , 1<= k <= n

// 둘째 줄에는 매일 측정한 온도를 나타내는 n개의 정수가 빈칸을 사이에 두고 주어짐
// 모든 수들은 -100 이상 100 이하

int n, k , temp, psum[100001], ret = -1000000;

int main(){
    cin >> n >> k;

    for( int i = 1 ; i <= n ; i ++){
        //ret에 최대값 계속 갱신해서 넣는 방식
        cin >> temp;
        psum[i] = psum[i-1] + temp;
    }
    for(int i = k; i<=n; i++){
        ret = max(ret,psum[i]-psum[i-k]);
    }
    cout << ret << "\n";
    return 0;

}