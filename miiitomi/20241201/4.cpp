// https://atcoder.jp/contests/abc139/tasks/abc139_e
#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;
using ll = long long;
using mint = modint998244353;
const ll INF = 2e+18;
const ll MOD = 998244353;

void solve() {
    int N;
    cin >> N;
    vector<deque<int>> A(N);
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N-1; j++) {
            int b;
            cin >> b;
            b--;
            A[i].push_back(b);
        }
    }
    set<pair<int,int>> done;
    deque<pair<int,int>> Q;
    for (int i = 0; i < N; i++) {
        int j = A[i].front();
        if (A[j].front() == i && !done.contains({min(i,j), max(i,j)})) {
            done.insert({min(i,j), max(i,j)});
            Q.push_back({min(i,j), max(i,j)});
        }
    }
    vector<int> last(N, 0);
    int d = 1;
    while (!Q.empty()) {
        auto [i, j] = Q.front();
        Q.pop_front();
        if (last[i] == d || last[j] == d) d++;
        last[i] = d;
        last[j] = d;
        A[i].pop_front();
        if (!A[i].empty()) {
            int k = A[i].front();
            if (!A[k].empty() && A[k].front() == i && !done.contains({min(i,k), max(i,k)})) {
                done.insert({min(i,k), max(i,k)});
                Q.push_back({min(i,k), max(i,k)});
            }
        }
        A[j].pop_front();
        if (!A[j].empty()) {
            int k = A[j].front();
            if (!A[k].empty() && A[k].front() == j && !done.contains({min(j,k), max(j,k)})) {
                done.insert({min(j,k), max(j,k)});
                Q.push_back({min(j,k), max(j,k)});
            }
        }
    }
    d = *max_element(last.begin(), last.end());
    if ((int)done.size() == (N*(N-1)/2)) cout << d << endl;
    else cout << -1 << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout << fixed << setprecision(15);
    int T = 1;
    // cin >> T;
    while (T--) solve();
}
