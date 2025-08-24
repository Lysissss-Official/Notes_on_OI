/*
〔2017〕NOIP普及组T4：跳房子 
题目描述详见：https://www.luogu.com.cn/problem/P3957
解题思路详见：https://github.com/Lysissss-Official/Notes_on_OI 

Code by -Lysissss.
-------------------
v1 (2025-8-24): 完成源码及相关注释 
v2 (2025-8-24): 编码格式炸了，注释进行重写 
*/

#include<bits/stdc++.h>

using namespace std;

/*----变量：输入----*/
int n, d, k;	//依次为：格子的数目、改进前机器人弹跳的固定距离、希望至少获得的分数 
int dis, scr;	//依次为：起点到一格子的距离、该格子的分数

/*----变量：处理及输出部分----*/
int g, l, r;	//依次为：花费金币的最小值、二分查找的左界限、二分查找的右界限 

deque<int> mq;		//<距离> 双端队列（单调队列）：跳跃范围内动归状态的最大值 
queue<int> preq;	//<距离> 队列：将放入单调队列的元素的集合 
map<int, int> best;	//<距离, 该格最优分数> 离散化数组：每个可到达距离处的单格最优分数 
map<int, int> dp;	//<距离, 累计最大分数> 离散化数组（动归状态）：到该距离处为止的累计分数的最大值 

/*----主函数----*/
int main()
{
	/*--输入--*/
	cin >> n >> d >> k;
	for(int i = 1; i <= n; i++)
	{
		cin >> dis >> scr;
		if(best.find(dis) != best.end())	//查找是否已经存有同距离处格子 
		{
			best[dis] = max(best[dis], scr);	//有同距离处格子，比较输入和已存最优分数，取较大值更新 
		}
		else
		{
			best[dis] = scr;	//无同距离处格子，输入即为该距离处最优分数 
		}
	}
	
	/*---二分查找---*/
	l = 0;		//初始化左界限为0 
	r = 500002;	//初始化右界限为500001（无穷大） 
	while(r - l > 1)
	{
		dp.clear();				//初始化清空状态 
		preq = queue<int> ();	//同上 
		mq = deque<int> ();		//同上 
		g = (l + r - 1) >> 1;	//取区间中点为拟定答案 
		dp[0] = 0;				//机器人初始在位置0，将位置0加入确定状态（分数为0） 
		preq.push(0);			//已经确定位置0状态，将位置0放入单调队列的预队列 
		for(map<int, int>::iterator i = best.begin(); i != best.end(); i++)	//定义迭代器遍历所有存有的位置（无格子的位置不遍历） 
		{
			/*-单调队列维护-*/
			while(!mq.empty() && mq.front() < max(0, i->first - d - g))		//除旧 
			{
				mq.pop_front();	//原单调队列队首（最大值所在距离）已经超出跳跃范围，推出单调队列 
			}
			while(!preq.empty() && preq.front() <= min(i->first - 1, i->first - d + g))	//迎新 
			{
				if(preq.front() < max(0, i->first - d - g))
				{
					preq.pop();	//原预队列队首（未放入单调队列的最远存有距离）已经超出跳跃范围，推出预队列
					continue;
				}
  				while (!mq.empty() && dp[mq.back()] < dp[preq.front()])
				{
					mq.pop_back();	//推出单调队列队尾小于预队列队首的元素
				}
  				mq.push_back(preq.front());	//将预队列队首放入单调队列队尾，保持单调性 
				preq.pop();	//将预队列队首推出预队列，重新循环对下一个元素（若有）进行同样操作 
			}
			
			/*-动归状态转移-*/
			if(!mq.empty())
			{
				dp[i->first] = dp[mq.front()] + best[i->first];	//转移方程：dp[当前距离] = max(dp[可从上一格跳至此的距离（集合）]) + 当前距离处单格最优分数 
				preq.push(i->first);	//已经确定当前位置状态，将当前位置放入单调队列的预队列 
			}
			if(dp[(--dp.end())->first] >= k)
			{
				r = g + 1;	//分数已经达到目标，拟定答案可能过大，将右界限设为区间中点（注意！！！拟定答案可能正好，新区间需要保留原区间中点） 
				break;		//已经满足目标要求，跳出循环减少无意义用时 
			}
		}
		if(r != g + 1)
		{
			l = g + 1;	//分数尚未达到目标，拟定答案一定过小（或不存在），将左界限设为区间中点（注意！！！拟定答案一定错误，新区间无需保留原区间中点） 
		}
	}
	
	/*---输出---*/ 
	if(l != 500001)
	{
		cout << l << endl;		//答案非无穷大，直接输出 
	}
	else
	{
		cout << "-1" << endl;	//答案为无穷大，输出-1 
	}
	return 0; 
}