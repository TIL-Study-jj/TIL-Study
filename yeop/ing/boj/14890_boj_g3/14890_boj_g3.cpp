#include <iostream>
#include <vector>
using namespace std;
int main(){
    int n, l;
    cin >> n >> l;
    vector<vector<int>> vecmap (n, vector<int>(n, 0));
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            cin >> vecmap[i][j];
        }
    }
    
    
    int ans = 0;
    // get possible horizontal
    for(int i = 0; i < n; i++){
        bool possible = true;
        int ramp = -1;
        for(int j = 1; j < n; j++){
            int temp = vecmap[i][j];
            int befo = vecmap[i][j-1];
            if (!possible){
                break;
            }
            if(temp != befo){
                if(befo + 1 == temp && ramp < j - l){ // place ramp before
                    ramp = j - 1;
                    // cout << "horizontal after ramp location is " << i << " " << ramp << "\n";
                }
                else if(befo - 1 == temp && ramp < j && j + l <= n){ // place ramp after
                    for(int k = j + 1; k < j + l; k++){
                        if(temp != vecmap[i][k]){
                            possible = false;
                            break;
                        }
                    }
                    if(possible){
                        ramp = j + l - 1;
                        // cout << "horizontal after ramp location is " << i << " " << ramp << "\n";
                    }
                }
                else{
                    possible = false;
                    break;
                }
            }
        }
        if(possible){
            // cout << "horizontal possible when i is" << i << "\n";
            ans++;
        }
    }
    // cout << ans << "\n";
    // get possible vertical
    for(int i = 0; i < n; i++){
        bool possible = true;
        int ramp = -1;
        for(int j = 1; j < n; j++){
            int temp = vecmap[j][i];
            int befo = vecmap[j-1][i];
            if (!possible){
                break;
            }
            if(temp != befo){
                if(befo + 1 == temp && ramp < j - l){ // place ramp before
                    ramp = j - 1;
                    // cout << "vertical after ramp location is " << ramp << " " << i << "\n";
                }
                else if(befo - 1 == temp && ramp < j && j + l <= n){ // place ramp after
                    for(int k = j + 1; k < j + l; k++){
                        if(temp != vecmap[k][i]){
                            possible = false;
                            break;
                        }
                    }
                    if(possible){
                        ramp = j + l - 1;
                        // cout << "vertical after ramp location is " << ramp << " " << i << "\n";
                    }
                }
                else{
                    possible = false;
                    break;
                }
            }
        }
        if(possible){
            // cout << "vertical possible when i is" << i << "\n";
            ans++;
        }
    }
    cout << ans;
}