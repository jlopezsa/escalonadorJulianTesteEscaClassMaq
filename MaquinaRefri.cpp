#include <iostream>
#include <stdio.h>
#include <time.h>
#include <typeinfo>
using namespace std;

#include "MaquinaRefri.h"
#include "EscalonadorEstruct.cpp"

MaquinaRefri::MaquinaRefri()
{
	passwordOperator = 33;
	pthread_create(&threadExemploThread, NULL, &MaquinaRefri::exemploThread, NULL);
#if INTERFACE == 1 // Using PC (diretivas de compilação para processdor)
	time(&timer);	
#else // Using Atlys
	inicio = clock();
#endif
};


EscalonadorEstruct projectEscVoid;

void MaquinaRefri::inicia()
{
	MaquinaRefri * ptrMaquina;	
	
	void (MaquinaRefri::*pMensagem)() = &MaquinaRefri::mensagem;	   // Deitel pg 972
	void (MaquinaRefri::*pEmergencia)() = &MaquinaRefri::emergencia;   // Deitel pg 972
	void (MaquinaRefri::*pEntradaDado)() = &MaquinaRefri::entradaDado; // Deitel pg 972

	projectEscVoid.init_Task_TimersStruct();
	projectEscVoid.addTaskReadyEstruct(pMensagem, ptrMaquina, 2, 0);
	projectEscVoid.addTaskReadyEstruct(pEmergencia, ptrMaquina, 5, 1);
	projectEscVoid.addTaskReadyEstruct(pEntradaDado, ptrMaquina, 10, 2);
	while (1)
	{
		projectEscVoid.schedulerStatesLogic();
	}
	cout << "inicia()..." << endl;
}
//
//
//
void MaquinaRefri::mensagem()
{
	cout << "mensagem()..." << endl;	
	MaquinaRefri * ptrMaquina;
	void (MaquinaRefri::*pEmergencia)() = &MaquinaRefri::emergencia;
	projectEscVoid.addTaskReadyEstruct(pEmergencia, ptrMaquina, 2, 3);
}
//
//
//
void MaquinaRefri::entradaDado()
{
	int teste;
	cout << "entradaDado()..." << endl;	
	//pthread_join(threadExemploThread, NULL);
	MaquinaRefri * ptrMaquina;	
	void (MaquinaRefri::*pEmergencia)() = &MaquinaRefri::emergencia;
	projectEscVoid.addTaskReadyEstruct(pEmergencia, ptrMaquina, 5, 3);
	
}
//
//
//
void MaquinaRefri::emergencia()
{
	MaquinaRefri * ptrMaquina;	
	cout << "emergencia()..." << endl;
	void (MaquinaRefri::*pMensagem)() = &MaquinaRefri::mensagem;
	projectEscVoid.addTaskReadyEstruct(pMensagem, ptrMaquina, 2, 4);
}
//
//
//
void *MaquinaRefri::exemploThread(void *)
{
	int testeIn;
	while (1)
	{
		cin >> testeIn;
		if (testeIn == 0)
		{
			cout << "....... THREAD executando: Insere 0................" << endl;
			//break;
		}
		else{
			cout << "....... THREAD executando: Outra coisa ................" << endl;
		}
	}
}