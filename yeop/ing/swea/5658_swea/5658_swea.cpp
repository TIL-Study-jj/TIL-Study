#include <iostream>
#include <vector>
#include <string>
#include <cmath>
#include <map>
using namespace std;
 
map<char, int> cvt16210 = {
    {'0', 0}, {'1', 1}, {'2', 2}, {'3', 3}, {'4', 4}, 
    {'5', 5}, {'6', 6}, {'7', 7}, {'8', 8}, {'9', 9}, 
    {'A', 10}, {'B', 11}, {'C', 12}, {'D', 13}, {'E', 14}, {'F', 15}
};
 
 
int biggest16(string arr[], int target, int stlen){
    map<int, int> mp; // use to sort and find the 'k' biggest bum
    int converted;
    for(int i = 0; i < stlen; i++){
        converted = 0;
        for(int j = 0; j < stlen / 4; j++){
            converted += cvt16210[arr[i][j]] * pow(16, (stlen / 4) - j - 1);
        }
        mp[converted] = 1;    
    }
    vector<int> finalvec;
    for(auto i = mp.begin(); i != mp.end(); i++){
        finalvec.push_back(i->first);
    }
    // for(int i = 0; i < finalvec.size(); i++){
    //     cout << finalvec[i] << " ";
    // }
    return finalvec[finalvec.size() - target];
}
 
 
 
int main(){
    int tc;
    cin >> tc;
    for(int t = 1; t <= tc; t++){
        int n, k;
        string s;
        cin >> n >> k >> s;
         
        string strarr[n];
        for(int i = 0; i < n; i++){
            string subst = "";
            for(int j = 0; j < n/4; j++){
                subst += s[(i+j)%n];
            }
            strarr[i] = subst;
        }
        cout << "#" << t << " " << biggest16(strarr, k, n) << "\n";   
    }
}