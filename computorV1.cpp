#include <iostream>
#include <vector>
#include <string.h>

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
		return (3);
	else if (eq.find("X^2") != std::string::npos)
		return (2);
	else if (eq.find("X^1") != std::string::npos)
		return (1);
	else if (eq.find("X^0") != std::string::npos)
		return (0);
	else
		return (-1);
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

int main(int argc, char *argv[])
{
  std::string arg;
	std::vector<std::string> v;
	std::vector<int> v_tem;
	std::vector<int> v_res;

  if (argc > 1)
  {
    arg = argv[1];
		int degree = get_degree(arg);
		v = split_term_res(arg);
		std::cout << v[0] << std::endl << v[1] << std::endl;
		std::cout << "degree = " << degree << std::endl;
  }
  return 0;
}
