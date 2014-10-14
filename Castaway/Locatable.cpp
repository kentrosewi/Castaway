#include "Locatable.h"

/**
	Default constructor for Locatable.
	Calls Entity's default constructor
	and sets its own variables to NULL.
**/
Locatable::Locatable() : Entity(), xPosition(NULL), yPosition(NULL) { }

/**
	Constructor for Locatable that takes a name, 
	as well as an x and y position.
	@param locatableName the name
	@param locatableXPosition the x position
	@param locatableYPosition the y position
**/
Locatable::Locatable(string locatableName, string locatableDescription, int locatableXPosition, int locatableYPosition) : Entity(locatableName, locatableDescription), 
	xPosition(locatableXPosition), yPosition(locatableYPosition) { }

/**
	Returns the Locatable's x position.
	@return xPosition
**/
int Locatable::getXPosition() const { return xPosition; }

/**
	Returns the Locatable's y position.
	@return yPosition
**/
int Locatable::getYPosition() const { return yPosition; }

/**
	Updates the Locatable's x and y position.
	@param xMove the direction of movement on x 
	@param yMove the direction of movement on y
**/
void Locatable::updatePosition(int xMove, int yMove)
{
	xPosition += xMove;
	yPosition += yMove;
}

/*
	Sets the x and y position of locatable.
	@param x the new x position for locatable
	@param y the new y position for locatabe
*/
void Locatable::setPosition(int x, int y)
{
	xPosition = x;
	yPosition = y;
}