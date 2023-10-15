#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

struct Task {
    ll id=0;
    ll d=0;
    ll c=0;
    ll s=0;

    Task() {}

    Task (ll _id, ll _d, ll _c, ll _s) {
        id = _id;
        d = _d;
        c = _c;
        s = _s;
    }
};

bool cmp(Task &a, Task &b) {
    return a.d < b.d;
}


int main() {
    int N;
    cin >> N;
    vector<Task> V(N);
    for (int i = 0; i < N; i++) {
        ll d, c, s;
        cin >> d >> c >> s;
        V[i] = Task(i, d, c, s);
    }
    sort(V.begin(), V.end(), cmp);

    vector<ll> dp(V[N-1].d+1, 0);
    for (Task &t : V) {
        for (int d = t.d; d >= 0; d--) {
            if (d - t.c < 0) break;
            dp[d] = max(dp[d], dp[d - t.c] + t.s);
        }
    }
    cout << *max_element(dp.begin(), dp.end()) << endl;
}
