#include <iostream>
#include <queue>
#include <tuple>
#include <map>
using namespace std;
int main() {
    int n;
    cin >> n;
    queue<tuple<int, int, int>> q;
    map<pair<int, int>, int> visited;  // (이모티콘 개수, 클립보드 개수) -> 시간
    q.push({1, 0, 0});
    visited[{1, 0}] = 0;

    while (!q.empty()) {
        int pn = get<0>(q.front());
        int pc = get<1>(q.front());
        int pt = get<2>(q.front());
        q.pop();
        if (pn == n) {
            cout << pt << "\n";
            return 0;
        }

        if (visited.find({pn, pn}) == visited.end()) { // Ctrl + C
            visited[{pn, pn}] = pt + 1;
            q.push({pn, pn, pt + 1});
        }

        if (pc > 0 && pn + pc <= 2 * n && visited.find({pn + pc, pc}) == visited.end()) { // Ctrl + V
            visited[{pn + pc, pc}] = pt + 1;
            q.push({pn + pc, pc, pt + 1});
        }

        if (pn > 1 && visited.find({pn - 1, pc}) == visited.end()) { // delete
            visited[{pn - 1, pc}] = pt + 1;
            q.push({pn - 1, pc, pt + 1});
        }
    }

    return 0;
}