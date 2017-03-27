#include <iostream>
#include <vector>
#include <string.h>
#include <regex>
#include <cmath>
#include "equation0.h"
#include "equation1.h"
#include "equation2.h"

int split(std::vector<std::string>& vec, std::string str, char c)
{
	vec.clear();
	std::string::size_type stTemp = str.find(c);
	while(stTemp != std::string::npos)
	{
		vec.push_back(str.substr(0, stTemp));
		str = str.substr(stTemp + 1);
		stTemp = str.find(c);
	}
	vec.push_back(str);
	return vec.size();
}

int get_degree(std::string eq)
{
	if (eq.find("X^3") != std::string::npos)
	{
		std::cout << "The polynomial degree is greater than 2, I can't solve." << std::endl;
		return (-1);
	}
	else if (eq.find("X^2") != std::string::npos)
	{
		std::cout << "Polynomial degree : 2" << std::endl;
		return (2);
	}
	else if (eq.find("X^1") != std::string::npos)
	{
		std::cout << "Polynomial degree : 1" << std::endl;
		return (1);
	}
	else if (eq.find("X^0") != std::string::npos)
	{
		std::cout << "Polynomial degree : 0" << std::endl;
		return (0);
	}
	else
	{
		std::cout << "Syntax Error" << std::endl;
		return (-1);
	}
}

std::vector<std::string> split_term_res(std::string str)
{
	std::vector<std::string> v;
	std::vector<std::string> v_term;
	std::vector<std::string> v_res;
	std::string str_term;
	std::string str_res;
	if (split(v, str, '=') == 2)
	{
		split(v_term, v[0], ' ');
		split(v_res, v[1], ' ');
		for (size_t i = 0; i < v_term.size(); i++) {
			str_term += v_term[i];
		}
		for (size_t i = 0; i < v_res.size(); i++) {
			str_res += v_res[i];
		}
	}
	v.clear();
	v.push_back(str_term);
	v.push_back(str_res);
	return (v);
}

std::vector<double> get_values(std::string str, int degree)
{
	std::vector<double> v;
	std::regex e ("([+|-]?\\d*[\\.]?\\d*)(?:\\*X\\^[0-9])");
	std::smatch m;
	while (std::regex_search(str, m , e))
	{
		int i = 0;
		for (auto x:m)
		{
			if (i)
				v.push_back(std::stod(x));
			i++;
		}
		str = m.suffix();
	}
	int len = v.size();
	while (len <= 3)
	{
		v.push_back(0);
		len++;
	}
	return (v);
}

int main(int argc, char *argv[])
{
  std::string arg;
	std::vector<std::string> v;
	std::vector<double> v_term;
	std::vector<double> v_result;

  if (argc > 1)
  {
    arg = argv[1];
		int degree = get_degree(arg);
		v = split_term_res(arg);
		v_term = get_values(v[0], degree);
		v_result = get_values(v[1], degree);
		switch (degree) {
			case 0:
			{
				equation_0 equation_0(v_term[0], v_result[0]);
				equation_0.solve();
				break;
			}
			case 1:
			{
				equation_1 equation_1(v_term[0], v_term[1], v_result[0], v_result[1]);
				equation_1.solve();
				break;
			}
			case 2:
			{
				equation_2 equation_2(v_term[0], v_term[1], v_term[2], v_result[0], v_result[1], v_result[2]);
				equation_2.solve();
				break;
			}
			default:
				break;
		}
  }
  return 0;
}
