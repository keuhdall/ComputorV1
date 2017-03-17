class equation_2
{
  private:
    int equation_term;
    int equation_term_x;
    int equation_term_x2;
    int equation_result;
    int equation_result_x;
    int equation_result_x2;
    void recalc_terms();

  public:
    equation_2(int newEquationTerm, int newEquationTermX, int newEquationTermX2,
      int newEquationResult, int newEquationResultX, int newEquationResultX2);
    ~equation_2();
    void solve();
};
