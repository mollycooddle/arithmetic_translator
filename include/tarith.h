﻿#pragma once

#include <iostream>
#include <string>
#include <stack>
#include <vector>

class Calculator{
	std::vector<std::string> terms;
	std::stack<std::string> stack;
	int stackSize = 0;
public:
	Calculator(std::string str = "")
	{
		std::string tmp;

		for (int i = 0; i < str.size(); i++) {
			tmp += str[i];
			terms.push_back(tmp);
			tmp.clear();
		}

		std::vector<std::string> numbers = {"0", "1", "2", "3", "4", "5", "6", "7", "8", "9", "."};
		std::vector<std::string> operations = { "+", "-", "*", "/", "(", ")"};

		int i = 0;
		while(i < size() - 1)
		{

			while ((terms[i + 1] != "+") && (terms[i + 1] != "-") && (terms[i + 1] != "*") && (terms[i + 1] != "/") &&  \
				   (terms[i + 1] != "(") && (terms[i + 1] != ")") && \
				   (terms[i] != "+") && (terms[i] != "-") && (terms[i] != "*") && (terms[i] != "/") && \
				   (terms[i] != "(") && (terms[i] != ")")) {
				for (std::string& j : numbers) {
					if (i >= size() - 1) {
						break;
					}

					if (terms[i + 1] == j) {
						terms[i] += terms[i + 1];
						terms.erase(terms.begin() + i + 1);
					}
				}

				if (i >= size() - 1) {
					break;
				}
			}

			//for (int u = 0; u < size(); u++)
			//	std::cout << terms[u] << " ";
			//	std::cout << std::endl;

			int oper = 0;

			if ((terms[0] == "+" || terms[0] == "-" || terms[0] == "*" || terms[0] == "/") || \
				(terms[size() - 1] == "+" || terms[size() - 1] == "-" || terms[size() - 1] == "*" || terms[size() - 1] == "/"))
				throw std::invalid_argument("Wrong expression");

			for (int j = 0; j < size() - 1; j++) {
				if ((terms[j] == "+" || terms[j] == "-" || terms[j] == "*" || terms[j] == "/") && \
					(terms[j + 1] == "+" || terms[j + 1] == "-" || terms[j + 1] == "*" || terms[j + 1] == "/")) {
					oper++;
				}

				if (oper != 0)
					throw std::invalid_argument("Wrong expression");

				oper = 0;
			}


			if (i >= size() - 1) {
				break;
			}

			for (std::string oper : operations) {
				if (terms[i] == oper) {
					continue;
				}
			}

			//for (int i = 0; i < size(); i++)
			//	std::cout << terms[i] << " ";
			//std::cout << std::endl;

			i++;
		}
	}

	void stackFilling() {
		std::vector<std::string> temp;
		int BracketsFront = 0;
		int BracketsEnd = 0;

		int point = 0;
		for (int j = 0; j < size(); j++) {
			std::string str = terms[j];

			if (terms[j][0] =='.' || terms[j][str.size() - 1] == '.')
				throw std::invalid_argument("Wrong expression");

			for (int h = 0; h < str.size(); h++) {
				if (str[h] == '.')
					point++;
			}

			if (point > 1)
				throw std::invalid_argument("Wrong expression");
			point = 0;

		}


		for (int i = 0; i < size(); i++) {
			if ((terms[i] == "*") || (terms[i] == "/")) {
				stack.push(terms[i]);
				terms.erase(terms.begin() + i);
				stackSize++;
			}

			if ((terms[i] == "+") || (terms[i] == "-")) {
				if (!stack.empty())
					if (stack.top() == "*" || stack.top() == "/") {

						while (i < size()) {
							temp.push_back(terms[i]);
							terms.erase(terms.begin() + i);
						}

						calculation();

						for (int j = 0; j < temp.size(); j++) {
							terms.push_back(temp[j]);
						}
						temp.clear();
						i = 1;
					}
				stack.push(terms[i]);
				terms.erase(terms.begin() + i);
				stackSize++;
			}

			if ((i + 1) < size() - 1)
				if (terms[i] == "(" && terms[i + 1] == ")")
					throw std::invalid_argument("Wrong expression");

			if (terms[i] == "(") {
				stack.push(terms[i]);
				terms.erase(terms.begin() + i);
				BracketsFront++;
			}

			if (terms[i] == ")") {
				stack.push(terms[i]);
				terms.erase(terms.begin() + i);

				if (!stack.empty())
					if (stack.top() == ")")
						if (i < size()) {

						while (i < size()) {
							temp.push_back(terms[i]);
							terms.erase(terms.begin() + i);
						}

						calculation();

						for (int j = 0; j < temp.size(); j++) {
							terms.push_back(temp[j]);
						}
						temp.clear();
						i = 0;
					}
				BracketsEnd++;
			}
		}

		if (BracketsEnd != BracketsFront)
			throw std::invalid_argument("Wrong expression");
	}

	void print_stack() {
		std::cout << stack.top() << std::endl;
	}

	void calculation() {

		//std::stack<std::string> tmp;
		//
		//
		//for (int i = 0; i < 4; i++) {
		//	tmp.push(stack.top());
		//	std::cout << tmp.top() << " ";
		//	stack.pop();
		//}
		//std::cout << std::endl;

		//for (int i = 0; i < 4; i++) {
		//	stack.push(tmp.top());
		//	std::cout << stack.top() << " ";
		//	tmp.pop();
		//}
		//std::cout << std::endl;


		while (size() >= 2) {
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

				if (std::stod(terms[size() - 1]) == 0 || terms[size() - 1] == "0" || terms[size() - 1] == std::to_string(1-1))
					throw std::invalid_argument("Wrong expression");

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

			if (stack.top() == ")") {
				stack.pop();
			}

			if (stack.top() == "(") {
				stack.pop();
			}

			//for (int i = 0; i < size(); i++) {
			//	std::cout << terms[i] << " ";
			//}
			//std::cout << std::endl;
			//std::cout << std::endl;
			//std::cout << std::endl;

		}

		//return std::stod(terms[0]);
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
