#include <iostream>
#include "monster.h"

using namespace std;

int main() {
	Monster<int> m = Vampire<int>(10, 12);
	cout << m.getAttackPower() << " " << m.getHealth() << endl;
	m.takeDamage(4);
	cout << m.getAttackPower() << " " << m.getHealth() << endl;
}