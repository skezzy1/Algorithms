#include <iostream>
#include <vector>
#include <list>
#include <stack>
#include <iterator>
#include <map>
#include <queue>
#include <algorithm>
#include <set>
using namespace std;

void main() {
	char* text = "abcdef";
	int i = 0;
	do
		cout << text[++i];
	while (i != 4);
}