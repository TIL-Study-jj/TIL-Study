#include <iostream>
using namespace std;
// CHATGPT IS GOD
int main() {
    int n;

    while (cin >> n) {
        int remainder = 1;
        int count = 1;

        while (remainder % n != 0) {
            remainder = (remainder * 10 + 1) % n; // FUCK!!!!!!!!!!
            count++; // NEW FACT : x mod N = (x mod N) mod N
        }

        cout << count << endl;
    }

    return 0;
}
