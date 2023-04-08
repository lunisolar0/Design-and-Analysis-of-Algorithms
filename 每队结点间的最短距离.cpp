#include <bits/stdc++.h>

using namespace std;

clock_t tic, toc;

ifstream Fin;

class shortestPath
{
private:
	vector<vector<int>> cost; //邻接矩阵
	vector<vector<int>> D; //终局状态矩阵
	vector<vector<int>> path; //终局路径矩阵
	  //构造函数
public:shortestPath(int n)
{
	cost.resize(n);
	for (auto& it : cost) it.resize(n, INT_MAX);
	for (int i = 0; i < n; i++) cost[i][i] = 0;
	init();
	D = cost;
	//初始化path
	for (int i = 0; i < D.size(); i++)
	{
		vector<int> temp;
		for (int j = 0; j < D[i].size(); j++)
		{
			temp.push_back(-1);
		}
		path.push_back(temp);
	}
	solution();
}
	  //初始化函数
private:void init()
{
	int start, end, value;
	Fin.open("shortestPath.txt");
	while(1)
	{
		cout << "请输入一条边的两个端点及权值：";
		Fin >> start >> end >> value;
		cout << start << " " << end << " " << value << endl;
		cost[start][end] = value;
		if (Fin.get() == EOF) break;
	}
	Fin.close();
}
	  //打印函数
private:void print(vector<vector<int>> mat)
{
	for (int i = 0; i < mat.size(); i++)
	{
		for (auto it : mat[i])
		{
			if (it == INT_MAX) cout << "∞\t";
			else cout << it << "\t";
		}
		cout << endl;
	}
}
	  //解决方法
private:void solution()
{
	//开始施法(弗洛伊德算法)
	for (int k = 0; k < cost.size(); k++)
	{ //逐步加点
		for (int i = 0; i < cost.size(); i++)
		{ //列遍历
			for (int j = 0; j < cost.size(); j++)
			{ //行遍历
				if (D[i][j] > D[i][k] + D[k][j] && D[i][k] < INT_MAX && D[k][j] < INT_MAX)
				{ //状态转移
					D[i][j] = D[i][k] + D[k][j];
					path[i][j] = k;
				}
			}
		}
	}
	cout << "邻接矩阵(cost)：" << endl;
	print(cost);
	cout << "终局状态矩阵(D)：" << endl;
	print(D);
	cout << "终局路径矩阵(path)：" << endl;
	print(path);
}
	  //路径输出(启动函数)
public:void getPath(int start, int end)
{
	if (D[start][end] == INT_MAX)
	{
		cout << start << "无法到达" << end << endl;
		return;
	}
	cout << start << "到" << end << "最短路径长度为:" << D[start][end] << " 路径如下：" << endl;
	cout << start << " -> "; 
	pathPrint(start, end);
	cout << end << endl;

}
	  //路径输出
private:void pathPrint(int start, int end)
{
	if (path[start][end] == -1) return;
	pathPrint(start, path[start][end]);
	cout << path[start][end] << " -> ";
	pathPrint(path[start][end], end);
}
};

int main()
{
	shortestPath* a = new shortestPath(7);
	for (int i = 0; i < 7; i++)
		for (int j = 0; j < 7; j++)
			a->getPath(i, j);
	return 0;
} 