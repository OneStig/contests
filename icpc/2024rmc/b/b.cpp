#include <bits/stdc++.h>

using namespace std;

typedef int uci;
#define int long long
#define sz(x) ((int)x.size())
#define all(a) (a).begin(), (a).end()

uci main() {
	cin.tie(0)->sync_with_stdio(0);
	cin.exceptions(cin.failbit);

	int n;
	cin >> n;
	vector<int> a(n);
	for(int i = 0; i < n; ++i) {
		cin >> a[i];
	}

	random_device rd;

	int cnt = 0;
	while(true) {
		cnt++;
		mt19937 g(rd());
		shuffle(a.begin(), a.end(),  g);

		vector<int> first_half, second_half;
		for(int i = 0; i < n / 2; ++i) {
			first_half.push_back(a[i]);
		}


		for(int i = n / 2; i < n; ++i) {
			second_half.push_back(a[i]);
		}

		int n1 = first_half.size();
		set<int> combinations_1;
		for(int bit = 0; bit < (1 << n1) - 1; ++bit) {
			int sum = 0;
			int one = 1;
			for(int i = 0; i < n1; ++i) {
				if(bit & (one << i)) {
					sum += first_half[i];
				}
			}

			combinations_1.insert(sum);
		}


		int n2 = sz(second_half);
		set<int> combinations_2;
		for(int bit = 0; bit < (1 << n2); ++bit) {
			int sum = 0;
			int one = 1;
			for(int i = 0; i < n1; ++i) {
				if(bit & (one << i)) {
					sum += second_half[i];
				}
			}


			combinations_2.insert(sum);
		}

		for(auto x : combinations_1) {
			if(x != 0 && combinations_2.find(x) != combinations_2.end()) {
				cout << x << "\n";
				return 0;
			}
		}

		first_half.clear(), second_half.clear();
		for(int i = 0; i < n / 2 - 1; ++i) {
			first_half.push_back(a[i]);
		}


		for(int i = n / 2; i < n; ++i) {
			second_half.push_back(a[i]);
		}

		n1 = first_half.size();
		combinations_1.clear();
		for(int bit = 0; bit < (1 << n1) - 1; ++bit) {
			int sum = 0;
			int one = 1;
			for(int i = 0; i < n1; ++i) {
				if(bit & (one << i)) {
					sum += first_half[i];
				}
			}

			combinations_1.insert(sum);
		}

		n2 = sz(second_half);
		combinations_2.clear();
		for(int bit = 0; bit < (1 << n2); ++bit) {
			int sum = 0;
			int one = 1;
			for(int i = 0; i < n1; ++i) {
				if(bit & (one << i)) {
					sum += second_half[i];
				}
			}


			combinations_2.insert(sum);
		}

		for(auto x : combinations_1) {
			if(x != 0 && combinations_2.find(x) != combinations_2.end()) {
				cout << x << "\n";
				return 0;
			}
		}
	}
}
