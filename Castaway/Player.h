#ifndef PLAYER_H
#define PLAYER_H

#include "Character.h"
#include "MoneyPouch.h"

class Player :
	public Character
{
public:
	Player(string, string, int, int);
	bool isConfused() const;
	void setConfused(bool);
	void incrementCommandsIssued();
	int getConfusedTurnsLeft() const;
	void decrementConfusedTurns();
	int getNumberOfCommandsIssued() const;
	bool hasLeftMainIsland() const;
	int getPeopleMadeHappy() const;
	void incrementPeopleMadeHappy();
	void addToPoints(int);
	int getPoints() const;
	void setFixedHyperDrive();
	void setHasBoughtSomething();
	bool foundSecretIsland() const;
	bool fixedHyperDrive() const;
	bool hasBoughtSomething() const;

private:
	int confusedTurns;
	bool confused;
	bool hyperDriveFixed;
	bool boughtSomething;
	int commandsIssued;
	int peopleMadeHappy;
	int points;

};
#endif
