#include "equation2.h"
#include <iostream>
#include <cmath>

equation_2::equation_2(double newEquationTerm, double newEquationTermX, double newEquationTermX2,
                        double newEquationResult, double newEquationResultX, double newEquationResultX2)
{
  equation_term = newEquationTerm;
  equation_term_x = newEquationTermX;
  equation_term_x2 = newEquationTermX2;
  equation_result = newEquationResult;
  equation_result_x = newEquationResultX;
  equation_result_x2 = newEquationResultX2;
}

equation_2::~equation_2()
{
}

void equation_2::recalc_terms()
{
  if (equation_result > 0)
    equation_term -= equation_result;
  else
    equation_term += equation_result;

  if (equation_result_x > 0)
    equation_term_x -= equation_result_x;
  else
    equation_term_x += equation_result_x;

  if (equation_result_x2 > 0)
    equation_term_x2 -= equation_result_x2;
  else
    equation_term_x2 += equation_result_x2;

  equation_result = 0;
  equation_result_x = 0;
  equation_result_x2 = 0;
}

void equation_2::solve()
{
  recalc_terms();
  std::cout << "Reduced form : " << equation_term << " * X^0 + " << equation_term_x << " * X^1 + " << equation_term_x2 << " = 0" << std::endl;
  double delta = (double)(pow(equation_term_x, 2) - (4 * equation_term * equation_term_x2));
  if (delta > 0)
  {
    double res1 = (-equation_term_x - sqrt(delta)) / (2 * equation_term_x2);
    double res2 = (-equation_term_x + sqrt(delta)) / (2 * equation_term_x2);
    std::cout << "Discriminent is strictly positive (" << delta << ")" << std::endl;
    std::cout << "The two solutions are : " << res1 << " and " << res2 << std::endl;
  }
  else if (!delta)
  {
    double res0 = -equation_term_x / 2 * equation_term_x2;
    std::cout << "Discriminent is equal to zero" << std::endl;
    std::cout << "The solution is : " << res0 << std::endl;
  }
  else
  {
    double resre = -equation_term_x / 2 * equation_term_x2;
    double resim = sqrt(-delta) / 2 * equation_term_x2;
    std::cout << "Discriminent is strictly negative (" << delta << ")" << std::endl;
    std::cout << "The two complexes solutions are : " << resre << " - " << resim << " and " << resre << " + " << resim << std::endl;
  }
}
