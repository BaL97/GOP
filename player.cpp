/* 	Authors:	 Davide Balestra
			 Andrea D'Arpa
			 Matteo Celani

	Description: Implements the player class
*/

#include "player.h"


//Default constructor-> only for sentinel element 
Player::Player(){	
	this->next=NULL;
	this->setName("");
	this->setAge(0);
	this->setTurn(-1);
	this->pNext=NULL;
	this->position=NULL;
}

//Constructor with parameters
Player::Player(string n, int a, Box *p){
	this->next=NULL;
	this->setName(n);
	this->setAge(a);
	this->setTurn(0);
	this->pNext=NULL;
	this->position=p;	//set her the start cell
}

//Setters
void Player::setName(string n){
	this->name=n;
}

void Player::setAge(int a){
	this->age=a;
}

void Player::setTurn(int t){
	this->turn=t;
}

//implents here the set cell method

//Getters
string Player::getName(){
	return this->name;
}

int Player::getAge(){
	return this->age;
}

int Player::getTurn(){
	return this->turn;
}

//implements here the get cell method
