// https://www.acmicpc.net/problem/2309
#include <bits/stdc++.h>
using namespace std;

int a[9];
int main(){
    //입력받기
    for(int i = 0; i< 9; i++){
        cin >> a[i];
    }
    sort(a,a+9);
    do{
        // for(int i:a)cout << i << " ";
        // cout << "\n";
        int sum = 0;
        for(int i = 0; i< 7; i++) sum += a[i];

        if(sum == 100)break;
    }while(next_permutation(a,a+9));
    for(int i = 0; i<7;i++) cout << a[i] << "\n";
    return 0;

    //array 원소 중 2개 골라서 빼기 ( 중복 가능 - 조합)

    // 뺀 array 다 더해서 100 나오는지 확인

    // 나오면 그 array 출력, 안나오면 다음 경우의 수
}

// permutation 하게 되면 배열의 순서가 바뀌게 된다.
// 조합으로 풀어도 되는데, 순열로 풀어도 무관한 문제