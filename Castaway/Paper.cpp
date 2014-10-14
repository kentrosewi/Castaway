#include "Paper.h"

/*
	Constructor for Paper.
	@param name the name of the paper
	@param description the description of the paper
	@param moveable if the paper is moveable
*/
Paper::Paper(string name, string description, bool moveable) : Item(name, description, moveable)
{
}
