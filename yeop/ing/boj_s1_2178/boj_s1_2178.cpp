#include <iostream>
#include <vector>
#include <queue>
#include <string>
#include <tuple>
using namespace std;
int main() {
	int n, m;
	cin >> n >> m;
	vector<vector<int>> mp(n, vector<int>(m, 0));
	string s;
	for (int i = 0; i < n; i++) { // create vector map
		cin >> s;
		for (int j = 0; j < m; j++) {
			mp[i][j] = s[j] - '0';
		}
	}
	queue<tuple<int, int, int>> q;
	vector<vector<bool>> visited(n, vector<bool>(m, true));
	q.push(make_tuple(0, 0, 1));
	int px, py, nx, ny, dist;
	int dx[4] = { 0, 0, 1, -1 };
	int dy[4] = { 1, -1, 0, 0, };
	visited[0][0] = false;
	while (true) {
		px = get<0>(q.front());
		py = get<1>(q.front());
		dist = get<2>(q.front());
		q.pop();
		if ((px == n - 1) && (py == m - 1)) {
			cout << dist;
			break;
		}
		for (int i = 0; i < 4; i++) {
			nx = px + dx[i];
			ny = py + dy[i];
			
			if ((0 <= nx && nx < n) && (0 <= ny && ny < m) && (visited[nx][ny]) && (mp[nx][ny] == 1)) {
				visited[nx][ny] = false;
				q.push(make_tuple(nx, ny, dist + 1));
			}
		}
	}
}