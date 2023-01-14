#ifndef __bisezione__
#define __bisezione__

#include <float.h> // Serve per includere DBL_MAX

#include "solutore.h"
#include "funzione_base.h"
#include "parabola.h"

using namespace std;

class bisezione : public solutore {

public:

  bisezione () : solutore() {;} ;
  bisezione (double a, double b, double prec) : solutore (a,b,prec) {;} ;
  ~bisezione () {;};

  double cercazeri (double a, double b, const funzionebase &f, double prec = 0.001, unsigned int nmax = 100 ) override {

    segno sign;

    double c = 0.5 * (b+a);

    int n2max = 0;

    double fa = f.eval(a);
    double fb = f.eval(b);
    double fc = f.eval(c);

    while(abs(b-a)>prec && n2max<nmax) {

    n2max ++;

    if (sign.eval(fa)*sign.eval(fc)<0) {

      return cercazeri(a, c, f);

    } else if (sign.eval(fc)*sign.eval(fb)<0) {

      return cercazeri(c, b, f);


    }

  }

  return c;

}



double cercazeri (double a, double b, const funzionebase *f, double prec = 0.001, unsigned int nmax = 100 ) {

    segno sign;

    double c = 0.5 * (b+a);

    int n2max = 0;

    double fa = f->eval(a);
    double fb = f->eval(b);
    double fc = f->eval(c);

    while(abs(b-a)>prec && n2max<nmax) {

    n2max ++;

    if (sign.eval(fa)*sign.eval(fc)<0) {

      return cercazeri(a, c, f);

    } else if (sign.eval(fc)*sign.eval(fb)<0) {

      return cercazeri(c, b, f);


    }

  }

  return c;
}

};

#endif