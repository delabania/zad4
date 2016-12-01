#include <iostream>
#include <cassert>
#include <vector>
#include <string>

#include "smalltown.h"
#include "monster.h"
#include "citizen.h"

using namespace std;

void test1();
void test2();
void test3();

int main() {

	cout << "test1:" << endl;
	test1();
	cout << "test2:" << endl;
	test2();
	cout << "test3:" << endl;
	test3();
	return 0;
}



void test1() {
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
}

//test na to czy tick dobrze dziala przy przeskakiwaniu powyzej t1
void test2() {
	auto smallTown = SmallTown<Vampire<int>, int, 6, 10, Adult<int> > (
	                     Vampire<int>(100, 1), Adult<int>(10, 18)
	                 );

	smallTown.tick(4); // 6->10
	//(100, 10)
	smallTown.tick(1); // 10->1
	//(100, 10)
	smallTown.tick(1); // 1->2
	//(100, 9)
	smallTown.tick(1); // 2->3
	//(100, 8)
	smallTown.tick(2); // 3->5
	//(100, 7)
	smallTown.tick(3); // 5->8
	//(100, 6)
	smallTown.tick(3); // 8->1
	//(100, 5)
	smallTown.tick(4); // 1->5
	//(100, 4)
	smallTown.tick(3); // 5->8
	//(100, 3)
	smallTown.tick(10); // 8->8
	//(100, 2)
	smallTown.tick(1); // 8->9
	//(100, 1)
	auto status = smallTown.getStatus();
	assert(get<1>(status) == 100);
	assert(get<2>(status) == 1);

	smallTown.tick(2); // 9->1
	//(100, 1)
	smallTown.tick(5);
	status = smallTown.getStatus();
	assert(get<1>(status) == 100);
	assert(get<2>(status) == 0);
	//(100, 0)

	smallTown.tick(1); // wypisanie MONSTER WON
	smallTown.tick(3); // wypisanie MONSTER WON
	smallTown.tick(111); // wypisanie MONSTER WON
	smallTown.tick(19239239U); // wypisanie MONSTER WON
	smallTown.tick(1); // wypisanie MONSTER WON

	smallTown.tick(1); // wypisanie MONSTER WON
	smallTown.tick(1); // wypisanie MONSTER WON
	smallTown.tick(1); // wypisanie MONSTER WON
	smallTown.tick(1); // wypisanie MONSTER WON
	smallTown.tick(1); // wypisanie MONSTER WON
	smallTown.tick(1); // wypisanie MONSTER WON

	smallTown.tick(1); // wypisanie MONSTER WON

	// Powinien wypisac 12 MONSTER WON
}

// DRAW
void test3() {
	auto smallTown = SmallTown<Vampire<int>, int, 1, 100, Adult<int>, Sheriff<int> > (
	                     Vampire<int>(10, 1), Adult<int>(5, 5), Sheriff<int>(10, 20, 1)
	                 );

	smallTown.tick(1); // 1->2
	auto status = smallTown.getStatus();
	assert(get<1>(status) == 9);
	assert(get<2>(status) == 2);
	// (9, 4, 9)

	smallTown.tick(1); // 2->3
	status = smallTown.getStatus();
	assert(get<1>(status) == 8);
	assert(get<2>(status) == 2);
	// (8, 3, 8)


	smallTown.tick(2); // 3->5
	status = smallTown.getStatus();
	assert(get<1>(status) == 7);
	assert(get<2>(status) == 2);
	// (7, 2, 7)

	smallTown.tick(3); // 5->8
	status = smallTown.getStatus();
	assert(get<1>(status) == 6);
	assert(get<2>(status) == 2);
	// (6, 1, 6)

	smallTown.tick(5); // 8->13
	status = smallTown.getStatus();
	assert(get<1>(status) == 5);
	assert(get<2>(status) == 1);
	// (5, 0, 5)

	smallTown.tick(8); // 13->21
	status = smallTown.getStatus();
	assert(get<1>(status) == 4);
	assert(get<2>(status) == 1);
	// (4, 0, 4)

	smallTown.tick(13); // 21->34
	status = smallTown.getStatus();
	assert(get<1>(status) == 3);
	assert(get<2>(status) == 1);
	// (3, 0, 3)

	smallTown.tick(21); // 34->55
	status = smallTown.getStatus();
	assert(get<1>(status) == 2);
	assert(get<2>(status) == 1);
	// (2, 0, 2)

	smallTown.tick(34); // 55->89
	status = smallTown.getStatus();
	assert(get<1>(status) == 1);
	assert(get<2>(status) == 1);
	// (1, 0, 1)

	smallTown.tick(55); // 89->144
	status = smallTown.getStatus();
	assert(get<1>(status) == 0);
	assert(get<2>(status) == 0);
	// (0, 0, 0)

	smallTown.tick(129);
	assert(get<1>(status) == 0);
	assert(get<2>(status) == 0);



}