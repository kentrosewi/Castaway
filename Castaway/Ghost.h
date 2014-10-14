#ifndef GHOST_H
#define GHOST_H

#include "NonPlayableCharacter.h"
#include "Player.h"
#include "Gameboard.h"

#include <iostream>

class Ghost :
	public NonPlayableCharacter
{
public:
	Ghost(string, string, int, int, bool);
	virtual void startDialog(Player&);
	bool getStolenValue();
	void moveGhost(direction, Gameboard&);
	void follow(Player&, Gameboard&);

private:
	string helloString;
	string dialogString;
	string dialogCompleteString;
	bool alreadyTalkedTo;
	bool stoleItem;
	bool oldMoveableState;
};
#endif GHOST_H
