#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int arr[301][301];  // 빙산 정보 저장
int dx[4] = {0, 0, 1, -1};  // 상하좌우 이동
int dy[4] = {1, -1, 0, 0};

int n, m; 
vector<pair<int, int>> icebergs;  

int countIcebergGroups() { // 빙산 개수 세기
    vector<vector<bool>> visited(n, vector<bool>(m, false));
    queue<pair<int, int>> q;
    int groups = 0;

    for (auto [x, y] : icebergs) {
        if (!visited[x][y] && arr[x][y] > 0) { 
            groups++;
            q.push({x, y});
            visited[x][y] = true;

            while (!q.empty()) {
                auto [cx, cy] = q.front();
                q.pop();

                for (int i = 0; i < 4; i++) {
                    int nx = cx + dx[i];
                    int ny = cy + dy[i];

                    if (0 <= nx && nx < n && 0 <= ny && ny < m && 
                        !visited[nx][ny] && arr[nx][ny] > 0) {
                        visited[nx][ny] = true;
                        q.push({nx, ny});
                    }
                }
            }
        }
    }
    return groups;
}

int main() {
    cin >> n >> m;
    
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> arr[i][j];
            if (arr[i][j] > 0) icebergs.push_back({i, j});
        }
    }

    int years = 0;

    while (!icebergs.empty()) {
        if (countIcebergGroups() >= 2) { // 빙산 덩어리 개수 체크
            cout << years;
            return 0;
        }

        vector<pair<int, int>> new_icebergs;
        vector<vector<int>> melting(n, vector<int>(m, 0));

        for (auto [x, y] : icebergs) {
            int melt_count = 0;
            for (int i = 0; i < 4; i++) {
                int nx = x + dx[i], ny = y + dy[i];
                if (0 <= nx && nx < n && 0 <= ny && ny < m && arr[nx][ny] == 0) {
                    melt_count++;
                }
            }
            melting[x][y] = melt_count;
        }

        for (auto [x, y] : icebergs) { // 빙산 녹이기
            arr[x][y] = max(0, arr[x][y] - melting[x][y]);
            if (arr[x][y] > 0) new_icebergs.push_back({x, y});
        }

        icebergs = new_icebergs;  // 업데이트된 빙산 리스트 반영
        years++;

        if (icebergs.empty()) { // 빙산이 다 녹았는지 체크
            cout << "0";
            return 0;
        }
    }
}