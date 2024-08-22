#include <bits/stdc++.h>
#include <boost/multiprecision/cpp_int.hpp>
using namespace std;
using cint = boost::multiprecision::cpp_int;

void solve() {
    string S;
    cin >> S;
    int N = S.size();
    vector<vector<int>> p(1, vector<int>(N));
    for (int i = 0; i < N; i++) {
        if (S[i] == 'L') p[0][i] = i-1;
        else p[0][i] = i+1;
    }
    cint K = 1;
    for (int k = 0; k < 100; k++) K *= 10;
    cint x = 2;
    while (x <= K) {
        vector<int> np(N);
        for (int i = 0; i < N; i++) np[i] = p.back()[p.back()[i]];
        p.push_back(np);
        x *= 2;
    }
    vector<int> v(N);
    iota(v.begin(), v.end(), 0);
    for (int k = 0; k < (int)p.size() && K > 0; k++) {
        if (K % 2 == 1) {
            vector<int> nv(N);
            for (int i = 0; i < N; i++) {
                nv[i] = p[k][v[i]];
            }
            swap(v, nv);
        }
        K /= 2;
    }
    vector<int> cnt(N, 0);
    for (int i = 0; i < N; i++) cnt[v[i]]++;

    for (int x : cnt) cout << x << " ";
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
