#include <iostream>
using namespace std;
int main(){
    int tc;
    cin >> tc;
    int n, k;
    int s, mn;
    for(int i = 0; i < tc; i++){
        cin >> n >> k;
        s = 0;
        mn = 1;
        for(int j = 1; j <= n; j++){
            if(s + j == k){
                s -= mn;
                mn += 1;
            }
            s += j;
        }
        cout << s << endl;
    }
    return 0;
}