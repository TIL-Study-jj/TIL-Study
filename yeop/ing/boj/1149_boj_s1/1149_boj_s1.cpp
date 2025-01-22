#include <iostream>
using namespace std;

int main(){

    int n, sr, sg, sb, ans;
    
    int r = 0;
    int g = 0;
    int b = 0;
    
    cin >> n;
    
    for(int i = 0; i < n; i++){
        cin >> sr >> sg >> sb;
        if(i == 0){
            r = sr;
            g = sg;
            b = sb;
        }
        else{
            if (g > b){ // find small r
                sr += b;
            }
            else{
                sr += g;
            }
            
            if (r > b){ // find small g
                sg += b;
            }
            else{
                sg += r;
            }
            
            if (r > g){ // find small b
                sb += g;
            }
            else{
                sb += r;
            }
            
            r = sr;
            g = sg;
            b = sb;
        }
    }
    if(r <= g && r <= b){
        ans = r;
    }
    else if(g <= r && g <= b){
        ans = g;
    }
    else{
        ans = b;
    }
    
    cout << ans;
    return 0;
}