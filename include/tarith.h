#pragma once

#include <iostream>
#include <string>
#include <stack>
#include <vector>

class Calculator{
	std::vector<std::string> terms;
	std::stack<std::string> stack;
public:
	Calculator(std::string str = "")
	{
		std::string tmp;
		for (int i = 0; i < str.size(); i++) {
			tmp += str[i];
			terms.push_back(tmp);
			tmp.clear();
		}

		std::vector<std::string> numbers = {"0", "1", "2", "3", "4", "5", "6", "7", "8", "9"};
		std::vector<std::string> operations = { "+", "-", "*", "/"};

		int i = 0;
		while(i < size() - 1)
		{

			while ((terms[i + 1] != "+") && (terms[i + 1] != "-") && (terms[i + 1] != "*") && (terms[i + 1] != "/") && \
				   (terms[i] != "+") && (terms[i] != "-") && (terms[i] != "*") && (terms[i] != "/")) {
				for (std::string j : numbers) {
					if (i + 1 >= size()) {
						break;
					}

					if (terms[i + 1] == j) {
						terms[i] += terms[i + 1];
						terms.erase(terms.begin() + i + 1);
					}
				}

				if (i + 1 >= size()) {
					break;
				}
			}
			
			if (i + 1 >= size()) {
				break;
			}

			for (std::string oper : operations) {
				if (terms[i] == oper) {
					continue;
				}
			}

			i++;
		}
	}

	void stackFilling() {
		for (int i = 0; i < size(); i++) {
			if ((terms[i] == "*") || (terms[i] == "/")) {
				stack.push(terms[i]);
				terms.erase(terms.begin() + i);
				
			}
			if ((terms[i] == "+") || (terms[i] == "-")) {
				if (!stack.empty())
					if (stack.top() == "*" || stack.top() == "/") {
						calculation();
					}

				stack.push(terms[i]);
				terms.erase(terms.begin() + i);
			}
		}
	}

	void print_stack() {
		std::cout << stack.top() << std::endl;
	}

	double calculation() {
		stackFilling();

		while (size() != 1) {
			if (stack.empty())
				break;

			if (stack.top() == "*") {
				terms[size() - 2] = std::to_string(std::stod(terms[size() - 1]) * std::stod(terms[size() - 2]));
				
				stack.pop();
				terms.pop_back();
			}

			if (stack.empty())
				break;

			if (stack.top() == "/") {
				terms[size() - 2] = std::to_string(std::stod(terms[size() - 2]) / std::stod(terms[size() - 1]));

				stack.pop();
				terms.pop_back();
			}

			if (stack.empty())
				break;

			if (stack.top() == "+") {
				terms[size() - 2] = std::to_string(std::stod(terms[size() - 1]) + std::stod(terms[size() - 2]));

				stack.pop();
				terms.pop_back();
			}

			if (stack.empty())
				break;

			if (stack.top() == "-") {
				terms[size() - 2] = std::to_string(std::stod(terms[size() - 2]) - std::stod(terms[size() - 1]));

				stack.pop();
				terms.pop_back();
			}

			if (stack.empty())
				break;

		}

		return std::stod(terms[0]);
	}

	std::string& operator[](size_t ind)
	{
		return terms[ind];
	}
	const std::string& operator[](size_t ind) const
	{
		return terms[ind];
	}

	void erase(int index) {
		terms.erase(terms.begin() + index);
	}

	int size() 
	{
		return terms.size();
	}

	friend std::ostream& operator<<(std::ostream& ostr, const Calculator& other)
	{
		
		for (int i = 0; i < other.terms.size(); i++) {
			std::cout << other.terms[i] << std::endl;
		}

		return ostr;
	}
};
