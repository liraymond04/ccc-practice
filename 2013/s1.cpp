#include <bits/stdc++.h>

using namespace std;

bool f(int n) {
    vector<int> digits(10, 0);
    while (n != 0) {
        if (digits[n % 10]) return false;
        digits[n % 10]++;
        n /= 10;
    }
    return true;
}

int main() {
    setbuf(stdout, 0);

    int n;
    cin >> n;

    n++;
    while (!f(n)) {
        n++;
    }

    cout << n;

    return 0;
}