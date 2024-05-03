// https://atcoder.jp/contests/abc250/tasks/abc250_e
#include <bits/stdc++.h>
using namespace std;

struct Queries {
    int num;
    int x;
    int y;
    bool ans;

    Queries(int num, int x, int y): num(num), x(x), y(y) {};
};

void solve() {
    int N;
    cin >> N;
    vector<int> a(N), b(N), v;
    for (int i = 0; i < N; i++) {
        cin >> a[i];
        v.push_back(a[i]);
    }
    for (int i = 0; i < N; i++) {
        cin >> b[i];
        v.push_back(b[i]);
    }
    sort(v.begin(), v.end());
    v.erase(unique(v.begin(), v.end()), v.end());
    for (int i = 0; i < N; i++) {
        a[i] = distance(v.begin(), lower_bound(v.begin(), v.end(), a[i]));
        b[i] = distance(v.begin(), lower_bound(v.begin(), v.end(), b[i]));
    }
    int M = v.size();

    int Q;
    cin >> Q;
    vector<Queries> V;
    for (int i = 0; i < Q; i++) {
        int x, y;
        cin >> x >> y;
        V.push_back(Queries(i, x, y));
    }
    int B = 1000;
    sort(V.begin(), V.end(), [&](const Queries &l, const Queries &r) {
        if (l.x / B != r.x / B) return l.x/B < r.x/B;
        else return l.y < r.y;
    });

    int x = 0, y = 0;
    vector<int> cnt_a(M, 0), cnt_b(M, 0);
    vector<bool> is_same(M, true);
    int diff = 0;
    for (Queries &q : V) {
        while (x < q.x) {
            int m = a[x];
            if (!is_same[m]) diff--;
            cnt_a[m]++;
            is_same[m] = ((cnt_a[m] == 0 && cnt_b[m] == 0) || (cnt_a[m] > 0 && cnt_b[m] > 0));
            if (!is_same[m]) diff++;
            x++;
        }
        while (x > q.x) {
            x--;
            int m = a[x];
            if (!is_same[m]) diff--;
            cnt_a[m]--;
            is_same[m] = ((cnt_a[m] == 0 && cnt_b[m] == 0) || (cnt_a[m] > 0 && cnt_b[m] > 0));
            if (!is_same[m]) diff++;
        }
        while (y < q.y) {
            int m = b[y];
            if (!is_same[m]) diff--;
            cnt_b[m]++;
            is_same[m] = ((cnt_a[m] == 0 && cnt_b[m] == 0) || (cnt_a[m] > 0 && cnt_b[m] > 0));
            if (!is_same[m]) diff++;
            y++;
        }
        while (y > q.y) {
            y--;
            int m = b[y];
            if (!is_same[m]) diff--;
            cnt_b[m]--;
            is_same[m] = ((cnt_a[m] == 0 && cnt_b[m] == 0) || (cnt_a[m] > 0 && cnt_b[m] > 0));
            if (!is_same[m]) diff++;
        }
        if (diff == 0) q.ans = true;
        else q.ans = false;
    }

    sort(V.begin(), V.end(), [&](const Queries &l, const Queries &r){return l.num < r.num;});
    for (auto &q : V) {
        if (q.ans) cout << "Yes\n";
        else cout << "No\n";
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout << fixed << setprecision(15);
    int T = 1;
    // cin >> T;
    while (T--) solve();
}

