#ifndef NONPLAYABLECHARACTER_H
#define NONPLAYABLECHARACTER_H

#include "Player.h"
#include "Character.h"
#include <iostream>

class NonPlayableCharacter : public Character
{
public:
	NonPlayableCharacter();
	NonPlayableCharacter(string, string, int, int, bool);
	virtual void startDialog(Player&) = 0;
	void setHappy(bool);
	bool getHappy() const;

private:
	bool happy;
};
#endif
