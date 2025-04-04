#include <iostream>
#include <vector>
using namespace std;
//vector<vector<int>> TZFE;

void PLAY(int cur, int end, int& ans, int l, int(&TZFE)[20][20]) {
    if (cur == end) {
        for (int i = 0; i < l; i++) {
            for (int j = 0; j < l; j++) {
                if (TZFE[i][j] > ans) {
                    ans = TZFE[i][j];
                }
            }
        }
        return;
    }
    // 여기에 상하좌우 스와이핑하는거 고고
    int CURARR[20][20] = { 0 };

    // MOVE UP
    for (int i = 0; i < l; i++) {
        vector<int>subvec(l, 0); int subvecidx = 0;
        for (int j = 0; j < l; j++) {
            if (TZFE[j][i] != 0) {
                subvec[subvecidx] = TZFE[j][i];
                subvecidx++;
            }
        }
        // MERGE
        for (int j = 0; j < subvecidx - 1; j++) {
            if (subvec[j] == subvec[j + 1]) {
                subvec[j] = 2 * subvec[j];
                subvec[j + 1] = 0;
            }
        }
        // 땡겨서 저장
        int saveidx = 0;
        for (int j = 0; j < l; j++) {
            if (subvec[j] != 0) {
                CURARR[saveidx][i] = subvec[j];
                saveidx++;
            }
        }
        for (int j = saveidx; j < l; j++) {
            CURARR[j][i] = 0;
        }
        subvec.clear();
    }
    /*
    cout << "iterate " << cur << "\n";
    for (int i = 0; i < l; i++) {
        for (int j = 0; j < l; j++) {
            cout << CURARR[i][j] << " ";
        }
        cout << "\n";
    }
    cout << "\n";
    */
    PLAY(cur + 1, end, ans, l, CURARR);
    // MOVE DOWN : 얘는 아래로 땡겨야 되고 (위에는 위로 정렬했지만 얜 아래)
    
    for (int i = 0; i < l; i++) {
        vector<int>subvec(l, 0); int subvecidx = l-1;
        for (int j = l - 1; j >= 0; j--) {
            if (TZFE[j][i] != 0) {
                subvec[subvecidx] = TZFE[j][i];
                subvecidx--;
            }
        }
        // MERGE
        for (int j = l - 1; j > subvecidx; j--) {
            if (j >= 1 && subvec[j] == subvec[j - 1]) {
                subvec[j] = 2 * subvec[j];
                subvec[j - 1] = 0;
            }
        }
        // 땡겨서 저장
        int saveidx = l - 1;
        for (int j = l - 1; j >= 0; j--) {
            if (subvec[j] != 0) {
                CURARR[saveidx][i] = subvec[j];
                saveidx--;
            }
        }
        for (int j = saveidx; j >= 0; j--) {
            CURARR[j][i] = 0;
        }
        subvec.clear();
    }
    /*
    cout << "iterate " << cur << "\n";
    for (int i = 0; i < l; i++) {
        for (int j = 0; j < l; j++) {
            cout << CURARR[i][j] << " ";
        }
        cout << "\n";
    }
    cout << "\n";
    */
    PLAY(cur + 1, end, ans, l, CURARR);
    
    // MOVE LEFT : 얘는 왼쪽으로 ..
    for (int i = 0; i < l; i++) {
        vector<int>subvec(l, 0); int subvecidx = 0;
        for (int j = 0; j < l; j++) {
            if (TZFE[i][j] != 0) {
                subvec[subvecidx] = TZFE[i][j];
                subvecidx++;
            }
        }
        // MERGE
        for (int j = 0; j < subvecidx - 1; j++) {
            if (j + 1 < l && subvec[j] == subvec[j + 1]) {
                subvec[j] = 2 * subvec[j];
                subvec[j + 1] = 0;
            }
        }
        // 땡겨서 저장
        int saveidx = 0;
        for (int j = 0; j < l; j++) {
            if (subvec[j] != 0) {
                CURARR[i][saveidx] = subvec[j];
                saveidx++;
            }
        }
        for (int j = saveidx; j < l; j++) {
            CURARR[i][j] = 0;
        }
        subvec.clear();
    }
    /*
    cout << "iterate " << cur << "\n";
    for (int i = 0; i < l; i++) {
        for (int j = 0; j < l; j++) {
            cout << CURARR[i][j] << " ";
        }
        cout << "\n";
    }
    cout << "\n";
    */
    PLAY(cur + 1, end, ans, l, CURARR);
    
    
    // MOVE RIGHT : 얘는 오른쪽으로 ...
    for (int i = 0; i < l; i++) {
        vector<int>subvec(l, 0); int subvecidx = l - 1;
        for (int j = l - 1; j >= 0; j--) {
            if (TZFE[i][j] != 0) {
                subvec[subvecidx] = TZFE[i][j];
                subvecidx--;
            }
        }
        // MERGE
        for (int j = l - 1; j > subvecidx; j--) {
            if (j >= 1 && subvec[j] == subvec[j - 1]) {
                subvec[j] = 2 * subvec[j];
                subvec[j - 1] = 0;
            }
        }
        // 땡겨서 저장
        int saveidx = l - 1;
        for (int j = l - 1; j >= 0; j--) {
            if (subvec[j] != 0) {
                CURARR[i][saveidx] = subvec[j];
                saveidx--;
            }
        }
        for (int j = saveidx; j >= 0; j--) {
            CURARR[i][j] = 0;
        }
        subvec.clear();
    }
    /*
    cout << "iterate " << cur << "\n";
    for (int i = 0; i < l; i++) {
        for (int j = 0; j < l; j++) {
            cout << CURARR[i][j] << " ";
        }
        cout << "\n";
    }
    cout << "\n";
    */
    PLAY(cur + 1, end, ans, l, CURARR);
    
}

int main() {
    int n; cin >> n;
    //TZFE.resize(n, vector<int>(n, 0));
    int TZFE[20][20] = { 0 };
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> TZFE[i][j];
        }
    }

    /*for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cout << TZFE[i][j] << " ";
        }
        cout << "\n";
    }*/
    int ans = 0;
    PLAY(0, 5, ans, n, TZFE);
    cout << ans;
}