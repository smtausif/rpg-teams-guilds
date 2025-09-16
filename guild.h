#ifndef SENECA_GUILD_H
#define SENECA_GUILD_H

#include "character.h"
#include <string>

namespace seneca
{
    class Guild
    {
        std::string m_name{};
        Character** m_members{ nullptr };
        size_t m_count{ 0 };

        bool exists(const std::string& name) const;

    public:
        Guild();
        Guild(const char* name);
        ~Guild();
        Guild(const Guild& other);
        Guild& operator=(const Guild& other);
        Guild(Guild&& other) noexcept;
        Guild& operator=(Guild&& other) noexcept;

        void addMember(Character* c);
        void removeMember(const std::string& name);
        Character* operator[](size_t idx) const;
        void showMembers() const;
    };
}

#endif
