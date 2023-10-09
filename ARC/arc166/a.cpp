#include <bits/stdc++.h>
using namespace std;

int N;
string X, Y;

bool is_ok(int s, int e) {
    if (s >= e) return true;

    int as = 0;
    int bs = 0;
    for (int i = s; i < e; i++) {
        if (Y[i] == 'A') as++;
        else bs++;
    }

    int x_a=0, x_b=0, x_c=0;
    for (int i = s; i < e; i++) {
        if (X[i] == 'A') x_a++;
        else if (X[i] == 'B') x_b++;
        else x_c++;
    }

    for (int i = s; i < e; i++) {
        if (X[i] == 'C') {
            if (x_a < as) {
                x_a++;
                X[i] = 'A';
            } else {
                X[i] = 'B';
                x_b++;
            }
        }
    }

    if (x_a != as || x_b != bs) return false;

    int next_b = e;
    for (int i = s; i < e; i++) {
        if (X[i] == 'B') {
            next_b = i;
            break;
        }
    }

    for (int i = s; i < e; i++) {
        if (X[i] == 'A') {
            if (Y[i] == 'A') continue;
            else {
                if (next_b >= e) return false;
                X[next_b] = 'A';
                for (int j = next_b+1; j < e; j++) {
                    if (X[j] == 'B') {
                        next_b = j;
                        break;
                    }
                    if (j == e-1) next_b = e;
                }
            }
        } else {
            if (Y[i] == 'B') {
                for (int j = next_b+1; j < e; j++) {
                    if (X[j] == 'B') {
                        next_b = j;
                        break;
                    }
                    if (j == e-1) next_b = e;
                }
            } else return false;
        }
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

    for (int i = 0; i <= (int)Cs.size(); i++) {
        int x, y;
        if (Cs.size() == 0) {
            x = 0;
            y = N;
        } else if (i == 0) {
            if (Cs[i] == 0) continue;
            x = 0;
            y = Cs[i];
        } else if (i < (int)Cs.size()) {
            x = Cs[i-1]+1;
            y = Cs[i];
        } else {
            x = Cs[i-1]+1;
            y = N;
        }

        if (!is_ok(x, y)) {
            cout << "No" << endl;
            return;
        }
    }

    cout <<"Yes" << endl;
}

int main() {
    int T;
    cin >> T;
    for (int t = 0; t < T; t++) solve();
}
