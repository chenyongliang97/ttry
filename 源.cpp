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
	while (cin >> n >> NP >> CR >> x >> y)                                                                /*n������ NP��������� CR��ͻ���� x��y�����ɳ�ʼ��ķ�Χ*/
	{
		init(x1, NP, x, y);                                                                               /*�������NP����ʼ�⣬�����x1������*/
		count = 0;
		for (i = 0; i < NP; i++)
			if (x1[i]>1.56&&x1[i] < 1.58) count++;
		cout << "before DE:" << count;
		count = 0;
		score = evaluate(x1, NP);
		while (count < n)                                                                                 /*һ��������n��*/
		{
			for (i = 0; i < NP; i++)                                                                      /*ÿ���ⶼ�п��ܷ���ͻ�䣨mutation��*/
			{
				do a = rand() % NP; while (a == i);                                                       /*���ѡȡһ����ͬ��i�Ľ�*/
				do b = rand() % NP; while (b == a || b == i);                                             /*���ѡȡһ����ͬ��i��a�Ľ�*/
				if ((rand() % 1000) / 1000.0 < CR) x2[i] = x1[i] + ((rand()%1000)/1000.0*2)*(x1[a] - x1[b]);/*����ͻ��Ƶ��*/
				else x2[i] = x1[i];                                                                       /*ͻ���ͻ�䣨����crossover��*/
			}
			if (score < evaluate(x2, NP))                                                                 /*ѡ��selection��*/
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