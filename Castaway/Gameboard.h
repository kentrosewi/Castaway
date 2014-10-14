#ifndef GAMEBOARD_H
#define GAMEBOARD_H

#include "NonPlayableCharacter.h"
#include "Shopkeeper.h"
#include "Match.h"
#include "Torch.h"
#include "Container.h"
#include "HyperDrive.h"
#include "Room.h"
#include "Tree.h"
#include "Hatchet.h"
#include "MoneyPouch.h"
#include "Rope.h"
#include "Paper.h"
#include <cassert>
#include "chest.h"

class Gameboard
{
public:
	Gameboard();
	~Gameboard();
	Room* getRoom(int, int) const;
	int getRows() const;
	int getColumns() const;

private:
	static const int COLUMNS = 11;
	static const int ROWS = 10;
	Room* array[COLUMNS][ROWS];
};
#endif