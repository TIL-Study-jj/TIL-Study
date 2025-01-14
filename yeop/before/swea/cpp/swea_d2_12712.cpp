#include <iostream>
#include <vector>
using namespace std;
int main(){
    int iter;
    cin >> iter;
    for(int i = 1; i < iter + 1; i++){
        int kill_max = 0;
        int n, m;
        cin >> n >> m;
        vector<vector<int>> mos (n, vector<int> (n, 0));
        
        int mosquitto;
        for(int j = 0; j < n; j++){
            for(int k = 0; k < n; k++){
                cin >> mosquitto;
                mos[j][k] = mosquitto;
            }
        }
        
        int x_shoot, p_shoot;
        for(int j = 0; j < n; j++){
            for(int k = 0; k < n; k++){
                x_shoot = -mos[j][k];
                p_shoot = -mos[j][k];
                
                for(int x = -m+1; x<m; x++){
                    if (0 <= j+x && j+x < n){
                        x_shoot += mos[j+x][k];
                    }
                    if (0 <= k+x && k+x < n){
                        x_shoot += mos[j][k+x];
                    }
                }
                
                for(int x = -m+1; x<m; x++){
                    if (0 <= j+x && j+x < n && 0 <= k+x && k+x < n){
                        p_shoot += mos[j+x][k+x];
                    }
                    if (0 <= j-x && j-x < n && 0 <= k+x && k+x < n){
                        p_shoot += mos[j-x][k+x];
                    }
                }
                
                if(kill_max < x_shoot){
                    kill_max = x_shoot;
                }
                if(kill_max < p_shoot){
                    kill_max = p_shoot;
                }
            }
        }
        cout << "#" << i << " " << kill_max << endl;
    }
}