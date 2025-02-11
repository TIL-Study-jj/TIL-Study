#include <iostream>
#include <cmath>
using namespace std;

void findseq(int cur_oneside, int r, int c, int cur_ltx, int cur_lty, int &seq) {
    if (cur_oneside == 1) {
        return;
    }

    int half = cur_oneside / 2;

    if (r < cur_ltx + half && c < cur_lty + half) { 
        findseq(half, r, c, cur_ltx, cur_lty, seq);
    } 
    else if (r < cur_ltx + half && c >= cur_lty + half) { 
        seq += half * half;
        findseq(half, r, c, cur_ltx, cur_lty + half, seq);
    } 
    else if (r >= cur_ltx + half && c < cur_lty + half) {
        seq += 2 * half * half;
        findseq(half, r, c, cur_ltx + half, cur_lty, seq);
    } 
    else {
        seq += 3 * half * half;
        findseq(half, r, c, cur_ltx + half, cur_lty + half, seq);
    }
}

int main() {
    int n, r, c;
    cin >> n >> r >> c;

    int seq = 0;
    int oneside = (int)pow(2, n);
    findseq(oneside, r, c, 0, 0, seq); 
    cout << seq; 
    return 0;
}
