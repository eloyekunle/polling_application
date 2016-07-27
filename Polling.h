#include <string>
using namespace std;

class Polling {
public:
	static const int issues = 5;
	static const int ratings = 10;

	Polling( const array< string, issues > &, array< array< int, ratings >, issues > & );

	int getHigestPoint();

	int getLowestPoint();

	double getAverage( const array< int, ratings > & ) const;

	void displayRatings() const;

	void processRatings();

	void setRatings();

	void enterRating();

	int getTotalPoints( const array< int, ratings > &) const;

private:
	array< string, issues> topics;
	array< array< int, ratings >, issues > responses;
};