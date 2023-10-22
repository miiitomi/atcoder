#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

void solve() {
    int N;
    cin >> N;
    string S;
    cin >> S;
    reverse(S.begin(), S.end());

    vector<ll> v;
    v.reserve(N);
    int cnt = 0;
    for (int i = 0; i < N; i++) {
        if (S[i] == '0') {
            v.push_back(i-cnt);
            cnt++;
        }
    }
    for (int i = 1; i < (int)v.size(); i++) v[i] += v[i-1];

    for (int i = 0; i < N; i++) {
        if (i < (int)v.size()) cout << v[i];
        else cout << -1;
        cout << " ";
    }
    cout << endl;
}

int main() {
    int T;
    cin >> T;
    for (int t = 0; t < T; t++) solve();
}
