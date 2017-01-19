#include "foto.h"

namespace phviewer{
	
	foto::foto(){
		titolo = new char[1];
		strcpy(titolo,"");
		descrizione = new char[1];
		strcpy(descrizione,"");
	}
	
	foto::~foto(){
		delete [] titolo;
		delete [] descrizione;
	}

	
	foto::foto(const char* t, const char* d){
		titolo = new char[strlen(t)+1];
		strcpy(titolo,t);
		descrizione = new char[strlen(d)+1];
		strcpy(descrizione,d);
	}
	
	foto::foto(const foto & f){
		titolo = new char[strlen(f.titolo)+1];
		strcpy(titolo,f.titolo);
		descrizione = new char [strlen(f.descrizione)+1];
		strcpy(descrizione,f.descrizione);
	}
	
	foto& foto::operator=(const foto & f){
		if(this==&f) return *this; //controllo self assignement
		set_titolo(f.titolo);
		set_descrizione(f.descrizione);
		return *this;
	}
	
	void foto::set_titolo(const char* t){
		if (titolo) delete [] titolo;
		titolo = new char[strlen(t)+1];
		strcpy(titolo,t);
	}
	
	void foto::set_descrizione(const char* d){
		if(descrizione) delete [] descrizione;
		descrizione = new char[strlen(d)+1];
		strcpy(descrizione,d);
	}
	
	void foto::print(ostream & of)const{
		of << titolo << ' ' << descrizione << ' ';

	}
	
	ostream & operator<<(ostream & of, const foto & f){
		f.print(of);
		return of;
	}
	
	void foto::read(istream & in){
		char buffer [600];
		in.getline(buffer,599);
		set_titolo(buffer);
		in.getline(buffer,599);
		set_descrizione(buffer);
	}
	
	istream & operator>>(istream & in, foto & f){
		f.read(in);
		return in;
	}
	
	void foto::printf(ofstream & of)const{
		int len1,len2;
		len1=strlen(titolo)+1;
		len2=strlen(descrizione)+1;
		of.write((char*)&len1,sizeof(len1));
		of.write(titolo,len1);
		of.write((char*)&len2,sizeof(len2));
		of.write(descrizione,len2);
		
	}
	
	void foto::save_bin(const char* nomefile)const {
		ofstream of;
		of.open(nomefile, ios::out | ios::binary);
		if(of.fail()){
			cout << "Errore File!";
			of.close();
		}
		this->printf(of);
		of.close();
	}
		
	
	void foto::readf(ifstream & in){
		int len1, len2;
		in.read((char*)&len1,sizeof(len1));
		if(titolo) delete [] titolo;
		titolo = new char[len1];
		in.read(titolo,len1);
		in.read((char*)&len2,sizeof(len2)); 
		if(descrizione) delete [] descrizione;
		descrizione = new char[len2];
		in.read(descrizione,len2);
	}
	
	void foto::read_bin(const char* filename){
		ifstream in;
		in.open(filename, ios::in | ios::binary);
		if(in.fail()){
			cout << "Errore File!";
			in.close();
		}
		
		this->readf(in);
		in.close();
	}
	
	
	
		
		
		
		
		
		
		
		
		
		
		
		
	
	
	
	
}
