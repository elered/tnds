#include <iostream>

#include "TApplication.h"
#include "TCanvas.h" 
#include "TGraph.h"
#include "TAxis.h"
#include <cmath>

#include "equazionidifferenziali.h"

using namespace std;

int main(int argc, char** argv){
  
  if(argc != 2)
  {
    cerr << "Uso: " << argv[0]  << " <passo_di_integrazione> " << endl;
    return -1;
  }

  Eulero myEuler;

  OscillatoreArmonico osc(1.0);

  double tmax = 70.0;
  double h = atof(argv[1]);
  vector<double> x {0.0, 1.0};
  double t = 0.0;

  int nstep = static_cast<int>(tmax/h+0.5);
  
  TApplication myApp("myApp",0,0); 
  
  TGraph myGraph1;
  TGraph myGraph2;

  TCanvas * myCanvas = new TCanvas();
  myCanvas->cd();

  for (int step = 0; step < nstep; step++){
    x = myEuler.Passo(t,x,h,osc);
    t = t+h;
    myGraph1.SetPoint(step, t, x[0]);
  }
  

  myGraph1.SetTitle("Oscillatore armonico");
  myGraph1.GetXaxis()->SetTitle("Posizione");
  myGraph1.GetYaxis()->SetTitle("Tempo");
  
  myGraph1.SetLineColor(2);
  myGraph1.SetMarkerStyle(1);   

  myGraph1.Draw("ALP"); 

  TCanvas * myCanvas1 = new TCanvas();
  myCanvas1->cd();

  int k = 0;

  for(double i=0.1; i>h; i=i/2) {
    int nstep = static_cast<int>(tmax/i+0.5);
    for(int step = 0; step < nstep; step ++) {
      x = myEuler.Passo(t,x,i,osc);
      t=t+i;
    }
    myGraph2.SetPoint(k,i, fabs(x[0]-sin(t)));
    k++;
    x[0] = 0.0;
    x[1] = 1.0;
    t = 0.0;
  }

  myCanvas1->SetLogx();
  myCanvas1->SetLogy();

  myGraph2.SetTitle("Andamento errore");
  myGraph2.GetXaxis()->SetTitle("Passo");
  myGraph2.GetYaxis()->SetTitle("Errore");
  
  myGraph2.SetLineColor(2);
  myGraph2.SetMarkerStyle(1);   

  myGraph2.Draw("ALP");

  myApp.Run();

  return 0;
}

 

