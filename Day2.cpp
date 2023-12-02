#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <fstream>
#include <istream>
#include <sstream>
#include <map>
#include "Days.h"

using namespace std;
typedef long long ll;
//typedef basic_istream<char> istream;

void Day2Part2() {
	ifstream input_file;
	input_file.open("input.txt");

	string game = "";
	int id = 1;
	ll result = 0;
	while (getline(input_file, game, '\n')) {
		bool flag = 1;
		vector<string> parts;
		string part = "";
		istringstream fgame(game);
		int cnt = 0;
		while (getline(fgame, part, ' ')) {
			if (cnt++ > 1)parts.push_back(part);
		}

		int last = 0; //last number of balls.
		map<string, int> minis;
		minis["blue"] = 0; minis["red"] = 0; minis["green"] = 0;
		for (int i = 0; i < parts.size(); i++) {
			if (i % 2 == 0) {
				last = stoi(parts[i]);
			}
			else {
				if (i < parts.size() - 1) parts[i].pop_back();
				minis[parts[i]] = max(minis[parts[i]], last);
			}
		}

		result += minis["blue"]*minis["red"]*minis["green"];
		id++;
		fgame.clear();
	}
	cout << result;
}

void Day2Part1() {
	ifstream input_file;
	input_file.open("input.txt");

	string game = "";
	int id = 1;
	ll result = 0;
	while (getline(input_file, game, '\n')) {
		bool flag = 1;		
		vector<string> parts;
		string part = "";
		istringstream fgame(game);
		int cnt = 0;
		while (getline(fgame, part, ' ')) {
			if(cnt++>1)parts.push_back(part);
		}

		int last = 0; //last number of balls.
		for (int i = 0; i < parts.size(); i++) {
			if (i % 2 == 0) {
				last = stoi(parts[i]);
			}
			else {
				if (i < parts.size() - 1) parts[i].pop_back();

				if (parts[i] == "red") {
					if (last > 12)flag = 0;
				}
				if (parts[i] == "green") {
					if (last > 13)flag = 0;
				}
				if (parts[i] == "blue") {
					if (last > 14)flag = 0;
				}
				if (flag == 0)break;
			}
		}

		result += flag * id;
		id++;
		fgame.clear();
	}
	cout << result;
}