#ifndef __SMALLTOWN_H__
#define __SMALLTOWN_H__

#include <string>
#include <tuple>
#include <cstddef>
#include <type_traits>
#include <typeinfo>
#include <iostream>
#include <utility>

#include "citizen.h"
#include "monster.h"

namespace {
    using bigpositive = unsigned long long;
    
    constexpr bigpositive giveDesiredFibbonacci(bigpositive index) {
        return (index <= 1) ? 1 : giveDesiredFibbonacci(index - 2) +
            giveDesiredFibbonacci(index - 1);
    }

    constexpr bigpositive giveFibArraySize(bigpositive maxNumber, bigpositive index) {
        return (giveDesiredFibbonacci(index) > maxNumber) ?
            index : giveFibArraySize(maxNumber, index + 1);
    }

    template <bigpositive...args>
    constexpr std::array <bigpositive, sizeof...(args)>
    giveArray(std::integer_sequence<bigpositive, args...>) {
        return std::array <bigpositive, sizeof...(args)> {{giveDesiredFibbonacci(args)...}};
    }


    template<typename M, typename U>
    void fight(M &monster, U &citizen) {
        citizen.takeDamage(monster.getAttackPower());
    }

    template<typename M, typename T>
    void fight(M &monster, Sheriff<T> &sheriff) {
        sheriff.takeDamage(monster.getAttackPower());
        monster.takeDamage(sheriff.getAttackPower());
    }
}

template <typename M, typename U, U t0, U t1, typename... C>
class SmallTown {
    private:
        static constexpr bigpositive _sizeOfArray = giveFibArraySize((bigpositive)t1, 0);
        static constexpr std::array<bigpositive, _sizeOfArray> _fibbonacciArray =
            giveArray(std::make_integer_sequence<bigpositive, _sizeOfArray>{});
        U _currentTime;
        U _cycleTimer;
        M _monster;
        std::tuple<C...> _citizens;
        bigpositive _alive;
    public:
        constexpr SmallTown(M monster, C... citizens) :
           _currentTime(t0), _cycleTimer(t1), _monster(monster),
           _citizens(citizens...), _alive(0) {
               static_assert(std::is_integral<U>::value, "Type not arythmetic");
               static_assert((t0 >= 0) && (t1 >= 0) && (t0 < t1), "Timestamps invalid");
               countInitialAlives<0, C...>(_citizens);
        }
            
        auto getStatus() {
            return std::make_tuple(_monster.getValueType(),
                _monster.getHealth(), _alive);
        }
        
        void tick(U timeStep) {
            bool annihilationTime = false;
            
            for (auto &in : _fibbonacciArray) {
                if (in == _currentTime) annihilationTime = true; 
            }
            
            if (annihilationTime) 
                attackAll();
            
                
            _currentTime = (_currentTime + timeStep)%_cycleTimer;
        };
        
    private:
        template<std::size_t Index, typename...Tupl>
        inline typename std::enable_if<Index == sizeof...(Tupl), void>::type
        countInitialAlives(std::tuple<Tupl...>& current) {}

        template<std::size_t Index, typename...Tupl>
        inline typename std::enable_if<Index<sizeof...(Tupl), void>::type
        countInitialAlives(std::tuple<Tupl...>& current) {
            auto currentCitizen = std::get<Index>(current);

            if(currentCitizen.getHealth() != 0)
                _alive++;

            countInitialAlives<Index + 1, Tupl...>(current);
        }
        
        template<std::size_t Index, typename...Tupl>
        inline typename std::enable_if<Index == sizeof...(Tupl), void>::type
        attAll(std::tuple<Tupl...>& current) {}

        template<std::size_t Index, typename...Tupl>
        inline typename std::enable_if<Index<sizeof...(Tupl), void>::type
        attAll(std::tuple<Tupl...>& current) {
            auto currentCitizen = std::get<Index>(current);
            auto currentHealth = currentCitizen.getHealth();
            fight(_monster, currentCitizen);

            if(currentCitizen.getHealth() == 0 && currentCitizen.getHealth() != currentHealth)
                _alive--;

            attAll<Index + 1, Tupl...>(current);
        }
        
        void attackAll() {
            if (_monster.getHealth() != 0)
                attAll<0, C...>(_citizens);
            
            if(_alive == 0) {
                if (_monster.getHealth() == 0) {
                    std::cout << "DRAW" << std::endl;
                } else {
                    std::cout << "MONSTER WON" << std::endl;
                }
            } else {
                if (_monster.getHealth() == 0) {
                    std::cout << "CITIZENS WON" << std::endl;
                }
            }
        }
};


template <typename M, typename U, U t0, U t1, typename...C>
constexpr bigpositive SmallTown<M, U, t0, t1, C...>::_sizeOfArray;

template <typename M, typename U, U t0, U t1, typename...C>
constexpr std::array<bigpositive, SmallTown<M, U, t0, t1, C...>::_sizeOfArray> SmallTown<M, U, t0, t1, C...>::_fibbonacciArray;

#endif /* __SMALLTOWN_H__ */
