#include <bits/stdc++.h>

using namespace std;

bool is_prime(int n) {
    if (n == 1) {
        return false;
    }

    int i = 2;
    while (i*i <= n) {
        if (n % i == 0) {
            return false;
        }
        i += 1;
    }

    return true;
}

int main() {
    int t;
    cin >> t;

    for (int i=0; i<t; i++) {
        int n;
        cin >> n;

        for (int j=2; j<=n; j++) {
            int a = j, b = 2 * n - j;
            if (is_prime(a) && is_prime(b) && 2 * n == a + b) {
                cout << a << " " << b << "\n";
                break;
            }
        }
    }
    
    return 0;
}