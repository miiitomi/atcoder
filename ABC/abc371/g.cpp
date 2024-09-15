#include <bits/stdc++.h>
#include <boost/multiprecision/cpp_int.hpp>
using namespace std;
using cint = boost::multiprecision::cpp_int;
const int INF = 1e+9;

void solve() {
    int N;
    cin >> N;
    vector<int> P(N), A(N), ans(N);
    for (int i = 0; i < N; i++) {
        cin >> P[i];
        P[i]--;
    }
    for (int i = 0; i < N; i++) {
        cin >> A[i];
        A[i]--;
    }
    cint x = 0, L1 = 1;
    vector<bool> done(N, false);
    for (int i = 0; i < N; i++) {
        if (done[i]) continue;
        int j = i;
        vector<int> cycle(1, j);
        done[j] = true;
        while (!done[P[j]]) {
            j = P[j];
            cycle.push_back(j);
            done[j] = true;
        }
        int mv = INF;
        cint nx = -1, L2 = cycle.size();
        cint L = lcm(L1, L2);
        for (cint y = x; y < L; y += L1) {
            if (mv > A[cycle[(int)(y%L2)]]) {
                mv = A[cycle[(int)(y%L2)]];
                nx = y;
            }
        }
        for (int k = 0; k < (int)cycle.size(); k++) {
            ans[cycle[k]] = A[cycle[(int)((k+nx)%L2)]];
        }
        swap(x, nx);
        swap(L1, L);
    }

    for (int a : ans) cout << a+1 << " ";
    cout << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout << fixed << setprecision(15);
    int T = 1;
    // cin >> T;
    while (T--) solve();
}
