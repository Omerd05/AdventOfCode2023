#include <iostream>
#include <string>
#include <fstream>
#include "Days.h"
#include <map>

using namespace std;
typedef long long ll;


void Day1Part1() {
	ifstream input_file;
	string line;
	input_file.open("input.txt");
	ll result = 0;

	while (getline(input_file, line, '\n')) {
		int N = line.size();
		
		for (int i = 0; i < N; i++) {
			if (line[i] <= '9') {
				result += (line[i] - '0') * 10;
				break;
			}
		}

		for (int i = N - 1; i >= 0; i--) {
			if (line[i] <= '9') {
				result += line[i] - '0';
				break;
			}
		}
	}

	cout << result;
	input_file.close();
}

void Day1Part2() {
	ifstream input_file;
	input_file.open("input.txt");
	string line;

	ll result = 0;

	//string edited = line;
	map<string, int> calib;

	calib["one"] = 1; calib["two"] = 2; calib["three"] = 3; calib["four"] = 4; calib["five"] = 5; calib["six"] = 6;
	calib["seven"] = 7; calib["eight"] = 8; calib["nine"] = 9;

	while (getline(input_file, line, '\n')) {
		int N = line.size();
		int l = 0;
		ll first = 0;
		ll last = 0;
		while (l < N) {
			if (line[l] <= '9') {
				if (first == 0)first = line[l] - '0';
				last = line[l] - '0';
				continue;
			}
			if (calib.count(line.substr(l, 3))) {
				if (first == 0)first = calib[line.substr(l, 3)];
				last = calib[line.substr(l, 3)];
				l++;
				continue;
			}
			if (calib.count(line.substr(l, 4))) {
				if (first == 0)first = calib[line.substr(l, 4)];
				last = calib[line.substr(l, 4)];
				l++;
				continue;
			}
			if (calib.count(line.substr(l, 5))) {
				if (first == 0)first = calib[line.substr(l, 5)];
				last = calib[line.substr(l, 5)];
				l++;
				continue;
			}
			l++;
		}
		result += first * 10 + last;
	}
	cout << result;
}