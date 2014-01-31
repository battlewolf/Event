#include <vector>
#include <list>
#include <map>
#include <set>
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
#include <string.h>
#include <ctime>
 
using namespace std;
 
#define REP(i,n) for(int i=0; i<n; i++)
#define FOR(i,x,y) for(int i=x; i<=y; i++)

bool determine (int n)
{
	if(n == 1) return false;
	int ret = true;
	for(int i=2; i < n ; i++)
		if(! (n%i) )
			ret = false;
	return ret;		
}
int solve(int lower_limit, int upper_limit)
{
	int ret=0;
	for( int i=lower_limit; i <= upper_limit; i++)
	{
		if(determine (i))
			ret++;
	}
	return ret;
}
main()
{
	int cases;
	scanf("%d", &cases);
	while(cases--)
	{
		int lower_limit , upper_limit;
		scanf("%d %d",&lower_limit, &upper_limit);
		printf("%d\n", solve(lower_limit , upper_limit));
	}
}
