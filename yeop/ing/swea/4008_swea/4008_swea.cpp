#include <iostream>
#include <vector>
#include <string>
#include <cmath>
#include <map>
using namespace std;
 
void findminmax(int level, int limit, int c_num, int & mini, int & maxi, int * number, int * operate){
    if(level == limit){
        if(c_num < mini){
            mini = c_num;
        }
        if(c_num > maxi){
            maxi = c_num;
        }
        return;
    }
    if(operate[0] != 0){
        operate[0] -= 1;
        findminmax(level + 1, limit, c_num + number[level], mini, maxi, number, operate);
        operate[0] += 1;
    }
    if(operate[1] != 0){
        operate[1] -= 1;
        findminmax(level + 1, limit, c_num - number[level], mini, maxi, number, operate);
        operate[1] += 1;
    }
    if(operate[2] != 0){
        operate[2] -= 1;
        findminmax(level + 1, limit, c_num * number[level], mini, maxi, number, operate);
        operate[2] += 1;
    }
    if(operate[3] != 0){
        operate[3] -= 1;
        findminmax(level + 1, limit, c_num / number[level], mini, maxi, number, operate);
        operate[3] += 1;
    }
}
 
 
int main(){
    int tc;
    cin >> tc;
    for(int t = 1; t <= tc; t++){
        int minval = 100000000;
        int maxval = -100000000;
        int n;
        int compute[4] = {0};
        int arr[12] = {0};
        cin >> n >> compute[0] >> compute[1] >> compute[2] >> compute[3];
        for(int i = 0; i < n; i++){
            cin >> arr[i];
        }
        findminmax(1, n, arr[0], minval, maxval, arr, compute);
        cout << "#" << t << " " << maxval-minval << "\n";   
    }
}