#include <iostream>

using namespace std;
int min(int x, int y) {
	return x >= y ? y : x;
}
int max(int x, int y) {
	return x >= y ? x : y;
}
class ret {
public:
	int rld_x, rld_y, rru_x, rru_y;
	ret(int x, int y) {
		rld_x = x;
		rru_x = x;
		rld_y = y;
		rru_y = y;
	}
	void show() {
		if (rld_x == -111111 || rld_y == -111111 || rru_x == -111111 || rru_y == -111111)
			cout << 0 << '\n';
		else
			cout << 1 << ' ' <<  rld_x << ' '  << rld_y << '\n'; 
	}
};

class robot {
private:
	int x, y, f1, f2, f3, f4;
	ret * range;
public:
	robot() {
		cin >> x >> y >> f1 >> f2 >> f3 >> f4;
		range = new ret(x, y);
	}
	void range_calculate() {
		if (f1 == 1)
			range->rld_x = -100000;
		if (f2 == 1)
			range->rru_y = 100000;
		if (f3 == 1)
			range->rru_x = 100000;
		if (f4 == 1)
			range->rld_y = -100000;
	}
	void show() {
		cout << x << y << f1 << f2 << f3 << f4 << '\n';
	}
	void show_range() {
		range->show();
	}
	ret get_range() {
		return *range;
	}
};

ret range_compare(ret r1, ret r2) {
	ret result = ret(-111111, -111111);

	// When not intersect
	if (r1.rld_x > r2.rru_x || r1.rru_x < r2.rld_x)
		return result;
	if (r1.rld_y > r2.rru_y || r1.rru_y < r2.rld_y)
		return result;
	result.rld_x = max(r1.rld_x, r2.rld_x);
	result.rld_y = max(r1.rld_y, r2.rld_y);
	result.rru_x = min(r1.rru_x, r2.rru_x);
	result.rru_y = min(r1.rru_y, r2.rru_y);
	return result;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	int q = 0;
	cin >> q;
	for (int i = 0; i < q; i++) {
		int n = 0;
		cin >> n;
		robot robots[n];
		robots[0].range_calculate();
		ret result = robots[0].get_range();
		for (int t = 0; t < n; t++) {
			robots[t].range_calculate();
			result = range_compare(result, robots[t].get_range());
		//	result.show();
		}
		result.show();
	}
	return 0;
}
