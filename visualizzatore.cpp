#include "visualizzatore.h"

using namespace std;

namespace phviewer{
	
	visualizzatore::visualizzatore(){
		sz=0;
		testa=0;
	}

	
	bool visualizzatore::push(const T & e){
		if(full())return false;
		Nodo* node = new Nodo;
		node->elem=e;
		node->next=testa;
		testa = node;
		sz++;
		return true;
	}	
	
	
	bool visualizzatore::pop(T & e){
		if(empty()) return false;
		e=testa->elem;
		delete [] testa;
		testa=testa->next;
		sz--;
		return true;
	}
	
	bool visualizzatore::top(T & e)const {
		if(empty()) return false;
		e=testa->elem;
		return true;
	}
	
	
	void visualizzatore::save_bin(const char* nomefile)const {
		Nodo* t = testa;
		while(t!=0){
			t->elem.save_bin(nomefile);
			t=t->next;
		}
	}
	
	
	void visualizzatore::print(ostream & of)const{
		Nodo* t = testa;
		while(t!=0){
			of << t->elem;
			t=t->next;
		}
	}
	
	
	ostream & operator<<(ostream & of, const visualizzatore & v){
		v.print(of);
		return of;
	}
	
	
	
	
	
	
	
	
}
