#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int main(){
    // if i used combinations .. it'll be better
    int arr[9];
    int num;
    int tsum = 0;
    for(int i = 0; i < 9; i++){
        cin >> num;
        arr[i] = num;
        tsum += num;
    }
    vector <int> vec (9, 0);
    bool found = false;
    for(int i = 0; i < 9; i++){
        if (found){
            break;
        }
        for(int j = i + 1; j < 9; j ++){
            if (tsum - arr[i] - arr[j] == 100){
                found = true;
                for(int k = 0; k < 9; k++){
                    if(k != i && k != j){
                        vec[k] = arr[k];
                    }
                    else{
                        vec[k] = 0;
                    }
                }
                break;
            }
        }
    }
    sort(vec.begin(), vec.end());
    for(int i = 2; i < 9; i++){
        cout << vec[i] << endl;
    }
}