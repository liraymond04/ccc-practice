#include <bits/stdc++.h>

using namespace std;

void add(vector<int> &points, int a, int b, int p) {
    if (p == 1) {
        points[a] += 1;
        points[b] += 1;
    } else if (p == 2) {
        points[b] += 3;
    } else if (p == 3) {
        points[a] += 3;
    }
}

bool check(vector<int> &games, int t) {
    vector<int> points(5, 0);
    add(points, 1, 2, games[0]);
    add(points, 1, 3, games[1]);
    add(points, 1, 4, games[2]);
    add(points, 2, 3, games[3]);
    add(points, 2, 4, games[4]);
    add(points, 3, 4, games[5]);
    for (int i=1; i<=4; i++) {
        if (t != i) {
            if (points[t] <= points[i]) {
                return false;
            }
        }
    }
    return true;
}

int main() {
    setbuf(stdout, 0);

    int t, g;
    cin >> t >> g;

    vector<int> games(6, 0);
    vector<bool> fixed(6, false);
    vector<int> to(6, 3);

    vector<int> nums(13);
    nums[2] = 0;
    nums[3] = 1;
    nums[4] = 2;
    nums[6] = 3;
    nums[8] = 4;
    nums[12] = 5;
    // 1-tie, 2-loss, 3-win
    for (int i=0; i<g; i++) {
        int a, b, sa, sb;
        cin >> a >> b >> sa >> sb;
        fixed[nums[a*b]] = true;
        to[nums[a*b]] = 1;
        if (sa > sb) {
            games[nums[a*b]] = 3;
        } else if (sa < sb) {
            games[nums[a*b]] = 2;
        } else {
            games[nums[a*b]] = 1;
        }
    }

    int ans = 0;
    for (int a=1; a<=to[0]; a++) {
        // game 0
        if (!fixed[0])
            games[0] = a;
        for (int b=1; b<=to[1]; b++) {
        // game 1
            if (!fixed[1])
                games[1] = b;
            int toc = 3;
            if (fixed[2]) {
                toc = 1;
            }
            for (int c=1; c<=to[2]; c++) {
            // game 2
                if (!fixed[2])
                    games[2] = c;
                for (int d=1; d<=to[3]; d++) {
                // game 3
                    if (!fixed[3])
                        games[3] = d;
                    for (int e=1; e<=to[4]; e++) {
                    // game 4
                        if (!fixed[4])
                            games[4] = e;
                        for (int f=1; f<=to[5]; f++) {
                        // game 5
                            if (!fixed[5])
                                games[5] = f;
                            if (check(games, t)) ans++;
                        }
                    }
                }
            }
        }
    }

    cout << ans;

    return 0;
}