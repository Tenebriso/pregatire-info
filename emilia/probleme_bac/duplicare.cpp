#include <iostream>

void duplicare(int n, int *d) {
	// power retine puterea lui 10 pe care o adaug la fiecare pas
	// incepe cu cifra unitatilor (1) apoi se muta la cifra zecilor (10)
	// a sutelor (100) etc.
	int ok = 0, power = 1;
	*d = 0;
	while (n > 0) {
		*d += power * (n % 10); 
		if (n % 2 == 1) {
			ok = 1;
			power *= 10;
			*d = power * (n % 10) + *d; 
		}
		power *= 10;
		n /= 10;
	}
	*d = ok == 0? -1 : *d;
}

int main() {
	int n, d;
	std::cout << "n = ";
	std::cin >> n;
	duplicare(n, &d);
	std::cout << "d = " << d << std::endl;

	return 0;
}
