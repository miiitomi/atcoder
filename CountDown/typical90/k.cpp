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

    ll ans = -1;
    for (int S = 0; S < (1 << N); S++) {
        ll now = 0;
        bool ok = true;
        ll tmp = 0;
        for (Task &v : V) {
            if (!(S&(1 << v.id))) continue;
            tmp += v.s;
            if (now + v.c <= v.d) now += v.c;
            else {
                ok = false;
                break;
            }
        }
        if (ok) ans = max(ans, tmp);
    }

    cout << ans << endl;
}
