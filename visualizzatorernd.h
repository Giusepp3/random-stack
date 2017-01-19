#ifndef RNDVIWR_H
#define RNDVIWR_H
#include "foto.h"
#include "visualizzatore.h"
#include <iostream>
#include <fstream>
#include <cstring>
#include <ctime>
#include <cstdlib>

using namespace std;

namespace phviewer{
	
	class visualizzatorernd : public visualizzatore{
		private:
			int mode;
		public:
			virtual bool pop(T &);
			int get_sz()const{return visualizzatore::get_sz();}
			bool set_mode(const int);
			
			
		
	};
	
	
	
	
	
	
}

#endif //RNDVIWR_H
