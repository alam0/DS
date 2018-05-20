//stack_default.cpp
#include <stack>
using namespace std;

const int N = 1<<25;

int main(){
	stack<int> s;
	
	for(int i = 0; i < N; i++){
		s.push(i);
	}
	
	while(!s.empty()){
		s.pop();
	}
}
