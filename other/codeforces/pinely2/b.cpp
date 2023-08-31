#include <bits/stdc++.h>
using namespace std;



void solve() {
    int N;
    cin >> N;

    vector<int> a(N), idx(N+1);
    for (int i = 0; i < N; i++) {
        cin >> a[i];
        idx[a[i]] = i;
    }

    int ans = 0;
    int tmp = -1;
    for (int i = 1; i <= N; i++) {
        if (tmp < idx[i]) tmp = idx[i];
        else {
            tmp =idx[i];
            ans++;
        }
    }



    cout << ans << endl;
}

int main() {
    int T;
    cin >> T;
    for (int t = 0; t < T; t++) solve();
}