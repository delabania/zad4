#include <iostream>
#include <cassert>
#include <vector>
#include <string>

#include "smalltown.h"
#include "monster.h"
#include "citizen.h"

using namespace std;

int main() {
	auto smallTown = SmallTown < Mummy<float>, int, 3, 40,
	     Sheriff<int>, Adult<int>, Teenager<long>, Adult<float> >
	     (Mummy<float>(100.0f, 25.0f),
	      Sheriff<int>(100, 35, 20),
	      Adult<int>(100, 21),
	      Teenager<long>(50, 14),
	      Adult<float> (120, 18));

	auto status = smallTown.getStatus();
	assert(get<1>(status) == 100.0f);
	assert(get<2>(status) == 4);

	smallTown.tick(2); // 3 -> 5
	status = smallTown.getStatus();
	assert(get<1>(status) == 80);
	assert(get<2>(status) == 4);

	smallTown.tick(3); // 5 -> 8
	// (80, 75, 75, 25, 95)
	status = smallTown.getStatus();
	assert(get<1>(status) == 60);
	assert(get<2>(status) == 3);
	// (60, 50, 50, 0, 70)

	smallTown.tick(1);
	smallTown.tick(1);
	smallTown.tick(1);
	smallTown.tick(1);
	smallTown.tick(1); // all : 8 -> 13
	status = smallTown.getStatus();
	assert(get<1>(status) == 40);
	assert(get<2>(status) == 3);
	// (40, 25, 25, 0, 45)
	smallTown.tick(9); // 13 -> 22
	status = smallTown.getStatus();
	assert(get<1>(status) == 20);
	assert(get<2>(status) == 1);
	//(20, 0, 0, 0, 20)
	smallTown.tick(10); // 22 -> 32
	smallTown.tick(2); // 32 -> 34

	status = smallTown.getStatus();
	assert(get<1>(status) == 20);
	assert(get<2>(status) == 1);
	//(20, 0, 0, 0, 20)

	smallTown.tick(2); // 34 -> 36
	status = smallTown.getStatus();
	assert(get<1>(status) == 20);
	assert(get<2>(status) == 0);
	//(20, 0, 0, 0, 0)



	status = smallTown.getStatus();


	return 0;
}
