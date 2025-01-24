#include <iostream>
using namespace std;

int main(){
    int tc;
    cin >> tc;
    int n, m, targetnum, two;
    bool onoff;
    for(int i = 1; i < tc + 1; i++){
        cin >> n >> m;
        targetnum = 0;
        two = 1;
        for(int j = 0; j < n; j++){
            targetnum += two;
            two *= 2;
        }
        while(true){
            if (m == targetnum){
                onoff = true;
                break;
            }
            else if (m < targetnum){
                onoff = false;
                break;
            }
            else{ // decrease m : the largest 2^x that smaller than m
                two = 1;
                while(true){
                    if (two > m){
                        break;
                    }
                    else{
                        two *= 2;
                    }
                }
                m -= (two/2);
            }
        }
        if (onoff){
            cout << "#" << i << " ON" << endl;    
        }
        else{
            cout << "#" << i << " OFF" << endl;
        }
        
    }
}