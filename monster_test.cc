#include <iostream>
#include "monster.h"
#include <cassert>

using namespace std;

void test_attack_victim();
void test_attack_sheriff();

int main() {
	Monster<int> m = Vampire<int>(10, 12);
	test_attack_victim();
	test_attack_sheriff();
}

void test_attack_victim() {
	Adult<int> a(50, 18);
	Teenager<float> t(11.5f, 12.23f);
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
}
void test_attack_sheriff() {
	//TODO: sheriff test
}
