#ifndef CREEP_H
#define CREEP_H

#include "Agent.h"

class Creep: public Agent{
 
	public:
		Creep (float x, float y, float width, float height, float speed);
		//Creep (const Creep& c1); //copy constructor
		~Creep();
		Creep(const Creep &source); // 2 : copy constructor
 		Creep &operator=(const Creep &source); // 3 : copy assignment operator
    	Creep(Creep &&source); // 4 : move constructor
    	Creep &operator=(Creep &&source); // 5 : move assignment operator

		int test2{1};
		void determineCentre();
		//void behaviour(int mapX, int mapY) override;
	protected:

		void initShape();
		void updateShape();

		void recurseShape(int x, int y, float prob);

};

#endif