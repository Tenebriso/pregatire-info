#include <iostream>
#include <string>
#include <vector>
#include <unordered_set>

// combinari de n luate cate p
#define n 5
#define p 3

bool check(std::string fruits[n], int solution[p], std::string fruit, int step) {
	for (int i = 0; i < step; i++) {
		// capsune si piersici nu pot fi pe acelasi platou
		if ((fruits[solution[i]].compare("capsune") == 0) &&
				(fruit.compare("piersici") == 0)) {
			return false;
		}
	}
	return true;
}

void printSolution(std::string fruits[n], int solution[p]) {
	for (int i = 0; i < p; i++) {
		std::cout << fruits[solution[i]] << ' ';
	}
	std::cout << std::endl;
}

void back(int step, int stop, std::string fruits[n], int solution[p]) {
	if (step == stop) {
		printSolution(fruits, solution);
		return;
	}
	// pornim de la fructul urmator ca sa le genereze in ordine
	unsigned i = step > 0 ? solution[step - 1] + 1 : 0;
	for (; i < n; ++i) {
		if (check(fruits, solution, fruits[i], step)){
			solution[step] = i;
			back(step + 1, stop, fruits, solution);
		}
	}
}


int main() {
	std::string fruits[n] = {"caise", "capsune", "prune", "piersici", "cirese"};
	int solution[p];
	back(0, p, fruits, solution);
}
