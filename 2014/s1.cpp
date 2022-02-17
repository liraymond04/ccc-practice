#include <bits/stdc++.h>

using namespace std;

int main() {
    setbuf(stdout, 0);

    int k, m;
    cin >> k >> m;

    vector<int> friends(k);
    for (int i=0; i<k; i++) {
        friends[i] = i+1;
    }

    for (int i=0; i<m; i++) {
        int r;
        cin >> r;

        vector<int> nf;
        for (int j=0; j<friends.size(); j++) {
            if ((j+1) % r != 0) {
                nf.push_back(friends[j]);
            }
        }

        friends = nf;
    }

    for (int f : friends) {
        cout << f << "\n";
    }

    return 0;
}