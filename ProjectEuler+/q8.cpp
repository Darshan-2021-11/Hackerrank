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

int solve() {
	int n, k;
	cin >> n >> k;
	string number;
	// if `n` is the digits of the number, the constraint states that i<=k<=7
	// and k<=n<=1000; so we need string to store the number if it gets large.
	//
	// Constraint allows product to be `int` datatype.
	cin >> number;

	int product = 0, temp;

	// ASCII values, `0` = 48, `1` = 49, `2` = 50 and so on till `9` = 57;
	// We need to subtract 48 from the char value to get the digit in the
	// string.
	//
	// Number of possible cosecutive numbers is `n-k+1`, hence the limit
	// `n-K+2`
	for(int i=0; i<(n-k+2); i++) {
		// kept temp=0; while compiling, rest is history ;)
		temp = 1;
		for (int j = i; j < (i+k); j++) {
			temp *= (number[j] - 48);
		}
		//	cout << temp << " ";
		product = max(product, temp);
	}
	cout << product << "\n";

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
