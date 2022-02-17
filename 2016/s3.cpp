#include <bits/stdc++.h>

using namespace std;


pair<int, int> bfs(vector<vector<int> > &adj, vector<bool> &valid, int n, int x) {
    vector<bool> visited(n, false);
    
    queue<pair<int, int> > q;
    q.push({x, 0});

    int cur, l;
    while (!q.empty()) {
        cur = q.front().first;
        l = q.front().second;
        q.pop();

        visited[cur] = true;

        for (int c : adj[cur]) {
            if (visited[c] || !valid[c]) continue;
            q.push({c, l+1});
        }
    }

    return {cur, l};
}

int diameter(vector<vector<int> > &adj, vector<bool> &valid, int n, int x) {
    pair<int, int > a = bfs(adj, valid, n, x);
    pair<int, int > b = bfs(adj, valid, n, a.first);
    return b.second;
}

bool dfs(vector<vector<int> > &adj, vector<bool> &visited, vector<bool> &valid, int x) {
    bool p = valid[x];

    visited[x] = true;

    for (auto cur : adj[x]) {
        if (visited[cur]) continue;
        p |= dfs(adj, visited, valid, cur);
    }

    valid[x] = p;
    return p;
}

int main() {
    setbuf(stdout, 0);

    int n, m;
    cin >> n >> m;

    vector<bool> valid(n, false), visited(n, false);
    vector<vector<int> > adj(n);
    int num;
    for (int i=0; i<m; i++) {
        cin >> num;
        valid[num] = true;
    }

    for (int i=0; i<n-1; i++) {
        int f, t;
        cin >> f >> t;
        adj[f].push_back(t);
        adj[t].push_back(f);
    }

    dfs(adj, visited, valid, num);
    int d = diameter(adj, valid, n, num);
    int e = accumulate(valid.begin(), valid.end(), 0);

    cout << (e-1) * 2 - d;

    return 0;
}