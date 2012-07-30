#include <algorithm>
#include <bitset>
#include <cctype>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <limits>
#include <map>
#include <queue>
#include <set>
#include <stack>
#include <vector>


#define UL unsigned long long
#define LL long long
#define LD long double
#define EPS 1e-9

using namespace std;

int main() {
	int o, reverse;
	while (scanf("%d", &o) == 1) {
		reverse = o;
		char * bits = (char*) &reverse;
		swap(bits[0], bits[3]);
		swap(bits[1], bits[2]);
		printf("%d converts to %d\n", o, reverse);
	}
	return 0;
}
