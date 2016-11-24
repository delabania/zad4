#ifndef __CITIZEN_H__
#define __CITIZEN_H__

#include <algorithm>
#include <cassert>


template <typename T, typename... >
class Citizen {
private:
	T _health, _age;
public:
	Citizen(T health, T age) :
		_health(health),
		_age(age) {
			assert(health >= 0 && age >= 0);
		}

	T getHealth() const {
		return _health;
	}
	T getAge() const {
		return _age;
	}
	void takeDamage(T damage) {
		assert(damage >= 0);
		_health = std::max<T>(_health - damage, 0);
	}
};

template <typename T>
class Adult : public Citizen<T> {
public:
	Adult(T health, T age) :
		Citizen<T>(health, age) {
		assert(18 <= age && age <= 100);
	}
};

template <typename T>
class Teenager : public Citizen<T> {
public:
	Teenager(T health, T age) :
		Citizen<T>(health, age) {
		assert(11 < age && age <= 17);
	}
};

template <typename T>
class Sheriff : public Citizen<T> {
private:
	T _attackPower;
public:
	Sheriff(T health, T age, T attackPower) :
		Citizen<T>(health, age),
		_attackPower(attackPower) {
		assert(attackPower >= 0);
		assert(18 <= age && age <= 100);
	}
	T getAttackPower() const{
		return _attackPower;
	}
};

#endif /*  __CITIZEN_H__ */