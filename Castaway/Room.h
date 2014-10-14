#ifndef ROOM_H
#define ROOM_H

#include "Locatable.h"
#include "Item.h"
#include "Command.h"
#include "NonPlayableCharacter.h"
#include "MoneyPouch.h"
#include "stringapps.h"
#include <vector>
#include <string>

class Room : public Locatable
{
public:
	Room();
	Room(string, string, string, bool, bool, bool, bool, int, int, bool);
	~Room();
	string getLongDescription() const;
	bool isValidExit(direction) const;
	bool isWater() const;
	bool getLighting() const;
	void addItem(Item*);
	void addNonPlayableCharacter(NonPlayableCharacter*);
	void removeNonPlayableCharacter(NonPlayableCharacter*);
	void deleteItem(Item*);
	void setLighting(bool);
	void setExitToTrue(direction);
	vector<Item*>* getContents();
	const vector<NonPlayableCharacter*>* getNonPlayableCharacters() const;
	int indexOfItem(string);
	int indexOfNonPlayableCharacter(string);

private:
	string longDescription;
	vector<Item*> contents;
	vector<NonPlayableCharacter*> nonPlayableCharacters;
	bool northExit;
	bool eastExit;
	bool southExit;
	bool westExit;
	bool lighting;
	bool water;
};

ostream& operator<<(ostream&, const vector<Item*>*);
ostream& operator<<(ostream&, const vector<NonPlayableCharacter*>*);

#endif
