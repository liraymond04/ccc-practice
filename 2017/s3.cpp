#include <bits/stdc++.h>

using namespace std;

int main() {
    setbuf(stdout, 0);
    vector<int> lengths(4001, 0);
    vector<int> boards(2001, 0);

    int n;
    cin >> n;

    for (int i=0; i<n; i++) {
        int num;
        cin >> num;
        boards[num]++;
    }

    for (int i=1; i<=2000; i++) {
        lengths[i*2] += boards[i]/2;
        for (int j=i+1; j<=2000; j++) {
            lengths[i+j] += min(boards[i], boards[j]);
        }
    }

    int m = 0, count = 0;
    for (int i=2; i<=4000; i++) {
        if (lengths[i] > m) {
            m = lengths[i];
            count = 1;
        } else if (lengths[i] == m) {
            count++;
        }
    }

    cout << m << " " << count;

    return 0;
}