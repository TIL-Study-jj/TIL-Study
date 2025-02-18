#include <iostream>
#include <map>
using namespace std;

int paper[10][10];
map<int, int> colorpaper = {{1, 5}, {2, 5}, {3, 5}, {4, 5}, {5, 5}};
int answer = -1;

int getMaxSize(int x, int y) {
    int size = 1;
    while (x + size < 10 && y + size < 10) { 
        for (int i = x; i <= x + size; i++) {
            for (int j = y; j <= y + size; j++) {
                if (paper[i][j] == 0) return size; 
            }
        }
        size++;
    }
    return size;
}

void placePaper(int x, int y, int size, int val) {
    for (int i = x; i < x + size; i++) {
        for (int j = y; j < y + size; j++) {
            paper[i][j] = val;
        }
    }
}

void findPaper(int x, int y, int used) {
    if (x == 10) {
        if (answer == -1 || used < answer) answer = used;
        return;
    }

    int nx = (y == 9) ? x + 1 : x;
    int ny = (y == 9) ? 0 : y + 1;

    if (paper[x][y] == 0) {
        findPaper(nx, ny, used);
        return;
    }

    int maxSize = getMaxSize(x, y);
    
    for (int size = maxSize; size >= 1; size--) {
        if (colorpaper[size] > 0) {
            placePaper(x, y, size, 0);
            colorpaper[size]--;
            
            findPaper(nx, ny, used + 1);
            
            placePaper(x, y, size, 1);
            colorpaper[size]++;
        }
    }
}

int main() {
    answer = -1;
    for (int i = 0; i < 10; i++) {
        for (int j = 0; j < 10; j++) {
            cin >> paper[i][j];
        }
    }
    findPaper(0, 0, 0);
    cout << answer << "\n";
    
}