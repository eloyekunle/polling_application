/*
 * main.cpp
 * Creates Polling object using a two-dimensional array of user ratings.
 * author: Oyekunle Elijah PlayMice <elijah@playmiceweb.com>
 * 27/07/16
 */

#include <array>
#include "Polling.h"	//Polling class definition

//function main begins program execution
int main() {
	array< string, Polling::issues > topics = {};
	array< array< int, Polling::ratings >, Polling::issues > responses = {}; //two-dimensional array of ratings
	Polling myPolling( topics, responses );
	myPolling.setTopics();
	myPolling.setRatings();
	myPolling.displayRatings();
	myPolling.processRatings();
} //end main