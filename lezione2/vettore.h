#ifndef __Vettore_h__
#define __Vettore_h__ // se non è stato definito, definisci vettore.h

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
    void scambia(unsigned int primo, unsigned int secondo);

    Vettore(const Vettore&);
    Vettore& operator=(const Vettore&);

 private:

	unsigned int m_N;
	double * m_v;

};

#endif // __Vettore_h__