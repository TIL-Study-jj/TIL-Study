#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main(){
    int tc;
    int n, k;
    int num;
    int ans;
    cin >> tc;
    for(int i = 1; i < tc + 1; i++){
        cin >> n >> k;
        vector<int> vec (n, 0);
        for(int j = 0; j < n; j++){
            cin >> num;
            vec[j] = num;
        }
        sort(vec.begin(), vec.end());
        
        if(vec.size() == k){
            ans = vec[n-1] - vec[0];
        }
        else{
            ans = vec[k-1] - vec[0];
            for(int j = 1; j < n - k + 1; j++){
                if (ans > (vec[j + k - 1] - vec[j])){
                    ans = vec[j + k - 1] - vec[j];
                }
            }
        }
        cout << "#" << i << " " << ans << endl;
    }
    return 0;
}