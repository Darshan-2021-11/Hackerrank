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

int prime_nos(vector <ll> &primes, unsigned int n){
	ll temp, sqrttemp;
	bool flag = true;
	if(primes.size()){
		temp = *(--primes.end()); temp++;
	} else {
		primes = { 2, 3, 5, 7 };
		temp = 11;
	}

	while(primes.size() < n){
		sqrttemp = sqrt(temp);
		for(unsigned int i = 0; primes[i] <= (sqrttemp+1); ++i){
			if(!(temp%primes[i])){
				flag = false;
				break;
			}
		}
		if(flag) primes.push_back(temp);

		// initializing values
		temp++;
		flag = true;
	}
	return 0;
}

int solve(vector <ll> &primes) {
	int n;
	cin >> n;
	prime_nos(primes, n);
	cout << primes[n-1] << "\n";

	return 0;
}

int32_t main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	vector <ll> primes;
	int TET = 1e9;
	cin >> TET;
	for (int i = 1; i <= TET; i++) {
		if (solve(primes)) {
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
