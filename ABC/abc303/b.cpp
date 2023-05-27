#include <bits/stdc++.h>
using namespace std;

int N, M;

int where_is(int x, vector<int> &v) {
    for (int i = 0; i < N; i++) {
        if (v[i] == x) return i;
    }
    return -1;
}

bool funaka(int x, int y, vector<vector<int> > &a) {
    for (int i = 0; i < M; i++) {
        int x_idx = where_is(x, a[i]);
        int y_idx = where_is(y, a[i]);
        if (abs(x_idx - y_idx) == 1) return false;
    }

    return true;
}

int main() {
    cin >> N >> M;
    vector<vector<int> > a(M, vector<int>(N));

    for (int i = 0; i < M; i++) {
        for (int j = 0; j < N; j++) {
            cin >> a[i][j];
            a[i][j]--;
        }
    }

    int ans = 0;
    for (int x = 0; x < N-1; x++) {
        for (int y = x+1; y < N; y++) {
            if (funaka(x, y, a)) ans++;
        }
    }

    cout << ans << endl;
}
