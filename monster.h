#ifndef __MONSTER_H__
#define __MONSTER_H__

#include <algorithm>
#include <string>
#include <typeinfo>
#include "citizen.h"


template <typename T, 
 typename = typename std::enable_if<std::is_arithmetic<T>::value, T>::type>
class Monster {
private:
	T _health, _attackPower;
public:
	Monster(T health, T attackPower) :
		_health(health),
		_attackPower(attackPower) {
		assert(health >= 0 && attackPower >= 0);
		valueType = typeid(T).name();
	}

	T getHealth() const {
		return _health;
	}
	T getAttackPower() const {
		return _attackPower;
	}
	void takeDamage(T damage) {
		assert(damage >= 0);
		_health = std::max<T>(_health - damage, 0);
	}

	std::string valueType;
};
template <typename T>
using Zombie = Monster<T>;
template <typename T>
using Vampire = Monster<T>;
template <typename T> 
using Mummy = Monster<T>;


template <typename M, typename U>
void attack(M &monster, U &victim) {
	victim.takeDamage(monster.getAttackPower());
}

template <typename M, typename T>
void attack(M &monster, Sheriff<T> &sheriff) {
	monster.takeDamage(sheriff.getAttackPower());
	sheriff.takeDamage(monster.getAttackPower());
}

#endif /* __MONSTER_H__ */
