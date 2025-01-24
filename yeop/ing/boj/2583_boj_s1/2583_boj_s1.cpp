#include <bits/stdc++.h>

using namespace std;
int main() {
    int m, n, k;
    cin >> m >> n >> k;
    vector<vector<int>> vecmap (m, vector<int>(n, 0));
    int rx1, ry1, rx2, ry2;
    for(int i = 0; i < k; i++){
        cin >> ry1 >> rx1 >> ry2 >> rx2;
        for(int x = rx1; x < rx2; x++){
            for(int y = ry1; y < ry2; y++){
                vecmap[x][y] = 1;
            }
        }
    }
    int areacnt = 0;
    int as;
    vector<int> areasize;
    queue<pair<int, int>> q;
    int dx[4] = {1,-1,0,0};
    int dy[4] = {0,0,1,-1};
    int px, py, nx, ny;
    for(int i = 0; i < m; i++){
        for(int j = 0; j < n; j++){
            if (vecmap[i][j] == 0){ // area found!
                as = 1;
                areacnt++;
                vecmap[i][j] = 1; // consider duplicate
                q.push(make_pair(i, j));
                while(true){
                    if(q.size() == 0){
                        break;
                    }
                    px = q.front().first;
                    py = q.front().second;
                    q.pop();
                    for(int k = 0; k < 4; k++){
                        nx = px + dx[k];
                        ny = py + dy[k];
                        if((0 <= nx && nx < m) && (0 <= ny && ny < n) && (vecmap[nx][ny] == 0)){
                            q.push(make_pair(nx, ny));
                            vecmap[nx][ny] = 1;
                            as++;
                        }
                    }
                }
                areasize.push_back(as);
            }
        }
    }
    cout << areacnt << "\n";
    sort(areasize.begin(), areasize.end());
    for(int i = 0; i < areacnt; i++){
        cout << areasize[i] << " ";
    }
}