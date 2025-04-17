#include <iostream>
using namespace std;
int main() {
	int n1, n2; cin >> n1 >> n2;
	int d = n2 - n1; int c = 1;
	switch (d) {
		case 0: {
			cout << "0";
			break;
		}
		case 1: {
			cout << "1";
			break;
		}
		default: {
			int cnt = 2;
			while (true) {
				d -= 2 * c; c++;
				if (d <= c) {
				    if(d == 0){
				        break;
				    }
					cnt++;
					break;
				}
				else if (d >= 2*c) {
					cnt++; cnt++;
				}
				else {
					cnt++; cnt++;
					break;
				}
			}
			cout << cnt;
		}
	}
	return 0;
}