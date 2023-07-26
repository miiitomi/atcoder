#include <bits/stdc++.h>
using namespace std;
typedef unsigned int uint;

void solve() {
    int N, K;
    cin >> N >> K;
    vector<pair<uint, uint>> a(N);
    for (int i = 0; i < N; i++) {
        cin >> a[i].first;
        a[i].second = i+1;
    }
    sort(a.begin(), a.end());

    int i = -1;
    int j = -1;
    int x = -1;
    int m_value = -1;

    for (int k = 0; k < N-1; k++) {
        uint y = (~a[k].first) % (1 << K);
        int new_value = ((a[k].first ^ y) & (a[k+1].first ^ y));
        if (m_value < new_value) {
            m_value = new_value;
            i = a[k].second;
            j = a[k+1].second;
            x = y;
        }
    }

    cout << i << " " << j << " " << x << endl;
}

int main() {
    int T;
    cin >> T;
    for (int i = 0; i < T; i++) solve();
}
