#include <iostream>
#include <queue>
using namespace std;
int arr[25][25] = { 0 };
int main() {
    int n;
    cin >> n;
    char cn; // input is not splited by space, so use char to save input individually
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> cn;
            arr[i][j] = cn - '0';
        }
    }
    queue<pair<int, int>> q;
    priority_queue<int> q2;
    int x, y, nx, ny, areasize;
    int dx[4] = { 0, 0, 1, -1 };
    int dy[4] = { 1, -1, 0, 0 };
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (arr[i][j] == 1) {
                q.push(make_pair(i, j));
                arr[i][j] = 0;
                areasize = 1;
                while (q.size() > 0) {
                    x = q.front().first;
                    y = q.front().second;
                    q.pop();
                    for (int k = 0; k < 4; k++) {
                        nx = x + dx[k];
                        ny = y + dy[k];
                        if ((0 <= nx && nx < n) && (0 <= ny && ny < n) && arr[nx][ny] == 1) {
                            arr[nx][ny] = 0;
                            q.push(make_pair(nx, ny));
                            areasize++;
                        }
                    }
                }
                q2.push(-areasize);
            }
        }
    }
    int qsize = q2.size();
    cout << qsize << "\n";
    for (int i = 0; i < qsize; i++) {
        cout << -q2.top() << "\n";
        q2.pop();
    }
}