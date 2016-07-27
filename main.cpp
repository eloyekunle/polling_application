#include <array>
#include "Polling.h"

using namespace std;

int main() {
	array< string, Polling::issues > topics = {};
	array< array< int, Polling::ratings >, Polling::issues > responses = {};
	Polling myPolling( topics, responses );
	myPolling.setTopics();
	myPolling.setRatings();
	myPolling.displayRatings();
	myPolling.processRatings();
}