// command parser for adventure game - resolves input into
// <verb, noun> format.  Reasonable first attempt at a parser,
// but essentially assumes correctly formatted input

//#include "stdafx.h"
#include "command.h"
#include "stringapps.h"
#include <string>
#include <iostream> // for testing


// Command: constructor takes input string and parses it into <verb, noun>
// format.  Will also look for "action nouns" (i.e. one-word movements
// commands) and convert into <Move, direction>.  If verb is Move, then
// noun is processed for direction and stored as an enumerated direction type.
Command::Command( string input ) {
	// check for no input
	if ( input.empty() ) {
		commandVerb = UnknownVerb;
		commandNoun = "";
		commandDirection = UnknownDirection;
		return;
	}

	// purge leading and trailing whitespace
	input = trim( input );

	// find seperators
	int firstWhitespace = input.find_first_of( " \t" );
	int secondWhitespace = input.find_first_of(" \t", firstWhitespace + 1);
	int thirdWhitespace = input.find_first_of(" \t", secondWhitespace + 1);
	int fourthWhitespace = input.find_first_of(" \t", thirdWhitespace + 1);
	int lastWhitespace = input.find_last_of(" \t");

	// check for one-word command
	if (firstWhitespace < 0) {
		commandNoun = "";

		// see if it is an "action noun" (i.e. movement shorthand)
		direction dir = parseDirection(input);
		if (dir != UnknownDirection) {
			commandVerb = Move;
			commandDirection = dir;
		}
		else
		{
			commandVerb = parseVerb(input);
		}

		return;
	}

	string rest;

	if (firstWhitespace == -1)
	{
		commandVerb = parseVerb(input);
		rest = "";
	}
	else
	{
		commandVerb = parseVerb(input.substr(0, firstWhitespace));
		rest = input.substr(firstWhitespace + 1);
	}

	int restFirstWhitespace = rest.find_first_of(" \t");
	int restSecondWhitespace = rest.find_first_of(" \t", firstWhitespace + 1);
	int restThirdWhitespace = rest.find_first_of(" \t", secondWhitespace + 1);
	int restFourthWhitespace = rest.find_first_of(" \t", thirdWhitespace + 1);
	int restLastWhitespace = rest.find_last_of(" \t");

	if (commandVerb == Move)
	{
		commandDirection = parseDirection(input.substr(firstWhitespace + 1));
	}
	else if (commandVerb == Look)
	{
		
		if (firstWhitespace == -1)
		{
			commandNoun = "";
			return;
		}
		
		// look
		if (rest == "")
		{
			commandNoun = rest;
			return;
		}

		string at = "at ";
		int atLength = at.length();
		int atIndex = rest.find(at);
		
		// look something
		if (atIndex == -1)
		{
			commandNoun = rest;
			return;
		}
		
		// look at something
		if (atIndex != -1)
		{
			commandNoun = rest.substr(atIndex + atLength);
			return;
		}
	}
	else if (commandVerb == Quit)
	{
		cout << "In else if(commandVerb == Quit)" << endl;
		return;
	}
	else if (commandVerb == Take)
	{
		string from = "from ";
		int fromLength = from.length();
		int fromIndex = rest.find(from);

		// take something
		if (fromIndex == -1)
		{
			commandNoun = rest;
			return;
		}
		// take something from someone
		else if (fromIndex != -1)
		{
			commandNoun = rest.substr(0, fromIndex - 1);

			if (fromIndex + fromLength <= rest.length())
				commandNoun2 = trim( rest.substr(fromIndex + fromLength) );

			return;
		}
	}
	else if (commandVerb == Give)
	{
		string to = "to ";
		int toLength = to.length();
		int toIndex = rest.find(to);

		// give something to someone
		if (toIndex != -1)
		{
			commandNoun = rest.substr(0, toIndex - 1);

			if (toIndex + toLength <= rest.length())
				commandNoun2 = rest.substr(toIndex + toLength);

			return;
		}
		// give someone something
		else
		{
			commandNoun = rest.substr(0, restLastWhitespace);
			/*
			commandNoun2 = rest.substr(0, restLastWhitespace);
			commandNoun = rest.substr(restLastWhitespace + 1);
			cout << commandNoun << "," << commandNoun2 << endl;
			*/
			return;
		}

	
	}
	else if (commandVerb == Drop)
	{
		commandNoun = rest;
		return;
	}
	else if (commandVerb == Inventory)
	{
		return;
	}
	else if (commandVerb == Help)
	{
		return;
	}
	else if (commandVerb == Use)
	{

		string on = "on ";
		int onLength = on.length();
		int onIndex = rest.find(on);
		
		// use something
		if (onIndex == -1)
		{
			commandNoun = rest;
			return;
		}
		// use something on something
		else if (onIndex != -1)
		{
			commandNoun = rest.substr(0, onIndex - 1);
	
			if (onIndex + onLength <= rest.length())
				commandNoun2 = rest.substr(onIndex + onLength);

			return;
		}
		
	}
	else if (commandVerb == Say)
	{
		string to = "to ";
		int toLength = to.length();
		int toIndex = rest.find(to);

		// say something
		if (toIndex == -1)
		{
			dialog = rest;
			dialog2 = rest;
			return;
		}
		// say something to someone
		else if (toIndex != -1)
		{
			dialog = rest.substr(0, toIndex - 1);
			dialog2 = dialog;

			if (toIndex + toLength <= rest.length())
				commandNoun = rest.substr(toIndex + toLength);

			return;
		}
	}
	else if (commandVerb == Talk)
	{
		string to = "to ";
		int toLength = to.length();
		int toIndex = rest.find(to);

		// talk to someone
		if (toIndex != -1)
		{
			if (toIndex + toLength <= rest.length())
				commandNoun = rest.substr(toIndex + toLength);

			return;
		}
	}
	else if (commandVerb == Open)
	{
		commandNoun = rest;
		return;
	}
	else if (commandVerb == Push)
	{
		string in = "in ";
		int inLength = in.length();
		int inIndex = rest.find(in);
		bool inBeforeItem;

		// push in item or push item in?
		if (inIndex == 0)
			inBeforeItem = true;
		else
			inBeforeItem = false;

		// push something
		if (inIndex == -1)
		{
			commandNoun = rest;
			return;
		}
		// push in something
		else if (inIndex != -1 && inBeforeItem)
		{
			if (inIndex + inLength <= rest.length())
				commandNoun = rest.substr(inIndex + inLength);
			return;
		}
		// push something in
		else if (inIndex != -1 && !inBeforeItem)
		{
			commandNoun = rest.substr(0, inIndex - 1);
			return;
		}
	}
	else if (commandVerb == Sleep)
	{
		return;
	}
	/*
	if ((commandVerb = parseVerb(input.substr(0, firstWhitespace))) == Sleep)
	{
		commandNoun = input.substr(firstWhitespace + 1);
		return;
	}
	
	// check for one-word command
	if ( firstWhitespace < 0 ) {
		commandNoun = "";

		// see if it is an "action noun" (i.e. movement shorthand)
		direction dir = parseDirection( input );
		if ( dir != UnknownDirection ) {
			commandVerb = Move;
			commandDirection = dir;
		}
		else
			commandVerb = parseVerb( input );

		return;
	}

	if((commandVerb = parseVerb( input.substr(0, firstWhitespace))) == Say)
	{
		commandNoun = input.substr(lastWhitespace + 1);

		dialog = input.substr(firstWhitespace + 1);
		dialog2 = input.substr(firstWhitespace + 1, secondWhitespace - firstWhitespace - 1);

		return;
	}

	if ((commandVerb = parseVerb(input.substr(0, firstWhitespace))) == Push)
	{

		int indexOfHyperDrive = input.find("hyper drive");
		int lengthOfHyperDriveString = 11;

		int commandLength = 4;
		if (indexOfHyperDrive != -1)
		{
			string thisNoun = input.substr(indexOfHyperDrive, lengthOfHyperDriveString);
			commandNoun = thisNoun;
			return;
		}
	}

	if ((commandVerb = parseVerb(input.substr(0, firstWhitespace))) == Open)
	{
		commandNoun = trim(input.substr(firstWhitespace + 1));
		return;
	}

	// otherwise we have a two-word command
	if(secondWhitespace == -1)
	{
		string thisVerb = input.substr( 0, firstWhitespace );
		commandVerb = parseVerb( thisVerb );
		string thisNoun = trim( input.substr( firstWhitespace, input.length() - firstWhitespace ) );
		commandDirection = parseDirection( thisNoun );
		commandNoun = thisNoun;
		return;
	}

	

	// we have a three-word command (ex. look at tree)
	if(thirdWhitespace == -1)
	{
		string thisVerb = input.substr(0, firstWhitespace );
		commandVerb = parseVerb( thisVerb );

		if (commandVerb == Take || commandVerb == Drop)
		{
			string thisNoun;
			string thisNoun2 = trim(input.substr(lastWhitespace + 1));
			//cout << thisNoun << endl;
			//cout << 
			int indexOfFrom = input.find("from");
			if (indexOfFrom != -1)
			{
				thisNoun = trim(input.substr(firstWhitespace + 1, secondWhitespace - firstWhitespace));
			}
			else
			{
				thisNoun = trim(input.substr(firstWhitespace));
			}
			commandNoun = thisNoun;
			commandNoun2 = thisNoun2;
			return;
		}

		string thisNoun = trim( input.substr( secondWhitespace, input.length() - secondWhitespace ) );
		commandDirection = parseDirection ( thisNoun );
		commandNoun = thisNoun;
		return;
	}

	// four or more word command
	if(thirdWhitespace != -1)
	{
		string thisVerb = input.substr(0, firstWhitespace );
		commandVerb = parseVerb( thisVerb );

		if(commandVerb == Look)
		{
			string thisNoun = trim( input.substr(secondWhitespace));
			commandNoun = thisNoun;
			return;
		}

		if(input.find("from") == -1 && commandVerb == Take)
		{
			string thisNoun = trim ( input.substr(firstWhitespace + 1));
			commandNoun = thisNoun;
			return;
		}


		if(commandVerb == Give)
		{
			string thisNoun = trim(input.substr( firstWhitespace + 1, lastWhitespace - 3 - firstWhitespace));
			string thisNoun2 = input.substr(lastWhitespace + 1);
			commandNoun = thisNoun;
			commandNoun2 = thisNoun2;
			return;
		}

		string thisNoun = trim( input.substr( firstWhitespace, secondWhitespace - firstWhitespace ) );
		commandNoun = thisNoun;
		string thisNoun2 = trim( input.substr( thirdWhitespace ) );
		commandNoun2 = thisNoun2;
		return;
	}
	*/
}



