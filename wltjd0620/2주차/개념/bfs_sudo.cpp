#include <bits/stdc++.h>
using namespace std;

vector <int> adj[100];
int visited[100];
int nodeList[] = {10,12,14,16,18,20,22,24};

void bfs(int here){
    queue <int> q;
    visited[here] = 1;
    // queue에 방문 노드 추가
    q.push(here);
    while(q.size()){
        int here = q.front(); q.pop();
        // here adj 에서 연결되어 있는 노드 하나씩 방문
        for(int i : adj[here]){
            // i -> adj 안에 있는 연결되어 있는 애들이니까
            if(visited[i]){
                continue;
            }
            // 이전 방문노드 ( here )보다 visited 값 하나 더 증가해서 넣어줌
            // 레벨별로 visited 배열 값이 달라서 최단거리를 찾을 수 있게 된다.
            visited[i] = visited[here] + 1;
            // adj ( 인접리스트 ) 에 있는 값을 queue에 다시 추가
            q.push(i);
        }
    }
}



int main(){
    adj[10].push_back(12);
    adj[10].push_back(14);
    adj[10].push_back(16);

    adj[12].push_back(18);
    adj[12].push_back(20);
    
    adj[20].push_back(22);
    adj[20].push_back(24);

    bfs(10);
    for(int i : nodeList){
        cout << i << " : " << visited[i] << '\n';
    }
    cout << "10번으로부터 24번까지 최단거리는 : " << visited[24] -1 << "\n";
    return 0;
}