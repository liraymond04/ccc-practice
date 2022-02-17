#include <bits/stdc++.h>

using namespace std;

bool dfs(vector<vector<int> > &adj, int p, int q, vector<bool> &visited) {
    if (p == q) {
        return true;
    }

    bool ans = false;
    visited[p] = true;
    for (int c : adj[p]) {
        if (visited[c]) continue;
        ans |= dfs(adj, c, q, visited);
    }
    
    return ans;
}

int main() {
    setbuf(stdout, 0);

    int n, m;
    cin >> n >> m;

    vector<vector<int> > adj(n+1);

    for (int i=0; i<m; i++) {
        int f, t;
        cin >> f >> t;
        adj[f].push_back(t);
    }

    int p, q;
    cin >> p >> q;
    
    vector<bool> visited(n+1, false);
    vector<bool> visited1(n+1, false);
    if (dfs(adj, p, q, visited)) {
        cout << "yes";
    } else if (dfs(adj, q, p, visited1)) {
        cout << "no";
    } else {
        cout << "unknown";
    }

    return 0;
}