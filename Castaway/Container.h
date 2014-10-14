#ifndef CONTAINER_H
#define CONTAINER_H

#include "usable.h"
#include "HyperDrive.h"
#include "Room.h"

class Container :
	public Usable
{
public:
	Container(string, string, bool);
	virtual void use(Player&, int, Room&, int);
	void fillUp();
	void emptyOut();
	bool isFull() const;

private:
	bool full;
};
#endif
