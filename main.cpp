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

double a=2.0;
double h(double x){return a*x;};
double hprime(double x){return a;};

double b=1.0;
double j(double x){return b;};
double jprime(double x){return 0.0;};




//  cout << "the name of this function is: " << __func__ << endl;

int main ()
{
  using namespace Roots;

  double fnewton = newton(1.5, f, fprime, 0.000001, 0.000001, 1000000);
  double fbisection = bisection(0, 1, f, 0.0, 0.0);
  cout << "*** *** *** *** ***" << "\n";
  cout << "Test of Function f :"<< "\n";
  cout << "Newton: function evaluated at "<< fnewton << " is " <<  f(fnewton)<< "\n";
  cout << "Bisection: function evaluated at "<<fbisection<< " is " << f(fbisection)<< "\n";
  getchar();

  double gnewton = newton(2, g, gprime, 0.000001, 0.000001, 1000000);
  double gbisection = bisection(1, 3, g, 0.000000001, 0.000000001);
  cout << "*** *** *** *** ***" << "\n";
  cout << "Test of Function g :"<< "\n";
  cout << "Newton: function evaluated at "<<gnewton  << " is " <<  g(gnewton)<< "\n";
  cout << "Bisection: function evaluated at " <<gbisection<< " is " << g(gbisection)<< "\n";
  getchar();

  double pnewton = newton(9999, p, pprime, 0.000001, 0.000001, 1000000);
  double pbisection = bisection(-2, 1, p, 0.000000001, 0.000000001);
  cout << "*** *** *** *** ***" << "\n";
  cout << "Test of Function p :"<< "\n";
  cout << "Newton: function evaluated at "<<pnewton<<" is "<<p(pnewton)<< "\n";
  cout << "Bisection: function evaluated at " <<pbisection<<" is "<<p(pbisection)<< "\n";
  getchar();

  double qnewton = newton(0.1, q, qprime, 0.000001, 0.000001, 1000000);
  double qbisection = bisection(-1, 1, q, 0.000000001, 0.000000001);
  cout << "*** *** *** *** ***" << "\n";
  cout << "Test of Function q :"<< "\n";
  cout << "Newton: function evaluated at "<<qnewton<<" is "<<q(qnewton)<< "\n";
  cout << "Bisection: function evaluated at "<<qbisection<<" is "<<q(qbisection)<< "\n";
  getchar();

  double rnewton = newton(5, r, rprime, 0.000001, 0.000001, 1000000);
  double rbisection = bisection(3, 5.1, r, 0.000000001, 0.000000001);
  cout << "*** *** *** *** ***" << "\n";
  cout << "Test of Function r :"<< "\n";
  cout << "Newton: function evaluated at "<<rnewton<<" is "<<r(rnewton) << "\n";
  cout << "Bisection: function evaluated at "<<rbisection<<" is "<<r(rbisection) << "\n";
  getchar();

  double snewton = newton(-0.1, s, sprime, 0.000001, 0.000001, 1000000);
  double sbisection = bisection(-1, 1, s, 0.000000001, 0.000000001);
  cout << "*** *** *** *** ***" << "\n";
  cout << "Test of Function s :"<< "\n";
  cout << "Newton: function evaluated at "<<snewton <<" is "<<s(snewton)<< "\n";
  cout << "Bisection: function evaluated at "<<sbisection<<" is "<<s(sbisection)<< "\n";
  getchar();

  double hnewton = newton(9999, h, hprime, 0.000001, 0.000001, 1000000);
  double hbisection = bisection(-501, 501, h, 0.000000001, 0.000000001);
  cout << "*** *** *** *** ***" << "\n";
  cout << "Test of Function h :"<< "\n";
  cout << "Newton: function evaluated at "<<hnewton <<" is "<<h(hnewton)<< "\n";
  cout << "Bisection: function evaluated at "<<hbisection <<" is "<<h(hbisection)<< "\n";
  getchar();

  double jnewton = newton(500, jprime, jprime, 0.000001, 0.000001, 1000000);
  double jbisection = bisection(-3, 3, j, 0.000000001, 0.000000001);
  cout << "*** *** *** *** ***" << "\n";
  cout << "Test of Function j :"<< "\n";
  cout << "Newton: function evaluated at "<<jnewton <<" is "<<j(jnewton)<< "\n";
  cout << "Bisection: function evaluated at "<<jbisection <<" is "<<j(jbisection)<< "\n";
  cout << "*** *** *** *** ***" << "\n";

}
