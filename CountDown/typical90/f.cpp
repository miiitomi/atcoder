#include <bits/stdc++.h>
using namespace std;

int main() {
    int N, K;
    cin >> N >> K;
    string S;
    cin >> S;

    string ans(K, 'x');
    priority_queue<pair<char,int>, vector<pair<char,int>>, greater<pair<char,int>>> Q;
    for (int i = 0; i + K <= N; i++) Q.push(make_pair(S[i], i));

    int now = 0;
    for (int i = 0; i < K; i++) {
        while (Q.top().second < now) Q.pop();
        auto p = Q.top();
        Q.pop();
        ans[i] = p.first;
        now = p.second;

        if (i != K-1) {
            int idx = N - (K - 1 - i);
            Q.push(make_pair(S[idx], idx));
        }
    }

    cout << ans << endl;
}
