#include <iostream>
using namespace std;
int main(){
    int tc;
    cin >> tc;
    int c1, c2, c3;
    int cnt;
    for(int i = 0; i < tc; i++){
        cin >> c1 >> c2 >> c3;
        cnt = 0;
        while(true){
            if(c1*c2*c3 == 0){
                cnt = -1;
                break;
            }
            else if(c1 < c2 && c2 < c3){
                break;
            }
            else{
                if(c1 >= c2){
                    c1 -= 1;
                    cnt += 1;
                }
                else{
                    if(c2 >= c3){
                        c2 -= 1;
                        cnt += 1;
                    }
                }
            }
        }
        cout << "#" << i+1 << " " << cnt << endl;
    }
    return 0;
}