// 1번 : 돌다리 두둘기기
#include <bits/stdc++.h>
using namespace std;

void DFS(int here){
    visited[here] = 1;
    for(int there : adj[here]){
        // 방문 되었는지 확인하고 진행
        if(visited[there])continue;
        DFS(there);
    }
}
// 시작지점에 대해 방문처리를 해주어야 한다.
// visited[1] = 1;
// DFS(1);


// 2번 : 못먹어도 go
void DFS2(int here){
    // 일단 방문되어있던 아니던 무조건 dfs 호출하고, 방문되어있다면 return으로 종료
    if(visited[here]) return;
    visited[here] = 1;
    for(int there : adj[here]){
        DFS(there);
    }
}