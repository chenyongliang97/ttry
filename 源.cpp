#include<iostream>
#include<ctime>
#include<cstdio>
#include<iomanip>
#include<algorithm>
using namespace std;



void init(double a[],int n,int x, int y)
{
	int i;
	for (i = 0; i < n; i++)
	{
		a[i] = rand()%1000/1000.0 *(y - x ) + x;
	}
}

double fun(double x)
{
	return sin(x);
}

double evaluate(double a[], int n)
{
	double sum = 0;
	for (int i = 0; i < n; i++)
		sum += fun(a[i]);
	return sum;
}

int main()
{
	double k, CR, score, x1[10000], x2[10000] ,x, y;
	int i, j, NP, count, n, a, b, c;
	while (cin >> n >> NP >> CR >> x >> y)                                                                /*n：代数 NP：解的数量 CR：突变率 x，y：生成初始解的范围*/
	{
		init(x1, NP, x, y);                                                                               /*随机产生NP个初始解，存放于x1数组中*/
		count = 0;
		for (i = 0; i < NP; i++)
			if (x1[i]>1.56&&x1[i] < 1.58) count++;
		cout << "before DE:" << count;
		count = 0;
		score = evaluate(x1, NP);
		while (count < n)                                                                                 /*一共做迭代n次*/
		{
			for (i = 0; i < NP; i++)                                                                      /*每个解都有可能发生突变（mutation）*/
			{
				do a = rand() % NP; while (a == i);                                                       /*随机选取一个不同于i的解*/
				do b = rand() % NP; while (b == a || b == i);                                             /*随机选取一个不同于i，a的解*/
				if ((rand() % 1000) / 1000.0 < CR) x2[i] = x1[i] + ((rand()%1000)/1000.0*2)*(x1[a] - x1[b]);/*控制突变频率*/
				else x2[i] = x1[i];                                                                       /*突变或不突变（交叉crossover）*/
			}
			if (score < evaluate(x2, NP))                                                                 /*选择（selection）*/
			{
				for (i = 0; i < NP; i++)
					x1[i] = x2[i];
				score = evaluate(x2, NP);
			}
			count++;
		}
		count = 0;
		for (i = 0; i < NP; i++)
			if (x1[i]>1.56&&x1[i] < 1.58) count++;
		cout << endl<< "after DE:" << count;
	}
}