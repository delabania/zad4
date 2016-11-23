#ifndef __SMALLTOWN_H__
#define __SMALLTOWN_H__

#include <string>
#include <tuple>
#include <cstddef>

namespace {
	//TODO: constexpr na liczby Fibonacciego
};


// jakis static assert na t0 i t1
template <typename M, typename U, U t0, U t1, typename... C>
class SmallTown {
private:
	//TODO
	//kontener na mieszkancow o rozmiarze sizeof...(C) 
public:
	SmallTown(M monster, C... citizens);
	std::tuple<std::string, T, size_t> & getStatus();
	void tick(U timeStep);
};

#endif /* __SMALLTOWN_H__ */