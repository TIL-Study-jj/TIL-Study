#include <iostream>
#include <map>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;
int main(){
    int t;
    cin >> t;
    vector<string> sc = {"A+", "A0", "A-", "B+", "B0", "B-", "C+", "C0", "C-", "D0"};
    for(int i = 1; i < t + 1; i++){
        int n, k;
        cin >> n >> k;
        
        vector<int> vec(n, 0);
        map<int, int> scoreboard;
        
        for(int j = 0; j < n; j++){
            int mid, fin, ass;
            cin >> mid >> fin >> ass;
            int tot = mid*35 + fin*45 + ass*20;
            vec[j] = tot;
            scoreboard[j] = tot;
        }
        
        sort(vec.begin(), vec.end());
        
        for(int j = 0; j < n; j++){
            if (vec[j] == scoreboard[k-1]){
                cout <<"#" << i << " " << sc[(int)((n - j - 1)*10/n)] << endl;
                break;
            }
        }
    }
}