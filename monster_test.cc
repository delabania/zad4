#include <iostream>
#include <cassert>
#include <vector>
#include <string>

//#include "monster.h"
#include "citizen.h"

using namespace std;


void test_attack_victim();
void test_attack_sheriff();
void test_valueType();

int main() {
	//test_attack_victim();
	//test_attack_sheriff();
	//test_valueType();
}
/*
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
	Sheriff<int> s(50, 20, 10);
	Zombie<int> z(10, 5);
	Vampire<float> v(20, 10);
	Mummy<int> m(40, 8);
	attack(z, s);
	assert(z.getHealth() == 0 && s.getHealth() == 45);
	attack(z, s);
	assert(z.getHealth() == 0 && s.getHealth() == 40);
	attack(v, s);
	assert(v.getHealth() == 10 && s.getHealth() == 30);
	attack(m, s);
	assert(m.getHealth() == 30 && s.getHealth() == 22);
	attack(m, s);
	assert(m.getHealth() == 20 && s.getHealth() == 14);
	attack(m, s);
	assert(m.getHealth() == 10 && s.getHealth() == 6);
	attack(m, s);
	assert(m.getHealth() == 0 && s.getHealth() == 0);
}

void test_valueType() {
	Zombie<int> z(10, 5);
	Vampire<float> v(20, 50);
	Mummy<int> m(19, 20);
	Mummy<short> m2(1, 1);
	assert(z.valueType == m.valueType);
	assert(z.valueType != v.valueType);
	assert(m.valueType != m2.valueType);
	//std::cout << z.valueType <<  " " << v.valueType <<
	//          " " << m2.valueType << std::endl;
}

void test_notArithmeticType() {
	//Nie powinno sie skompilowac
	Zombie<vector<int>> z({10, 2}, {5, 3});
	Zombie<int *> x(NULL, NULL);
	Teenager<std::string> o("as", "jefiq");
}

void test_takeDamage() {
	Zombie<int> z(10, 5);
	vector<int> x = {1};
	z.takeDamage(x);
	int * y = NULL;
	z.takeDamage(y);
}*/





