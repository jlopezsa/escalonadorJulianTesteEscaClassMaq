// Controlador de máquina de venda de refrigerantes

#include <iostream>

using namespace std;

#define INTERFACE 1 // 1 = PC  || 2 = ATLYS

#include "MaquinaRefri.cpp"

#if INTERFACE == 1 // Using PC (diretivas de compilação para processdor)
#include <pthread.h>
#else // Using Atlys
//
#endif

int main()
{

	MaquinaRefri objMaquina;
	objMaquina.inicia();

	
	return 0;
}