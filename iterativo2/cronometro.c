#include "cronometro.h"

#include <time.h>

clock_t _tempo;

void inicia_cronometro() {
    _tempo = clock();
    
}

double para_cronometro() {

	double v;
	v = (double) (clock() - _tempo) / ((double) CLOCKS_PER_SEC);
	return v;

}
