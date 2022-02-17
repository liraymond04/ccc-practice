#include <bits/stdc++.h>

using namespace std;

int main() {
    setbuf(stdout, 0);

    int n;
    cin >> n;

    vector<int> tides(n);
    for (int i=0; i<n; i++) {
        cin >> tides[i];
    }
    sort(tides.begin(), tides.end());

    if (n % 2 == 0) {
        for (int i=0; i<n/2; i++) {
            cout << tides[n/2-i-1] << " " << tides[n/2+i] << " ";
        }
    } else {
        for (int i=1; i<=n/2; i++) {
            cout << tides[n/2-i+1] << " " << tides[n/2+i] << " ";
        }
        cout << tides[0];
    }

    return 0;
}