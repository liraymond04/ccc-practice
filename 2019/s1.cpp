#include <bits/stdc++.h>

using namespace std;

int main() {
    vector<vector<int> > grid = { {1, 2}, {3, 4} };

    string s;
    cin >> s;

    int h = 0, v = 0;
    for (char c : s) {
        if (c == 'H') {
            h++;
        } else {
            v++;
        }
    }

    if (h & 1) {
        reverse(grid.begin(), grid.end());
    }
    if (v & 1) {
        reverse(grid[0].begin(), grid[0].end());
        reverse(grid[1].begin(), grid[1].end());
    }
    
    for (int i=0; i<2; i++) {
        for (int j=0; j<2; j++) {
            cout << grid[i][j] << " ";
        }
        cout << "\n";
    }

    return 0;
}