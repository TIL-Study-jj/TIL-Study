#include <iostream>
#include <map>
#include <algorithm>
#include <vector>
using namespace std;
map<int, pair<int, int>> sorting;

bool compare(int a, int b){
    if(sorting[a].first == sorting[b].first) return sorting[a].second < sorting[b].second;
    return sorting[a].first > sorting[b].first;
}


int main(){
    int n, c;
    cin >> n >> c;
    vector<int> vc(n, 0);
    for(int i = 0; i < n; i++){
        cin >> vc[i];
        if(sorting.count(vc[i])){ // is exist
            sorting[vc[i]].first++;
        }
        else{
            sorting[vc[i]] = make_pair(1, i);
        }
    }
    // for(auto i = sorting.begin(); i != sorting.end(); i++){
    //     cout << i->first << " : " << i->second.first << ", " << i->second.second << "\n";
    // }
    sort(vc.begin(), vc.end(), compare);
    for(int i = 0; i < n; i++){
        cout << vc[i] << " ";
    }
    
    return 0;
}