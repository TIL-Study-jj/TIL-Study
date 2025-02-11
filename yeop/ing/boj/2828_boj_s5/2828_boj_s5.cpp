#include <iostream>
using namespace std;
int main(){
    int n, m;
    cin >> n >> m;
    int lp = 1;
    int rp = m;
    int tc;
    cin >> tc;
    int num, dist;
    int movcnt = 0;
    for(int i = 0; i < tc; i++){
        cin >> num;
        if(lp > num || num > rp){
            if(lp > num){
                dist = lp - num;
                movcnt += dist;
                lp -= dist;
                rp -= dist;
            }
            else{
                dist = num - rp;
                movcnt += dist;
                lp += dist;
                rp += dist;
            }
        }
        // cout << movcnt << "\n";
        // cout << "num : " << num << " lp : " << lp << " rp : " << rp << " mov : " << movcnt << "\n";
    }
    cout << movcnt;
    return 0;
}