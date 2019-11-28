#ifndef MAQUINAREFRI
#define MAQUINAREFRI

//#include "EscalonadorEstruct.h"
class MaquinaRefri
{
	int estAtual;
	int passwordOperator;
	int passwordInserido;
	int option;
	pthread_t threadExemploThread;	
public:
	MaquinaRefri();
	void inicia();
	void mensagem();
	void entradaDado();
	void emergencia();
	static void* exemploThread(void *);
	//static void* thread_fun( void* args ) ;
#if INTERFACE == 1 || INTERFACE == 3			// Using PC (diretivas de compilação para processdor)
	time_t timer, timerFim; // contabiliza segundos no PC
#else						// Using Atlys
	clock_t inicio, fim; // contabiliza segundo no LEON3
#endif
};

#endif // MAQUINAREFRI