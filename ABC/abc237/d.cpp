#include <bits/stdc++.h>
using namespace std;

struct Node {
    int n;
    int next = -1;
    int back = -1;

    Node(int i) {
        n = i;
        next = -1;
        back = -1;
    }
};

struct List {
    vector<Node> V;

    List(int N) {
        V.reserve(N);
        V.push_back(Node(0));
    }

    void push(char c) {
        int i = V.size();
        V.push_back(Node(i));
        Node &node_i = V[i];
        if (c == 'L') {
            Node &node_i_1 = V[i-1];
            if (node_i_1.back != -1) {
                Node &node_back = V[node_i_1.back];
                node_back.next = i;
                node_i.back = node_i_1.back;
            }
            node_i_1.back = i;
            node_i.next = i-1;
        } else {
            Node &node_i_1 = V[i-1];
            if (node_i_1.next != -1) {
                Node &node_next = V[node_i_1.next];
                node_next.back = i;
                node_i.next = node_i_1.next;
            }
            node_i_1.next = i;
            node_i.back = i-1;
        }
    }

    void print() {
        int now = 0;
        while (V[now].back != -1) {
            now = V[now].back;
        }
        while (V[now].next != -1) {
            cout << now << " ";
            now = V[now].next;
        }
        cout << now << endl;
    }
};

int main() {
    int N;
    cin >> N;
    string S;
    cin >> S;
    
    List l(N);
    for (char c : S) {
        l.push(c);
    }
    l.print();
}
