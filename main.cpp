#include <iostream>
#include <fstream>

using namespace std;


int m[101][101];
int x = 12, y=12, x1=1, y11=23, x2=3, y2=4;


bool vlazit(int a, int b) {
	return ((a % x1 == 0) && ((b % y11) == 0)) ||
		(((a % x2) == 0) && ((b % y2) == 0)) ||
		(((b % x1) == 0) && ((a % y11) == 0)) ||
		(((b % x2) == 0) && ((a % y2) == 0));
}

int ans(int a, int b) {
	if (m[a][b] != 2 * a * b)
		return m[a][b];
	if (vlazit(a,b)){
		m[a][b] = 0;
		return 0;
	}
	for (int dx = 1; dx <= a/2; dx++)
		m[a][b] = min(m[a][b], ans(dx, b) + ans(a-dx, b));
	for (int dy = 1; dy <= b/2; dy++)
		m[a][b] = min(m[a][b], ans(a, dy) + ans(a, b-dy));
	return m[a][b];
}

int main() {
	ifstream in("input.txt");
	in >> x >> y >> x1 >> y11 >> x2 >> y2;
	in.close();
	for (int i = 0; i <= 100; i++)
		for (int j = 0; j <= 100; j++)
			m[i][j] = 2 * i * j;
	for (int i = 0; i < x1; i++)
		for (int j = 0; j < y11; j++)
			m[i][j] = i * j;
	for (int i = 0; i < x2; i++)
		for (int j = 0; j < y2; j++)
			m[i][j] = i * j;
	m[x1][y11] = 0;
	m[x2][y2] = 0;
	ofstream out("output.txt");
	out << ans(x, y);
	out.close();
	return 0;
}