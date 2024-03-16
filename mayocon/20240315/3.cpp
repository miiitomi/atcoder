// https://atcoder.jp/contests/abc250/tasks/abc250_c
#include <bits/stdc++.h>
using namespace std;

void solve() {
    int N, Q;
    cin >> N >> Q;
    vector<int> a(N), place(N);
    for (int i = 0; i < N; i++) {
        a[i] = i;
        place[i] = i;
    }

    for (int q = 0; q < Q; q++) {
        int x;
        cin >> x;
        x--;
        int i = place[x];
        int j = i+1;
        if (j == N) j = i-1; 
        int y = a[j];
        swap(a[i], a[j]);
        swap(place[x], place[y]);
    }

    for (int b : a) cout << b+1 << " ";
    cout << "\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout << fixed << setprecision(15);
    int T = 1;
    // cin >> T;
    while (T--) solve();
}
