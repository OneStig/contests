#include <bits/stdc++.h>

using namespace std;

template <class T> class SumSegmentTree {
  private:
	const T DEFAULT = 0;

	vector<T> segtree;
	int len;

  public:
	SumSegmentTree(int len) : len(len), segtree(len * 2, DEFAULT) {}

	void set(int ind, T val) {
		ind += len;
		segtree[ind] = val;
		for (; ind > 1; ind /= 2) {
			segtree[ind / 2] = segtree[ind] + segtree[ind ^ 1];
		}
	}

	T range_sum(int start, int end) {
		T sum = DEFAULT;
		for (start += len, end += len; start < end; start /= 2, end /= 2) {
			if (start % 2 == 1) { sum += segtree[start++]; }
			if (end % 2 == 1) { sum += segtree[--end]; }
		}
		return sum;
	}
};

int main() {
	int t;
	cin >> t;

	while (t--) {
		int n;
		cin >> n;

		vector<pair<int, int>> line;
		
		for (int i = 0; i < n; i++) {
			int a, b;
			cin >> a >> b;

			line.push_back({a, b});
			line.push_back({b, INT_MAX});
		}

		sort(line.begin(), line.end());

		map<int, int> bInd;

		SumSegmentTree<long long> bs(2 * n);
		long long ans = 0;

		for (int i = 2 * n - 1; i >= 0; i--) {
			if (line[i].second == INT_MAX) {
				bInd[line[i].first] = i;
			}
			else {
				int cur = bs.range_sum(i, bInd[line[i].second]);
				ans += cur;
				bs.set(bInd[line[i].second], 1);
			}
		}

		cout << ans << endl;
	}
}

