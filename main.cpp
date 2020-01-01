#include <iostream>
#include <cmath>
using namespace std;
#include "error.hpp"
#include "Roots.hpp"
using namespace Roots;

typedef double (*pfn) (double);

double f(double x){return (1/x) - pow(2,x);};
double fprime(double x){return ((-1/(2*x) ) -exp(x*log(2)));};

double g(double x){return (pow(2,(-x)) + exp(x) + 2 * cos(x) - 6);};
double gprime(double x){return ( exp(-x*log(2)) + exp(x) - 2 * sin(x) );};

double p(double x){return (x+1);};
double pprime(double x){return 1;};

double q(double x){return (x*x)-1;};
double qprime(double x){return (2*x);};

double r(double x){return (x*x*x)-(5*x*x)+(3*x)+7;};
double rprime(double x){return (3*x*x)-(10*x)+(3);};

double s(double x){return 1-(x*x);};
double sprime(double x){return (-2*x);};

double h(double x){return x;};
double hprime(double x){return 1;};

double j(double x){return 1;};
double jprime(double x){return 0;};




//  cout << "the name of this function is: " << __func__ << endl;

int main ()
{
  using namespace Roots;
  cout << "*** *** *** *** ***" << "\n";
  cout << "Test of Function f :"<< "\n";
  cout << "Newton:"<< newton(1.5, f, fprime, 0.000001, 0.000001, 1000000) << "\n";
  cout << "Bisection:"<<bisection(0, 1, f, 0.000000001, 0.000000001)<< "\n";


  cout << "*** *** *** *** ***" << "\n";
  cout << "Test of Function g :"<< "\n";
  cout << "Newton:"<<newton(2, g, gprime, 0.000001, 0.000001, 1000000) << "\n";
  cout << "Bisection:" <<bisection(1, 3, g, 0.000000001, 0.000000001)<< "\n";

  cout << "*** *** *** *** ***" << "\n";
  cout << "Test of Function p :"<< "\n";
  cout << "Newton:"<<newton(9999, p, pprime, 0.000001, 0.000001, 1000000) << "\n";
  cout << "Bisection:" <<bisection(-2, 1, p, 0.000000001, 0.000000001)<<"\n";

  cout << "*** *** *** *** ***" << "\n";
  cout << "Test of Function q :"<< "\n";
  cout << "Newton:"<<newton(0.1, q, qprime, 0.000001, 0.000001, 1000000) << "\n";
  cout << "Bisection:"<<bisection(-1, 1, q, 0.000000001, 0.000000001)<< "\n";

  cout << "*** *** *** *** ***" << "\n";
  cout << "Test of Function r :"<< "\n";
  cout << "Newton:"<<newton(5, r, rprime, 0.000001, 0.000001, 1000000) << "\n";
  cout << "Bisection:"<<bisection(3, 5.1, r, 0.000000001, 0.000000001)<< "\n";

  cout << "*** *** *** *** ***" << "\n";
  cout << "Test of Function s :"<< "\n";
  cout << "Newton:"<<newton(-0.1, s, sprime, 0.000001, 0.000001, 1000000) << "\n";
  cout << "Bisection:"<<bisection(-1, 1, s, 0.000000001, 0.000000001)<< "\n";

  cout << "*** *** *** *** ***" << "\n";
  cout << "Test of Function h :"<< "\n";
  cout << "Newton:"<<newton(500, h, hprime, 0.000001, 0.000001, 1000000) << "\n";
  cout << "Bisection:"<<bisection(-501, 501, h, 0.000000001, 0.000000001)<< "\n";

  /*
  cout << "*** *** *** *** ***" << "\n";
  cout << "Test of Function j :"<< "\n";
  cout << newton(500, hprime, jprime, 0.000001, 0.000001, 1000000) << "\n";
  cout << bisection(-3, 3, j, 0.000000001, 0.000000001)<< "\n";
  cout << "*** *** *** *** ***" << "\n";
  */
}
