#include <bits/stdc++.h>
using namespace std;

int h,w;
char m[100][100];
int result[100][100];
int visited[100][100];
string s;



int main(){
    memset(result,-1,sizeof(result));
    
    cin >> h >> w;
    for(int i = 0; i<h; i++){
        cin >> s;
        for(int j = 0; j<s.size();j++){
            m[i][j] = s[j];
        }
    }

    for(int i = 0; i<w ; i++){
        for(int j = 0; j < h; j++){
            for(int k = 0; k < w; k++){
                if(m[j][k] == 'c'){
                    if(visited[j][k] != 1){
                        result[j][k] = i;
                        visited[j][k] = 1;
                    }
                }
            }
        }
    }
    

    for(int i = 0; i < h ; i++){
        for(int j = 0; j < w ; j++){
            cout << result[i][j] << " ";
        }
        cout << "\n";
    }
    return 0;
}

// 특정값으로 채워져있는 배열 선언 방법
// 