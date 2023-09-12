#include <bits/stdc++.h>
using namespace std;

void solve() {
    int N;
    cin >> N;
    set<int> S;
    for (int i = 0; i < N; i++) {
        int x;
        cin >> x;
        S.insert(x);
    }

    int x = 0;
    while (S.count(x)) x++;

    while (true) {
        cout << x << endl;
        fflush(stdout);

        int y;
        cin >> y;

        if (y < 0) return;
        else x = y;
    }
}

int main() {
    int T;
    cin >> T;
    for (int t = 0; t < T; t++) solve();
}
