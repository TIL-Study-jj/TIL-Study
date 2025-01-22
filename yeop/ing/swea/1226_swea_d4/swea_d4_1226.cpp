#include <iostream>
#include <string>
#include <deque>
#include <array>
#include <vector>
using namespace std;
int main() {
    int ans, sx, sy, ex, ey, nx, ny;
    string s;
    for (int i = 1; i < 11; i++){
        cin >> ans;
        vector<vector<int>> maze(16, vector<int>(16, 0)); // 2nd vec
        for (int j = 0; j < 16; j++) {
            cin >> s;
            for (int k = 0; k < 16; k++) {
                maze[j][k] = (s[k] - '0');
                if ((s[k] - '0') == 2) {
                    sx = j;
                    sy = k;
                }
                else if ((s[k] - '0') == 3) {
                    ex = j;
                    ey = k;
                }
            }
        }
        // find way : using bfs
        deque<pair<int, int>> deq;
        deq.push_back(make_pair(sx, sy));
        int cx, cy;
        bool findway = false;
        int dx[4] = { 0, 0, 1, -1 };
        int dy[4] = { 1, -1, 0, 0 };
        vector<vector<bool>> visited(16, vector<bool>(16, true)); // 2nd vec
        visited[sx][sy] = false;
        while (true) {
            if (deq.size() == 0) {
                break;
            }
            cx = deq.front().first;
            cy = deq.front().second;
            if (cx == ex && cy == ey) {
                findway = true;
                break;
            }
            deq.pop_front();
            for (int j = 0; j < 4; j++) {
                nx = cx + dx[j];
                ny = cy + dy[j];
                if ((0 <= nx && nx < 16) && (0 <= ny && ny < 16) && (visited[nx][ny]) && (maze[nx][ny] != 1)) {
                    deq.push_back(make_pair(nx, ny));
                    visited[nx][ny] = false;
                }
            }
        }
        if (findway) {
            ans = 1;
        }
        else {
            ans = 0;
        }
        cout << "#" << i << " " << ans << endl;
    }
}