#include "Torch.h"

/*
	Constructor for Torch.
	@param torchName the torch's name
	@param torchDescription the torches description
	@param torchMoveable if the torch is moveable
*/
Torch::Torch(string torchName, string torchDescription, bool torchMoveable) : Item(torchName, torchDescription, torchMoveable), 
	lit(false)
{
	timer = MAX_TIME;
}

/*
	Puts out the torch.
	Sets lit bool value to false.
*/
void Torch::putOut()
{
	lit = false;
	cout << "The torch went out. I hope there is another match somewhere.\n";
}

/*
	Lights the torch.
	Sets lit bool value to true.
*/
void Torch::light()
{
	lit = true;
}

/*
	Returns if the torch is lit.
	@return lit bool value for if torch is lit
*/
bool Torch::isLit() const
{
	return lit;
}

/*
	Decrements the torch timer by one.
	If timer reaches zero, put out the torch
	and reset the timer for the next time it
	is lit.
*/
void Torch::decrementTimer()
{
	timer--;

	if (timer == 0)
	{
		putOut();
		timer = MAX_TIME;
	}
}