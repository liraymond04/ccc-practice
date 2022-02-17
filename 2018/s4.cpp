#include <bits/stdc++.h>

using namespace std;

long long f(int n, unordered_map<int, long long> &dp) {
    if (n == 1 || n == 2) return 1;
    if (dp.count(n)) return dp[n];

    long long ans = 0;
    int k = n;
    while (k >= 2) {
        int w = n / k, next = n / (w + 1);
        ans += (k - next) * f(w, dp);
        k = next;
    }
    dp[n] = ans;

    return ans;
}

int main() {
    int n;
    cin >> n;

    unordered_map<int, long long> dp;
    dp[1] = 1;

    cout << f(n, dp);
    
    return 0;
}