#include "Item.h"

/**
	Default constructor for Item.
	Calls Entity's default constructor
	and sets moveable to NULL.
**/
Item::Item() : Entity(), moveable(NULL) { }

/**
	Constructor for Item that takes a name 
	and a boolean value.
	@param itemName the name for the Item
	@param itemMoveable true if Item is moveable
**/
Item::Item(string itemName, string itemDescription, bool itemMoveable) : Entity(itemName, itemDescription), moveable(itemMoveable) { }

/*
	Destructor for Item.
	Is pure virtual to allow Item to be abstract.
*/
Item::~Item() {}

/**
	Tells if Item is moveable.
	@return moveable
**/
bool Item::isMoveable() const { return moveable; }

/**
	Sets the moveable boolean of Item.
	@param itemMoveable true if item should be able to be moved
**/
void Item::setMoveable(bool itemMoveable) { moveable = itemMoveable; }

