#include <bits/stdc++.h>
using namespace std;

int tn, n;
string k, k1;


int main(){
    cin >> tn;
    for(int i = 0; i<tn;i++){
        map<string,int> clothes;
        cin >> n;
        for(int j = 0; j<n; j++){
            cin >> k >> k1;
            clothes[k1] = clothes[k1] + 1;
        }
        // 각 clothes value+1 끼리 곱해서 1 빼줌
        long long ret = 1;
        for(auto j : clothes){
            ret = ret * (j.second+1);
        }
        ret--;
        cout << ret << "\n";
    }
    return 0;
}