class equation_2
{
  private:
    double equation_term;
    double equation_term_x;
    double equation_term_x2;
    double equation_result;
    double equation_result_x;
    double equation_result_x2;
    void recalc_terms();

  public:
    equation_2(double newEquationTerm, double newEquationTermX, double newEquationTermX2,
      double newEquationResult, double newEquationResultX, double newEquationResultX2);
    ~equation_2();
    void solve();
};
