//#ifndef __Vettore_h__
//#define __Vettore_h__ // se non è stato definito, definisci vettore.h

#include <iostream>
#include <fstream>
#include <string>

using namespace std;

class Vettore {
 public:

	Vettore();
	Vettore(unsigned int N);
	~Vettore();

    unsigned int GetN() const { return m_N; }
    void SetComponent(unsigned int, double); 
    double GetComponent(unsigned int) const;
    double& operator[] (unsigned int i) const;


 private:

	unsigned int m_N;
	double *m_v;

};

Vettore read(int ntot, const char* filename);
double media (const Vettore &v);
double varianza(const Vettore &v);
void sort_by (Vettore &v);
double mediana (Vettore &v);
void print(const char* filename,  Vettore &v);
void print(Vettore &v);

//#endif // __Vettore_h__