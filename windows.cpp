#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

int how_tabs(std::string line) {
	int counter = 0;
	for (int i = 0; i < line.size(); ++i) {
		if (line[i] == 'T') {
			counter += 1;
		}
	}
	return counter;
}

std::string next_elem(std::vector<std::string> v, int tabs) {
	int counter = 0;
	std::string next;
	std::vector<std::string>::reverse_iterator it;
	for (it = v.rbegin(); counter != tabs + 1; ++it) {
		if (it == v.rend()) it = v.rbegin();
		next = *it;
		counter += 1;
		//std::cout << next << " ";
	}
	return next;
}

int main() {

	int n;
	std::cin >> n;
	std::cin.ignore();

	std::vector<std::string> v;
	std::vector<std::string> vr;
	std::string s;
		
	for (int i = 0; i < n; ++i) {
		getline(std::cin, s);
		v.push_back(s);
	}

	for (int i = 0; i < v.size(); ++i) {
		if (v[i][0] == 'R') {
			vr.push_back(v[i]);
		}
		else if (v[i][0] == 'A') {
			int tabs = how_tabs(v[i]);
			//std::string next = v[n % tabs];
			std::string next = next_elem(vr, tabs);
			//std::cout << std::endl;
			vr.push_back(next);
		}
	}

	for (int i = 0; i < vr.size(); ++i) {
		std::string result;
		result = vr[i].substr(4, vr[i].size());
		std::cout << result << std::endl;
	}

	return 0;
}