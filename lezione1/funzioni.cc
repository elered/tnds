#include<iostream>
#include<fstream>
#include<cmath>
#include<sstream>
#include "funzioni.h"

using namespace std;

double *read_load(int ntot, char *filename){
    fstream infile;
    infile.open(filename,ios::in);
    if(!infile.good())
        throw runtime_error("ERROR, failed to open file...");

    infile.clear(); infile.seekg(0);

    double *read = new double[ntot];
    for(int i = 0; i < ntot; i++){
        infile >> read[i];
    }
    infile.close();
    return read;
}

double media(double *m, int ntot){
    double sum = 0;
    for (int i = 0; i < ntot; i++){
        sum += m[i];
    }
    return sum/ntot;
}

double varianza(double *m, int ntot){
    double sum = 0;
    for (int i = 0; i < ntot; i++){
        sum += m[i];
    }
    double media = sum/ntot;
    
    double scarti = 0;
    for(int i = 0; i < ntot; i++){
        scarti += pow((m[i] - media),2);
    }
    return (scarti/(ntot-1));
}

void sort_by_(double *m, int ntot){    
    double dep;              
    for (int i = 0; i < ntot - 1; i++){
        for (int j = i + 1; j < ntot; j++){
            if (m[i] > m[j]){
                dep = m[i];
                m[i] = m[j];
                m[j] = dep;
            }
        }   
    }
}

double mediana(double *m, int ntot) {
    double mediana;
        if(ntot%2==0) {
            double num1 = m[(ntot/2)-1];
            double num2 = m[(ntot/2)];
            mediana = (num1 + num2)/2;
            } else {
                mediana = m[(ntot+1)/2];
            }
    return mediana;
}

void print(const char* filename,  double *m, int ntot) {
    fstream outfile(filename, ios::out);
    for(int i=0; i<ntot; i++) {
        outfile << m[i] << endl;
    }
    outfile.close();
}

void print(double *m, int ntot) {
    cout << "Elementi dell'array:" << endl;
    for(int i=0; i<ntot; i++) {
        cout << "Elemento " << i+1 << ": " << m[i] << endl;
    }
}