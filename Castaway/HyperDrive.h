#ifndef HYPERDRIVE_H
#define HYPERDRIVE_H

#include "Item.h"
#include <iostream>
class HyperDrive :
	public Item
{
public:
	HyperDrive(string, string, bool);
	void pushIn();
	bool isPushedIn() const;
	bool isCool() const;
	void setCool(bool);
	void startPuzzle();
	bool isFixed() const;
	void setFixed(bool);
private:
	bool pushedIn;
	bool cooledOff;
	bool fixed;
};
#endif
