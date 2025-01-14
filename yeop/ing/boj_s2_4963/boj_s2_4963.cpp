#include <iostream>
#include <queue>
#include <vector>
using namespace std;

int main(){
    int m, n, nx, ny, cx, cy;
    int dx[8] = {-1, -1, -1, 0, 0, 1, 1, 1};
    int dy[8] = {-1, 0, 1, -1, 1, -1, 0, 1};
    while(true){
        cin >> m >> n;
        if(m == 0){ // it not matters that didn't use condition m = 0 && n == 0
            break;
        }
        else{
            int num;
            vector<vector<int>> mp (n, vector<int>(m, 0)); // initialize map
            for(int i = 0; i < n; i++){ // create map
                for(int j = 0; j < m; j++){
                    cin >> num;
                    mp[i][j] = num;
                }    
            }
            
            int islandcnt = 0;
            queue<pair<int, int>> q;
            
            for(int i = 0; i < n; i++){ // visit map
                for(int j = 0; j < m; j++){
                    if(mp[i][j] == 1){
                        q.push(make_pair(i, j));
                        mp[i][j] = 0; // changing value instead of using visited array(vector)
                        islandcnt += 1;
                        while(true){
                            if(q.size() == 0){
                                break;
                            }
                            nx = q.front().first;
                            ny = q.front().second;
                            q.pop();
                            for(int k = 0; k < 8; k++){
                                cx = nx + dx[k];
                                cy = ny + dy[k];
                                if((0 <= cx && cx < n) && (0 <= cy && cy < m) && (mp[cx][cy] == 1)){
                                    mp[cx][cy] = 0;
                                    q.push(make_pair(cx, cy));
                                }
                            }
                        }
                    }
                }    
            }
            cout << islandcnt << endl;
        }
    }
    return 0;
}