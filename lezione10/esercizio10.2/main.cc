#include "TApplication.h"
#include "TCanvas.h" 
#include "TH1F.h"
#include "TAxis.h"
#include <cmath>
#include <iostream>
#include "randomgen.h"

using namespace std;

int main(){
  
  integralMC integra(1);

  int nmax = 10000;

  seno s;
  
  TApplication myApp("myApp",0,0); 

  TCanvas c;

  c.Divide(3,2);

  TH1F ave100("ave100", "ave100", 100, 0, 0);
  
  for (int i = 0; i<nmax; i++) {

    ave100.Fill(integra.integraleave(0,M_PI,s,100));

  }

  double stdevA100 = ave100.GetStdDev();

  c.cd(1);

  ave100.SetTitle("Integrale media");
  ave100.GetXaxis()->SetTitle("valore integrale");
  ave100.GetYaxis()->SetTitle("N");
  
  ave100.SetLineColor(2);
  ave100.SetMarkerStyle(1);   

  ave100.Draw(); 

  TH1F ave500("ave500", "ave500", 100, 0, 0);
  
  for (int i = 0; i<nmax; i++) {

    ave500.Fill(integra.integraleave(0,M_PI,s,500));

  }

  double stdevA500 = ave500.GetStdDev();

  c.cd(2);

  ave500.SetTitle("Integrale media");
  ave500.GetXaxis()->SetTitle("valore integrale");
  ave500.GetYaxis()->SetTitle("N");
  
  ave500.SetLineColor(2);
  ave500.SetMarkerStyle(1);   

  ave500.Draw(); 

TH1F ave1000("ave1000", "ave1000", 100, 0, 0);
  
  for (int i = 0; i<nmax; i++) {

    ave1000.Fill(integra.integraleave(0,M_PI,s,1000));

  }

  double stdevA1000 = ave1000.GetStdDev();

  c.cd(3);

  ave1000.SetTitle("Integrale media");
  ave1000.GetXaxis()->SetTitle("valore integrale");
  ave1000.GetYaxis()->SetTitle("N");
  
  ave1000.SetLineColor(2);
  ave1000.SetMarkerStyle(1);   

  ave1000.Draw(); 

TH1F ave5000("ave5000", "ave5000", 100, 0, 0);
  
  for (int i = 0; i<nmax; i++) {

    ave5000.Fill(integra.integraleave(0,M_PI,s,5000));

  }

  double stdevA5000 = ave5000.GetStdDev();

  c.cd(4);

  ave5000.SetTitle("Integrale media");
  ave5000.GetXaxis()->SetTitle("valore integrale");
  ave5000.GetYaxis()->SetTitle("N");
  
  ave5000.SetLineColor(2);
  ave5000.SetMarkerStyle(1);   

  ave5000.Draw(); 

TH1F ave10000("ave10000", "ave10000", 100, 0, 0);
  
  for (int i = 0; i<nmax; i++) {

    ave10000.Fill(integra.integraleave(0,M_PI,s,10000));

  }

  double stdevA10000 = ave10000.GetStdDev();

  c.cd(5);

  ave10000.SetTitle("Integrale media");
  ave10000.GetXaxis()->SetTitle("valore integrale");
  ave10000.GetYaxis()->SetTitle("N");
  
  ave10000.SetLineColor(2);
  ave10000.SetMarkerStyle(1);   

  ave10000.Draw(); 

TCanvas c2;

  c2.Divide(3,2);

  TH1F hom100("hom100", "hom100", 100, 0, 0);
  
  for (int i = 0; i<nmax; i++) {

    hom100.Fill(integra.integralehom(0,M_PI,1,s,100));

  }

  double stdevH100 = hom100.GetStdDev();

  c2.cd(1);

  hom100.SetTitle("Integrale hit or miss");
  hom100.GetXaxis()->SetTitle("valore integrale");
  hom100.GetYaxis()->SetTitle("N");
  
  hom100.SetLineColor(2);
  hom100.SetMarkerStyle(1);   

  hom100.Draw(); 

  TH1F hom500("hom500", "hom500", 100, 0, 0);
  
  for (int i = 0; i<nmax; i++) {

    hom500.Fill(integra.integralehom(0,M_PI,1,s,500));

  }

  double stdevH500 = hom500.GetStdDev();

  c2.cd(2);

  hom500.SetTitle("Integrale hit or miss");
  hom500.GetXaxis()->SetTitle("valore integrale");
  hom500.GetYaxis()->SetTitle("N");
  
  hom500.SetLineColor(2);
  hom500.SetMarkerStyle(1);   

  hom500.Draw(); 

  TH1F hom1000("hom1000", "hom1000", 100, 0, 0);
  
  for (int i = 0; i<nmax; i++) {

    hom1000.Fill(integra.integralehom(0,M_PI,1,s,1000));

  }

  double stdevH1000 = hom1000.GetStdDev();

  c2.cd(3);

  hom1000.SetTitle("Integrale hit or miss");
  hom1000.GetXaxis()->SetTitle("valore integrale");
  hom1000.GetYaxis()->SetTitle("N");
  
  hom1000.SetLineColor(2);
  hom1000.SetMarkerStyle(1);   

  hom1000.Draw(); 

  TH1F hom5000("hom5000", "hom5000", 100, 0, 0);
  
  for (int i = 0; i<nmax; i++) {

    hom5000.Fill(integra.integralehom(0,M_PI,1,s,5000));

  }

  double stdevH5000 = hom5000.GetStdDev();

  c2.cd(4);

  hom5000.SetTitle("Integrale hit or miss");
  hom5000.GetXaxis()->SetTitle("valore integrale");
  hom5000.GetYaxis()->SetTitle("N");
  
  hom5000.SetLineColor(2);
  hom5000.SetMarkerStyle(1);   

  hom5000.Draw(); 

  TH1F hom10000("hom10000", "hom10000", 100, 0, 0);
  
  for (int i = 0; i<nmax; i++) {

    hom10000.Fill(integra.integralehom(0,M_PI,1,s,10000));

  }

  double stdevH10000 = hom10000.GetStdDev();

  c2.cd(5);

  hom10000.SetTitle("Integrale hit or miss");
  hom10000.GetXaxis()->SetTitle("valore integrale");
  hom10000.GetYaxis()->SetTitle("N");
  
  hom10000.SetLineColor(2);
  hom10000.SetMarkerStyle(1);   

  hom10000.Draw(); 



  myApp.Run();

  return 0;
}