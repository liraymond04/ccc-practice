#include <bits/stdc++.h>

using namespace std;

int main() {
    setbuf(stdout, 0);

    int n, k;
    cin >> n >> k;

    int days = n / k;
    if (n % k != 0) {
        days++;
    }

    vector<long long> a(n);
    for (int i=0; i<n; i++) {
        cin >> a[i];
    }

    
    vector<long long> dp(n), prevdpmax(n), dpa(n);
    int start, end;

    for (int i=0; i<days; i++) {
        start = i * k, end = (i+1) * k - 1;
        if (end >= n) {
            end = n-1;
        }

        long long daymax = 0;
        for (int j=start; j<=end; j++) {
            daymax = max(daymax, a[j]);
            if (i == 0)  {
                dp[j] = daymax;
            } else {
                dp[j] = prevdpmax[j-k] + daymax;
                dp[j] = max(dp[j], dpa[j-k]);
            }
        }

        long long maxpreva = 0;
        for (int j=end; j>=start; j--) {
            prevdpmax[j] = max(prevdpmax[j+1], dp[j]);
            dpa[j] = max(dpa[j+1], dp[j] + maxpreva);
            maxpreva = max(maxpreva, a[j]);
        }
    }

    cout << dp[end];

    return 0;
}