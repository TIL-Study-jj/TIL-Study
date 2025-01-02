// https://www.acmicpc.net/problem/2309
#include <bits/stdc++.h>
using namespace std;
int tall[9];
int main(){
    //입력
    for (int i = 0 ; i < 9 ; i++){
        cin >> tall[i] ;
    }
    // for (int i = 0 ; i < 9 ; i++){
    //     cout << tall[i] << " ";
    // }
    // 순열 적용 위해 오름차순 정렬
    sort(tall, tall + 9);
    // 7개 앞에 슬라이스 해서 더했을 때 100인 경우 출력
    do{
        int temp = 0;
        for(int i=0; i<7 ;i++){
            temp = temp + tall[i];
        }
        if(temp == 100){
            break;
            //for (int i : tall) cout << i << "\n";
        }
    }while(next_permutation(tall,tall+9));
    // 출력 ( 오름차순으로 )
    for(int i= 0 ; i < 7 ; i ++) cout << tall[i] << "\n";


    return 0;
}