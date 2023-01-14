#include<iostream>
#include<cmath>
#include<fstream>
#include "vettore.h"

template <typename T> Vettore<T> read(int ntot, const char* filename) {

    Vettore<T> v(ntot);
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

template <typename T> double media (const Vettore<T> &v)  {
    double sum = 0;
    for (int i = 0; i < v.GetN(); i++){
        sum += v.GetComponent(i);
    }
    return sum/(v.GetN());
}

template <typename T> double varianza (const Vettore<T> &v) {
    
    double scarti = 0;
    for(int i = 0; i < v.GetN(); i++){
        scarti += pow((v.GetComponent(i) - media(v)),2);
    }
    return (scarti/(v.GetN()-1));
}

template <typename T> void sort_by (Vettore<T> &v) {
    T dep;              
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

template <typename T> double mediana (const Vettore<T> &v) {
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

template <typename T> void print(const char* filename,  Vettore<T> &v) {
    fstream outfile(filename, ios::out);
    for(int i=0; i<v.GetN(); i++) {
        outfile << v.GetComponent(i) << endl;
    }
    outfile.close();
}

template <typename T> void print(const Vettore<T> &v) {
    cout << "Elementi dell'array:" << endl;
    for(int i=0; i<v.GetN(); i++) {
        cout << "Elemento " << i+1 << ": " << v.GetComponent(i) << endl;
    }
}