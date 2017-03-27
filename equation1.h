class equation_1
{
  private:
    double equation_term;
    double equation_term_x;
    double equation_result;
    double equation_result_x;
    void recalc_terms();

  public:
    equation_1(double newEquationTerm, double newEquationTermX, double newEquationResult, double newEquationResultX);
    ~equation_1();
    void solve();
};
