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

int fib_series_vec(vector <ll> &fib, int n) {
	ll t1, t2, ti;
	if(fib.size() == 0){
		t1 = 1, t2 = 2;
		fib.push_back(t1);
		fib.push_back(t2);
	} else {
		auto it = fib.end();
		it--;
		t2 = *(it--);
		t1 = *(it);
	}
	while(t2+t1 <= n){
		ti = t1;
		t1 = t2;
		t2 += ti;
		fib.push_back(t2);
	}
	return 0;
}

int solve(vector <ll> &fib) {
	ll n, sum = 0;
	cin >> n;

	// if fib.size() == 0 and we deferenced *(--fib.end()), it would give error
	// and would not even provide the wrong line number :(
	if(!fib.size() || *(--fib.end()) < n){
		fib_series_vec(fib, n);
	}

	for(auto i: fib){
		// condition is not even required, every third term of the series from
		// index 1(taking initial index as 0), we get even number since we are
		// always summing previous two terms, if the predecessor or second
		// predecessor is even, the other would always be negative and give odd
		// number, even is always obtained when there is two odd terms in both
		// of that position.
		if(!(i&1) && (i <= n)){ sum += i; }
		else if(i>n) break;
		//	cout << i << " ";
	}
	cout << sum << "\n";

	return 0;
}

int32_t main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	vector <ll> fib;
	int TET = 1e9;
	cin >> TET;
	for (int i = 1; i <= TET; i++) {
		if (solve(fib)) {
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
