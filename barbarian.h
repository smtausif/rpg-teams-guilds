// Name: SM Tausif
// Seneca Email: stausif@myseneca.ca
// Student ID: 187699236
// Date: 11.06.25

// I declare that this submission is the result of my own work and I only copied the code that my professor provided to complete my assignments. This submitted piece of work has not been shared with any other student or 3rd party content provider.

#ifndef SENECA_BARBARIAN_H
#define SENECA_BARBARIAN_H

#include "characterTpl.h"

namespace seneca
{
    template<typename T, typename Ability_t, typename Weapon_t>
    class Barbarian : public CharacterTpl<T>
    {
        int m_baseAttack{};
        int m_baseDefense{};
        Ability_t m_ability{};
        Weapon_t m_weapon[2]{};

    public:
        Barbarian(const char* name, int healthMax, int baseAttack, int baseDefense, Weapon_t primaryWeapon, Weapon_t secondaryWeapon)
            : CharacterTpl<T>(name, healthMax),
              m_baseAttack(baseAttack),
              m_baseDefense(baseDefense)
        {
            m_weapon[0] = primaryWeapon;
            m_weapon[1] = secondaryWeapon;
        }

        int getAttackAmnt() const override {
            return m_baseAttack + static_cast<int>((static_cast<double>(m_weapon[0]) + static_cast<double>(m_weapon[1])) / 2.0);
        }

        int getDefenseAmnt() const override {
            return m_baseDefense;
        }

        Character* clone() const override {
            return new Barbarian(*this);
        }

        void attack(Character* enemy) override {
            std::cout << this->getName() << " is attacking " << enemy->getName() << "." << std::endl;
            m_ability.useAbility(this);
            int dmg = getAttackAmnt();
            m_ability.transformDamageDealt(dmg);
            std::cout << "    Barbarian deals " << dmg << " melee damage!" << std::endl;
            enemy->takeDamage(dmg);
        }

        void takeDamage(int dmg) override {
            std::cout << this->getName() << " is attacked for " << dmg << " damage." << std::endl;
            std::cout << "    Barbarian has a defense of " << m_baseDefense << ". Reducing damage received." << std::endl;
            dmg -= m_baseDefense;
            if (dmg < 0) dmg = 0;
            m_ability.transformDamageReceived(dmg);
            CharacterTpl<T>::takeDamage(dmg);
        }
    };
}

#endif