// getVerb: returns the appropriate value from the enumerated verb type
verb Command::getVerb() {
	return commandVerb;
}



// getNoun: return the trimmed string containing the noun.  Note that nothing else is
// done to the noun other than trim (i.e. no change in case, whitespace compression, etc.)
string Command::getNoun() {
	return toLowercase(commandNoun);
}

/*
	Returns a lower-version of commandNoun2;
	@return commandNoun2 the noun to return
*/
string Command::getNoun2() {
	return toLowercase(commandNoun2);
	//return commandNoun2;
}

/*
	Returns dialog.
	@return dialog the dialog string to return
*/
string Command::getDialog() {
	return dialog;
}

/*
	Returns dialog 2.
	@return dialog2 the dialog string to return
*/
string Command::getDialog2() {
	return dialog2;
}

// getDirection: returns the appropriate value from the enumerated direction type
direction Command::getDirection() {
	return commandDirection;
}

	

// parseVerb: processes string and looks for matching verb
verb parseVerb( string verbString ) {
	string s = toLowercase( verbString );

	if ( s == "go" || s == "move" )
		return Move;
	if ( s == "look" || s == "l")
		return Look;
	if ( s == "quit" || s == "q")
		return Quit;
	if ( s == "take" || s == "get" )
		return Take;
	if ( s == "drop" )
		return Drop;
	if ( s == "i" || s == "inven" || s == "inventory" || s == "inv")
		return Inventory;
	if ( s == "h" || s == "help" || s == "?" )
		return Help;
	if ( s == "use" )
		return Use;
	if ( s == "say" )
		return Say;
	if( s == "give" )
		return Give;
	if( s == "talk" )
		return Talk;
	if (s == "open")
		return Open;
	if (s == "push")
		return Push;
	if (s == "z" || s == "sleep")
		return Sleep;

	return UnknownVerb;
}

// parseDirection: processes string and looks for matching direction
direction parseDirection( string directionString ) {
	string dirString = toLowercase( directionString );

	if ( dirString == "north" || dirString == "n" )
		return North;
	if ( dirString == "south" || dirString == "s")
		return South;
	if ( dirString == "east" || dirString == "e")
		return East;
	if ( dirString == "west" || dirString == "w")
		return West;

	return UnknownDirection;
}