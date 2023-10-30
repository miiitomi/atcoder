// https://atcoder.jp/contests/abc304/tasks/abc304_d
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
    int W, H, N;
    cin >> W >> H >> N;
    vector<int> p(N), q(N);
    for (int i = 0; i < N; i++) cin >> p[i] >> q[i];

    int A, B;
    cin >> A;
    vector<int> a(A+1, W);
    for (int i = 0; i < A; i++) cin >> a[i];
    cin >> B;
    vector<int> b(B+1, H);
    for (int i = 0; i < B; i++) cin >> b[i];

    map<pair<int,int>, int> mp;
    for (int i = 0; i < N; i++) {
        p[i] = distance(a.begin(), lower_bound(a.begin(), a.end(), p[i]));
        q[i] = distance(b.begin(), lower_bound(b.begin(), b.end(), q[i]));
        mp[make_pair(p[i], q[i])]++;
    }

    int mi = 1e+9, ma = -1, cnt = 0;
    for (auto iter = mp.begin(); iter != mp.end();iter++) {
        mi = min(mi, iter->second);
        ma = max(ma, iter->second);
        cnt++;
    }

    if ((ll)cnt < (A+1LL)*(B+1LL)) mi = 0;

    cout << mi << " " << ma << endl;
}
