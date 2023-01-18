#ifndef __RANDOMGEN_H__
#define __RANDOMGEN_H__
#include <cmath>
#include <iostream>

using namespace std;

class randomgen{

  public:
     randomgen(unsigned int n) {n = m_seed, m_a = 1664525, m_c = 1013904223, m_m = 1<<31;}; // 1<<31 è due alla 31, operatore binario shift

     void seta(unsigned int a) {m_a = a;}
     void setc(unsigned int c) {m_c = c;}
     void setm(unsigned int m) {m_m = m;}

     double rand() {

        m_seed = (m_a*m_seed+m_c)%m_m;
        return double (m_seed)/m_m;

     };
     double unif(double xmin, double xmax) {

        return xmin + (xmax -xmin) * rand();

     };
     double exp(double mean) {

        return -(1/mean)*log(1.-rand());

     };
     double gauss(double mean, double sigma) {
      
      double s = rand();
      double t = rand();
      double x = sqrt(-2.*log(1.-s))*cos(2*M_PI*t);

      return mean+x*sigma;

     };
     
     double gaussAR(double mean, double sigma) {

      double s = unif(0,1);

      double t = unif(0,1);

      double xmin = mean - 5*sigma;

      double xmax = mean + 5*sigma;

      double x = xmin + (xmax-xmin)*s;

      double max = 1/(sigma*sqrt(2 * M_PI));

      double f = max * 1/(exp(pow((x-mean), 2)/(2 * pow(sigma, 2))));

      double y = max*t;

      while (y < f) {

         return gaussAR(mean, sigma);

      }

      return x;

     };

  private:
     unsigned int m_a, m_c, m_m;
     unsigned int m_seed;
};

#endif