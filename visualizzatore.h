#ifndef VIEWR_H
#define VIEWR_H
#include <iostream>
#include <cstring>
#include <fstream>
#include "foto.h"

namespace phviewer{
	

	typedef foto T;
	
	struct Nodo;
	
	struct Nodo{
		T elem;
		Nodo* next;
	};
	
	
	class visualizzatore{
		private:
			Nodo* testa;
			int sz;
		protected:
			Nodo* get_testa()const{return testa;}
			void print(ostream & of)const;
			int get_sz()const{return sz;}
		public:
			visualizzatore(); //costruttore
		//	visualizzatore(const visualizzatore &) = delete; //elimino il costruttore di copia
			bool push(const T &);
			virtual bool pop(T &);
			bool top(T &)const;
			bool empty()const{return sz==0;}
			bool full()const{return false;} //la pila è allocata dinamicamente
			void save_bin(const char* nomefile)const;
			friend ostream & operator<<(ostream & of, const visualizzatore & v);
			
	};
	




}


#endif //VIEWR_H
