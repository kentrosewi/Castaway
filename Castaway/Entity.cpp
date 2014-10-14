#include "Entity.h"


/**
	Default constructor for Entity. 
	Sets name to NULL.
**/
Entity::Entity() : name(NULL), description(NULL) 
{ 
}

/**
	Constructor for Entity that takes a string.
	@param entityName the value to assign to name
**/
Entity::Entity(string entityName, string entityDescription) : name(entityName), description(entityDescription) 
{ 
}

/**
	Returns Entity's name.
	@return name
**/
string Entity::getName() const 
{ 
	return name; 
}

/**
	Sets the name of Entity.
	@param entityName
**/
void Entity::setName(string entityName) 
{ 
	name = entityName; 
}

void Entity::setDescription(string entityDescription)
{
	description = entityDescription;
}

/**
	Returns the Entity's description.
	@return description
**/
string Entity::getDescription() const 
{ 
	return description; 
}
