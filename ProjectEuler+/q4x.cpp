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
	int n;
	cin >> n;

	// this part generates sequential pallindrome in decreasing order of the
	// given value of `n`
	//
	// METHOD: We take the 3 most significant digits of the given 101101 < N <
	// 1000000, since N is conveniently between the range of 6-digit numbers,
	// we can safely say that the most 3 most significant digits will generate
	// the nearest pallindromic number less than the given digit.
	int p_s = n / 1000, p_s_d, t, p_n, f1 = 0, f2 = 0;
	bool flag = true;

	while(flag){
		// the error I was getting in the answer was due to that the value of
		// variable `t` was never reset which caused weird bugs in the answer
		// value to zero.
		t = 0;
		p_s_d = p_s;
		while(p_s_d){
			// 't' is the pallidrome of the most significant digits
			t = t * 10 + (p_s_d % 10);
			p_s_d /= 10;
		}
		// our newly generated pallindrome
		p_n = p_s*1000 + t;
		if(p_n > n){
			p_s--;
			continue;
		}

		// to reduce the testing number by half, we take square root and try to find
		// the 3 digit factor from the remaining half of 3 digits number if any.
		t = sqrt(p_n);
		if(t*t == p_n){
			// if(p_n > n) condition was not given above, it would print wrong
			// result, we don't even know till now if such a square pallindrome
			// exists or not
			cout << t << " " << t << "\n";
			return 0;
		}
		if(t>500){
			// most probable since 500^2 = 250000; which constitutes only 1/4th
			// of the 6 digit numbers
			// NEVER MIND, we never need two 500 to test for factor, since
			// previously discussed, 500^2 = 250000, which is not a pallindrome
			while(t<1000){
				if(!(p_n%t)){
					f1 = t;
					f2 = p_n/t;
					break;
				}
				t++;
			}
		} else {
			// it is taken for granted that if t!>500, it is less than 500 and more
			// by the given constrains(see explanation of the first `if`)
			while(t>100){
				if(!(p_n%t)){
					f1 = t;
					f2 = p_n/t;
					break;
				}
				t--;
			}
		}
		if(f1/100 && f2/100 && !(f1/1000) && !(f2/1000)){
			// a ridiculous problem faced by me in the given answer by this
			// upcoming line is that the test cases do not accept two factors
			// in the output when the f1>f2; why GOD?Why?
			//	cout << p_n << " " << f1 << " " << f2 << "\n";
			//
			//	Turns out it was my bad, I gave the output of the pallindromic
			//	number too! YIKES!
			//
			//	But they still do not accept smaller values after big values in
			//	the factors
			//
			//	FINAL: turns out, I never had to print the factors in the first
			//	place, I always had to print only the pallindromic number, took
			//	me like 15 mins to troubleshoot all of this. AGHH!
			cout << p_n << "\n";
			flag = false;
		}
		p_s--;
	}
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
