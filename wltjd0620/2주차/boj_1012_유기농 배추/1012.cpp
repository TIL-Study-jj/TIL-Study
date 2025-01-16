// 1012 유기농 배추
#include <bits/stdc++.h>
using namespace std;
// 컴포넌트 구하기 ( connected component )
// dfs
// 기본적으로 깊이 우선 탐색
// 쭉 들어가는 개념 -> 재귀함수로 구현
// 1. 노드 방문처리
// 2. map으로 따진다고 할 때, 4방향으로 돌아보기
// 3. map인 경우에는 일단 움직인 값이 map 벗어나지 않는지 확인
// 4. 돌면서 안에서 visited = 0, x = 1인 경우 해당 노드에서 다시 재귀함수 돌리기

const int max_map = 51;
int t, m, n, k, x,y,ret, ny, nx;
int dy[4] = {-1,0,1,0};
int dx[4] = {0,1,0,-1};
int baecu[max_map][max_map];
int visited[max_map][max_map];
//int a[max_map][max_map];

void dfs(int y, int x){
    // 일단 방문처리
    visited[y][x] = 1;
    // 재귀함수
    for(int i = 0; i < 4 ; i++){
        ny = y + dy[i];
        nx = x + dx[i];
        if(ny< 0 || nx < 0 | ny >= n || nx >= m) continue;
        if(baecu[ny][nx]==1 && !visited[ny][nx]){
            dfs(ny,nx);
        }
    }
    return;
}

int main(){
    cin >> t;
    for(int i = 0; i < t ; i++){
        fill(&baecu[0][0], &baecu[0][0] + 51 * 51, 0);
        fill(&visited[0][0], &visited[0][0] + 51 * 51, 0);
        ret = 0;
        cin >> m >> n >> k;
        for(int j = 0; j < k; j++){
            cin >> x >> y;
            baecu[y][x] = 1;
           
        }
        // 모든 노드에 대해 dfs??
        for(int l = 0; l < n; l++){
            for(int z = 0; z < m; z++){
                if(baecu[l][z]==1 && !visited[l][z]){
                    ret++;
                    dfs(l,z);
                }
            }
        }
        cout << ret << "\n";
        
    }
    
    return 0;
}

// 테스트케이스 주어질 경우 맵도 초기화 해줘야 함.