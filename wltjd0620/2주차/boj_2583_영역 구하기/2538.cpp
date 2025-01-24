//2583 영역구하기
#include <bits/stdc++.h>
using namespace std;

// 눈금의 간격 1 m*n 크기 모눈종이
// k개의 직사각형 그린다.
// k개의 직사각형의 내부를 제외한 나머지 부분이 몇 개의 분리된 영역으로 나누어진다
// 분리된 영역의 넓이

// 출력
// 몇개의 분리된 영역으로 나누어 지는지, 각 영역의 넓이가 얼마인지

// Logic
// 알고리즘 : dfs - > 컴포넌트 찾기
// 일단 m-1 n-1 을 최대로 잡고 , 좌표가 주어지면 해당 좌표가 블럭이라고 생각
// 좌표 주어지면 for문으로 for first x -> end x { for first y -> end y }a[y][x] = 1 ( 색칠 )

// map 전체 좌표 돌면서 visited = 0인 dfs 재귀 횟수 cnt로 올려서 넓이 구하고 -> Push_back ( 이건 그럼 vector로 선언)
// dfs 가 몇번 반복됐냐로 ret로 올려서 개수

int m, n, k, fx, fy, ex, ey; // 셋다 100 이하 자연수
int dy[4] = {-1,0,1,0};
int dx[4] = {0,1,0,-1};
int ny, nx, cnt=1, ret;
int a[104][104], visited[104][104];
vector <int> cntcnt;

void dfs(int y, int x){
    visited[y][x] = 1;

    for(int i = 0; i<4;i++){
        ny = y + dy[i];
        nx = x + dx[i];
        if(ny < 0 || nx < 0 || ny >=m|| nx >= n | a[ny][nx]==1) continue;
        if(visited[ny][nx] == 0){
            dfs(ny, nx); // 이 dfs가 몇번 반복됐는지 구하면 된다.
            cnt++;
        }  
    }
    return;
}



int main(){
    cin >> m >> n >> k; // n이 x고 m이 y네
    for(int i = 0; i < k ; i++){
        cin >> fx >> fy >> ex >> ey ; // 0,2 / 4,4
        for(int j = fy; j < ey ; j++){
            for(int z = fx; z < ex ; z++){
                a[j][z] = 1;
                //cout << a[j][z] << "\n";
            }
        }
    }
    // map 출력함수
    // for(int i = 0; i < m; i++){
    //     for(int j= 0; j < n; j++){
    //         cout << a[i][j] << " ";
    //     }
    //     cout << "\n";
    // }
    
    for(int i = 0; i < m ; i++){
        for(int j = 0; j < n ; j++){
            if(a[i][j]==0 && visited[i][j]==0){
                dfs(i,j);
                cntcnt.push_back(cnt);
                ret++;
                cnt = 1;
            }
        }
    }

    cout << ret << "\n";
    sort(cntcnt.begin(),cntcnt.end());
    for(int i = 0; i < cntcnt.size(); i++){
        cout << cntcnt[i] << " ";
    }
    return 0;
}

// 따로 ret를 젤 필요 없이 cntcnt size로 풀어줘도 풀리는 문제