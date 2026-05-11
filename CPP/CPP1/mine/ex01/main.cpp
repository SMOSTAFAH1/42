#include "Zombie.hpp"

int main(void) {
	const int N = 5;
	Zombie* horde = zombieHorde(N, "HordeZombie");
	if (horde == 0)
		return 1;
	
	for (int i = 0; i < N; i++) {
		horde[i].announce();
	}
	
	delete[] horde;
	
	return 0;
}
