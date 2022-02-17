#include <bits/stdc++.h>

using namespace std;

struct In {
    int x1, y1, x2, y2, tint;
};

int main() {
    setbuf(stdout, 0);
    int n, t;
    cin >> n >> t;

    set<int> x, y;
    vector<In> in(n);
    for (int i=0; i<n; i++) {
        int x1, y1, x2, y2, tint;
        cin >> x1 >> y1 >> x2 >> y2 >> tint;
        in[i] = {x1, y1, x2, y2, tint};
        x.insert(x1); x.insert(x2);
        y.insert(y1); y.insert(y2);
    }


    vector<vector<long long> > diff(y.size(), vector<long long>(x.size(), 0));

    unordered_map<int, int> numx, numy;
    vector<int> vx, vy;
    int i=0;
    for (int c : x) {
        numx[c] = i;
        i++;
        vx.push_back(c);
    }
    i=0;
    for (int c : y) {
        numy[c] = i;
        i++;
        vy.push_back(c);
    }

    for (In cur : in) {
        for (int i=numy[cur.y1]; i<numy[cur.y2]; i++) {
            diff[i][numx[cur.x1]] += cur.tint;
            diff[i][numx[cur.x2]] -= cur.tint;
        }
    }

    for (int i=0; i<y.size(); i++) {
        for (int j=0; j<x.size()-1; j++) {
            diff[i][j+1] = diff[i][j] + diff[i][j+1];
        }
    }

    long long area = 0;
    for (int i=0; i<y.size()-1; i++) {
        for (int j=0; j<x.size()-1; j++) {
            if (diff[i][j] >= t) {
                area += (long long)(vy[i+1] - vy[i]) * (vx[j+1] - vx[j]);
            }
        }
    }

    cout << area;

    return 0;
}