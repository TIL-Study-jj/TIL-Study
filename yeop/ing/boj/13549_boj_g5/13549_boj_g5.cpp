#include <iostream>
#include <queue>
#include <vector>
using namespace std;

int main() {
    int n, k;
    cin >> n >> k;

    if (n >= k) {
        cout << n - k;
        return 0;
    }

    vector<int> HIDENSICK(100001, -1);
    queue<int> q;
    
    HIDENSICK[n] = 0;
    q.push(n);

    while (!q.empty()) {
        int cur = q.front();
        q.pop();

        int nextTime = HIDENSICK[cur] + 1;

        for (int i = cur * 2; i <= 100000 && HIDENSICK[i] == -1; i *= 2) {
            HIDENSICK[i] = HIDENSICK[cur];
            q.push(i);
        }

        for (int next : {cur - 1, cur + 1}) {
            if (next >= 0 && next <= 100000 && HIDENSICK[next] == -1) {
                HIDENSICK[next] = nextTime;
                q.push(next);
            }
        }

        if (HIDENSICK[k] != -1) {
            cout << HIDENSICK[k];
            return 0;
        }
    }
}
