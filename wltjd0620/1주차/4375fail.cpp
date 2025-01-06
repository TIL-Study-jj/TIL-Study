#include <bits/stdc++.h>
using namespace std;

// while로 인풋 받기였나?
// cin이 없을 때까지 받기
// 1부터 11,111 쭉 올려가면서 n이 


int main(){
    // 입력받기
    int n;
    while(scanf("%d",&n) != EOF){ // 입력값이 없을 때까지
        int i= 1, cnt = 1;
        int m = 1;
        while(1){ // 1111... 찾을 때까지
            if(m%n == 0){
                break;
            }else{
                m += (i*10);
                i *= 10;
                cnt++;
            }
        }
        printf("%d\n",cnt);
    }
    return 0;
    
}
