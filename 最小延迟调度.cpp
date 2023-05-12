#include <bits/stdc++.h>

using namespace std;

class waitingUser
{
public:
    int i = 0; // 该用户序号
    int t = 0; // 该用户耗费的时间
    int d = 0; // 该用户的期待结束时间
    waitingUser(int i, int t, int d)
    {
        this->i = i;
        this->t = t;
        this->d = d;
    }
    friend bool operator>(waitingUser WU1, waitingUser WU2)
    {
        return WU1.d > WU2.d;
    }
};

int main()
{
    waitingUser WU[5]{{1, 5, 10}, {2, 8, 12}, {3, 4, 15}, {4, 10, 11}, {5, 3, 20}};
    priority_queue<waitingUser, vector<waitingUser>, greater<waitingUser>> queue;
    for (int i = 0; i < 5; i++)
        queue.push(WU[i]);
    int f[5] = {0}, currDelay = 0, maxDelay = 0;
    for (int i = 0; i < 5; i++)
    {
        currDelay = max(queue.top().t + f[i] - queue.top().d, 0);
        if (currDelay > maxDelay)
            maxDelay = currDelay;
        if (i < 4)
            f[i + 1] = f[i] + queue.top().t;
        cout << "i=" << queue.top().i << "\tt=" << queue.top().t << "\td=" << queue.top().d << "\tf(" << i + 1 << ")=" << f[i] << "\tdelay=" << currDelay << endl;
        queue.pop();
    }
    cout << "maxDelay=" << maxDelay;
    return 0;
}
