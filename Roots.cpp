#include <iostream>
#include <cmath>
#include "error.hpp"
#include "Roots.hpp"
using namespace std;
typedef double (*pfn) (double);
namespace Roots{
  double bisection(double a, double b, pfn f , double delta, double epsilon)
  {
    double midpoint = (a+b)/ 2;
    while (((abs(b-a)) > delta) && ((abs(f(midpoint))) > epsilon)
  )
    {
      if (f(a)*f(midpoint) < 0) return bisection(a, b=midpoint, f, delta, epsilon);
      else return bisection(a=midpoint, b, f, delta, epsilon);
    }
    return midpoint;
  }

  bool root(pfn f, double xp)
  {
    if (f(xp)==0.0) return true;
    else return false;
  };

  bool divisionbyzero(pfn fd, double xp)
  {
  if (fd(xp)==0.0) return true;
  else return false;
  };

  bool haveWeFoundSolution(double xp, double xn)
  {
  if (xn==xp) return false;
  else return true;
  };
  double newton(double xp, pfn f, pfn fd, double delta, double epsilon, int n_max)
  {
    if (root(f,xp)) return xp;
    if (!divisionbyzero(fd, xp))
    {
      double xn = xp - (f(xp)/fd(xp));
      while (    ((abs(xn-xp)) > delta) && ((abs(f(xn)))  > epsilon)     )
      {
        return newton(xn, f, fd, delta, epsilon, n_max-1);
      }
      if (haveWeFoundSolution(xp,xn)) return xn;
      else {error("Method Diverge");}
    }
    else {error("Divisiong By Zero Occurs");}
  }
}
