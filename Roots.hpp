#ifndef ROOTS_H
#define ROOTS_H
#include <iostream>
#include <cmath>
using namespace std;
#include "error.hpp"


typedef double (*pfn) (double);
namespace Roots{
double bisection(double a, double b, pfn f , double delta, double epsilon);
bool root(pfn f, double xp);
bool divisionbyzero(pfn fd, double xp);
bool haveWeFoundSolution(double xp, double xn);
double newton(double xp, pfn f, pfn fd, double delta, double epsilon, int n_max);
}
#endif
