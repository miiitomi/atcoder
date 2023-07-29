#include <bits/stdc++.h>
using namespace std;

void solve() {
    int N;
    cin >> N;
    int count = 0;
    for (int i = 1; i <= N; i++) {
        int p;
        cin >> p;
        if (i == p) count++;
    }

    if (count % 2 == 0) cout << count / 2 << endl;
    else cout << count / 2 + 1 << endl;
}

int main() {
    int T;
    cin >> T;
    for (int t = 0; t < T; t++) solve();    
}
