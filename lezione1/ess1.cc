#include<iostream>
#include<fstream>
#include "funzioni.h"
#include<cstdlib>
using namespace std;

int main(int argc, char** argv) {

    if(argc<4) {
        cout << "Uso del programma: " << argv[0] << " <n_data> <nome_file> <nome_outfile>" << endl;
        return -1;
    }

    int ntot=atoi(argv[1]);

    char *filename=argv[2];

    char *fileout=argv[3];
    
    double *v = read_load(ntot, filename);

    cout << "Media: " << media(v, ntot) << endl;

    cout << "Varianza: " << varianza(v, ntot) << endl;

    sort_by_(v, ntot);

    cout << "Mediana: " << mediana(v, ntot) << endl;

    print(fileout, v, ntot);

    print(v, ntot);

    return 0;

}