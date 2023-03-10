#include <iostream>
#include <fstream>
#include <cstdlib>

#include "funzioni.h"

int main(int argc, char** argv) {

    if(argc<4) {
        cout << "Uso del programma: " << argv[0] << " <n_data> <nome_file> <nome_outfile>" << endl;
        return -1;
    }

    int ntot=atoi(argv[1]);

    char *filename=argv[2];

    char *fileout=argv[3];

    Vettore v = read(ntot, filename);

    cout << "Media: " << media(v) << endl;

    cout << "Varianza: " << varianza(v) << endl;

    sort_by(v);

    cout << "Mediana: " << mediana(v) << endl;

    print(argv[3], v);

    print(v);

    return 0;
}