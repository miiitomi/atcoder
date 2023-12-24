// https://atcoder.jp/contests/abc229/tasks/abc229_d
#include <bits/stdc++.h>
using namespace std;

int main() {
    string S;
    cin >> S;
    int K;
    cin >> K;

    deque<int> A, B, C;
    for (int i = 0; i < (int)S.size(); i++) if (S[i] == '.') C.push_back(i);

    while (!C.empty() && K--) {
        B.push_back(C.front());
        C.pop_front();
    }

    int ans = -1;
    while (true) {
        if (A.empty()) {
            if (C.empty()) ans = S.size();
            else ans = max(ans, C.front());
        } else if (C.empty()) {
            ans = max(ans, -1 + (int)S.size() - A.back());
        } else {
            ans = max(ans, C.front() - A.back() - 1);
        }

        if (C.empty()) break;
        B.push_back(C.front());
        C.pop_front();
        A.push_back(B.front());
        B.pop_front();
    }

    cout << ans << endl;
}
