#include<string>
#include<sstream>

using namespace std;

double *read_load(int ntot, char *filename);

double media(double *m, int ntot);

double varianza(double *m, int ntot);

void sort_by_(double *m, int ntot);

double mediana(double *m, int ntot);

void print(const char* filename, double *m, int ntot);

void print(double *m, int ntot);