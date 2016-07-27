/*
 * Polling.h
 * Definition of class Polling that uses a two-dimensional array to store user ratings.
 * Member functions are declared in Polling.cpp
 * author: Oyekunle Elijah PlayMice <elijah@playmiceweb.com>
 * 27/07/16
 */

#include <string>

using namespace std;

class Polling {
public:
	//constants
	static const int issues = 5;        //number of topics
	static const int ratings = 10;        //maximum rating scale

	//constructor initializes array of topics and ratings
	Polling( const array< string, issues > &, array< array< int, ratings >, issues > & );

	int getHighestPoint();		//function to get highest rated topic

	int getLowestPoint();		//function to get lowest rated topic

	double getAverage( const array< int, ratings > & ) const;	//function to get averate rating for each topic

	void displayRatings() const;	//display the contents of the responses array

	void processRatings();	//perform various operations on ratings data

	void setRatings();	//function to rate different topics

	void setTopics();	//function to set the topics

	void enterRating();	//function to get the ratings, individually

	int getTotalPoints( const array< int, ratings > & ) const;	//function to get the total rating points of an array

private:
	array< string, issues > topics;		//array to store the topics
	array< array< int, ratings >, issues > responses;    //Multi-dimensional array to store ratings.
};