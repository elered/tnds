#include<iostream>
#include<cmath>
#include<fstream>
#include "assert.h"

#include<vector>
#include<algorithm>

using namespace std;

template <typename T> vector<T> read(int ntot, const char* filename) {

    vector<T> v;
    fstream infile;
    infile.open(filename,ios::in);
    if(!infile.good()) {
        throw runtime_error("ERROR, failed to open file...");

    infile.clear(); infile.seekg(0);
    }else {
        for(int i = 0; i < ntot; i++){
            T vettore = 0;
            infile >> vettore;
            v.push_back(vettore);
            if(infile.eof()){
                break;
            }
        }
    }

    infile.close();
    return v;
}

template <typename T> double media (const vector<T> &v)  {
    double sum = 0;
    for (int i = 0; i < v.size(); i++){
        sum += v[i];
    }
    return sum/(v.size());
}

template <typename T> double varianza (const vector<T> &v) {
    
    T scarti = 0;
    for(int i = 0; i < v.size(); i++){
        scarti += pow((v[i] - media(v)),2);
    }
    return (scarti/(v.size()-1));
}

template <typename T> void sort_by (vector<T> &v) {
    T dep;              
    for (int i = 0; i < v.size() - 1; i++){
        for (int j = i + 1; j < v.size(); j++){
            if (v[i] > v[j]){
                dep = v[i];
                v[i]=v[j];
                v[j] = dep;
            }
        }   
    }
}

template <typename T> double mediana (const vector<T> &v) {
    double mediana;
        if(v.size()%2==0) {
            double num1 = v[v.size()/2-1];
            double num2 = v[v.size()/2];
            mediana = (num1 + num2)/2;
        } else {
            mediana = v[(v.size())/2];
        }
    return mediana;
}

template <typename T> void print(const char* filename,  vector<T> &v) {
    fstream outfile(filename, ios::out);
    for(int i=0; i<v.size(); i++) {
        outfile << v[i] << endl;
    }
    outfile.close();
}

template <typename T> void print(const vector<T> &v) {
    cout << "Elementi dell'array:" << endl;
    for(int i=0; i<v.size(); i++) {
        cout << "Elemento " << i+1 << ": " << v[i] << endl;
    }
}