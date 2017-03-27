#include "equation1.h"
#include <iostream>
#include <cmath>

equation_1::equation_1(double newEquationTerm, double newEquationTermX, double newEquationResult, double newEquationResultX)
{
  equation_term = newEquationTerm;
  equation_term_x = newEquationTermX;
  equation_result = newEquationResult;
  equation_result_x = newEquationResultX;
}

equation_1::~equation_1()
{
}

void equation_1::recalc_terms()
{
  if (equation_result > 0)
    equation_term -= equation_result;
  else
    equation_term += equation_result;

  if (equation_result_x > 0)
    equation_term_x -= equation_result_x;
  else
    equation_term_x += equation_result_x;

  equation_result = 0;
  equation_result_x = 0;
}

void equation_1::solve()
{
  recalc_terms();
  std::cout << "Reduced form : " << equation_term << " * X^0 + " << equation_term_x << " * X^1" << " = 0" << std::endl;
  if (equation_term > 0)
    equation_result -= equation_term;
  else
    equation_result += equation_term;
  equation_term = 0;

  if (equation_result_x > 0)
    equation_term_x -= equation_result_x;
  else
    equation_term_x += equation_result_x;
  equation_result_x = 0;
  equation_result /= equation_term_x;
  std::cout << "The solution is : " << equation_result << std::endl;
}
