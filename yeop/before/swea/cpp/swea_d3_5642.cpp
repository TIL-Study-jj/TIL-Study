#include <iostream>
#include <vector>
using namespace std;

int main(){
    int tc;
    cin >> tc;
    int n;
    for(int i = 1; i < tc + 1; i++){
        cin >> n;
        vector<int> vec (n, 0);
        int num;
        int mnum = -10000;
        for(int j = 0; j < n; j++){
            cin >> num;
            if(j == 0){
                vec[j] = num;    
            }
            else{
                if (vec[j-1] < 0){
                    vec[j] = num;
                }
                else{
                    vec[j] = num + vec[j - 1];
                }
            }
            if (vec[j] > mnum){
                mnum = vec[j];
            }
        }
        cout << "#" << i << " " << mnum << endl;
        
    }
}