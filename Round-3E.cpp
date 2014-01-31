/*Debug/Optimise it*/
#include <vector>
#include <list>
#include <map>
#include <set>
#include <queue>
#include <deque>
#include <stack>
#include <bitset>
#include <algorithm>
#include <functional>
#include <numeric>
#include <utility>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <cstring>

using namespace std;

vector <string> v;
int n,m;
bool visited[55][55][15];
int dx[] = {0, 0, 1, -1};
int dy[] = {1, -1, 0, 0};
int c=0;

int solve(int i, int j)
{	
	queue <int> q;
	q.push(i);
	q.push(j);
	q.push(0);
	q.push(0);
	while(!q.empty())
	{
		int nx = q.front();
		q.pop();
		int ny = q.front();q.pop();
		int cost = q.front(); q.pop();
		int count = q.front();q.pop();
		if(visited[nx][ny][count]) continue;		
		visited[nx][ny][count] = true;				 
		if(v[nx][ny] == '*')
		 count++;
		bool can = true;
		if(v[nx][ny] == 'S') return cost;
		if(v[nx][ny] == '~' && count < c)
		 can = false;
		if(v[nx][ny] == '#')
		 can = false;
		if(can)
		{			
			for(int x = 0; x < 4; ++x)
			{
				int xx = nx+dx[x];
				int yy = ny+dy[x];
				if(xx >= 0 && yy >= 0 && xx < n && yy < m)
				 q.push(xx), q.push(yy), q.push(cost+1), q.push(count);
			}
		}
	}
	return -1;
}
int main()
{
	while(1)	
	{	
		cin >> n >> m;
		if(n == 0 && m == 0)
		 break;
		string a;
		v.clear();
		for(int i = 0; i < n; ++i)
		{
			cin >> a;
			v.push_back(a);		
		}		
		c = 0;
		memset(visited, false, sizeof visited);		
		int result;
		for(int i = 0; i < n; ++i)
			for(int j=0; j < m; ++j)
			{
				if(v[i][j] == '*')
			 		c++;
			}
		for(int i = 0; i < n; ++i)		
			for(int j = 0; j < m; ++j)
			{
				if(v[i][j] == 'R')
				{
		    		result=solve(i, j);
					goto sita;
				}
			}
		sita:;
		cout << result << '\n';	
	}
}
