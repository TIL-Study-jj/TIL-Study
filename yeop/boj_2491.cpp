#include <iostream>
#include <vector>
using namespace std;
int main(){
    int n;
    cin >> n;
    // vector<int> vec;
    vector<int> vec_i (n, 1);
    vector<int> vec_d (n, 1);
    int num, bnum;
    int i_idx = 1;
    int d_idx = 1;
    for(int i = 0; i < n; i++){
        cin >> num;
        if(i != 0){
            if(bnum < num){
                i_idx++;
                d_idx = 1;
                vec_i[i] = i_idx;
                vec_d[i] = d_idx;
            }
            else if(num < bnum){
                d_idx++;
                i_idx = 1;
                vec_i[i] = i_idx;
                vec_d[i] = d_idx;
            }
            else{
                d_idx++;
                i_idx++;
                vec_i[i] = i_idx;
                vec_d[i] = d_idx;
            }
        }
        bnum = num;
    }
    int maxnum = 0;
    for(int i = 0; i < n; i++){ // just using max(container) .. is more better. but i can't remember lol
        if(vec_i[i] > maxnum){ 
            maxnum = vec_i[i];
        }
        if(vec_d[i] > maxnum){
            maxnum = vec_d[i];
        }
    }
    cout << maxnum;
}