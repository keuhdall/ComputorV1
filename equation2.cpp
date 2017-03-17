#include "equation_2.h"

equation_2::equation_2(int newEquationTerm, int newEquationTermXm int newEquationResult, int newEquationResultX);
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
  equation_term -= equation_result;
  equation_term_x -= equation_result_x;
  equation_term_x2 -= equation_result_x2;
  equation_result = 0;
  equation_result_x = 0;
  equation_result_x2 = 0;
}

void equation_2::solve()
{
  int delta = pow(equation_term_x, 2) - (4 * equation_term * equation_term_x2);
  if (delta > 0)
  {
    int res1 = -equation_term_x - sqrt(delta) / 2 * equation_term_x2;
    int res2 = -equation_term_x + sqrt(delta) / 2 * equation_term_x2;
    std::cout << "Delta est superieur a 0" << std::endl;
    std::cout << "L'equation a deux solutions : " << res1 << " et " << res2 << std::endl;
  }
  else if (!delta)
  {
    int res0 = -equation_term_x / 2 * equation_term_x2;
    std::cout << "Delta est egal a 0" << std::endl;
    std::cout << "L'equation a une solution : " << res0 << std::endl;
  }
  else
  {
    int resre = -equation_term_x / 2 * equation_term_x2;
    int resim = sqrt(-delta) / 2 * equation_term_x2;
    std::cout << "Delta est inferieur a 0" << std::endl;
    std::cout << "L'equation a 2 solutions complexes : " << resre << " - " << resim << " et " << resre << " + " << resim << std::endl;
  }
}
