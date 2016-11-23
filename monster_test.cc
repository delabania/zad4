#include <iostream>
#include "monster.h"
#include <cassert>

using namespace std;

void test1();

int main() {
	Monster<int> m = Vampire<int>(10, 12);
	test1();
}

void test1() {
	Adult<int> a(50, 18);
	Teenager<float> t(11.5f, 12.23f);
	Sheriff<int> s(100, 45, 5);
	Zombie<int> z(10, 5);
	Vampire<float> v(20, 50);
	Mummy<int> m(19, 20);
	attack(m, a);
	assert(a.getHealth() == 30);
	attack(z, a);
	assert(a.getHealth() == 25);
	attack(m, a);
	assert(a.getHealth() == 5);
	attack(v, a);
	assert(a.getHealth() == 0);
	attack(z, t);
	assert(t.getHealth() == 6.5f);
	//TODO: sheriff test
}