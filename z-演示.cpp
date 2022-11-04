#include<iostream>
#include<stack>

using namespace std;

int main() {
	stack<int> stk;
	for (int i = 0; i < 10; i++) {
		stk.push(i);
	}
	while (!stk.empty()) {
		int a = stk.top();
		printf("%d", a);
		stk.pop();
	}
}