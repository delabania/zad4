#ifndef __MONSTER_H__
#define __MONSTER_H__

#include <algorithm>
#include "citizen.h"

//TODO: valueType, void attack<M,U>

template <typename T, typename... >
class Monster {
private:
	T _health, _attackPower;
public:
	Monster(T health, T attackPower) :
		_health(health),
		_attackPower(attackPower) {}

	T getHealth() const {
		return _health;
	}
	T getAttackPower() const {
		return _attackPower;
	}
	void takeDamage(T damage) {
		_health -= std::min(damage, _health);
	}
	// valueType - cos z decltype? 
};

template <typename T>
class Zombie : public Monster<T> {
public:
	Zombie(T health, T attackPower) :
		Monster<T>(health, attackPower) {}
};

template <typename T>
class Vampire : public Monster<T> {
public:
	Vampire(T health, T attackPower) :
		Monster<T>(health, attackPower) {}
};

template <typename T>
class Mummy : public Monster<T> {
public:
	Mummy(T health, T attackPower) :
		Monster<T>(health, attackPower) {}
};

template <typename M, typename U>
void attack(M monster, U victim) {
	//... gdy U != Sheriff<T>
}

template <typename M, typename T>
void attack(M monster, Sheriff<T> sheriff) {
	// gdy U == sheriff
}

#endif /* __MONSTER_H__ */
