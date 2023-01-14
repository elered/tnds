#ifndef __INTEGRAL_H__
#define __INTEGRAL_H__

#include <iostream>
#include <cmath>
#include "funzione_base.h"

using namespace std;

class integral {

 public:
  
  integral (double a, double b){
    checkinterval (a,b);
    m_nstep = 0;
    m_h = 0; 
    m_sum = 0;
    m_integral =0;
  }

  virtual double integra(double prec, funzionebase& f) = 0;

 protected:

  void checkinterval (double a, double b){

    m_a = min(a,b);
    m_b = max(a,b);

    if(a>b) {
      m_sign = -1;
    } else {
      m_sign =1;
    };

  }

  unsigned int m_nstep;
  double m_a, m_b;
  double m_sum, m_integral, m_h;
  int m_sign;
};

class trapezoidi : public integral {

 public:

  trapezoidi (double a, double b) : integral (a, b){;};

  double integra(double prec, funzionebase& f) override{

    double fa = f.eval(m_a);
    double fb = f.eval(m_b);
    m_nstep = 2;
    double In;
    double I2n;
    double fk = 0.5*fa + 0.5*fb;


        do {
            double m_h = (m_b-m_a)/m_nstep;

            for(int k=1; k<m_nstep; k+=2) { 

            fk += f.eval(m_a+k*m_h);

            };

            In = I2n;

            I2n = m_sign*fk*m_h;

            m_nstep *= 2;
    

        } while(prec<(4./3.)*fabs(I2n-In));

        return I2n;
 

    };

};

#endif // __INTEGRAL_H__