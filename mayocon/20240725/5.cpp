// https://atcoder.jp/contests/abc322/tasks/abc322_d
#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;
using ll = long long;
using mint = modint998244353;
const ll INF = 2e+18;
const ll MOD = 998244353;

void f(vector<string> &A) {
    int M = A.size(), N = A[0].size();
    bool done = false;
    while (!done) {
        done = true;
        if (A[0] == string(N, '.')) {
            A.erase(A.begin());
            M--;
            done = false;
        }
        if (!done) continue;

        if (A.back() == string(N, '.')) {
            A.pop_back();
            M--;
            done = false;
        }
        if (!done) continue;

        bool contain_black = false;
        for (int i = 0; i < M; i++) if (A[i][0] == '#') contain_black = true;
        if (!contain_black) {
            for (int i = 0; i < M; i++) A[i].erase(A[i].begin());
            N--;
            done = false;
            continue;
        }

        contain_black = false;
        for (int i = 0; i < M; i++) if (A[i].back() == '#') contain_black = true;
        if (!contain_black) {
            for (int i = 0; i < M; i++) A[i].pop_back();
            N--;
            done = false;
            continue;
        }
    }
}

void g(vector<string> &A) {
    int M = A.size(), N = A[0].size();
    vector<string> B(N, string(M, '.'));
    for (int i = 0; i < M; i++) {
        for (int j = 0; j < N; j++) {
            B[j][M-1-i] = A[i][j];
        }
    }
    swap(A, B);
}

bool is_ok(vector<string> &A, vector<string> &B, vector<string> &C) {
    for (int ai = 0; ai + A.size() <= 4; ai++) {
        for (int aj = 0; aj + A[0].size() <= 4; aj++) {
            for (int bi = 0; bi + B.size() <= 4; bi++) {
                for (int bj = 0; bj + B[0].size() <= 4; bj++) {
                    for (int ci = 0; ci + C.size() <= 4; ci++) {
                        for (int cj = 0; cj + C[0].size() <= 4; cj++) {
                            vector<vector<ll>> cnt(4, vector<ll>(4, 0));
                            for (int i = 0; i < A.size(); i++) {
                                for (int j = 0; j < A[0].size(); j++) {
                                    if (A[i][j] == '#') cnt[ai+i][aj+j]++;
                                }
                            }
                            for (int i = 0; i < B.size(); i++) {
                                for (int j = 0; j < B[0].size(); j++) {
                                    if (B[i][j] == '#') cnt[bi+i][bj+j]++;
                                }
                            }
                            for (int i = 0; i < C.size(); i++) {
                                for (int j = 0; j < C[0].size(); j++) {
                                    if (C[i][j] == '#') cnt[ci+i][cj+j]++;
                                }
                            }

                            bool exists_not_one = false;
                            for (int i = 0; i < 4; i++) {
                                for (int j = 0; j < 4; j++) {
                                    if (cnt[i][j] != 1) {
                                        exists_not_one = true;
                                    }
                                }
                            }

                            if (!exists_not_one) return true;
                        }
                    }
                }
            }
        }
    }
    return false;
}

void solve() {
    vector<string> A(4), B(4), C(4);
    for (int i = 0; i < 4; i++) cin >> A[i];
    for (int i = 0; i < 4; i++) cin >> B[i];
    for (int i = 0; i < 4; i++) cin >> C[i];
    f(A);
    f(B);
    f(C);

    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 4; j++) {
            if (is_ok(A, B, C)) {
                cout << "Yes\n";
                return;
            }
            g(B);
        }
        g(C);
    }
    cout << "No\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout << fixed << setprecision(15);
    int T = 1;
    // cin >> T;
    while (T--) solve();
}
