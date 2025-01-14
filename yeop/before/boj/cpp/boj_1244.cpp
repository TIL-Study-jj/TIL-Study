#include <iostream>
#include <vector>
using namespace std;

int main(){
    
    int n;
    cin >> n;
    vector<int> vec;
    
    int num;
    
    for(int i = 0; i < n; i++){
        cin >> num;
        vec.push_back(num);
    }
    
    int m;
    cin >> m;
    
    int sex;
    
    for(int i = 0; i < m; i++){
        cin >> sex >> num;
        
        if (sex == 1){ // man : change the multiple of number
            for(int j = num - 1; j < n; j = j + num){
                if(vec[j] == 0){
                    vec[j] = 1;
                }
                else{
                    vec[j] = 0;
                }
            }
        }
        else{ // woman : change the longest pair : using 2 pointer?
            int lp = num-1;
            int rp = num-1;
            while (true){
                lp = lp - 1;
                rp = rp + 1;
                if (lp < 0 || rp == n){
                    break;
                }
                else{
                    if (vec[lp] != vec[rp]){
                        break;
                    }
                }
            }
            lp += 1;
            rp -= 1;
            for(int j = lp; j < rp + 1; j++){
                if(vec[j] == 0){
                    vec[j] = 1;
                }
                else{
                    vec[j] = 0;
                }
            }
        }
    }
    
    for(int i = 1; i <= n; i++){
        cout << vec[i-1] << " ";
        if (i % 20 == 0){
            cout << endl;
        }
    }
    
    return 0;
}