#include <iostream>
#include <string>
#include <set>

int main() {
	
	int N, input;
	std::set <int> set;
	std::cin >> N;

	for (int i = 0; i < N; i++) {
		std::cin >> input;
		set.insert(input);
	}

	std::cout << set.size();

	return 0;
}