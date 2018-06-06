/*
* 	Authors:	Davide Balestra
*			Andrea D'Arpa
*
*	Description:	Header file of class Map
*/

#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<ctime>
#include "player.h"

using namespace std;
class Map{
private:
	int length;
	int avg;
	int nEmpty;
public:
	Start *init;		//Start Box (first of the map)
	Map(bool mode);		//Create the map (Hard/Easy MODE)
	
	int testRand();
	//setter and getter
	void setLength(int l);
	int getLength();
	void setAvg(int a);
	int getAvg();
	void setNEmpty(int n);
	int getNEmpty();	

	//methods for generation of map
	void generateMap(bool mode);	//generate the map depemding by its difficulty parameter
	int calcNBox(bool mode);	//calculate the number of boxes inside the map (easy 40<=n<=63  --- hard 64<=n<=90)
	int HowEmpty(bool mode);	//decide the percentuage of empty boxes in the map (easy 36<=n<=50 --- hard 20<=n<=35)
					
	/*function returns a box pointer that will be generated this way:
	*	-  generate a number in a interval between 2 and 8 (every number is a corrispoundent Box's id 
	*	-  do, the box relative to his id will be generated and returned
	*	-  the number generation will depend on Empty Boxes perc: 
	* 	   a number from 1 to 100 will be generated. if the value it's <= to Empty Box perc -> insert an empty box
	*	   else insert a casual box (Empty not included)
	*		this will provide a simulation of a real estraction with probability perc
	*/
	Box *genBox();
};
