#include <bits/stdc++.h>

using namespace std;

int main() {
	int tc;
	cin >> tc;
	
	while (tc--) {
		int n, q;
		cin >> n >> q;

		vector<vector<int>> raw(1);
		vector<long long> dup;
		vector<long long> lens(1, 0);
		int over = -1;

		while (n--) {
			int b, x;
			cin >> b >> x;

			if (b == 1) {
				raw.back().push_back(x);
				lens.back()++;
			}
			else {
				dup.push_back(x + 1);

				if (INT_MAX / lens.back() > (x + 1)) {
					lens.push_back(lens.back() * (x + 1));
				}

				raw.push_back(vector<int>());
			}
		}

		dup.push_back(1);

		//cout << "lens:" << endl;
		//for (long long i : lens) {
			//cout << i << " "; 
		//}
		//cout << endl;

		//cout << "dups:" << endl;
		//for (long long i : dup) {
			//cout << i << " "; 
		//}
		//cout << endl;

		vector<int> ans;

		while (q--) {
			long long k;
			cin >> k;
			k--;

			int ind = upper_bound(lens.begin(), lens.end(), k) - lens.begin();

			while (ind > 0) {
				ind--;

				//cout << ind << " " << k << " " << lens[ind] << " " << dup[ind] << endl;
				if (lens[ind] * dup[ind] <= k) {
					//cout << ind << " " << k - lens[ind] * dup[ind] << endl;
					ans.push_back(raw[ind][k - lens[ind] * dup[ind]]);
					break;
				}
				
				k %= lens[ind];
			}
		}

		for (int i = 0; i < ans.size(); i++) {
			if (i != 0) {
				cout << ' ';
			}

			cout << ans[i];
		}

		cout << endl;
		cout << tc << endl;
	}
}
