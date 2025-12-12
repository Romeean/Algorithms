#include <iostream>
#include <vector>

using namespace std;



void hayonTower(int n, char A, char B, char C) {
	if (n == 0) return;

	hayonTower(n - 1, A, C, B);

	cout << "Move disk " << n << " from " << A << " to " << B << endl;

	hayonTower(n - 1, C, B, A);
}

int main()
{
	hayonTower(3, 'A', 'B', 'C');
	return 0;
}
