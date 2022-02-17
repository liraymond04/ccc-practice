#include <bits/stdc++.h>

using namespace std;

struct Pos {
    int row, col;
};

Pos destination(vector<vector<char> > &grid, vector<vector<bool> > &seen, vector<vector<bool> > &visited, Pos cur) {
    while (true) {
        if (visited[cur.row][cur.col]) {
            return {-1, -1};
        }

        visited[cur.row][cur.col] = true;
        if (grid[cur.row][cur.col] == 'L') {
            cur.col -= 1;
            continue;
        }
        if (grid[cur.row][cur.col] == 'R') {
            cur.col += 1;
            continue;
        }
        if (grid[cur.row][cur.col] == 'D') {
            cur.row += 1;
            continue;
        }
        if (grid[cur.row][cur.col] == 'U') {
            cur.row -= 1;
            continue;
        }

        if (seen[cur.row][cur.col] || grid[cur.row][cur.col] == 'C' || grid[cur.row][cur.col] == 'W') {
            return {-1, -1};
        }

        return cur;
    }
}

int main() {
    setbuf(stdout, 0);

    int n, m;
    cin >> n >> m;
    
    vector<vector<char> > grid(n, vector<char>(m));
    vector<vector<int> > ans(n, vector<int>(m, -1));
    queue<pair<Pos, int> > q;

    vector<Pos> camera;

    int startrow, startcol;
    for (int i=0; i<n; i++) {
        for (int j=0; j<m; j++) {
            cin >> grid[i][j];
            if (grid[i][j] == 'S') {
                startrow = i; startcol = j;
            }
            if (grid[i][j] == 'C') {
                camera.push_back({i, j});
            }
        }
    }

    vector<vector<bool> > seen(n, vector<bool>(m, false));
    for (Pos c : camera) {
        Pos cur = c;
        while (grid[cur.row][cur.col] != 'W') {
            if (grid[cur.row][cur.col] == 'L' || grid[cur.row][cur.col] == 'R' || grid[cur.row][cur.col] == 'U' || grid[cur.row][cur.col] == 'D') {
                cur.row++;
                continue;
            }
            seen[cur.row][cur.col] = true;
            cur.row++;
        }
        cur = c;
        while (grid[cur.row][cur.col] != 'W') {
            if (grid[cur.row][cur.col] == 'L' || grid[cur.row][cur.col] == 'R' || grid[cur.row][cur.col] == 'U' || grid[cur.row][cur.col] == 'D') {
                cur.row--;
                continue;
            }
            seen[cur.row][cur.col] = true;
            cur.row--;
        }
        cur = c;
        while (grid[cur.row][cur.col] != 'W') {
            if (grid[cur.row][cur.col] == 'L' || grid[cur.row][cur.col] == 'R' || grid[cur.row][cur.col] == 'U' || grid[cur.row][cur.col] == 'D') {
                cur.col++;
                continue;
            }
            seen[cur.row][cur.col] = true;
            cur.col++;
        }
        cur = c;
        while (grid[cur.row][cur.col] != 'W') {
            if (grid[cur.row][cur.col] == 'L' || grid[cur.row][cur.col] == 'R' || grid[cur.row][cur.col] == 'U' || grid[cur.row][cur.col] == 'D') {
                cur.col--;
                continue;
            }
            seen[cur.row][cur.col] = true;
            cur.col--;
        }
    }

    if (!seen[startrow][startcol]) {
        q.push({{startrow, startcol}, 0});
    }

    vector<vector<bool> > visited(n, vector<bool>(m, false));
    while (!q.empty()) {
        Pos cur = q.front().first;
        int step = q.front().second;
        ans[cur.row][cur.col] = step;
        q.pop();

        visited[cur.row][cur.col] = true;

        if (grid[cur.row+1][cur.col] == 'W' || seen[cur.row+1][cur.col] || visited[cur.row+1][cur.col]) {
            
        } else {
            if (grid[cur.row+1][cur.col] == 'L' || grid[cur.row+1][cur.col] == 'R' || grid[cur.row+1][cur.col] == 'D' || grid[cur.row+1][cur.col] == 'U') {
                Pos fin = destination(grid, seen, visited, {cur.row+1, cur.col});
                if (fin.row != -1) {
                    q.push({{fin.row, fin.col}, step + 1});
                }
            } else {
                q.push({{cur.row+1, cur.col}, step + 1});
                visited[cur.row+1][cur.col] = true;
            }
        }

        if (grid[cur.row-1][cur.col] == 'W' || seen[cur.row-1][cur.col] || visited[cur.row-1][cur.col]) {
            
        } else {
            if (grid[cur.row-1][cur.col] == 'L' || grid[cur.row-1][cur.col] == 'R' || grid[cur.row-1][cur.col] == 'D' || grid[cur.row-1][cur.col] == 'U') {
                Pos fin = destination(grid, seen, visited, {cur.row-1, cur.col});
                if (fin.row != -1) {
                    q.push({{fin.row, fin.col}, step + 1});
                }
            } else {
                q.push({{cur.row-1, cur.col}, step + 1});
                visited[cur.row-1][cur.col] = true;
            }
        }

        if (grid[cur.row][cur.col+1] == 'W' || seen[cur.row][cur.col+1] || visited[cur.row][cur.col+1]) {
            
        } else {
            if (grid[cur.row][cur.col+1] == 'L' || grid[cur.row][cur.col+1] == 'R' || grid[cur.row][cur.col+1] == 'D' || grid[cur.row][cur.col+1] == 'U') {
                Pos fin = destination(grid, seen, visited, {cur.row, cur.col+1});
                if (fin.row != -1) {
                    q.push({{fin.row, fin.col}, step + 1});
                }
            } else {
                q.push({{cur.row, cur.col+1}, step + 1});
                visited[cur.row][cur.col+1] = true;
            }
        }

        if (grid[cur.row][cur.col-1] == 'W' || seen[cur.row][cur.col-1] || visited[cur.row][cur.col-1]) {
            
        } else {
            if (grid[cur.row][cur.col-1] == 'L' || grid[cur.row][cur.col-1] == 'R' || grid[cur.row][cur.col-1] == 'D' || grid[cur.row][cur.col-1] == 'U') {
                Pos fin = destination(grid, seen, visited, {cur.row, cur.col-1});
                if (fin.row != -1) {
                    q.push({{fin.row, fin.col}, step + 1});
                }
            } else {
                q.push({{cur.row, cur.col-1}, step + 1});
                visited[cur.row][cur.col-1] = true;
            }
        }
    }

    for (int i=0; i<n; i++) {
        for (int j=0; j<m; j++) {
            if (grid[i][j] == '.') {
                cout << ans[i][j] << "\n";
            }
        }
    }

    return 0;
}