#include <iostream>
#include <vector>
#include <string>
using namespace std;

int main(){
    int iter;
    cin >> iter;
    
    for(int k = 1; k < iter + 1; k++){
        int n;
        cin >> n;
        
        vector<vector<int>> vec(n, vector<int>(n, 0));
        // vector<vector<int>> vec;
        
        int num;
        for(int i = 0; i < n; i++){
            for(int j = 0; j < n; j++){
                cin >> num;
                vec[i][j] = num;
            }
        }
        
        vector<vector<string>> n_vec(n, vector<string>(3, ""));
        
        string num_s= "";
        
        for(int i = 0; i < n; i++){
            num_s = "";
            for(int j = n-1; j >= 0; j--){
                num_s += to_string(vec[j][i]);
            }
            n_vec[i][0] = num_s;
        }
        
        for(int i = n-1; i >= 0; i--){
            num_s = "";
            for(int j = n-1; j >= 0; j--){
                num_s += to_string(vec[i][j]);
            }
            n_vec[n-i-1][1] = num_s;
        }
        
        for(int i = n-1; i >= 0; i--){
            num_s = "";
            for(int j = 0; j < n; j++){
                num_s += to_string(vec[j][i]);
            }
            n_vec[n-i-1][2] = num_s;
        }
        
        cout <<"#" << k << endl;
        for(int i = 0; i < n; i++){
            for(int j = 0; j < 3; j++){
                cout << n_vec[i][j] << " ";
            }
            cout << endl;
        }
    }
    return 0;
}