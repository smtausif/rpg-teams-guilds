// Name: SM Tausif
// Seneca Email: stausif@myseneca.ca
// Student ID: 187699236
// Date: 11.06.25

// I declare that this submission is the result of my own work and I only copied the code that my professor provided to complete my assignments. This submitted piece of work has not been shared with any other student or 3rd party content provider.

#ifndef SENECA_CHARACTERTPL_H
#define SENECA_CHARACTERTPL_H

#include "character.h"
#include <iostream>

namespace seneca
{
    template<typename T>
    class CharacterTpl : public Character
    {
        int m_healthMax{};
        T m_health{};

    public:
        CharacterTpl(const char* name, int healthMax)
            : Character(name), m_healthMax(healthMax)
        {
            m_health = healthMax;
        }

    void takeDamage(int dmg) override {
        m_health -= dmg;
        if (static_cast<int>(m_health) <= 0) {
            m_health = 0; 
            std::cout << "    " << getName() << " has been defeated!" << std::endl;
        } else {
            std::cout << "    " << getName() << " took " << dmg << " damage, "
                      << static_cast<int>(m_health) << " health remaining." << std::endl;
    }
}

        int getHealth() const override { return static_cast<int>(m_health); }
        int getHealthMax() const override { return m_healthMax; }
        void setHealth(int health) override { 
            m_health = (health < 0) ? 0 : health; 
        }
        void setHealthMax(int health) override { m_healthMax = health; m_health = health; }
    };
}
#endif
