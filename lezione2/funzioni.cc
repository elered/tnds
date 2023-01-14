#include<iostream>
#include<cmath>
#include<fstream>
#include "funzioni.h"

Vettore::Vettore(unsigned int N) {
  //cout << "Calling constructor with arguments" << endl;
  m_N = N;
  m_v = new double[N];
  for ( int k = 0 ; k < N ; k++ ) m_v[k] = 0;
  
}

double& Vettore::operator[] (unsigned int i) const {
    if (i<m_N) {
        return m_v[i];
    } else {
        cout << "Errore: indice " << i << ", dimensione " << m_N << endl;
        exit(-1);
    }
}

Vettore::~Vettore() {
    delete[] m_v;
}

void Vettore::SetComponent(unsigned int i, double a) {
  if ( i<m_N ) {
    m_v[i]=a;
  } else {
    cout << "Errore: indice " << i << ", dimensione " << m_N << endl;
    exit (-1);
  }
}

double Vettore::GetComponent(unsigned int i) const {
    if (i<m_N) {
        return m_v[i];
    } else {
        cout << "Errore: indice " << i << ", dimensione " << m_N << endl;
        exit(-1);
    }
}

Vettore read(int ntot, const char* filename) {

    Vettore v(ntot);
    fstream infile;
    infile.open(filename,ios::in);
    if(!infile.good()) {
        throw runtime_error("ERROR, failed to open file...");

    infile.clear(); infile.seekg(0);
    }else {
        for(int i = 0; i < ntot; i++){

            double vector = 0;
            infile >> vector;
            v.SetComponent(i, vector);
            if(infile.eof()){
                break;
            }
        }
    }

    infile.close();
    return v;
}

double media (const Vettore &v)  {
    double sum = 0;
    for (int i = 0; i < v.GetN(); i++){
        sum += v.GetComponent(i);
    }
    return sum/(v.GetN());
}

double varianza (const Vettore &v) {
    
    double scarti = 0;
    for(int i = 0; i < v.GetN(); i++){
        scarti += pow((v.GetComponent(i) - media(v)),2);
    }
    return (scarti/(v.GetN()-1));
}

void sort_by (Vettore &v) {
    double dep;              
    for (int i = 0; i < v.GetN() - 1; i++){
        for (int j = i + 1; j < v.GetN(); j++){
            if (v.GetComponent(i) > v.GetComponent(j)){
                dep = v.GetComponent(i);
                v.SetComponent(i, v.GetComponent(j));
                v.SetComponent(j, dep);
            }
        }   
    }
}

double mediana (Vettore &v) {
    double mediana;
        if(v.GetN()%2==0) {
            double num1 = v[v.GetN()/2-1];
            double num2 = v[v.GetN()/2];
            mediana = (num1 + num2)/2;
        } else {
            mediana = v[(v.GetN())/2];
        }
    return mediana;
}

void print(const char* filename,  Vettore &v) {
    fstream outfile(filename, ios::out);
    for(int i=0; i<v.GetN(); i++) {
        outfile << v.GetComponent(i) << endl;
    }
    outfile.close();
}

void print(Vettore &v) {
    cout << "Elementi dell'array:" << endl;
    for(int i=0; i<v.GetN(); i++) {
        cout << "Elemento " << i+1 << ": " << v.GetComponent(i) << endl;
    }
}