#include <iostream>
#include <cstring>
#include <queue>
using namespace std;
int arr[100][100];
bool vis[100][100];
int main(){
    int n; cin >> n; char c;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            cin >> c;
            if(c == 'R'){
                arr[i][j] = 2;
            }
            else if(c == 'G'){
                arr[i][j] = 4;
            }
            else{ // B
                arr[i][j] = 3;
            }
        }
    }
    int dx[4] = {0,0,1,-1};
    int dy[4] = {1,-1,0,0};
    
    int c1 = 0; int c2 = 0;
    for(int i = 0; i < n; i++){ // find condition 1 
        for(int j = 0; j < n; j++){
            if(!vis[i][j]){
                vis[i][j] = true;
                int target = arr[i][j];
                queue<pair<int, int>> q;
                q.push(make_pair(i, j));
                c1++;
                while(!q.empty()){
                    int px = q.front().first;
                    int py = q.front().second;
                    q.pop();
                    for(int k = 0; k < 4; k++){
                        int nx = px + dx[k];
                        int ny = py + dy[k];
                        if(0 <= nx && nx < n && 0 <= ny && ny < n && arr[nx][ny] == target && !vis[nx][ny]){
                            vis[nx][ny] = true;
                            q.push(make_pair(nx, ny));
                        }
                    }
                }
            }
        }
    }
    memset(vis, false, sizeof(vis));
    for(int i = 0; i < n; i++){ // find condition 2
        for(int j = 0; j < n; j++){
            if(!vis[i][j]){
                vis[i][j] = true;
                int target;
                if(arr[i][j] % 2 == 0){
                    target = 2;
                }
                else{
                    target = 3;
                }
                queue<pair<int, int>> q;
                q.push(make_pair(i, j));
                c2++;
                while(!q.empty()){
                    int px = q.front().first;
                    int py = q.front().second;
                    q.pop();
                    for(int k = 0; k < 4; k++){
                        int nx = px + dx[k];
                        int ny = py + dy[k];
                        if(0 <= nx && nx < n && 0 <= ny && ny < n && arr[nx][ny] % target == 0 && !vis[nx][ny]){
                            vis[nx][ny] = true;
                            q.push(make_pair(nx, ny));
                        }
                    }
                }
            }
        }
    }
    cout << c1 << " " << c2;
    return 0;
}