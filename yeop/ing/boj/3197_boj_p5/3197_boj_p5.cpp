#include <iostream>
#include <queue>
#include <cstring>
using namespace std;

const int MAX = 1500;
char arr[MAX][MAX]; // 2nd arr map set
bool visited[MAX][MAX];
bool swanVisited[MAX][MAX];
int r, c;
int swanx1, swany1, swanx2, swany2;

int dx[4] = {1, -1, 0, 0};
int dy[4] = {0, 0, 1, -1};

bool isValid(int x, int y) {
    return x >= 0 && x < r && y >= 0 && y < c;
}

int main() {
    cin >> r >> c;
    queue<pair<int, int>> waterQueue;
    queue<pair<int, int>> swanQueue, nextSwanQueue;

    for (int i = 0; i < r; i++) {
        cin >> arr[i];
        for (int j = 0; j < c; j++) {
            if (arr[i][j] == 'L') {
                if (swanx1 == 0 && swany1 == 0) {
                    swanx1 = i;
                    swany1 = j;
                } 
                else {
                    swanx2 = i;
                    swany2 = j;
                }
                arr[i][j] = '.'; // set swan = water
                waterQueue.push({i, j});
            } else if (arr[i][j] == '.') {
                waterQueue.push({i, j}); // save water position
            }
        }
    }

    swanQueue.push({swanx1, swany1}); 
    swanVisited[swanx1][swany1] = true; 

    int days = 0;

    while (true) {
        while (!swanQueue.empty()) { // CAN TWO SWANs MET ??
            int x = swanQueue.front().first;
            int y = swanQueue.front().second;
            swanQueue.pop();

            for (int i = 0; i < 4; i++) {
                int nx = x + dx[i];
                int ny = y + dy[i];

                if (isValid(nx, ny) && !swanVisited[nx][ny]) { // consider the first visit & Bound
                    swanVisited[nx][ny] = true; // add new position that swan can visit

                    if (nx == swanx2 && ny == swany2) { // if two swan can met : END
                        cout << days << "\n";
                        return 0; 
                    }

                    if (arr[nx][ny] == '.') { // can visit thie iterate : push current queue
                        swanQueue.push({nx, ny});
                    } 
                    else if (arr[nx][ny] == 'X') { // can't visit now but can visit next time (it'll melt next day) : push future queue
                        nextSwanQueue.push({nx, ny});
                    }
                }
            }
        }
        // if two swan cannot met : melting ice
        int watersize = waterQueue.size();
        for (int i = 0; i < watersize; i++) {
            int x = waterQueue.front().first;
            int y = waterQueue.front().second;
            waterQueue.pop();

            for (int j = 0; j < 4; j++) {
                int nx = x + dx[j];
                int ny = y + dy[j];

                if (isValid(nx, ny) && arr[nx][ny] == 'X') {
                    arr[nx][ny] = '.'; // melt ! change the value
                    waterQueue.push({nx, ny}); // more search : BFS
                }
            }
        }

        swanQueue = nextSwanQueue; // super crack zz : get future queue to current queue : consider duplicate !!!!!!!
        while (!nextSwanQueue.empty()) {
            nextSwanQueue.pop();
        }
        days++;
    }
}
