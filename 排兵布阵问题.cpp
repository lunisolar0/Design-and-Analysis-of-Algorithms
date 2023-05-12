#include <bits/stdc++.h>

using namespace std;

ifstream Fin;

// 数据存储矩阵
class armsData
{
    int n;                  // 矩阵阶数
    vector<vector<int>> A;  // 存储矩阵
    vector<int> arrange;    // 排列数组
    vector<int> maxArrange; // 最大排列
    int maxAttack;          // 最大攻击力

public: // 构造函数
    armsData(int n)
    {
        this->n = n;
        for (int i = 0; i < n; i++)
            arrange.push_back(i);
        dataInput(n);
        dfs(0, n - 1);
    }

private: // 兵种数据矩阵录入
    void dataInput(int n)
    {
        Fin.open("armsData.txt");
        for (int i = 0; i < n; i++)
        {
            vector<int> temp(n);
            for (int j = 0; j < n; j++)
            {
                cout << "请输入第" << i + 1 << "兵种在第" << j + 1 << "个点上的攻击力:";
                Fin >> temp[j];
                cout << temp[j] << endl;
            }
            A.push_back(temp);
        }
        Fin.close();
    }

public: // 数据打印
    void dataPrint()
    {
        cout << "数据矩阵如下(纵为兵种,横为兵种在各防卫点上的攻击力)：" << endl;
        for (auto it1 : A)
        {
            for (auto it2 : it1)
            {
                cout << it2 << "\t";
            }
            cout << endl;
        }
        cout << "最大攻击力排兵布阵方案：" << endl;
        for (int i = 0; i < maxArrange.size(); i++)
        {
            cout << "兵种" << i + 1 << "的位置：" << maxArrange[i] << endl;
        }
        cout << "此时，攻击力达到最大值：" << maxAttack << endl;
    }

public: // 深度优先搜索(交换法)
    void dfs(int lo, int hi)
    {
        if (lo > hi)
        {
            // for (auto it : arrange)
            //     cout << it;
            // cout << ":" << attackCalculate() << endl;
            if (attackCalculate() > maxAttack)
            {
                maxAttack = attackCalculate();
                maxArrange = arrange;
            }
            return;
        }
        for (int i = lo; i <= hi; i++)
        {
            swap(arrange[lo], arrange[i]);
            dfs(lo + 1, hi);
            swap(arrange[lo], arrange[i]);
        }
    }

private:
    int attackCalculate()
    {
        int ret = 0;
        for (int i = 0; i < arrange.size(); i++)
            ret = ret + A[i][arrange[i]];
        return ret;
    }
};

int main()
{
    armsData a(5);
    a.dataPrint();
    return 0;
}