// https://atcoder.jp/contests/abc135/tasks/abc135_b
#include <bits/stdc++.h>
using namespace std;

bool is_ok(vector<int> p, vector<int> &q, int i, int j) {
    swap(p[i], p[j]);
    return p == q;
}

int main() {
    int N;
    cin >> N;
    vector<int> p(N);
    for (int i = 0; i < N; i++) cin >> p[i];
    vector<int> q = p;
    sort(q.begin(), q.end());

    for (int i = 0; i < N; i++) {
        for (int j = i; j < N; j++) {
            if (is_ok(p, q, i, j)) {
                cout << "YES" << endl;
                return 0;
            }
        }
    }

    cout << "NO" << endl;
}
