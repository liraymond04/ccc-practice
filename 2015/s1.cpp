#include <bits/stdc++.h>

using namespace std;

int main() {
    setbuf(stdout, 0);

    int n;
    cin >> n;

    vector<int> a;
    for (int i=0; i<n; i++) {
        int num;
        cin >> num;

        if (num > 0) {
            a.push_back(num);
        } else {
            a.pop_back();
        }
    }

    int sum = 0;
    for (int i=0; i<a.size(); i++) {
        sum += a[i];
    }

    cout << sum;

    return 0;
}