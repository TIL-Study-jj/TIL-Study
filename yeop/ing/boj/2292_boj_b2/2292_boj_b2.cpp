#include <iostream>
using namespace std;
int main(){
    int leftpointer = 1, rightpointer = 1, len = 0, increase = 6;
    int roomnum;
    cin >> roomnum;
    while(true){
        if(leftpointer <= roomnum && roomnum <= rightpointer){
            len++;
            break;
        }
        leftpointer = rightpointer + 1;
        rightpointer += increase;
        increase += 6;
        len++;
    }
    cout << len;
    return 0;
}