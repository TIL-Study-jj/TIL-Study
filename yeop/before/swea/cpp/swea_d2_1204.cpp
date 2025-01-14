#include <iostream>
#include <map>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    int iter;
    cin >> iter;
    for (int i = 0; i < iter; i++) {
        int number;
        cin >> number;
        map<int, int> scoremap;
        for (int j = 0; j < 1000; j++) {
            int score;
            cin >> score;
            scoremap[score] += 1;
        }

        vector<pair<int, int>> sv(scoremap.begin(), scoremap.end());

        sort(sv.begin(), sv.end(), [](const pair<int, int>& a, const pair<int, int>& b) {return a.second > b.second;}); // value 기준 정렬
        
        int maxnum = 0;
        vector<int> least;
        
        for (const auto& entry : sv) {
            if (maxnum <= entry.second){
                maxnum = entry.second;
                least.push_back(entry.first);
            }
            else{
                break;
            }
        }
        sort(least.begin(), least.end());
        cout << "#" << number << " "<<least[least.size()-1] << '\n';
    }
    return 0;
}

