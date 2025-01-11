#include <bits/stdc++.h>
using namespace std;

const int dy[] = {-1,0,1,0};
const int dx[] = {0,1,0,-1};

int main(){
    int y = 0, x = 0;
    for(int i = 0; i< 4; i++){ // 시계방향으로 탐색 ( 위 오른쪽 아래 왼쪽 )
        int ny = y + dy[i];
        int nx = x + dx[i];
        cout << ny << " : " << nx << "\n";
    }
    return 0; 
}