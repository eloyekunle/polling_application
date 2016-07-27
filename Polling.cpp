/*
 * Polling.cpp
 * Member-function definitions for class Polling that uses a two-dimensional array to store ratings.
 * author: Oyekunle Elijah PlayMice <elijah@playmiceweb.com>
 * 27/07/16
 */

#include <iostream>
#include <iomanip>
#include "Polling.h"

using namespace std;


//constructor initializes array of topics and ratings
Polling::Polling( const array< string, issues > &issuesArray, array< array< int, ratings >, issues > &ratingsArray )
		: topics( issuesArray ), responses( ratingsArray ) {
}


//function to get averate rating for each topic
double Polling::getAverage( const array< int, ratings > &setOfRatings ) const {
	int total = 0;

	for ( int rating : setOfRatings )
		total += rating;

	return static_cast<double>(getTotalPoints( setOfRatings )) / total;
}


//function to get the ratings, individually
void Polling::enterRating() {
	cout << "Enter a rating (1 -" << Polling::ratings << ") for the following topics: " << endl;

	for ( int issue = 0; issue < topics.size(); ++issue ) {
		int rating;
		cout << topics[ issue ] << ": ";
		cin >> rating;
		if ( rating >= 1 and rating <= 10 )		//error checking
			++responses[ issue ][ rating - 1 ];
		else {
			cout << "Invalid input. Enter values between 1 and " << Polling::ratings << " " << endl;
			enterRating();
		}
	}
}


//function to rate different topics
void Polling::setRatings() {
	string sentinel = "y";

	while ( sentinel == "y" ) {
		enterRating();
		cout << "Create another entry? (y/n) ";
		cin >> sentinel;
	}
}


//function to set the topics
void Polling::setTopics() {
	int reply;
	array< string, Polling::issues > defaultTopics = {"Politics", "Hunger", "Security", "Crime", "Philantropy"};
	cout << "Enter 1 or 2\n1] Use Default Topics (";

	for ( string topic : defaultTopics )
		cout << " " << topic << " ";

	cout << ")\n2] Create your own Topics\n>> ";
	cin >> reply;

	if ( reply == 1 )
		topics = defaultTopics;
	else if ( reply == 2 ) {
		cout << "Enter your topics: " << endl;
		for ( int topic = 0; topic < Polling::issues; ++topic ) {
			cout << ">> ";
			cin >> topics[ topic ];
		}
	} else {
		cout << "Invalid Input. Enter 1 or 2." << endl;
		setTopics();
	}
}


//perform various operations on ratings data
void Polling::processRatings() {
	int highestTotal = getHighestPoint();
	int lowestTotal = getLowestPoint();
	cout << "\nTopic with Higest Total Ratings: " << topics[ highestTotal ] << " (" <<
	getTotalPoints( responses[ highestTotal ] ) << ")" << endl;
	cout << "Topic with Lowest Total Ratings: " << topics[ lowestTotal ] << " (" <<
	getTotalPoints( responses[ lowestTotal ] ) << ")" << endl;
}


//display the contents of the responses array
void Polling::displayRatings() const {
	cout << "\nThe ratings are: " << endl;
	cout << setw( 14 );

	for ( size_t i = 1; i <= ratings; ++i )
		cout << i << " ";
	cout << "Average" << " Total" << endl;

	for ( size_t issue = 0; issue < responses.size(); ++issue ) {
		cout << setw( 12 ) << topics[ issue ] << " ";
		for ( size_t rating = 0; rating < responses[ issue ].size(); ++rating )
			cout << responses[ issue ][ rating ] << " ";

		double average = getAverage( responses[ issue ] );
		cout << setw( 8 ) << setprecision( 2 ) << fixed << average;		//display to 2d.p.

		int total = getTotalPoints( responses[ issue ] );
		cout << setw( 6 ) << total << endl;
	}
}


//function to get the total rating points of an array
int Polling::getTotalPoints( const array< int, ratings > &setOfRatings ) const {
	int total = 0;

	for ( int rating = 1; rating <= setOfRatings.size(); ++rating )
		total += rating * setOfRatings[ rating - 1 ];

	return total;
}


//function to get highest rated topic
int Polling::getHighestPoint() {
	int fig = 0;

	for ( int topic = 0; topic < topics.size(); ++topic )
		if ( getTotalPoints( responses[ topic ] ) > getTotalPoints( responses[ fig ] ))
			fig = topic;

	return fig;
}


//function to get lowest rated topic
int Polling::getLowestPoint() {
	int fig = 0;

	for ( int topic = 0; topic < topics.size(); ++topic )
		if ( getTotalPoints( responses[ topic ] ) < getTotalPoints( responses[ fig ] ))
			fig = topic;

	return fig;
}