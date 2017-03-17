#include "equation_1.h"

equation_1::equation_1(int newEquationTerm, int newEquationTermXm int newEquationResult, int newEquationResultX);
{
  equation_term = newEquationTerm;
  equation_term_x = newEquationTermX;
  equation_result = newEquationResult;
  equation_result_x = newEquationResultX;
}

equation_1::~equation_1()
{
}

void equation_1::solve()
{
  equation_result -= equation_term;
  equation_term = 0;
  equation_term_x -= equation_result_x;
  equation_result_x = 0;
  equation_result /= equation_term_x;
  std::cout << "la solution c'est : " << equation_result << " fdp" << std::endl;
}
