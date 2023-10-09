#include <bits/stdc++.h>
using namespace std;

int N;
string X, Y;

bool is_ok(int s, int e) {
    int a_x = 0, a_y = 0;
    for (int i = s; i < e; i++) {
        if (X[i] == 'A') a_x++;
        if (Y[i] == 'A') a_y++;
    }

    vector<int> B_x, B_y;
    for (int i = s; i < e; i++) {
        if (X[i] == 'C') {
            if (a_x < a_y) a_x++;
            else X[i] = 'B';
        }
        if (X[i] == 'B') B_x.push_back(i);
        if (Y[i] == 'B') B_y.push_back(i);
    }

    if (a_x != a_y) return false;

    for (int i = 0; i < (int)B_x.size(); i++) {
        if (B_x[i] < B_y[i]) return false;
    }
    
    return true;
}

void solve() {
    cin >> N >> X >> Y;

    vector<int> Cs;
    for (int i = 0; i < N; i++) {
        if (Y[i] == 'C') {
            if (X[i] == 'C') Cs.push_back(i);
            else {
                cout << "No" << endl;
                return;
            }
        }
    }

    if (Cs.empty()) {
        if (!is_ok(0, N)) {
            cout << "No" << endl;
            return;
        }
    } else {
        for (int i = 0; i <= (int)Cs.size(); i++) {
            int s, e;
            if (i == 0) {
                s = 0;
                e = Cs[i];
            } else if (i < Cs.size()) {
                s = Cs[i-1]+1;
                e = Cs[i];
            } else {
                s = Cs[i-1]+1;
                e = N;
            }
            if (!is_ok(s, e)) {
                cout << "No" << endl;
                return;
            }
        }
    }

    cout << "Yes" << endl;
    return;
}

int main() {
    int T;
    cin >> T;
    for (int t = 0; t < T; t++) solve();
}
