#include <bits/stdc++.h>
using namespace std;

const int n = 6;
vector<int> adj[n];
int visited[n];

void dfs(int u){
    //방문처리
    visited[u] = 1;
    //출력하고
    cout << u << "\n";
    // adj돌면서
    for(int v: adj[u]){
        //방문하지 않은 노드라면
        if(visited[v]==0){
            // 해당 노드부터 다시 dfs 시작
            dfs(v);
            cout << "으랏챠" << v << "\n";
        }
    }
    // u로부터 갈 수 있는 노드가 전부 방문처리 되었을 경우
    cout << u << "로부터 시작된 함수가 종료되었습니다. \n";
    return;
}

int main(){
    adj[1].push_back(2);
    //adj[2].push_back(1);

    adj[1].push_back(3);
    //adj[3].push_back(1);

    adj[2].push_back(4);
    adj[4].push_back(2);

    adj[2].push_back(5);
    //adj[5].push_back(2);

    //예외처리
    
    dfs(1);
    return 0;
}


// 노드 번호로 인접리스트 구성할 경우에는 노드의 개수보다 +1 해준다.
// 인덱스로 접근하면 1번 노드가 0인덱스가 되어야 하는데, 그럼 복잡해지기 때문
// 