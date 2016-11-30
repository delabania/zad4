#ifndef __MONSTER_H__
#define __MONSTER_H__

#include <algorithm>
#include <string>
#include <typeinfo>

#include "citizen.h"

template <typename T, typename = typename std::enable_if<std::is_arithmetic<T>::value, T>::type>
class Monster {
    private:
        T _health, _attackPower;
        std::string _valueType;
    public:
        Monster(T health, T attackPower) :
            _health(health), _attackPower(attackPower) {
            assert(health >= 0 && attackPower >= 0);
            _valueType = typeid(T).name();
        }

        T getHealth() const {
            return _health;
        }
        
        T getAttackPower() const {
            return _attackPower;
        }

        std::string getValueType() {
            return _valueType;
        }
        
        void takeDamage(T damage) {
            assert(damage >= 0);
            _health = std::max<T>(_health - damage, 0);
        }
};

template <typename T>
using Zombie = Monster<T>;
template <typename T>
using Vampire = Monster<T>;
template <typename T> 
using Mummy = Monster<T>;

#endif /* __MONSTER_H__ */
