#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
int main(){
    int n, k;    
    cin >> n >> k;
    vector<int> vec (n, 0);
    vector<int> subvec (n - k + 1, 0);
    int num;
    int subnum;
    for(int i = 0; i < n; i++){
        cin >> num;
        vec[i] = num;
        if(i == k - 1){
            for(int j = 0; j <= i; j++){
                subvec[0] += vec[j];
            }
            subnum = vec[0];
        }
        else if(i >= k){
            subvec[i-k+1] = subvec[i-k] + num - subnum;
            subnum = vec[i-k+1];
        }
    }
    
    cout << *max_element(subvec.begin(), subvec.end()); // i'll never use for loop to get max element
}