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

// This takes more time to execute(TLE)
//
//	int solve() {
//		ll sum = 0;
//		int n, count3 = 0, count5 = 0;
//		cin >> n;
//	
//		bool divBy3, divBy5;
//		for(int i=1; i<n; i++){
//			divBy3 = count3==2 ? (count3 = 0, true) : (count3++, false);
//			divBy5 = count5==4 ? (count5 = 0, true) : (count5++, false);
//			if(divBy3 || divBy5){
//				//	cout << i << " ";
//				sum += i;
//			}
//		}
//		cout << sum << "\n";
//	
//		return 0;
//	}

int solve() {
	ll sum = 0;
	// Got wrong answer due to use of wrong container, int, instead of long
	long n, n3v = 0, n5v = 0, n15v = 0;
	cin >> n;

	if(n<=0) return 0;
	// do not even this loop and above 3 temporary variables, we can directly
	// divide by 3, 5 or 15 to get number of terms, and apply AP formula that
	// contains n
	while(--n){
		if((n%3 == 0) && (n3v == 0)) n3v = n;
		if((n%5 == 0) && (n5v == 0)) n5v = n;
		// if a value of 'n' is found such that it is divided by 15, it is
		// guaranteed that n3v and n5v is found as 15 is LCM of 3 and 5.
		if((n%15 == 0) && (n15v == 0)) { n15v = n; break; }
	}
	// Using formula of AP, summing terms of 3 and 5 AP and removing duplicates
	// i.e. multiples of 15
	sum = 1ll * ( ((n3v*(3+n3v))/6) + ((n5v*(5+n5v))/10) - ((n15v*(15+n15v))/30) );

	cout << sum << "\n";

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
