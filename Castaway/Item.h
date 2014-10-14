#ifndef ITEM_H
#define ITEM_H

#include "Entity.h"

class Item : public Entity
{
public:
	Item();
	Item(string, string, bool);
	virtual ~Item() = 0;
	bool isMoveable() const;

	void setMoveable(bool);
private:
	bool moveable;
	string description;

};
#endif
