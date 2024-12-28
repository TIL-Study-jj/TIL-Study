#include <iostream>
#include <queue>
#include <cmath>
using namespace std;

int main() {
    int iter;
    cin >> iter;
    for(int i = 0; i < iter; i++){
        priority_queue<int, vector<int>> q; // max heap queue
        for(int j = 0; j < 10; j++){
            int num;
            cin >> num;
            q.push(num);
        }
        int summ = 0;
        q.pop();
        while(q.size() != 1){
            summ += q.top();
            q.pop();
        }
        cout << "#" << i+1 << " " << round(static_cast<double>(summ) / 8) << endl;
    }
}
