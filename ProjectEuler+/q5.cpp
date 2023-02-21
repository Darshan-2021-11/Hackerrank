#ifdef ONPC
	#define _GLIBCXX_DEBUG
#endif
#include <bits/stdc++.h>
#define sz(a) ((int)((a).size()))
#define char unsigned char

using namespace std;
// mt19937 rnd(239);
mt19937 rnd(chrono::steady_clock::now().time_since_epoch().count());

typedef long long ll;
typedef long double ld;

int gcd(int a, int b) {
	while (a) {
		b %= a;
		swap(a, b);
	}
	return b;
}

int solve() {
	int n; ll sm = 1;
	// sm = 1; since 1<= n <= 40;
	cin >> n;
	for(int i=1; i <= n; i++){
		if(sm%i){
			// the tricky thing to notice here is that if the number is not
			// prime, we can multiply with it, but if it is composite, we need
			// to find the factors until `n` and select the maximum power of
			// the thing for each value of `i` in this loop, and most probably
			// find factors for each numbers and store it in a vector most
			// probably
			//
			// but if we use the formula for LCM of two numbers, we could
			// easily by pass the previous approach and just use it when
			// conflict occurs
			// i.e. LCM = (product of two numbers) / HCF;
			//
			sm = 1ll * (sm*i)/(gcd(sm, i));
		}
	}
	cout << sm << "\n";
	return 0;
}

int32_t main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	int TET = 1e9;
	cin >> TET;
	for (int i = 1; i <= TET; i++) {
		if (solve()) {
			break;
		}
		#ifdef ONPC
			cout << "__________________________" << "\n";
		#endif
	}
	#ifdef ONPC
		cerr << endl << "finished in " << clock() * 1.0 / CLOCKS_PER_SEC <<
		"second(s)" << "\n";
	#endif
}
