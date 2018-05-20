#include <climits>
#include <random>
#include <vector>
#include <iostream>
#include <algorithm>
#include <set>
//#include <unordered_set>
using namespace std;

const int N = 1 << 15;

int main(int argc, char *argv[]) {
	random_device	rd;
	default_random_engine	g(rd());
	uniform_int_distribution<> d(1, INT_MAX);
	vector<int>	v;
	
	// Generate N random ints
	for (int i = 0; i < N; i++) {
		v.pushback(d(g));
	}
	
	// Scan vector for duplicates
	for (auto it = v.begin(); it != v.end(); it++) {
		if(*it != *(it + 1) {
			cout << *it << " is duplicated" << endl;
		}
	}
	return 0;
}
