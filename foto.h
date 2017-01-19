#ifndef FOTO_H
#define FOTO_H
#include <iostream>
#include <cstring>
#include <string>
#include <fstream>

using namespace std;

namespace phviewer{
	
	class foto{
		private:
			char* titolo;
			char* descrizione;
			void print(ostream &)const;
			void read(istream &);
			void printf(ofstream &)const;
			void readf(ifstream &);
			
		public:
			foto(); //costruttore di default
			foto(const char* titolo, const char* descrizione); //costruttore con argomenti
			~foto(); //distruttore
			foto(const foto &); //costruttore di copia
			foto& operator=(const foto &); //op. assegnamento
			void set_titolo(const char*);
			void set_descrizione(const char*);
			char* get_titolo()const{return titolo;}
			char* get_descrizione()const{return descrizione;}
			friend ostream &operator<<(ostream & os, const foto &);
			friend istream & operator>>(istream & in, foto &);
			void save_bin(const char*)const;
			void read_bin(const char*);
		
	};
	
	
	
	
	
	
	
	
	
}

#endif //FOTO_H
