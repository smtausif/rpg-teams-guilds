// Name: SM Tausif
// Seneca Email: stausif@myseneca.ca
// Student ID: 187699236
// Date: 11.06.25

// I declare that this submission is the result of my own work and I only copied the code that my professor provided to complete my assignments. This submitted piece of work has not been shared with any other student or 3rd party content provider.

#ifndef SENECA_TEAM_H
#define SENECA_TEAM_H

#include "character.h"
#include <string>

namespace seneca
{
    class Team
    {
        std::string m_name{};
        Character** m_members{ nullptr };
        size_t m_count{ 0 };

        bool exists(const std::string& name) const;

    public:
        Team();
        Team(const char* name);
        ~Team();
        Team(const Team& other);
        Team& operator=(const Team& other);
        Team(Team&& other) noexcept;
        Team& operator=(Team&& other) noexcept;

        void addMember(const Character* c);
        void removeMember(const std::string& name);
        Character* operator[](size_t idx) const;
        void showMembers() const;
    };
}

#endif
