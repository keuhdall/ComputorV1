#include "equation0.h"
#include <iostream>
#include <cmath>

equation_0::equation_0(double newEquationTerm, double newEquationResult)
{
  equation_term = newEquationTerm;
  equation_result = newEquationResult;
}

equation_0::~equation_0()
{
}

void equation_0::solve()
{
  if (equation_term != equation_result)
  {
    std::cout << "This equation is impossible to solve." << std::endl;
  }
  else
  {
    std::cout << "The solution is equal to the whole set of real numbers" << std::endl;
  }
}
