#include <bits/stdc++.h>

using namespace std;

int main() {
    setbuf(stdout, 0);

    int w, n;
    cin >> w >> n;

    vector<int> cars(3, 0);
    for (int i=0; i<n; i++) {
        int input;
        cin >> input;
        cars.push_back(input);
    }
    cars.push_back(w+1);

    int ans = 0, i = 3;
    int total = cars[i-3] + cars[i-2] + cars[i-1] + cars[i];
    while (total <= w) {
        ans++; i++;
        total = cars[i-3] + cars[i-2] + cars[i-1] + cars[i];
    }
    
    cout << ans;

    return 0;
}