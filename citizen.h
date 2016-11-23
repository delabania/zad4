#ifndef __CITIZEN_H__
#define __CITIZEN_H__


#include <algorithm>

template <typename T, typename... >
class Citizen {
// Moze zrobic protected, jezeli by byla potrzeba uzycia w podklasach (?)
private:
	T _health, _age;
public:
	T getHealth() {
		return _health;
	}
	T getAge() {
		return _age;
	}
	void takeDamage(T damage) {
		_health = std::max(_health - damage, 0);
	}
};

template <typename T>
class Adult {
public:
	Adult(T health, T age) :
		Citizen<T>(health, age) {
		static_assert(18 <= age && age <= 100, "Invalid age");
	}
};

template <typename T>
class Teenager {
public:
	Teenager(T health, T age) :
		Citizen<T>(health, age) {
		static_assert(11 < age && age <= 17, "Invalid age");
	}
};

template <typename T>
class Sheriff {
private:
	T _attackPower;
public:
	Sheriff(T health, T age, T attackPower) :
		_attackPower(attackPower) {
		static_assert(18 <= age && age <= 100, "Invalid age");
	}
	T getAttackPower() {
		return _attackPower;
	}
};

#endif /*  __CITIZEN_H__ */