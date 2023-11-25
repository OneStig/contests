#include <bits/stdc++.h>

using namespace std;

struct SegTree {
	vector<int> segtree;
	int len;

	void init(vector<int> nums) {
		segtree = nums;
		len = nums.size();
	}

	void set(int ind, int val) {
		ind += len;
		segtree[ind] = val;
		for (; ind > 1; ind /= 2) {
			segtree[ind / 2] = segtree[ind] + segtree[ind ^ 1];
		}
	}

	int range_sum(int start, int end) {
		int sum = 0;

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
		int n, q;
		cin >> n >> q;
		vector<int> nums(n);
		
		for (int i = 0; i < n; i++) {
			cin >> nums[i];
		}

		SegTree st;
		st.init(nums);

		for (int i = 0; i < q; i++) {
			int op;
			cin >> op;

			if (op == 1) {
				int x;
				cin >> x;

			}
			else {
				int x, y;
				cin >> x >> y;
				st.set(x, y);
			}
		}
	}
}
