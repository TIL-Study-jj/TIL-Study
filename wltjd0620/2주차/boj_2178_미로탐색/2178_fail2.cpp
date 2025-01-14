#include <bits/stdc++.h>
using namespace std;

const int max_map = 104;
int n,m, visited[max_map][max_map], a[max_map][max_map];
int x,y;

int dy[4] = {-1,0,1,0};
int dx[4] = {0,1,0,-1};

int main(){
    // 줄 단위로 받아야 할 때는 scanf 사용
    scanf("%d %d", &n, &m);
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m ; j++){
            scanf("%1d", &a[i][j]);
        }
    }
    
    queue <pair<int,int>> q;
    visited[0][0] = 1;
    q.push({0,0});
    while(q.size()){
        tie(y,x) = q.front(); q.pop();
        for(int i = 0; i<4; i++){
            int ny = y + dy[i];
            int nx = x + dx[i];
            if(ny<0|| ny >=n || nx < 0 || nx >=m || visited[ny][nx]==0) continue;
            if(visited[ny][nx]) continue;
            visited[ny][nx] = visited[y][x] + 1;
            q.push({ny,nx});
        }
    }
    
    printf("%d", visited[n-1][m-1]);
    return 0;

}

// 틀렸던 이유 : 28번줄 visited 가 아니라 a임