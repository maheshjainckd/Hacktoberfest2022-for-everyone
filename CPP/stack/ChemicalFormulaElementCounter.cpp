// A c++ program which takes in a chemical formula and returns the count of each element in the Chemical Formula
// To get an exact count of the elements, the Formulas should be written in correct format as by the rule
// (1) if element name is a single symbol, It must be uppercase letter
// (2) If element name is more than one symbol, First letter should be uppercase and the following characters shoul be lowercase

// Exmple: = K4(ON(SO3)2)2
// The above is a valid expression for a chemical formula


#include <iostream>
#include <string>
#include <vector>
#include <stack>

using namespace std;
void vector_sort(vector<string>&, vector<int>&);
void display(vector<string>, vector<int>);


int main() {

	string equation;

	cout << "Program to calculate count of each element in a chemical formula :)" << endl << endl;
	cout << "Enter chemimcal Formula here: ";
	getline(cin, equation);
	
	
	bool flag;
	string element_name = "";

	// holds themultiplier at the end of bracket
	int multiplier;
	
	// Original parallel stacks of element and count
	stack<string> element;
	stack<int> count;

	// Temporary parallel stacks of element and count
	stack<string> temp_element;
	stack<int> temp_count;

	// paralle of elements and their respective counts
	vector<string> vector_element;
	vector<int> vector_count;


	// Algorithm using stl stack

	for (int i = 0; i < equation.length(); i++)
	{
		element_name = "";

		if (equation[i] >= 'A' && equation[i] <= 'Z') {

			element_name += equation[i];

			if (equation[i + 1] >= 'a' && equation[i + 1] <= 'z') {

				element_name += equation[i + 1];
				element.push(element_name);

				int x = 2;
				int sum = 0;
				if (isdigit(equation[i + x])) {

					while (isdigit(equation[i + x])) {

						sum = (sum*10) + (equation[i + x] - '0');
						x++;
					}
					count.push(sum);
				}
				else {

					count.push(1);
				}
				continue;
			}

			element.push(element_name);

			int x = 1;
			int sum = 0;
			if (isdigit(equation[i + x])) {

				while (isdigit(equation[i + x])) {

					sum = (sum * 10) + (equation[i + x] - '0');
					x++;
				}
				count.push(sum);
			}
			else {

				count.push(1);
			}
		}

		else if (equation[i] == '(') {

			element.push("(");
			count.push('(');
		}

		else if (equation[i] == ')') {

			do {

				temp_element.push(element.top());
				element.pop();
				temp_count.push(count.top());
				count.pop();
			} while (element.top() != "(");

			element.pop();
			count.pop();

			multiplier = equation[i + 1] - '0';

			while (!temp_count.empty()) {

				element.push(temp_element.top());
				temp_element.pop();
				count.push(temp_count.top() * multiplier);
				temp_count.pop();
			}
		}
	}

	//---------- Adding the count to respective elements -> i.e.adding duplicate elements --------------

	string elem;
	int counter;

	while (!element.empty()) {

		flag = 0;

		elem = element.top();
		element.pop();
		counter = count.top();
		count.pop();

		for (int i = 0; i < vector_element.size(); i++)
		{

			if (elem == vector_element[i]) {

				vector_count[i] += counter;
				flag = 1;
			}
		}

		if (!flag) {
			vector_element.push_back(elem);
			vector_count.push_back(counter);
		}
	}

	vector_sort(vector_element, vector_count);

	display(vector_element, vector_count);



	system("pause");
	return 0;
}


void vector_sort(vector<string>& v_element, vector<int>& v_count) {

	//----------------------- Sorting ----------------------

	string temp;
	int t_count = 0;
	for (int i = 0; i < v_count.size() - 1; i++) {
		for (int j = i + 1; j < v_count.size(); j++) {

			if (v_element[i][0] > v_element[j][0]) {

				temp = v_element[i];
				t_count = v_count[i];
				v_element[i] = v_element[j];
				v_count[i] = v_count[j];

				v_element[j] = temp;
				v_count[j] = t_count;
			}
		}
	}

	//------------------------------------------------
}


void display(vector<string> v_element, vector<int> count) {
	//----------- Displaying on console ---------------
	for (int i = 0; i < count.size(); i++)
	{
		if (count[i] == 1) {
			cout << v_element[i] << " ";
			continue;
		}
		cout << v_element[i] << count[i] << " ";
	}

	cout << endl;
}
