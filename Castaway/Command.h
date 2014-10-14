// command parser interface.  When a Command object is instantiated,
// the passed string is parsed into <verb, noun> format, which is defined
// as: first word is a verb or a direction, and all remaining words comprise
// the noun.  

#ifndef COMMAND_H
#define COMMAND_H

#include <string>
using namespace std;

// enumerated data types - used to indicate the supported directions and verbs
// for the program.  Supported nouns (other than directions) are obtained from
// the item data file.  The 'Unknown' values are used when there's no match.
enum direction { North, South, East, West, UnknownDirection };
enum verb { Move, Look, Quit, Take, Drop, Inventory, Help, Use, Say, Give, Talk, Open, Push, Sleep, UnknownVerb };

class Command {
	public:
		Command( string input );
		verb getVerb();
		string getNoun();
		string getNoun2();
		string getDialog();
		string getDialog2();
		direction getDirection();
	private:
		verb commandVerb;			// store for the selected action
		string commandNoun;			// store for the noun
		string commandNoun2;		// store for the second noun
		string dialog;
		string dialog2;
		direction commandDirection;	// store for the direction of travel (as appropriate)
};


// auxiliary functions
verb parseVerb( string verbString );
direction parseDirection( string directionString );

#endif