#include <iostream>
#include <map>
using namespace std;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int n, num;
    map<int, int> mp;
    cin >> n;
    for(int i = 0; i < n; i++){
        cin >> num;
        mp[num]++;
    }
    for(auto i = mp.begin(); i != mp.end(); i++){
        for(int j = 0; j < i->second; j++){
            cout << i->first << "\n";
        }
    }
}