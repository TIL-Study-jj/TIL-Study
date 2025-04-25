#include <iostream>
#include <vector>
using namespace std;
vector <int> visited (26, 0);
vector<vector<int>> MAP;
int maxd = 1;
int dx[4] = {1,-1,0,0};
int dy[4] = {0,0,1,-1};
// DFS로 maxd찾기
void DFS(vector<int> & visited, int x, int y, int d, int n, int m){
    // cout << MAP[x][y] << "\n";
    for(int i = 0; i < 4; i++){
        int nx = x + dx[i];
        int ny = y + dy[i];
        if(0 <= nx && nx < n && 0 <= ny && ny < m && visited[MAP[nx][ny]] == 0){
            visited[MAP[nx][ny]] = 1;
            DFS(visited, nx, ny, d + 1, n, m);
            visited[MAP[nx][ny]] = 0;
        }
    }
    if(maxd < d){
        maxd = d;
    }
    return;
}
int main(){
    int r, c; cin >> r >> c;
    MAP.resize(r, vector<int>(c));
    char a;
    for(int i = 0;i < r; i++){
        for(int j = 0; j < c; j++){
            cin >> a;
            MAP[i][j] = a - 'A';
        }
    }
    
    visited[MAP[0][0]] = 1;
    DFS(visited, 0, 0, 1, r, c);
    cout << maxd;
}