//	Philipp Siedler
//	Bjarne Stroustrup's PPP
//	Chapter 10 Exercise 4

#include "std_lib_facilities.h"

struct Reading {
	int hour;
	double temperature;
	char suffix;
	Reading(int h, double t, char s) :hour(h), temperature(t), suffix(s) {}
};

ostream& operator<<(ostream& os, Reading& _temps) {
	os << _temps.hour << " " << _temps.temperature << " " << _temps.suffix << endl;
	return os;
}

vector<Reading> temps;

string oname = "output/raw_temps.txt";
ofstream ost(oname);

int random_temperatur(int seed, int max) {
	srand(seed);
	return randint(max);
}

char random_suffix(int seed) {
	srand(seed);
	if (randint(100) <= 50) {
		return 'c';
	}
	else {
		return 'f';
	}
}

void fill_vector(vector<Reading>& _temps) {
	cout << "Generating Data." << endl;
	int h;
	double t;
	char s;
	int temp_hour = 0;

	for (int i = 0; i < 50; i++) {
		if (!(i % 24)) {
			temp_hour = 0;
		}

		h = temp_hour;
		t = random_temperatur(0, 90);
		s = random_suffix(1);
		
		_temps.push_back(Reading{ h, t, s});
		temp_hour++;
	}
}


void write_file(vector<Reading>& _temps) {
	cout << "Writing File." << endl;
	for (int i = 0; i < temps.size(); i++) {
		ost << _temps[i];
	}
	cout << "Done!" << endl;
}

int main()
try
{

	fill_vector(temps);
	write_file(temps);

	keep_window_open();
}
catch (runtime_error e) {
	cout << e.what() << endl;
	keep_window_open();
}
catch (...) {
	cout << "Exiting" << endl;
	keep_window_open();
}