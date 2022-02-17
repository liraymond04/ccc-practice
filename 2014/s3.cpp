#include <bits/stdc++.h>

using namespace std;

int main() {
    int t;
    cin >> t;

    for (int i=0; i<t; i++) {
        int n;
        cin >> n;
        vector<int> mountain;

        for (int j=0; j<n; j++) {
            int input;
            cin >> input;
            mountain.push_back(input);
        }

        vector<int> branch;
        int car = n - 1;

        int next = 1;
        bool result = true;

        while (result && next <= n) {
            if (car >= 0 && next == mountain[car]) {
                car--;
                next++;
            } else if (branch.size() > 0 && next == branch[branch.size()-1]) {
                branch.erase(branch.begin() + (branch.size()-1));
                next++;
            } else if (car >= 0) {
                branch.push_back(mountain[car]);
                car--;
            } else {
                result = false;
            }
        }

        if (result) {
            cout << "Y" << endl;
        } else {
            cout << "N" << endl;
        }
    }

    return 0;
}