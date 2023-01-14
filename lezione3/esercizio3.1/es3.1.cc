#include <iostream>
#include <fstream>
#include <cstdlib>

#include "funzioni2.h"

int main(int argc, char** argv) {

    if(argc<4) {
        cout << "Uso del programma: " << argv[0] << " <n_data> <nome_file> <nome_outfile>" << endl;
        return -1;
    }

    int ntot=atoi(argv[1]);

    char *filename=argv[2];

    char *fileout=argv[3];

    vector <double> v = read <double> (ntot, filename);

    cout << "Media: " << media<double>(v) << endl;

    cout << "Varianza: " << varianza<double>(v) << endl;

    sort_by<double>(v);

    cout << "Mediana: " << mediana<double>(v) << endl;

    print(argv[3], v);

    print(v);

    return 0;
}