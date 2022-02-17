#include <bits/stdc++.h>

using namespace std;

int main() {
    int n;
    cin >> n;

    vector<int> v(n);
    for (int i=0; i<n; i++) {
        cin >> v[i];
    }
    sort(v.begin(), v.end());

    double ans = INFINITY;
    for (int i=1; i<n-1; i++) {
        ans = min(ans, (double)(v[i] - v[i-1]) / 2 + (double)(v[i+1] - v[i]) / 2);
    }

    cout << setprecision(1) << fixed << ans;
    
    return 0;
}