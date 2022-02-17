#include <bits/stdc++.h>

using namespace std;

int main() {
    setbuf(stdout, 0);

    int n;
	cin >> n;

	vector<int> team1(n);
	vector<int> team2(n);

	for (int i=0; i<n; i++) {
		cin >> team1[i];
	}
	for (int i=0; i<n; i++) {
		cin >> team2[i];
	}

	int k = 0, score1 = 0, score2 = 0;
	for (int i=0; i<n; i++) {
		score1 += team1[i];
		score2 += team2[i];

		if (score1 == score2) {
			k = i + 1;
        }
	}

	cout << k;

    return 0;
}