#include <bits/stdc++.h>
using namespace std;

// 장마철
// 높이 정보 파악
// 물에 잠기지 않는 안전 영역이 최대 몇개인지 조사
// 일정한 높이 이하의 모든 지점은 물에 잠긴다고 가정
// 행과 열의 크기가 N인 2차원 배열 ( 정사각형 )
// 해당 지점의 높이를 표시하는 자연수
// 
// 입력
// n
// 순서대로 n개의 높이 정보를 나타내는 map

// 방문 여부도 체크?
// 모든 비가 내리는 값 중에 안전영역의 최대 개수 값을 구하는 문제


const int max_map = 104;
int n, nx, ny, x, y, limit, ret,temp;
int dy[4] = {-1,0,1,0};
int dx[4] = {0,1,0,-1};

bool chimsu[max_map][max_map];
int a[max_map][max_map];
bool visited[max_map][max_map];

void dfs(int y, int x, int limit){
    visited[y][x] = 1;
    if(a[y][x] <= limit){
        chimsu[y][x] = 1;
    }
    for(int i = 0; i< 4; i++){
        ny = y + dy[i];
        nx = x + dx[i];
        if(ny < 0 | nx < 0 | ny >=n | nx >=n) continue;
        if(visited[ny][nx]==0 && a[y][x] > limit){
            dfs(ny,nx,limit);
        }
    }
    return;
}

int main(){
    cin >> n;
    for(int i = 0; i< n;i++){
        for(int j = 0; j< n; j++){
            cin >> a[i][j];
        }
    }

    //int max_map_suwi = *max_element(a.begin(),a.end());
    
    // 수위별로 전부 반복
    for(int z = 0; z <= 100; z++){
        // ret 값을 temp에 일단 저장 ( 초기 ret 값 )
        ret = 0;
        fill(&chimsu[0][0], &chimsu[0][0]+104*104,0);
        fill(&visited[0][0], &visited[0][0]+104*104,0);
        for(int i = 0; i < n; i++){
            for(int j = 0; j < n ; j++){
            // map, ret 초기화 ( ret은 새로 나온 값이 더 크면 그 값으로 변환하는 식으로)
                if(a[i][j] > z && !visited[i][j]){
                    // ret이 뭐냐 ? -> 컴포넌트 개수
                    dfs(i,j,z);
                    ret++;
                    // 컴포넌트 개수가 언제 올라가야해? -> dfs가 끝났을 때마다
                    // 결론적으로 모든 map에 대해서 도는데, 해당 map안에서 dfs를 돌리고, if visited[] 체크할 때마다 ret이 올라가야 한다.
                }
                // 해당 ret이 전에 있던 ret보다 크면 그 ret으로 바꾸면 된다.
                
            }
        }
        // if(ret){
        //     cout << z << " " << ret << "\n";
        // }
        
        if(ret > temp){
            temp = ret;
        }
    }
    cout << temp;
    return 0;
}
