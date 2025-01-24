#include <iostream>
using namespace std;
// chatGPT is the FUTURE.
long long power(long long a, long long b, long long c) { // recursive function
    if (b == 0) {
        return 1;
    }
    long long half = power(a, b / 2, c); // divide jisu / 2
    long long result = (half * half) % c; // result is a^(b/2*2) % c
    if (b % 2 == 1) {
        result = (result * a) % c; // if jisu is odd number, have to multiply one time at result
    }
    return result;
}

int main() {
    long long a, b, c;
    cin >> a >> b >> c;
    a %= c;
    cout << power(a, b, c) << endl;
    return 0;
}
