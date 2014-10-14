// helpful routines that the string class unfortunately doesn't have...
//#include "stdafx.h"
#include "stringapps.h"
#include <ctype.h>



// trim: eliminates leading and trailing whitespace
string trim( const string thisString ) {
	string s = thisString;
	int firstChar = s.find_first_not_of( " \t\n" );
	if ( firstChar > 0 ) 
		s.erase( 0, firstChar );

	int lastChar = s.find_last_not_of( " \t\n" );
	if ( lastChar < s.length() - 1 )
		s.erase( lastChar + 1, s.length() - (lastChar + 1 ) );
	
	return s;
}



// toLowercase: returns a string where all letters are lowercase
// Useful for when case insensitive matches are needed
string toLowercase( const string thisString ) {
	string s = thisString;
	for ( int i = 0; i < s.length(); i++ )
		s[i] = tolower( s[i] );
	return s;
}