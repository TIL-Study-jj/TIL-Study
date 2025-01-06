#include <bits/stdc++.h>
using namespace std;

// 재료의 개수 n ( 1<= n <= 15,000)
// 갑옷을 만드는데 필요한 수 m( 1<= m <= 10,000,000)
// n개의 재료들이 가진 고유한 번호들이 공백을 기준으로 주어짐 ( <= 100,000, 자연수 )

// 출력 : 갑옷을 만들 수 있는 개수 출력.

// 조합으로 모든 경우의 수 다 더해보고 있는 경우의 수면 cnt + 1

int n,m,cnt;
int r = 2;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);cout.tie(NULL);
    cin >> n;
    cin >> m;
    vector<int> k(n);

    for(int i = 0; i< n; i++){
        cin >> k[i];
    }
    // for(int i = 0; i< n; i++){
    //     cout << k[i];
    // }
    sort(k.begin(),k.end());
    
    do{
        int ret = 0;
        for(int i = 0; i<r ; i++){
            ret += k[i];
        }
        if(ret == m){
            cnt++;
        }
        reverse(k.begin()+r, k.end());
    }while ( next_permutation(k.begin(),k.end()));
    if(cnt == 0){
        cout << cnt;
        return 0;
    }
    cout << cnt/2;

    return 0;

}

// 이 문제를 next_permutation으로 풀게 되면 경우의 수 최대인 경우에 15,000! 계산이 되어
// 시간초과가 발생한다.


// 항상 문제 풀 때는 문제 범위를 보고 시간복잡도를 가늠해줘야 함.