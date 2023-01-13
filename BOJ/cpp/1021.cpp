#include <iostream>
#include <deque>

using namespace std;

int main() {
    cin.tie(NULL);
    cin.sync_with_stdio(false);

    int N, M;
    cin >> N >> M;

    deque<int> q;
    int l, r, cnt = 0;
    for (int i = 1; i <= N; i++) {
        q.push_back(i);
    }

    while (M--) {
        int num;
        cin >> num;

        for (int i = 0; i < q.size(); i++) {
            if (q[i] == num) {
                l = i;
                r = q.size() - i;
                break;
            }
        }

        if (l <= r) {
            while (1) {
                if (q.front() == num) {
                    break;
                }

                q.emplace_back(q.front());
                q.pop_front();
                cnt++;
            }
            q.pop_front();
            
        }
        else {
            cnt++;
            while (1) {
                if (q.back() == num) {
                    break;
                }

                q.emplace_front(q.back());
                q.pop_back();
                cnt++;
            }
            q.pop_back();
        }
    }

    cout << cnt << '\n';

    return 0;
}