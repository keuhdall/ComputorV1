#include "equation_0.h"

equation_0::equation_0(int newEquationTerm, int newEquationResult)
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
    std::cout << "C'est pas bon fdp" << std::end;
  }
  else
  {
    std::cout << "La solution c'est l'ensemble des reels fdp" << std::endl;
  }
}
