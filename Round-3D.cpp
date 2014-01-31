/* Optimise the code*/

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
#define MAX_ELEMENT 10000
typedef long long ll;
int array[MAX_ELEMENT];
int solve(int lower_limit,int upper_limit)
{
	int minimum_element=array[lower_limit];
	for(int i=lower_limit+1; i<=upper_limit; i++)
		if(minimum_element > array[i])
			minimum_element = array[i];
	return minimum_element;		
}
main()
{
	int cases;	
	scanf("%d", &cases);
	while(cases--)
	{
		int no_of_elements,no_of_queries;
		scanf("%d", &no_of_elements);
		for(int i=0; i<no_of_elements; i++)
			scanf("%d", &array[i]);
		scanf("%d", &no_of_queries);
		for(int i=0; i<no_of_queries; i++)	
		{
			int lower_limit,upper_limit;
			scanf("%d %d",&lower_limit,&upper_limit);
			printf("%d\n",solve(lower_limit, upper_limit));
		}
	}
}
