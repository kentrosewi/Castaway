#ifndef LOCATABLE_H
#define LOCATABLE_H

#include "Entity.h"

class Locatable : public Entity
{
public:
	Locatable();
	Locatable(string, string, int, int);
	int getXPosition() const;
	int getYPosition() const;
	void updatePosition(int, int);
	void setPosition(int, int);

private:
	int xPosition;
	int yPosition;

};
#endif