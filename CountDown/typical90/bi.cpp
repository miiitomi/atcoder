#include <bits/stdc++.h>
using namespace std;

int main() {
    int Q;
    cin >> Q;
    deque<int> D;
    while (Q--) {
        int t, x;
        cin >> t >> x;
        if (t == 1) D.push_front(x);
        else if (t == 2) D.push_back(x);
        else cout << D[x-1] << "\n";
    }
}
