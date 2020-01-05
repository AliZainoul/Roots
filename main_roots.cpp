#include <iostream>
#include <cmath>
using namespace std;
#include "error.hpp"
#include "Roots.hpp"
using namespace Roots;

typedef double (*pfn) (double);


double r(double x){return (x*x*x)-(5*x*x)+(3*x)+7;};
double rprime(double x){return (3*x*x)-(10*x)+(3);};

double p(double x){return (x+1);};
double pprime(double x){return 1;};

double q(double x){return (x*x)-1;};
double qprime(double x){return (2*x);};

double s(double x){return 1-(x*x);};
double sprime(double x){return (-2*x);};

double f(double x){return (1/x) - pow(2,x);};
double fprime(double x){return ((-1/(2*x) ) -exp(x*log(2)));};

double g(double x){return (pow(2,(-x)) + exp(x) + 2 * cos(x) - 6);};
double gprime(double x){return ( exp(-x*log(2)) + exp(x) - 2 * sin(x) );};

double a=-15.5;
double h(double x){return a*x;};
double hprime(double x){return a;};

double b=0.5;
double j(double x){return b;};
double jprime(double x){return 0.0;};


//  cout << "The name of this function is: " << __func__ << endl;

int main ()
{
  using namespace Roots;

  // Params for Newton Method
  long int d = 1000000; // nmax
  double delta = 0.000001,  epsilon = 0.000001; // delta and epsilon

  // Params for Bisection Method
  double atled = 0.000001, nolispe = 0.000001; // delta and epsilon


  cout << "*** *** *** *** ***" << "\n";
  cout << "Test of Function r :"<< "\n";
  double newtonr = newton(5, r, rprime, delta, epsilon, d);
  double bisectionr = bisection(3, 5.1, r, atled, nolispe);
  cout << "Newton: function evaluated at "<<newtonr<<" is "<<r(newtonr) << "\n";
  cout << "Bisection: function evaluated at "<<bisectionr<<" is "<<r(bisectionr) << "\n";
  getchar();

  cout << "*** *** *** *** ***" << "\n";
  cout << "Test of Function f :"<< "\n";
  double newtonf = newton(1.5, f, fprime, delta, epsilon, d);
  double bisectionf = bisection(0, 1, f, atled, nolispe);
  cout << "Newton: function evaluated at "<< newtonf << " is " <<  f(newtonf)<< "\n";
  cout << "Bisection: function evaluated at "<<bisectionf<< " is " << f(bisectionf)<< "\n";
  getchar();

  cout << "*** *** *** *** ***" << "\n";
  cout << "Test of Function g :"<< "\n";
  double newtong = newton(2, g, gprime, delta, epsilon, d);
  double bisectiong = bisection(1, 3, g, atled, nolispe);
  cout << "Newton: function evaluated at "<<newtong<< " is " <<  g(newtong)<< "\n";
  cout << "Bisection: function evaluated at " <<bisectiong<< " is " << g(bisectiong)<< "\n";
  getchar();

  cout << "*** *** *** *** ***" << "\n";
  cout << "Test of Function p :"<< "\n";
  double newtonp = newton(9999, p, pprime, delta, epsilon, d);
  double bisectionp = bisection(-2, 1, p, atled, nolispe);
  cout << "Newton: function evaluated at "<<newtonp<<" is "<<p(newtonp)<< "\n";
  cout << "Bisection: function evaluated at " <<bisectionp<<" is "<<p(bisectionp)<< "\n";
  getchar();

  cout << "*** *** *** *** ***" << "\n";
  cout << "Test of Function q :"<< "\n";
  double newtonq = newton(0.1, q, qprime, delta, epsilon, d);
  double bisectionq = bisection(-1, 1, q, atled, nolispe);
  cout << "Newton: function evaluated at "<<newtonq<<" is "<<q(newtonq)<< "\n";
  cout << "Bisection: function evaluated at "<<bisectionq<<" is "<<q(bisectionq)<< "\n";
  getchar();

  cout << "*** *** *** *** ***" << "\n";
  cout << "Test of Function s :"<< "\n";
  double newtons = newton(-0.1, s, sprime, delta, epsilon, d);
  double bisections = bisection(-1, 1, s, atled, nolispe);
  cout << "Newton: function evaluated at "<<newtons<<" is "<<s(newtons)<< "\n";
  cout << "Bisection: function evaluated at "<<bisections<<" is "<<s(bisections)<< "\n";
  getchar();

  cout << "*** *** *** *** ***" << "\n";
  cout << "Test of Function h :"<< "\n";
  double newtonh = newton(9999, h, hprime, delta, epsilon, d);
  double bisectionh = bisection(-501, 501, h, atled, nolispe);
  cout << "Newton: function evaluated at "<<newtonh<<" is "<<h(newtonh)<< "\n";
  cout << "Bisection: function evaluated at "<<bisectionh<<" is "<<h(bisectionh)<< "\n";
  getchar();

  cout << "*** *** *** *** ***" << "\n";
  cout << "Test of Function j :"<< "\n";
  double newtonj = newton(500, j, jprime, delta, epsilon, d);
  double bisectionj = bisection(-3, 3, j, atled, nolispe);
  cout << "Newton: function evaluated at "<<newtonj<<" is "<<j(newtonj)<< "\n";
  cout << "Bisection: function evaluated at "<<bisectionj <<" is "<<j(bisectionj)<< "\n";
  cout << "*** *** *** *** ***" << "\n";

  return 0;
}
