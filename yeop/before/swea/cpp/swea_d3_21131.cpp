#include <iostream>
#include <vector>

using namespace std;

int main(){
    int tc;
    cin >> tc;
    for(int i = 1; i < tc + 1; i++){
        int n;
        cin >> n;
        vector<vector<int>> vec (n, vector<int>(n, 0));
        int num;
        int tp;
        for(int j = 0; j < n; j++){
            for(int k = 0; k < n; k++){
                cin >> num;
                vec[j][k] = num;
            }
        }
        tp = 0; // transpose count
        bool updown = true; // state
        for(int j = n-1; j > 0; j--){
            if (updown && vec[0][j] != j+1){
                tp += 1;
                updown = !updown; // changing state
            }
            else if (!updown && vec[j][0] != j+1){
                tp += 1;
                updown = !updown; // changing state
            }
        }
        cout << tp << endl;
    }
}
