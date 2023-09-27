// https://atcoder.jp/contests/abc216/tasks/abc216_d
#include <bits/stdc++.h>
using namespace std;

int main() {
    int N, M;
    cin >> N >> M;
    vector<int> k(M);
    vector<queue<int>> a(M);

    queue<pair<int, int>> Q;
    vector<int> t(N, -1);

    for (int i = 0; i < M; i++) {
        cin >> k[i];
        for (int j = 0; j < k[i]; j++) {
            int x;
            cin >> x;
            x--;
            a[i].push(x);

            if (j == 0) {
                if (t[x] != -1) Q.push(make_pair(t[x], i));
                else t[x] = i;
            }
        }
    }

    while (!Q.empty()) {
        vector<int> I(2);
        I[0] = Q.front().first;
        I[1] = Q.front().second;
        Q.pop();

        for (int i : I) {
            a[i].pop();
            if (a[i].empty()) continue;
            int x = a[i].front();
            if (t[x] != -1) Q.push(make_pair(t[x], i));
            else t[x] = i;
        }
    }

    for (int i = 0; i < M; i++) if (!a[i].empty()) {
        cout << "No" << endl;
        return 0;
    }

    cout << "Yes" << endl;
}
