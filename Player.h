#ifndef PLAYER_H
#define PLAYER_H
#include <string>
#include <iostream>

using namespace std;

class player
{
private:
	string name;
	int score;
	int health;
	int keyNumber;
	int healthItemsHeld;

public:
	player();
	void changeScore(int x);
	int getScore();
	void assignName(string a);
	string getName();
	int getHealth();
	void addHealth();
	void takeHealth();
	void openMenu();
	void addKey();
	void takeKey();
	void addHealthItem();
	void useHealthItem();

};
#endif
