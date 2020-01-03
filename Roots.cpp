#include <iostream>
#include <cmath>
using namespace std;
#include "error.hpp"
#include "Roots.hpp"
typedef double (*pfn) (double);
namespace Roots{
  bool root(pfn f, double x)
  {
    if (f(x)==0.0) return true;
    else return false;
  };

  bool divisionbyzero(pfn f, double x)
  {
  if (f(x)==0.0) return true;
  else return false;
  };

  bool Solution(double xp, double xn, pfn fd, double delta, double epsilon)
  {
  if (((abs(fd(xp)))<epsilon) || ((abs(xn-xp))<=delta)) return true;
  else return false;
  };

  // BISECTION METHOD DOES NOT WORK ON CONSTANT FUNCTIONS
  double bisection(double a, double b, pfn f , double delta, double epsilon)
  {
    double midpoint = (a+b)/ 2;
    //if  ((x!==y!==z) && (f(x)==f(y)==f(z))) error ("Constant functions do not admit roots.");
    if (root(f,0.0)) return 0.0;
    if (root(f,midpoint)) return midpoint;
    if (root(f,a)) return a;
    if (root(f,b)) return b;

    while (((abs(b-a)) > delta) && ((abs(f(midpoint))) > epsilon))
    {
      if (root(f,a) || root(f,midpoint)) break;
      else
      {
        if (f(a)*f(midpoint) < 0) return bisection(a, b=midpoint, f, delta, epsilon);
        else return bisection(a=midpoint, b, f, delta, epsilon);
      }
    }
    return midpoint;
  }

  double newton(double xp, pfn f, pfn fd, double delta, double epsilon, int n_max)
  {
    double fxp,fdxp,xn;
    double x; // Arbitrary x;
    if (fd(x) == 0.0) error ("Constant functions do not admit roots.");
    if (root(f,0.0)) return 0.0;
    if (root(f,xp)) return xp;
    x = xp;
    if (!divisionbyzero(fd,xp))
    for (unsigned int k=1;k<=n_max;k++)
    {
      fxp = f(x);
      fdxp = fd(x);
      if (((abs(fdxp))<epsilon)) error("Denominator too small;");
      else xn = x - (f(x)/fd(x));
      if (Solution(x, xn, fd, delta, epsilon)) return xn;
      else x = xn;
    }
    else error("Division By Zero occurs.");
    error("Too many interations or diverging method; please try with another guess");
  }
}

/*  double newton(double xp, pfn f, pfn fd, double delta, double epsilon, int n_max)
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
  */
