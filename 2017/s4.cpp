#include <bits/stdc++.h>

using namespace std;

struct Edge {
    int u, v, w, i;
    friend bool operator < (const Edge &a, const Edge &b) {
        if (a.w == b.w) {
            return a.i < b.i;
        }
        return a.w < b.w;
    }
};

int find(vector<int> &parent, int x) {
    if (x == parent[x]) {
        return x;
    } else {
        int p = find(parent, parent[x]);
        parent[x] = p;
        return p;
    }
}

bool unite(vector<int> &parent, vector<int> &size, int u, int v) {
    int pu = find(parent, u);
    int pv = find(parent, v);

    if (pu == pv) {
        return false;
    } else {
        if (size[pu] < size[pv]) {
            parent[pu] = pv;
            size[pv] += size[pu];
        } else {
            parent[pv] = pu;
            size[pu] += size[pv];
        }
        return true;
    }
}

int main() {
    setbuf(stdout, 0);

    int n, m, d;
    cin >> n >> m >> d;

    vector<Edge> edges(m);
    for (int i=0; i<m; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        edges[i] = {u, v, w, i};
    }
    sort(edges.begin(), edges.end());

    vector<int> parent(n);
    for (int i=0; i<n; i++) {
        parent[i] = i;
    }

    vector<int> size(n, 1);
    int num = 0, outside = 0;
    Edge maxedge;
    for (const auto &x : edges) {
        if (unite(parent, size, x.u, x.v)) {
            maxedge = x;
            if (x.i >= n-1) {
                outside++;
            } 
            num++;
        }

        if (num == n-1) {
            break;
        }
    }

    if (maxedge.i < n - 1) {
        cout << outside;
        return 0;
    }

    for (int i=0; i<n; i++) {
        parent[i] = i;
        size[i] = 1;
    }
    num = 0;

    for (const auto &x : edges) {
        if (find(parent, x.u) == find(parent, x.v)) {
            continue;
        }
        if (maxedge.w > x.w || (maxedge.w == x.w && x.i < n - 1)) {
            if (unite(parent, size, x.u, x.v)) {
                num++;
            }
        } else {
            if (x.w <= d && x.i < n - 1) {
                cout << outside-1;
                return 0;
            }
        }

        if (num == n-1) {
            break;
        }
    }
    
    cout << outside;

    return 0;
}