#include <bits/stdc++.h>
using namespace std;

int dy[] = {-1,0,1,0};
int dx[] = {0,1,0,-1};
int n,m,ret,ny,nx;
// 사이즈가 100 100 이므로 여유롭게 104 부여
int a[104][104];
bool visited[104][104];

// xy축 있는 2차원 map이므로 매개변수 2개
// 이 방식은 돌다리 두들겨보기 방식
void dfs(int y, int x){
    // 해당 노드 방문처리
    visited[y][x] = 1;
    // 상하좌우 탐색
    for(int i = 0; i< 4; i++){
        // nyx로 dy, dx만큼 각각 이동
        ny = y + dy[i];
        nx = x + dx[i];
        // 이동한 값이 맵을 벗어나는지 확인해줘야 함
        if(ny < 0 || nx < 0 || ny >= n || nx >= m) continue;
        // 맵을 벗어나지 않고, 해당 맵의 값이 1이고 ( 육지 ), 방문하지 않은 노드라면
        if(a[ny][nx]==1 && !visited[ny][nx]){
            // 더 깊게 탐색
            dfs(ny,nx);
        }
    }
    return;
}

int main(){
    // dfs 함수를 어떻게 쓸거냐?
    // 일단 맵을 다 돌아야지
    cin >> n >> m;
    for(int i = 0; i < n ; i++){
        for(int j = 0; j< m; j++){
            cin >> a[i][j];
        }
    }
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m ; j++){
            // a[i][j] 가 육지이고 방문되지 않았다면
            if(a[i][j]==1 && visited[i][j]==0){
                ret++ ; dfs(i,j);
            }
        }
    }
    cout << ret;
}