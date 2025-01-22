#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <cstring> // using memset

using namespace std;
int main(){
    int arrmap[100][100] = {0};
    int n, num, minh, maxh;
    cin >> n;
    minh = 100;
    maxh = 1;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            cin >> num;
            arrmap[i][j] = num;
            if(minh > num){
                minh = num;
            }
            if(maxh < num){
                maxh = num;
            }
        }
    }
    bool visited[100][100];
    vector<int> area;
    int areanum, qx, qy, nx, ny;
    int dx[4] = {0,0,1,-1};
    int dy[4] = {1,-1,0,0};
    for(int h = minh; h < maxh; h++){
        queue<pair<int, int>> q;
        memset(visited, false, sizeof(visited)); // initalize 2nd bool matrix
        areanum = 0;
        for(int i = 0; i < n; i++){
            for(int j = 0; j < n; j++){
                if(arrmap[i][j] > h && !visited[i][j]){
                    visited[i][j] = true;
                    q.push(make_pair(i, j));
                    areanum++;
                    while(true){
                        if(q.size() == 0){
                            break;
                        }
                        qx = q.front().first;
                        qy = q.front().second;
                        q.pop();
                        for(int k = 0; k < 4; k++){
                            nx = qx + dx[k];
                            ny = qy + dy[k];
                            if((0 <= nx && nx < n) && (0 <= ny && ny < n) && (arrmap[nx][ny] > h) && (!visited[nx][ny])){
                                q.push(make_pair(nx, ny));
                                visited[nx][ny] = true;
                            }
                        }
                    }
                }
            }
        }
        area.push_back(areanum);
    }
    sort(area.begin(), area.end());
    if (area.size()== 0){
        cout << 1;
    }
    else{
        cout << area[area.size()-1];   
    }
    return 0;
}