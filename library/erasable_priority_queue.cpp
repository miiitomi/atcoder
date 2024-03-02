template<typename T> struct erasable_priority_queue {
    priority_queue<T> Q, R;

    void push(T x) {
        Q.push(x);
    }

    void erase(T x) {
        R.push(x);
    }

    T top() {
        T x = Q.top();
        while (!R.empty() && R.top() == x) {
            Q.pop();
            R.pop();
            x = Q.top();
        }
        return x;
    }

    int size() {
        return Q.size() - R.size();
    }

    bool empty() {
        return Q.size() == R.size();
    }
};
