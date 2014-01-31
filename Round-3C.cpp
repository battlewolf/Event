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
#define MOD 1000000007

int k, k_count;

int solve( int n )
{
	if ( n == k )
		k_count++;
	if ( n == 0 || n == 1 ) return n;
	return ( solve ( n - 1 ) + solve ( n - 2 ) ) % MOD;
}
main()
{
	int cases;
	scanf("%d", &cases);
	while(cases--)
	{
		int n;
		scanf("%d %d", &n, &k);
		k_count = 0;
		solve( n );
		cout << k_count << "\n";
	}
}
