#include <iostream>
#include <deque>

using namespace std;

int main(){
    int n;
    cin >> n;
    int vs;
    int num;
    long long plus, minus, minuscnt;
    int me;
    for(int i = 1; i < n+1; i++){
        cin >> vs;
        deque<int> dq;
        me = 0;
        for(int j = 0; j < vs; j++){
            cin >> num;
            dq.push_back(num);
            if (num > me){ // find max element
                me = num;
            }
        }
        plus = 0;
        minus = 0;
        minuscnt = 0;
        int popn;
        for(int j = 0; j < vs; j++){
            popn = dq.front();
            dq.pop_front();
            if (popn < me){ // if popped element is lower than max element : buy it
                minus -= popn;
                minuscnt += 1;
            }
            else if (popn == me){ // if popped element is max element
                if(minuscnt > 0){ // if you bought some element before : sell everything
                    plus += (minuscnt*popn) + minus;
                    minuscnt = 0;
                    minus = 0;
                }
                me = 0;
                for(int k = 0; k < dq.size(); k++){ // find new max element
                    if (dq[k] > me){
                        me = dq[k];
                    }
                }
            }
        }
        cout << "#" << i << " " << plus << endl;
    }
}
