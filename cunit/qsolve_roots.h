// qsolve_roots.h
// version 1.01

// coefs for ax^2 + bx + c = 0
typedef struct {
  double	a;
  double	b;
  double	c;
} Coef;

// Real roots for ax^2 + bx + c = 0
typedef struct {
  double	x1;
  double	x2;
} Root;

// quadratic eqaution solver
int qsolve_roots(Coef *coef, Root *root);
