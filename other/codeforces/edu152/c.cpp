#include <bits/stdc++.h>
using namespace std;

void solve() {
    int N, M;
    cin >> N >> M;
    string S;
    cin >> S;
    vector<int> A(N+1, 0);
    for (int i = 0; i < N; i++) {
        A[i+1] = A[i];
        if (S[i] == '1') A[i+1]++;
    }

    set<pair<int, int>> Q;
    for (int i = 0; i < M; i++) {
        int l, r;
        cin >> l >> r;
        l--;

        if (A[r] - A[l] == 0 || A[r] - A[l] == r - l) {
            Q.insert(make_pair(-1, -1));
            continue;
        }

        if (S[l] == '0') {
            int rr = r;
            int m;
            while (rr - l > 1) {
                m = (rr + l) / 2;
                if (A[m] - A[l] != 0) {
                    rr = m;
                } else {
                    l = m;
                }
            }
        }

        if (A[r] - A[l] == 0 || A[r] - A[l] == r - l) {
            Q.insert(make_pair(-1, -1));
            continue;
        }

        if (S[r-1] == '1') {
            int ll = l;
            int rr = r;
            int m;
            while (rr - ll > 1) {
                m = (rr + ll) / 2;
                if (A[r] - A[m] == r - m) {
                    rr = m;
                } else {
                    ll = m;
                }
            }
            r = rr;
        }

        if (A[r] - A[l] == 0 || A[r] - A[l] == r - l) {
            Q.insert(make_pair(-1, -1));
            continue;
        }

        Q.insert(make_pair(l, r));
    }

    cout << (int)Q.size() << endl;
}

int main() {
    int T;
    cin >> T;
    for (int i = 0; i < T; i++) solve();
}
