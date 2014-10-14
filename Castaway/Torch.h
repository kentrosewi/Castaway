#ifndef TORCH_H
#define TORCH_H

#include "item.h"
#include <iostream>

class Torch :
	public Item
{
public:
	Torch(string, string, bool);
	void light();
	void putOut();
	bool isLit() const;
	void decrementTimer();

private:
	bool lit;
	int timer;
	const static int MAX_TIME = 10;

};
#endif TORCH_H
