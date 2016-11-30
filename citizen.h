#ifndef __CITIZEN_H__
#define __CITIZEN_H__

#include <algorithm>
#include <cassert>

using age_t = int;

template <typename T, age_t ageMin, age_t ageMax, bool canAttack,
          typename = typename std::enable_if<std::is_arithmetic<T>::value, T>::type>
class Citizen {
private:
	T _health, _age;
public:
	Citizen(T health, T age) :
		_health(health),
		_age(age)
	{
		static_assert(!canAttack, "a");
		assert(ageMin <= age && age <= ageMax);
		assert(health >= 0);
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
using Adult = Citizen <T, 18, 100, false>;
template <typename T>
using Teenager = Citizen <T, 11, 17, false>;
template <typename T>
using Sheriff = Citizen<T, 18, 100, true>;


template<typename T>
class Citizen<T, 18, 100, true> {
private:
	T _health, _age, _attackPower;
public:
	Citizen(T health, T age, T attackPower) :
		_health(health),
		_age(age),
		_attackPower(attackPower)
	{
		assert(18 <= age && age <= 100);
		assert(health >= 0);
	}

	T getHealth() const {
		return _health;
	}
	T getAge() const {
		return _age;
	}
	T getAttackPower() const {
		return _attackPower;
	}

	void takeDamage(T damage) {
		assert(damage >= 0);
		_health = std::max<T>(_health - damage, 0);
	}
};

#endif /*  __CITIZEN_H__ */
