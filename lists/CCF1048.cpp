#include<iostream>
using namespace std;

int a[105][105];
int main() {
	int n, x[105], y[105];
	cin >> n;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			cin >> a[j][i];
		}
	}

	for (int i = 1; i <= n; i++) {
		x[i] = 0;
		y[i] = 0;
	}

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			x[i] += a[j][i];
			y[j] += a[j][i];
		}
	}


	int cx = 0, cy = 0, xz, yz;
	for (int i = 1; i <= n; i++) {
		if (x[i] % 2 == 1) {
			cx++;
			xz = i;
		}
		if (y[i] % 2 == 1) {
			cy++;
			yz = i;
		}
	}

	if (cx == 0 && cy == 0) {
		cout << "OK";
	}
	else if (cx == 1 && cy == 1) {
		cout << xz << " " << yz;
	}
	else {
		cout << "Corrupt";
	}

	return 0;
}