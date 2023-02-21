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

// My idea: first checking every number if it divides the given number until we
// get to its square root, take out factors and check if they are prime or not
// in a different mode
//
// DRAWBACK: I NEVER NEED THE FACTORS I KEPT TRACK OF ALL FACTORS OF THAT
// NUMBER
//
// From Internet: first divide each number until it no longer divides, and keep
// track of the last number that divided(if `n` is the number, `i` is a factor,
// we do n/=i, until `n` reduces to a number that is no longer divided by `i`,
// then we simply increase the value of `i`), the number that remains to the
// very last would be the one that cannot be divided until we come to the
// number that is the largest prime, we would have exhausted all other factors
// from the number.

int solve() {
	ll n;
	cin >> n;

	for(ll i=2; i<(sqrt(n)+1); i++){
		while(!(n%i)){
			n /= i;
		}
	}

	cout << n << "\n";

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
