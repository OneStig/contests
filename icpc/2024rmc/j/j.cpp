#include <bits/stdc++.h>

using namespace std;

typedef int uci;
#define int long long
#define ld long double
#define sz(x) ((int)x.size())
#define all(a) (a).begin(), (a).end()

uci main() {
	cin.tie(0)->sync_with_stdio(0);
	cin.exceptions(cin.failbit);
	int n;
	cin >> n;
	vector<pair<int,int>> points;
	for (int i = 0; i < n; i++){
		int a,b;
		cin >> a  >> b;
		points.push_back({a,b});
	}
	int maxi = 0;
	for (int i = 0; i < n; i++) {
		if (points[i].second > points[maxi].second) {
			maxi = i;
		}
	}

	// LEFT
	int leftbest = 0;
	int leftheight = 10000000000;
	pair<int,int> maxslope = {1,0};
	for (int j = maxi-1; j > -1; j--) {
		pair<int,int> slope = {(points[maxi].second - points[j].second),
			(points[maxi].first - points[j].first)};
		if (maxslope.second * slope.first <= maxslope.first * slope.second) {
			if (points[j].second <= leftheight) {
				leftheight = points[j].second;
				leftbest = j;
			}
			maxslope = slope;
		}
	}

	// right
	int rightbest = 0;
	int rightheight = 10000000000;
	pair<int,int> minslope = {01,0};
	for (int j = maxi+1; j < n; j++) {
		pair<int,int> slope = {(points[maxi].second - points[j].second),
			(points[maxi].first - points[j].first)};
		//cout << minslope.first << " " << minslope.second << "\n";
		//cout << slope.first << " " << slope.second << "\n";
		if (minslope.second * slope.first >= minslope.first * slope.second) {
			if (points[j].second <= rightheight) {
				rightheight = points[j].second;
				rightbest = j;
			}
			minslope = slope;
		}
	}
	//cout << leftbest << " " << rightbest << "\n";

	cout << points[leftbest].first << " " << points[leftbest].second << "\n";
	cout << points[rightbest	].first << " " << points[rightbest].second << "\n";



}
