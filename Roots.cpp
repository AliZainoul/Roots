#include <iostream>
#include <cmath>
using namespace std;
#include "error.hpp"
#include "Roots.hpp"
typedef double (*pfn) (double);

namespace Roots{
  bool root(pfn f, double x) {return (f(x)==0.0)?true:false;};
  bool divisionbyzero(pfn f, double x) {return (f(x)==0.0)?true:false;};
  bool Solution(double xp, double xn, pfn fd, double delta, double epsilon)
  {   return (((abs(fd(xp)))<epsilon) || ((abs(xn-xp))<=delta)) ? true:false; };

  // BISECTION METHOD
  double bisection(double a, double b, pfn f , double delta, double epsilon)
  {
    double midpoint = (a+b)/ 2;
    if (root(f,midpoint)) return midpoint;
    if (root(f,a)) return a;
    if (root(f,b)) return b;
    if (root(f,0.0)) return 0.0;
    if (f(midpoint+epsilon)-f(midpoint)==0.0)
    error("Constant Functions do no admit roots.");
    if (((abs(b-a)) > delta) && ((abs(f(midpoint))) > epsilon))
    {
      if (f(a)*f(midpoint) < 0)
        return bisection(a, b=midpoint, f, delta, epsilon);
      else return bisection(a=midpoint, b, f, delta, epsilon);
    }
    return midpoint;
  };

  // NEWTON METHOD
  double newton(double xp, pfn f, pfn fd, double delta, double epsilon, int nmax)
  {
    double fxp,fdxp,xn;
    if (root(f,xp)) return xp;
    if ((1/epsilon)*(f(xp+epsilon)-f(xp))==0.0)
    error("Constant Functions do no admit roots.");
    if (!root(fd,xp)) // Avoiding dividing by Zero
      for (unsigned int k=1;k<=nmax;k++)
      {
        fxp = f(xp);
        fdxp = fd(xp);
        if (((abs(fdxp))<epsilon))
        error("Denominator fd(xp) too small; please try with another guess xp.");
        else xn = xp - (f(xp)/fd(xp));
        if (Solution(xp, xn, fd, delta, epsilon)) return xn;
        else xp = xn;
      }
    else error("Division By Zero occurs.");
    error("Too many interations or diverging method; please try with another guess xp.");
  };
}
