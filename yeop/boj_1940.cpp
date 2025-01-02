#include <iostream>
#include <algorithm>
#include <deque>
using namespace std;

int main(){
    int n, m;
    cin >> n >> m;
    deque<int> dq (n, 0);
    int num;
    for(int i = 0; i < n; i++){
        cin >> num;
        dq[i] = num;
    }
    sort(dq.begin(), dq.end());
    int jm = 0;
    while(true){
        if(dq.size() <= 1){
            break;
        }
        num = dq.front() + dq.back();
        if(num == m){ // pop both (back, front)
            jm += 1;    
            dq.pop_front();
            dq.pop_back();
        }
        else{
            if(num > m){ // pop back
                dq.pop_back();
            }
            else{ // pop front
                dq.pop_front();
            }
        }
    }
    cout << jm;
}