#ifndef __RANDOMGEN_H__
#define __RANDOMGEN_H__
#include<cmath>
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
 

  private:
     unsigned int m_a, m_c, m_m;
     unsigned int m_seed;
};

class funzionebase {

  public:

  virtual double eval (double) const = 0;

  virtual ~funzionebase () {}

};

class seno : public funzionebase {
    
    public:

    double eval(double x) const {

        return sin(x);
    }
};

class integralMC {
    
    public:

    integralMC(unsigned int seed):m_myrand (seed){};
    ~integralMC() {;} ;

    double integralehom(double xmin, double xmax, double fmax, funzionebase &f, int punti) {


        double nhit = 0;

        double x = 0;

        double y = 0;

        for(int i=0; i<punti; i++) {

            x = m_myrand.unif(xmin,xmax);

            y = m_myrand.unif(0,fmax);

            if(y<f.eval(x)) {

            nhit ++;

            }
        }

        return (xmax-xmin)*fmax*(nhit/punti);

    };

    double integraleave(double xmin, double xmax, funzionebase &f, int punti) {

        double sum = 0;

        for(int i = 0; i<punti; i++) {
            
            double x = m_myrand.unif(xmin,xmax);

            sum += f.eval(x);
        }

        return (xmax-xmin)*(sum/punti);
    };

    private:

    randomgen m_myrand;
};

#endif