#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <algorithm>
using namespace std;
int main()
{   
    int num;
    cin >> num;
    string s;
    map<char, int> se;
    for(int i = 0; i < num; i++){
        cin >> s;
        se[s[0]] += 1;
    }
    string player = "";
    for(auto i = se.begin(); i != se.end(); i++){
        if(i->second >= 5){
           player += i->first;
        }
        // cout << i->first << " " << i->second << endl;
    }
    if(player.size() == 0){
        cout << "PREDAJA";
    }
    else{
        sort(player.begin(), player.end());
        cout << player;
    }
    
    return 0;
}