#include <bits/stdc++.h>
using namespace std;

void output(int N) {
    int res;
    cout << "mul " << N << endl;
    cin >> res;
    cout << "!" << endl;
    cin >> res;
    return;
}

void solve() {
    int N;
    cin >> N;
    int res;
    cout << "digit" << endl;
    cin >> res;
    cout << "digit" << endl;
    cin >> res;
    cout << "add -8" << endl;
    cin >> res;
    cout << "add -4" << endl;
    cin >> res;
    cout << "add -2" << endl;
    cin >> res;
    cout << "add -1" << endl;
    cin >> res;
    output(N);
    return;
}

int main() {
    int T;
    cin >> T;
    while (T--) {
        solve();
    }
}
