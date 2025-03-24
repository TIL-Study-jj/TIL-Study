#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
int main(){
    int n, st, ed;
    vector<pair<int, int>> vc1;
    
    cin >> n;
    for(int i = 0; i < n; i++){
        cin >> st >> ed;
        vc1.push_back(make_pair(ed, st));
    }
    sort(vc1.begin(), vc1.end());
    int count = 1;
    int target = vc1[0].first;
    for(int i = 1; i < n; i++){
        if(vc1[i].second >= target){
            count++;
            target = vc1[i].first;
        }
    }
    cout << count;
}