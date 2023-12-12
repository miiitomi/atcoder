// https://atcoder.jp/contests/abc217/tasks/abc217_e
#include <bits/stdc++.h>
using namespace std;

int main() {
    int T;
    cin >> T;

    priority_queue<int, vector<int>, greater<int>> Q;
    deque<int> D;

    while (T--) {
        int k;
        cin >> k;
        if (k == 1) {
            int x;
            cin >> x;
            D.push_back(x);
        } else if (k == 2) {
            if (!Q.empty()) {
                int a = Q.top();
                Q.pop();
                cout << a << endl;
            } else {
                int a = D.front();
                D.pop_front();
                cout << a << endl;
            }
        } else {
            while (!D.empty()) {
                int a = D.front();
                Q.push(a);
                D.pop_front();
            }
        }
    }
}
