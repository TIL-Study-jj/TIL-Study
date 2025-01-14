#include <iostream>
using namespace std;
int main(){
    int ten = 10;
    int len, res;
    char num;
    for(int i = 1; i < ten + 1; i++){
        res = 0;
        cin >> len;
        for(int j = 0; j < len; j++){
            cin >> num;
            if(j % 2 == 0){
                res += num - '0';
            }
        }
        cout << "#" << i << " " << res << endl;
    }
}