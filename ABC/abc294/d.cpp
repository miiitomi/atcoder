#include <bits/stdc++.h>
using namespace std;

int main() {
    int N, Q;
    cin >> N >> Q;

    set<int> called, uncalled;
    for (int i = 1; i <= N; i++) uncalled.insert(i);

    for (int q = 0; q < Q; q++) {
        int k;
        cin >> k;

        if (k == 1) {
            int a = *uncalled.begin();
            uncalled.erase(a);
            called.insert(a);
        } else if (k == 2) {
            int a;
            cin >> a;
            called.erase(a);
        } else {
            int a = *called.begin();
            cout << a << endl;
        }
    }
}
