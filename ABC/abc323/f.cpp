#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

ll to_left(vector<ll> a, vector<ll> b) {
    ll ans = 0;
    if (a[0] < b[0]) {
        ans += abs(b[0]-1 - a[0]);
        ans += abs(b[1] - a[1]);
    } else if (a[1] != b[1]) {
        ans += abs(b[0]-1 - a[0]);
        ans += abs(b[1] - a[1]);
    } else {
        ans += 1;
        ans += abs(b[0]-1 - a[0]);
        ans += 1;
    }
    return ans;
}

ll to_right(vector<ll> a, vector<ll> b) {
    ll ans = 0;
    if (a[0] > b[0]) {
        ans += abs(b[0]+1 - a[0]);
        ans += abs(b[1] - a[1]);
    } else if (a[1] != b[1]) {
        ans += abs(b[0]+1 - a[0]);
        ans += abs(b[1] - a[1]);
    } else {
        ans += 1;
        ans += abs(b[0]+1 - a[0]);
        ans += 1;
    }
    return ans;
}

ll to_up(vector<ll> a, vector<ll> b) {
    ll ans = 0;
    if (a[1] > b[1]) {
        ans += abs(b[1]+1 - a[1]);
        ans += abs(b[0] - a[0]);
    } else if (a[0] != b[0]) {
        ans += abs(b[1]+1 - a[1]);
        ans += abs(b[0] - a[0]);
    } else {
        ans += 1;
        ans += abs(b[1]+1 - a[1]);
        ans += 1;
    }
    return ans;
}

ll to_down(vector<ll> a, vector<ll> b) {
    ll ans = 0;
    if (a[1] < b[1]) {
        ans += abs(b[1]-1 - a[1]);
        ans += abs(b[0] - a[0]);
    } else if (a[0] != b[0]) {
        ans += abs(b[1]-1 - a[1]);
        ans += abs(b[0] - a[0]);
    } else {
        ans += 1;
        ans += abs(b[1]-1 - a[1]);
        ans += 1;
    }
    return ans;
}

ll yoko(vector<ll> &a, vector<ll> &b, vector<ll> &c) {
    if (b[0] == c[0]) return 0;

    ll ans = 0;
    if (b[0] < c[0]) {
        ans += to_left(a, b);
        a[0] = b[0]-1;
        a[1] = b[1];
        ans += abs(c[0]-b[0]);
        b[0] = c[0];
        a[0] = b[0]-1;
    } else {
        ans += to_right(a, b);
        a[0] = b[0]+1;
        a[1] = b[1];
        ans += abs(b[0]-c[0]);
        b[0] = c[0];
        a[0] = b[0]+1;
    }
    return ans;
}

ll tate(vector<ll> &a, vector<ll> &b, vector<ll> &c) {
    if (b[1] == c[1]) return 0;

    ll ans = 0;
    if (b[1] < c[1]) {
        ans += to_down(a, b);
        a[1] = b[1]-1;
        a[0] = b[0];
        ans += abs(c[1]-b[1]);
        b[1] = c[1];
        a[1] = b[1]-1;
    } else {
        ans += to_up(a, b);
        a[1] = b[1]+1;
        a[0] = b[0];
        ans += abs(b[1] - c[1]);
        b[1] = c[1];
        a[1] = b[1]+1;
    }
    return ans;
}


ll tate_yoko(vector<ll> a, vector<ll> b, vector<ll> c) {
    ll ans = 0;
    ans += tate(a, b, c);
    ans += yoko(a, b, c);
    return ans;
}

ll yoko_tate(vector<ll> a, vector<ll> b, vector<ll> c) {
    ll ans = 0;
    ans += yoko(a, b, c);
    ans += tate(a, b, c);
    return ans;
}

int main() {
    vector<ll> a(2), b(2), c(2);
    cin >> a[0] >> a[1] >> b[0] >> b[1] >> c[0] >> c[1];

    ll ans = min(tate_yoko(a, b, c), yoko_tate(a, b, c));
    cout << ans << endl;
}
