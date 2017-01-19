#include "visualizzatorernd.h"

using namespace std;

namespace phviewer{
	
	
	bool visualizzatorernd::set_mode(const int m){
		if(m!=0 || m!=1){
			cout << "Errore! Inserisci i valori corretti!!" << endl;
			return false;
		}
		mode=m;
		return true;
	}
	
	
	bool visualizzatorernd::pop(T & e){
		if(empty()) return false;
		if(mode==0){
			visualizzatore::pop(e);
		}
		
		srand(time(NULL));
            int id = rand() % (get_sz())+1;
            cout << "ID" << id << endl;
            if(id==1) visualizzatore::pop(e);
            else {
              Nodo * temp=get_testa();
              Nodo * prec;
              for(int i=1; i<id; i++){
                 prec=temp;
                 temp=temp->next;
              }
              e=temp->elem;
              prec->next=prec->next->next;
              delete temp;
	}
	}
	
	
	
	
	
}
