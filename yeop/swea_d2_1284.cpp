#include <iostream>
using namespace std;

int main() {
    int iter;
    cin >> iter;
	for(int i = 1; i < iter + 1; i++){
		
		int p, q, r, s, w;
		cin >> p >> q >> r >> s >> w;
		
		int a_p, b_p;
		
		a_p = w*p;
		b_p = q;
		
		if(w > r){
			b_p += (w-r)*s;
		}
		
		if (a_p <= b_p){
			b_p = a_p;
		}
		
		cout << "#" << i << " " << b_p << endl;
	}
    return 0;
}

