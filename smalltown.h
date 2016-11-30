#ifndef __SMALLTOWN_H__
#define __SMALLTOWN_H__

#include <string>
#include <tuple>
#include <cstddef>
#include "citizen.h"
#include "monster.h"
#include <type_traits>
#include <typeinfo>
#include <iostream>
#include <tuple>

namespace {
    //for tuple
    
    
    //for fibbo
    constexpr unsigned giveDesiredFibbonacci(unsigned index) {
        return index <= 1 ? 1 : giveDesiredFibbonacci(index - 2) +
            giveDesiredFibbonacci(index - 1);
    }

    constexpr unsigned giveFibArraySize(unsigned maxNumber, unsigned index) {
        return giveDesiredFibbonacci(index) > maxNumber ? index : giveFibArraySize(maxNumber, index + 1);
    }

    template <unsigned...args>
    constexpr std::array <unsigned, sizeof...(args)> giveArray(std::integer_sequence<unsigned, args...>) {
        return std::array <unsigned, sizeof...(args)> {{giveDesiredFibbonacci(args)...}};
    }
}

template <typename M, typename U, U t0, U t1, typename... C>
class SmallTown {
    private:
        static constexpr unsigned _sizeOfArray = giveFibArraySize((unsigned)t1, 0);
        static constexpr std::array<unsigned, _sizeOfArray> _fibbonacciArray = giveArray(std::make_integer_sequence<unsigned, _sizeOfArray>{});
        U _currentTime;
        U _cycleTimer;
        M _monster;
        std::tuple<C...> _citizens;
        unsigned _alive;
    public:
        constexpr SmallTown(M monster, C... citizens) :
           _currentTime(t0), _cycleTimer(t1), _monster(monster),
           _citizens(citizens...), _alive(sizeof...(C)) {
               static_assert(std::is_integral<U>::value, "Type not arythmetic");
               static_assert((t0 >= 0) && (t1 >= 0) && (t0 < t1), "Timestamps invalid");
        }
            
        auto getStatus() {
            return std::make_tuple(_monster.valueType, _monster.getHealth(), _alive);
        }
        
        void tick(U timeStep) {
            bool annihilationTime = false;
            U steppedTime = (_currentTime + timeStep)%_cycleTimer;
            
            for (auto &in : _fibbonacciArray) {
                if (in == steppedTime) annihilationTime = true; 
            }
            
            if (annihilationTime) 
                attackAll();
        };
        
        private:
            void attackAll() {
                //for_each(_citizens, unpacker{});
                
                if(_alive == 0) {
                    if (_monster.getHealth() == 0) {
                        std::cout << "DRAW";
                    } else {
                        std::cout << "CITIZENS WON";
                    }
                } else {
                    if (_monster.getHealth() == 0) {
                        std::cout << "DRAW";
                    } else {
                        std::cout << "MONSTER WON";
                    }
                }
            }
};


template <typename M, typename U, U t0, U t1, typename...C>
constexpr unsigned SmallTown<M, U, t0, t1, C...>::_sizeOfArray;

template <typename M, typename U, U t0, U t1, typename...C>
constexpr std::array<unsigned, SmallTown<M, U, t0, t1, C...>::_sizeOfArray> SmallTown<M, U, t0, t1, C...>::_fibbonacciArray;

#endif /* __SMALLTOWN_H__ */
