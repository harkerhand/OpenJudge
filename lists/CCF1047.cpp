#include<iostream>
using namespace std;

int a[8][8], c[8][8];

int main() {

	for (int i = 1; i < 6; i++) {
		for (int j = 1; j < 6; j++) {
			cin >> a[j][i];
		}
	}

	int max, maxn = 0;
	for (int i = 1; i < 6; i++) {
		max = 0;
		for (int j = 1; j < 6; j++) {
			if (a[j][i] > max) {
				max = a[j][i];
				maxn = j;
			}
		}
		c[maxn][i]++;
	}

	int min, minn = 0;
	for (int i = 1; i < 6; i++) {
		min = 100000;
		for (int j = 1; j < 6; j++) {
			if (a[i][j] < min) {
				min = a[i][j];
				minn = j;
			}
		}
		c[i][minn]++;
	}

	int ok = 1;
	for (int i = 1; i < 6; i++) {
		for (int j = 1; j < 6; j++) {
			if (c[i][j] == 2) {
				cout << j << " " << i << " " << a[i][j];
				ok--;
			}
		}
	}
	if (ok)cout << "not found";

	return 0;
}