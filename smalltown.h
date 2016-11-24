#ifndef __SMALLTOWN_H__
#define __SMALLTOWN_H__

#include <string>
#include <tuple>
#include <cstddef>
#include "citizen.h"
#include "monster.h"

namespace {
	//TODO: constexpr na liczby Fibonacciego
};


// jakis static assert na t0 i t1
template <typename M, typename U, U t0, U t1, typename... C>
class SmallTown {
private:
	//TODO
	// potwor
	M _monster;
	// Wektor zywych mieszkancow 
	// pytanie czy w ten sposob nie stracimy informacji 
	// o tym kto jest szeryfem przy przeladowaniu attack()...
	vector<Citizen> _citizens; 
public:
	SmallTown(M monster, C... citizens) {

	}

	std::tuple<std::string, T, size_t> & getStatus() {
		//std::string = m.valueType;
		//T = m.getHealth()
		//size_t = _citizens.size()
	}
	void tick(U timeStep);
};

#endif /* __SMALLTOWN_H__ */