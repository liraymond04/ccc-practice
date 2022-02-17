#include <bits/stdc++.h>

using namespace std;

const int maxn = 400 + 5;
int n; int a[maxn]; int s[maxn];

int sum(int i, int j) {
    return s[j] - s[i] + a[i];
}

bool dp[maxn][maxn];

int main() {
    setbuf(stdout, 0);

    cin >> n;

    for (int i=0; i<n; i++) {
        cin >> a[i];
    }
    s[0] = a[0];
    for (int i=1; i<n; i++) {
        s[i] = s[i - 1] + a[i];
    }

    memset(dp, false, sizeof(dp));
    for (int i=0; i<n; i++) {
        dp[i][i] = true;
    }

    int ans = 0;
    for (int len=1; len<=n; len++) {
        for (int i=0; i<n-len+1; i++) {
            int j = i + len - 1;

            if (dp[i][j]) {
                ans = max(ans, sum(i, j));
                continue;
            }

            for (int k=i; k<j; k++) {
                if (dp[i][k] && dp[k+1][j] && sum(i, k) == sum(k+1, j)) {
                    dp[i][j] = true;
                    break;
                }
            }

            if (dp[i][j]) {
                ans = max(ans, sum(i, j));
                continue;
            }

            for (int len2=1; len2<=len-2; len2++) {
                if (dp[i][j]) break;
                for (int k=i+1; k+len2<=j; k++) {
                    int l = k + len2 - 1;
                    if (dp[i][k-1] && dp[k][l] && dp[l+1][j] && sum(i, k-1) == sum(l+1, j)) {
                        dp[i][j] = true;
                        break;
                    }
                }
            }

            if (dp[i][j]) {
                ans = max(ans, sum(i, j));
            }
        }
    }

    cout << ans;

    return 0;
}