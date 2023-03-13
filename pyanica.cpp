#include <iostream>
#include <string>
#include <deque>
#include <queue>

int main() {
		
	std::string first;
	std::string second;

	std::queue <int> dfirst;
	std::queue <int> dsecond;

	int counter = 0;

	for (int i = 0, x; i < 5; ++i) std::cin >> x, dfirst.push(x);
	for (int i = 0, x; i < 5; ++i) std::cin >> x, dsecond.push(x);

	while (dfirst.empty() == false && dsecond.empty() == false && counter < 1000000) {
		if (dfirst.front() == 9 && dsecond.front() == 0) {
			dsecond.push(dfirst.front());
			dsecond.push(dsecond.front());
			dsecond.pop();
			dfirst.pop();
		}
		else if (dfirst.front() == 0 && dsecond.front() == 9) {
			dfirst.push(dsecond.front());
			dfirst.push(dfirst.front());
			dfirst.pop();
			dsecond.pop();
		}
		else if (dfirst.front() > dsecond.front()) {
			dfirst.push(dsecond.front());
			dfirst.push(dfirst.front());
			dfirst.pop();
			dsecond.pop();
		}
		else if (dfirst.front() < dsecond.front()) {
			dsecond.push(dfirst.front());
			dsecond.push(dsecond.front());
			dsecond.pop();
			dfirst.pop();
		}
		counter += 1;
	}

	if (counter == 1000000) {
		std::cout << "botva";
		return 0;
	}

	if (dfirst.empty() == true) {
		std::cout << "second " << counter;
	}
	else {
		std::cout << "first " << counter;
	}
	
	return 0;
}