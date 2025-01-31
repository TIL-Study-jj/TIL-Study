// 2910 빈도 정렬
#include <bits/stdc++.h>
using namespace std;

// 빈도를 조사
// 숫자 n개로 이루어진 수열, 숫자는 모두 c보다 작거나 같다
// 자주 등장하는 빈도 순대로 정렬하려고 한다.

// 두 수 x와 y가 있을 때 x가 y보다 수열에서 많이 등장할 경우 x가 y보다 앞에 있어야 함
// 등장하는 횟수가 같으면 먼저 나온 것이 앞에

// 수열이 주어졌을 때 빈도 정렬을 하는 프로그램

// map으로 묶어서 생각?
int n,c;
map<int, pair<int,int>> mp; // 값, 개수, 순서 순
int a[1004];

int main(){
    cin >> n >> c;
    for(int i = 0; i < n ; i ++){
        cin >> a[i];
    }
    for(int i = 0; i < n ; i++){
        mp[a[i]].first += 1;
        if(mp.find(a[i])==mp.end()) // find를 사용해 키가 있는지 확인
            // 값이 없는 경우 삽입
            mp[a[i]].second = i;
    }
    // 이러면 map를 통해 배열이 정리된 상태
    
    // 이제 빈도수에 따라 순서대로 정렬
    for(int i = 0; i < n ; i++){
        
    }
    
}

// 빈도를 조사