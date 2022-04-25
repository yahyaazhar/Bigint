/*Stack: Sum of Strings with BigInt
  Name: M Yahya*/

#include <iostream>
#include <string>
#include <stdlib.h>
using namespace std;

class Stack {
public:
	int* sumArr;
	int curr = 0;

	int size , top = 0;
	int* arr;
	Stack(int s) {
		size = s;
		arr = new int[size];
		sumArr = new int[size + 1];
		for (int i = 0; i < size; i++) {
			arr[i] = -1;
		}
		for (int i = 0; i < size + 1; i++) {
			sumArr[i] = 0;
		}
	}
	
	bool isFull() {
		if (top == size) {
			return true;
		}
		else {
			return false;
		}
	}

	bool isEmpty() {
		if (top == 0) {
			return true;
		}
		else {
			return false;
		}
	}

	void push(int value) {
		if (!isFull()) {
			arr[top] = value;
			top++;

		}
		else {
			cout << "Array is full!\n";
		}
	}

	int pop() {
		if (!isEmpty()) {
			int i;
			i = arr[top - 1];
			arr[top - 1] = -1;
			top--;
			return i;
		}
		else {
			return 0;
		}
	}

	string Sum(string num1, string num2) {

		int size1, size2 = 0;
		int index1 = 0;
		int index2 = 0;
		size1 = num1.length();
		size2 = num2.length();
		if (size1 > size2) {
			num2.resize(10);
			size2 = num2.length();
		}
		else if (size1 < size2) {
			num1.resize(10);
			size1 = num1.length();
		}
		for (int k = size1 - 1; k >= 0; k--) {

			int n1 = (num1[k] - '0');
			int n2 = (num2[k] - '0');


			add(n1, n2);
		}
		
		collect(pop());
		
		return "null";

	}

	void add(int a, int b) {

		int sum = 0;
		int module;
		int carry;

		sum = a + b + pop();

		module = sum % 10;
		carry = int(sum / 10);
		collect(module);
		push(carry);
	
	}

	void collect(int digit) {
		int num;
		num = digit;
		sumArr[curr] = num;
		curr++;
	}

	void display() {
		cout << "\n\nshowing sum\n";
		for (int i = curr - 1; i >= 0; i--) {
			cout << sumArr[i];
		}
		cout << endl;
	}
};

int main() {
	string str1 = "9568";
	string str2 = "3215";

	string str3, str4;

	cout << str1 << " + " << str2 << endl;
	
	Stack el(5);
	el.Sum(str1, str2);
	el.display();

	
	cout << "\nCode only work for equal size string\n";
	cout << "\n\nEnter Values to add: \n";
	
	cin >> str3;  cout << " + \n"; cin >> str4;
	Stack el2(5);
	el2.Sum(str3, str4);
	el2.display();

	system("pause");
	return 0;

}