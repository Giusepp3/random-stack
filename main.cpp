//Giuseppe Ferrara

#include "foto.h"
#include "visualizzatore.h"
#include <iostream>
#include <cstring>
#include <fstream>

using namespace std;

using namespace phviewer;

int main() {
/*	
//	foto f; //costruttore di default
	foto f1("una giornata al mare", "bel paesaggio con uno sfondo pieno di barche"); //costruttore con argomenti
//	foto f2(foto("sciata insieme", "io ed i miei amici sugli sci con molta neve")); //costruttore di copia
//	f=f2; //operatore di assegnazione
//	foto f4;
//	cin >> f4;
//	cout << f <<endl << f1 <<endl << f2 <<endl << f4; //test degli operatori di shift
	
	f1.save_bin("filedati.bin");
	
	foto f2("test titolo", "test descrizione");
	
	cout << "foto f2 prima di leggere file: " << f2;
	
	f2.read_bin("filedati.bin");
	
	cout << endl << "foto f2 dopo la lettura da file : " << f2;
	
	*/
	
	foto f("tit f1","desc f1" );
	foto f2("tit f2", "desc f2");
	
	visualizzatore v;
	
	v.push(f);
	v.push(f2);
	
	cout << v;
	

	return 0;
	
	
} //i distruttori intervegono qui
