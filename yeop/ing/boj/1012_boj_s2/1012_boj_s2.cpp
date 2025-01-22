#include <iostream>
#include <queue>
#include <cstring> // using memset
using namespace std;
int main() {
    int tc;
    cin >> tc;
    int dx[4] = {0, 0, 1, -1};
    int dy[4] = {1, -1, 0, 0};
    bool visited[50][50];
    for(int i = 0; i < tc; i++){
        int m, n, k, x, y, px, py, nx, ny, cx, cy; // zzzzzzzzz
        cin >> m >> n >> k;
        int snail = 0;
        memset(visited, false, sizeof(visited)); // initialize 2nd bool !! : have to remember
        for(int j = 0; j < k; j++){
            cin >> x >> y;
            visited[y][x] = true; // super crack zz
        }
        // save the info at the visited(2nd bool arr) and processing with queue
        queue<pair<int, int>> q;
        for(x = 0; x < 50; x++){
            for(y = 0; y < 50; y++){
                if(visited[x][y]){
                    snail++;
                    // cout << "need snail" << x << " " << y << "\n";
                    visited[x][y] = false;
                    q.push(make_pair(x, y));
                    while(q.size()>0){
                        px = q.front().first;
                        py = q.front().second;
                        q.pop();
                        for(int j = 0; j < 4; j++){
                            cx = px + dx[j];
                            cy = py + dy[j];
                            if((0 <= cx && cx < n) && (0 <= cy && cy < m) && visited[cx][cy]){
                                visited[cx][cy] = false;
                                q.push(make_pair(cx, cy));
                            }
                        }
                    }
                }
            }
        }
        cout << snail << "\n";
    }
    return 0;
}