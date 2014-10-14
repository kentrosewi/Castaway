#ifndef ENTITY_H
#define ENTITY_H

#include <string>

using namespace std;

class Entity
{
public:
	Entity();
	Entity(string, string);
	string getName() const;
	string getDescription() const;
	void setName(string);
	void setDescription(string);
private:
	string name;
	string description;

};
#endif
