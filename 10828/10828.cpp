#include<iostream>

using namespace std;

struct stack {
	int arr[10000];
	int last = -1;

	void push(int data) {
		arr[++last] = data;
	}
	bool empty() {
		if (last == -1) return true;
	}


};

int main() {

	stack s;
	s.push(1);
	s.push(2);
	s.push(5);


	return 0;
}