// https://atcoder.jp/contests/abc250/tasks/abc250_e
#include <bits/stdc++.h>
using namespace std;

int main() {
    int N;
    cin >> N;
    vector<int> a(N), b(N), v;
    for (int i = 0; i < N; i++) {
        cin >> a[i];
        a[i]--;
        v.push_back(a[i]);
    }
    for (int i = 0; i < N; i++) {
        cin >> b[i];
        b[i]--;
        v.push_back(b[i]);
    }
    sort(v.begin(), v.end());
    v.erase(unique(v.begin(), v.end()), v.end());
    for (int i = 0; i < N; i++) a[i] = distance(v.begin(), lower_bound(v.begin(), v.end(), a[i]));
    for (int i = 0; i < N; i++) b[i] = distance(v.begin(), lower_bound(v.begin(), v.end(), b[i]));

    vector<int> A(v.size(), 1e+9), B(v.size(), 1e+9);
    for (int i = 0; i < N; i++) {
        A[a[i]] = min(A[a[i]], i);
        B[b[i]] = min(B[b[i]], i);
    }
    vector<int> x(N, -1), y(N, -1);
    for (int i = 0; i < N; i++) {
        x[i] = max(x[i], B[a[i]]);
        y[i] = max(y[i], A[b[i]]);
        if (i < N-1) {
            x[i+1] = x[i];
            y[i+1] = y[i];
        }
    }

    int Q;
    cin >> Q;

    for (int q = 0; q < Q; q++) {
        int s, t;
        cin >> s >> t;
        s--;
        t--;
        if (t >= x[s] && s >= y[t]) {
            cout << "Yes" << endl;
        } else {
            cout << "No" << endl;
        }
    }
}
