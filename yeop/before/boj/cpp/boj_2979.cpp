#include <iostream>
#include <map>
using namespace std;
int main(){
    map<int, int> parkq;
    int a, b, c;
    cin >> a >> b >> c;
    int t1, t2;
    for(int i = 0; i < 3; i++){
        cin >> t1 >> t2;
        for(int j = t1; j < t2; j++){
            parkq[j]++;
        }
    }
    int tots = 0;
    for(auto i = parkq.begin(); i != parkq.end(); i++){
        if(i->second != 0){
            if(i->second == 1){
                tots += a;
            }
            else if(i->second == 2){
                tots += 2*b;
            }
            else if(i->second == 3){
                tots += 3*c;
            }
            
        }
    }
    cout << tots;
}