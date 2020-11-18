#include <iostream>
#define n 4

using namespace std;
#include <vector>

void afisare(vector<int> subset) {
	for (int i = 0; i < subset.size(); i++) {
		std::cout << subset[i] << " ";
	}
	std::cout << std::endl;
}


void back(vector<int>& subset, int pas) 
{ 
	afisare(subset); 
	for (int i = pas; i < n; i++) { 
		// include A[i] in subset
		subset.push_back(i + 1); 
		// urmatorul element
		back(subset, i + 1); 
		// exclude A[i] din subset
		subset.pop_back(); 
	} 
	return; 
}

int main() 
{ 
	vector<int> solutie; 

	back(solutie, 0); 

	return 0; 
} 
	
