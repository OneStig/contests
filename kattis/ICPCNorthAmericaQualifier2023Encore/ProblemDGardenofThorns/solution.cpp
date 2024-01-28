#include <bits/stdc++.h>
#include <cinttypes>

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

void ins(set<array<ld, 3>>& pts, ld x, ld y, ld x1, ld y1) {
	if (x1 >= 0 && x1 <= w && y1 >= 0 && y1 <= h) {
		pts.insert({angle(x, y, x1, y1), x1, y1});
	}
}

ld edge(ld xc, ld yc, ld a1, ld x1, ld y1, ld a2, ld x2, ld y2) {
	if (((x1 == x2 && (x1 == 0 || x1 == w)) ||
		(y1 == y2 && (y1 == 0 || y1 == h)))) {
		// we are on the same edge, make a triangle

		return (x1 * y2 + x2 * yc + xc * y1 - x1 * yc - x2 * y1 - xc * y2) / 2;
	}

	ld propang = a2 - a1;

	return r * r * propang / 2;
}

ld comp(ld x, ld y) {
	ld circ = 0;

	set<array<ld, 3>> pts; // angle, x, y

	// 0, 0
	if (dist(x, y, 0, 0) <= r) {
		ins(pts, x, y, 0, 0);
	}

	// 0, h
	if (dist(x, y, 0, h) <= r) {
		ins(pts, x, y, 0, h);
	}

	// w, 0
	if (dist(x, y, w, 0) <= r) {
		ins(pts, x, y, w, 0);
	}

	// w, h
	if (dist(x, y, w, h) <= r) {
		ins(pts, x, y, w, h);
	}

	if (pts.size() == 4) {
		return total;
	}

	//////////////////////////////

	ld lw = overt(x, y, 0);
	ld rw = overt(x, y, w);
	ld bw = overt(y, x, 0);
	ld tw = overt(y, x, h);

	if (lw >= 0) {
		ins(pts, x, y, 0, y + lw);
		ins(pts, x, y, 0, y - lw);
	}

	if (rw >= 0) {
		ins(pts, x, y, (ld)w, y + rw);
		ins(pts, x, y, (ld)w, y - rw);
	}

	if (bw >= 0) {
		ins(pts, x, y, x + bw, 0);
		ins(pts, x, y, x - bw, 0);
	}

	if (tw >= 0) {
		ins(pts, x, y, x + tw, (ld)h);
		ins(pts, x, y, x - tw, (ld)h);
	}

	if (pts.size() <= 1) {
		return M_PI * r * r;
	}

	vector<array<ld, 3>> segments;

	for (auto it = pts.begin(); it != pts.end(); it++) {
		auto cur = *it;
		segments.push_back({cur[0], cur[1], cur[2]});
	}
	auto frst = *(pts.begin());
	segments.push_back({2 * M_PI + frst[0], frst[1], frst[2]});

	for (int i = 1; i < segments.size(); i++) {
		circ += edge(x, y, segments[i - 1][0], segments[i - 1][1], segments[i - 1][2], segments[i][0], segments[i][1], segments[i][2]);
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
