// 2178 
#include <bits/stdc++.h>
using namespace std;

// map 사이즈는 무조건 const 붙여서
const int max_map = 104;
int n, m; 
// Vector로 선언하지 말고 최대 n,m 값으로 바꿔서 선언해라
// vector <int> mapp[][];
// vector <int> visited[][];
int mapp[max_map][max_map];
int visited[max_map][max_map];
string s;

int dy[4] = {-1,0,1,0};
int dx[4] = {0,1,0,-1};

void bfs(int y,int x){
    // queue에다가 처음 값을 근데 2차원이면 어떻게 넣음?
    // -> pair을 사용하면 된다.
    queue <pair<int,int>> q;

    // 방문처리
    visited[y][x] = 1;
    q.push({y,x}); // push 할 때는 무조건 visited에 방문처리
    
    while(q.size()){
        int ty, tx;
        tie(ty,tx) = q.front(); q.pop();
        for(int i = 0 ; i<4; i++){
            int ny = ty + dy[i];
            int nx = tx + dx[i]; 
            if(ny < 0 || ny >= n || nx < 0 || nx >= m|| mapp[ny][nx]==0) continue;
            if(visited[ny][nx])continue;
            visited[ny][nx] = visited[ty][tx] + 1;
            q.push({ny,nx});
        }
    }
}


int main(){
    cin >> n >> m;

    // 붙어서 들어오면 어떻게 받아야하지?
    // string??
    for(int i = 0; i< n; i++){
        cin >> s;
        // cout << s;
        for(int j = 0; j < m; j++){
            
            mapp[i][j] = s[j];
            cout << s[j] << "in" << mapp[i][j] << "\n";
            // cout << j << " | " << i << " = " << mapp[i][j] << "\n";
        }
    }


    // 최소니까 bfs인 것 같은데
    // 인접리스트를 만들어야 하고 adj
    // adj 바탕으로 bfs 함수를 돌려줘야 한다.

    // 좌표로 접근하면 안 되나?
    // 이것도 상하좌우 돌리는 개념이니까
    bfs(0,0);
    cout << visited[n-1][m-1];
    return 0;

}

// 틀렸던 이유 : 입력받을 때 mapp[i][j] = s[j] - '0'; 을 통해 문자를 숫자로 바꾸는 역할이 필요ㅕ함
// string으로 받았기 때문에 '0'을 통해 int 변환을 해 줘야 한다.