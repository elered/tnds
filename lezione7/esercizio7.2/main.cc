#include <cmath>
#include <iostream>
#include "integrali.h"
#include "funzione_base.h"
#include <iomanip>
#include "TGraph.h"
#include "TCanvas.h"
#include "TF1.h"
#include "TApplication.h"
#include "TAxis.h"
#include "TLegend.h"

using namespace std;

int main(int argc, char * argv[] ) {
  
  if (argc != 2) {
    cerr << "Usage: " << argv[0] << " <precisione>" << endl;
    return -1;
  }

  double prec = atof(argv[1]);

  seno f;
  trapezoidi myint(0, M_PI);


  double I = myint.integra(prec, f);


  cout << " Prec = " << prec << endl;
  cout << " I = " << I << endl;
  
  return 0;

}