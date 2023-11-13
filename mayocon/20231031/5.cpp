// https://atcoder.jp/contests/abc323/tasks/abc323_f
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

ll to_left(ll xa, ll ya, ll xb, ll yb) {
    if (ya != yb || xa < xb) {
        return abs(xb-1 - xa) + abs(yb - ya);
    } else return 1 + to_left(xa, ya+1, xb, yb);
}

ll to_right(ll xa, ll ya, ll xb, ll yb) {
    if (ya != yb || xb < xa) {
        return abs(xb+1 - xa) + abs(yb - ya);
    } else return 1 + to_right(xa, ya+1, xb, yb);
}

ll to_upper(ll xa, ll ya, ll xb, ll yb) {
    if (xa != xb || yb < ya) {
        return abs(xb - xa) + abs(yb+1 - ya);
    } else return 1 + to_upper(xa+1, ya, xb, yb);
}

ll to_down(ll xa, ll ya, ll xb, ll yb) {
    if (xa != xb || yb > ya) {
        return abs(xb - xa) + abs(yb-1 - ya);
    } else return 1 + to_down(xa+1, ya, xb, yb);
}

ll tate(ll xb, ll yb, ll xc, ll yc) {
    return abs(yb - yc);
}

ll yoko(ll xb, ll yb, ll xc, ll yc) {
    return abs(xb - xc);
}

ll tate_yoko(ll xa, ll ya, ll xb, ll yb, ll xc, ll yc) {
    ll ans = 0;
    if (yb < yc) {
        ans += to_down(xa, ya, xb, yb);
        ans += tate(xb, yb, xc, yc);
        yb = yc;
        ya = yb - 1;
        xa = xb;
    } else if (yb > yc) {
        ans += to_upper(xa, ya, xb, yb);
        ans += tate(xb, yb, xc, yc);
        yb = yc;
        ya = yb + 1;
        xa = xb;
    }

    if (xb < xc) {
        ans += to_left(xa, ya, xb, yb);
        ans += yoko(xb, yb, xc, yc);
    } else if (xb > xc) {
        ans += to_right(xa, ya, xb, yb);
        ans += yoko(xb, yb, xc, yc);
    }

    return ans;
}

ll yoko_tate(ll xa, ll ya, ll xb, ll yb, ll xc, ll yc) {
    ll ans = 0;
    if (xb < xc) {
        ans += to_left(xa, ya, xb, yb);
        ans += yoko(xb, yb, xc, yc);
        xb = xc;
        xa = xb - 1;
        ya = yb;
    } else if (xb > xc) {
        ans += to_right(xa, ya, xb, yb);
        ans += yoko(xb, yb, xc, yc);
        xb = xc;
        xa = xb + 1;
        ya = yb;
    }

    if (yb < yc) {
        ans += to_down(xa, ya, xb, yb);
        ans += tate(xb, yb, xc, yc);
    } else if (yb > yc) {
        ans += to_upper(xa, ya, xb, yb);
        ans += tate(xb, yb, xc, yc);
    }

    return ans;
}


int main() {
    ll xa, ya, xb, yb, xc, yc;
    cin >> xa >> ya >> xb >> yb >> xc >> yc;

    cout << min(tate_yoko(xa, ya, xb, yb, xc, yc), yoko_tate(xa, ya, xb, yb, xc, yc)) << endl;
}
