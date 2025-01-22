#include <iostream>
using namespace std;

int main() {
    int x, y, sx, sy, n;
    int linelen = 0;
    cin >> n;
    for(int i = 0; i < n; i++){
        cin >> x >> y;
        if(i == 0){ // init
            sx = x;
            sy = y;
        }
        else{
            if(sy < x){ // line is broken : add before line length and new init
                linelen += (sy - sx);
                sx = x;
                sy = y;
            }
            else{ // line continues : update new right coordinates (left fixed)
                if(sy < y){
                    sy = y;
                }
            }
        }
        // cout << sx << " " << sy << "\n";
    }
    linelen += (sy - sx);
    
    cout << linelen;
    
    return 0;
}