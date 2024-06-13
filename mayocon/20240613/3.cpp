// https://atcoder.jp/contests/abc158/tasks/abc158_d
#include <bits/stdc++.h>
using namespace std;

void solve() {
    string S;
    cin >> S;
    deque<char> D;
    for (char c : S) D.push_back(c);
    bool forward = true;
    int Q;
    cin >> Q;
    while (Q--) {
        int t;
        cin >> t;
        if (t == 1) {
            forward = !forward;
        } else {
            int f;
            char c;
            cin >> f >> c;
            if (f == 1) {
                if (forward) D.push_front(c);
                else D.push_back(c);
            } else {
                if (forward) D.push_back(c);
                else D.push_front(c);
            }
        }
    }

    if (forward) {
        while (!D.empty()) {
            cout << D.front();
            D.pop_front();
        }
    } else {
        while (!D.empty()) {
            cout << D.back();
            D.pop_back();
        }
    }
    cout << "\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout << fixed << setprecision(15);
    int T = 1;
    // cin >> T;
    while (T--) solve();
}
