/*Optimise the code */

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
#incude <cstring>

using namespace std;

bool solve(string a)
{
	int j = a.size()-1;
	for(int i = 0; i < a.size() && j >=0; ++i, --j)
	 if(a[i] != a[j])
	  return false;
	return true;
}

int main()
{
	int cases;
	cin >> cases;
	while(cases--)
	{
		string a;		
		cin >> a;		
		int n = a.size();
		int l = 1;
		for(int i = 0; i < n; ++i)
		{
			for(int j = 0; j < n; ++j)
			{
				string temp = a.substr(i,j);
				if(solve(temp) == true)
				 l = max(l, (int)temp.size());
			}
		}
		cout << l << '\n';
	}
}
