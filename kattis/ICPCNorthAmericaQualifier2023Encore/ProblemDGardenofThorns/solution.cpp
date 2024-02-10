#include <bits/stdc++.h>

#define ld long double

using namespace std;

ld n, r, w, h;
ld total;

ld dist(ld x1, ld y1, ld x2, ld y2) {
	return sqrt((x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2));
}

ld angle(ld x1, ld y1, ld x2, ld y2) {
	x2 -= x1;
	y2 -= y1;

	ld ang = atan2(y2, x2);

	if (ang < 0) {
		ang += 2 * M_PI;
	}

	return ang;
}

ld overt(ld x, ld y, ld x1) {
	if (abs(x1 - x) == r) {
		return 0;
	}

	if (abs(x1 - x) > r) {
		return -1;
	}

	return sqrt(r * r - (x1 - x) * (x1 - x));
}

void ins(set<array<ld, 2>>& dup, vector<array<ld, 2>>& pts, ld x1, ld y1) {
	if (x1 >= 0 && x1 <= w && y1 >= 0 && y1 <= h &&
		dup.find({x1, y1}) == dup.end()) {
		pts.push_back({x1, y1});
		dup.insert({x1, y1});
	}
}

ld edge(ld xc, ld yc, ld x1, ld y1,  ld x2, ld y2) {
	if (((x1 == x2 && (x1 == 0 || x1 == w)) ||
		(y1 == y2 && (y1 == 0 || y1 == h)))) {
		// we are on the same edge, make a triangle

		return (x1 * y2 + x2 * yc + xc * y1 - x1 * yc - x2 * y1 - xc * y2) / 2;
	}

	ld a2 = angle(xc, yc, x2, y2);
	ld a1 = angle(xc, yc, x1, y1);

	if (a1 > a2) {
		a2 += 2 * M_PI;
	}

	ld propang = a2 - a1;

	return r * r * propang / 2;
}

ld comp(ld x, ld y) {
	ld circ = 0;

	vector<array<ld, 2>> pts; // angle, x, y
	set<array<ld, 2>> dup;

	// 0, 0
	if (dist(x, y, 0, 0) <= r) {
		ins(dup, pts, 0, 0);
	}

	ld bw = overt(y, x, 0);

	if (bw >= 0) {
		ins(dup, pts, x + bw, 0);
		ins(dup, pts, x - bw, 0);
	}

	// w, 0
	if (dist(x, y, w, 0) <= r) {
		ins(dup, pts, w, 0);
	}

	ld rw = overt(x, y, w);

	if (rw >= 0) {
		ins(dup, pts, (ld)w, y + rw);
		ins(dup, pts, (ld)w, y - rw);
	}

	// w, h
	if (dist(x, y, w, h) <= r) {
		ins(dup, pts, w, h);
	}
	
	ld tw = overt(y, x, h);
	
	if (tw >= 0) {
		ins(dup, pts, x + tw, (ld)h);
		ins(dup, pts, x - tw, (ld)h);
	}
	
	// 0, h
	if (dist(x, y, 0, h) <= r) {
		ins(dup, pts,  0, h);
	}


	ld lw = overt(x, y, 0);

	if (lw >= 0) {
		ins(dup, pts, 0, y + lw);
		ins(dup, pts, 0, y - lw);
	}

	if (pts.size() <= 1) {
		return M_PI * r * r;
	}

	pts.push_back({pts.front()[0], pts.front()[1]});

	for (int i = 1; i < pts.size(); i++) {
		circ += edge(x, y, pts[i - 1][0], pts[i - 1][1],  pts[i][0], pts[i][1]);
	}

	return circ;
}

int main() {
	constexpr auto max_precision{numeric_limits<ld>::digits10 + 1};

	cin >> n >> r >> w >> h;
	total = w * h;

	ld ans = 0;

	while (n--) {
		ld x, y, v;
		cin >> x >> y >> v;
		ans += comp(x, y) / total * v;
	}

	cout << setprecision(max_precision) << ans << endl;
}
