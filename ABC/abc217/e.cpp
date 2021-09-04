#include <bits/stdc++.h>
using namespace std;

int main() {
    int Q;
    cin >> Q;
    queue<int> que;
    map<int, int> S;
    queue<int> ans;

    for (int i = 0; i < Q; i++) {
        int a;
        cin >> a;
        if (a == 1) {
            int x;
            cin >> x;
            que.push(x);
        } else if (a == 3) {
            while (!que.empty()) {
                S[que.front()]++;
                que.pop();
            }
        } else {
            if (S.empty()) {
                ans.push(que.front());
                que.pop();
            } else {
                int x = S.begin()->first;
                ans.push(x);
                S[x]--;
                if (S[x] == 0) {
                    S.erase(x);
                }
            }
        }
    }

    while (!ans.empty()) {
        cout << ans.front() << endl;
        ans.pop();
    }
}
