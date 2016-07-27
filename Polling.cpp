#include <iostream>
#include <iomanip>
#include "Polling.h"
using namespace std;

//Constructor
Polling::Polling( const array< string, issues > &issuesArray, array< array< int, ratings >, issues > &ratingsArray )
		: topics( issuesArray ), responses( ratingsArray ) {

}

double Polling::getAverage( const array< int, ratings > &setOfRatings ) const {
	int total = 0;
	for ( int rating : setOfRatings )
		total += rating;
	return static_cast<double>(getTotalPoints( setOfRatings )) / total;
}

void Polling::enterRating() {
	cout << "Enter a rating (1 -"<< Polling::ratings << ") for the following issues: " << endl;
	for ( int issue = 0; issue < topics.size(); ++issue ) {
		int rating;
		cout << topics[ issue ] << ": ";
		cin >> rating;
		++responses[ issue ][ rating - 1 ];
	}
}

void Polling::setRatings() {
	string sentinel = "y";
	while ( sentinel == "y" ) {
		enterRating();
		cout << "Create another entry? (y/n) ";
		cin >> sentinel;
	}
}

void Polling::setTopics() {
	int reply;
	array< string, Polling::issues> defaultTopics = {"Politics", "Hunger", "Security", "Crime", "Philantropy"};
	cout << "Enter 1 or 2\n1] Use Default Topics (";
	for( string topic : defaultTopics)
		cout << " " << topic << " ";
	cout << ")\n2] Create your own Topics\n>> ";
	cin >> reply;
	if(reply == 1) {
		topics = defaultTopics;
	} else {
		cout << "Enter your topics: " << endl;
		for ( int topic = 0; topic < Polling::issues; ++topic ) {
			cout << ">> ";
			cin >> topics[ topic ];
		}
	}
}

void Polling::processRatings() {
	int highestTotal = getHigestPoint();
	int lowestTotal = getLowestPoint();
	cout << "\nTopic with Higest Total Ratings: " << topics[ highestTotal ] << " (" <<
	getTotalPoints( responses[ highestTotal ] ) << ")" << endl;
	cout << "Topic with Lowest Total Ratings: " << topics[ lowestTotal ] << " (" <<
	getTotalPoints( responses[ lowestTotal ] ) << ")" << endl;
}

void Polling::displayRatings() const {
	cout << "\nThe ratings are: " << endl;
	cout << setw( 14 );
	for ( size_t i = 1; i <= ratings; ++i )
		cout << i << " ";
	cout << "Average" << " Total" << endl;
	for ( size_t issue = 0; issue < responses.size(); ++issue ) {
		cout << setw( 12 ) << topics[ issue ] << " ";
		for ( size_t rating = 0; rating < responses[ issue ].size(); ++rating ) {
			cout << responses[ issue ][ rating ] << " ";
		}

		double average = getAverage( responses[ issue ] );
		cout << setw( 8 ) << setprecision( 2 ) << fixed << average;

		int total = getTotalPoints( responses[ issue ] );
		cout << setw( 6 ) << total << endl;
	}
}

int Polling::getTotalPoints( const array< int, ratings > &setOfRatings ) const {
	int total = 0;
	for ( int rating = 1; rating <= setOfRatings.size(); ++rating ) {
		total += rating * setOfRatings[ rating - 1 ];
	}
	return total;
}

int Polling::getHigestPoint() {
	int fig = 0;
	for ( int topic = 0; topic < topics.size(); ++topic ) {
		if( getTotalPoints(responses[ topic ]) > getTotalPoints(responses[ fig ]) )
			fig = topic;
	}
	return fig;
}

int Polling::getLowestPoint() {
	int fig = 0;
	for ( int topic = 0; topic < topics.size(); ++topic ) {
		if( getTotalPoints(responses[ topic ]) < getTotalPoints(responses[ fig ]) )
			fig = topic;
	}
	return fig;
}