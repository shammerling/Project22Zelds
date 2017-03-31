#include "player.h"
#include <iostream>
#include <fstream>
#include <string>
#include <math.h>
#include <cstdlib>
using namespace std;

player::player()
{
	name = "";
	health = 10;
}

void player::assignName(string a)
{
	name = a;
}

string player::getName()
{
	return name;
}

void player::changeScore(int x)
{
	score = score + x;
}

int player::getScore()
{
	return score;
}

int player::getHealth()
{
	return health;
}

void player::addHealth()
{
	health = health + 2;
}

void player::takeHealth()
{
	health = health - 2;
}

void player::openMenu()
{
	cout << "" << endl;
}

void player::addKey()
{
	keyNumber = keyNumber + 1;
}

void player::takeKey()
{
	keyNumber = keyNumber - 1;
}

void player::addHealthItem()
{
	healthItemsHeld = healthItemsHeld + 1;
}

void player::useHealthItem()
{
	healthItemsHeld = healthItemsHeld - 1;
	addHealth();
}
