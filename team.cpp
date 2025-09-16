#include "team.h"
#include <iostream>

namespace seneca
{
    Team::Team() = default;

    Team::Team(const char* name) : m_name(name), m_members(nullptr), m_count(0) {}

    Team::~Team() {
        for (size_t i = 0; i < m_count; i++) {
            delete m_members[i];
        }
        delete[] m_members;
    }

    Team::Team(const Team& other) : m_name(other.m_name), m_count(other.m_count) {
        m_members = new Character * [m_count];
        for (size_t i = 0; i < m_count; i++)
            m_members[i] = other.m_members[i]->clone();
    }

    Team& Team::operator=(const Team& other) {
        if (this != &other) {
            for (size_t i = 0; i < m_count; i++)
                delete m_members[i];
            delete[] m_members;

            m_name = other.m_name;
            m_count = other.m_count;
            m_members = new Character * [m_count];
            for (size_t i = 0; i < m_count; i++)
                m_members[i] = other.m_members[i]->clone();
        }
        return *this;
    }

    Team::Team(Team&& other) noexcept {
        *this = std::move(other);
    }

    Team& Team::operator=(Team&& other) noexcept {
        if (this != &other) {
            for (size_t i = 0; i < m_count; i++)
                delete m_members[i];
            delete[] m_members;

            m_name = std::move(other.m_name);
            m_members = other.m_members;
            m_count = other.m_count;

            other.m_members = nullptr;
            other.m_count = 0;
        }
        return *this;
    }

    bool Team::exists(const std::string& name) const {
        for (size_t i = 0; i < m_count; i++) {
            if (m_members[i]->getName() == name) return true;
        }
        return false;
    }

    void Team::addMember(const Character* c) {
        if (!exists(c->getName())) {
            Character** tmp = new Character * [m_count + 1];
            for (size_t i = 0; i < m_count; i++)
                tmp[i] = m_members[i];
            tmp[m_count] = c->clone();
            delete[] m_members;
            m_members = tmp;
            m_count++;
        }
    }

    void Team::removeMember(const std::string& name) {
        for (size_t i = 0; i < m_count; i++) {
            if (m_members[i]->getName() == name) {
                delete m_members[i];
                for (size_t j = i; j < m_count - 1; j++)
                    m_members[j] = m_members[j + 1];
                m_count--;
                Character** tmp = nullptr;
                if (m_count > 0) {
                    tmp = new Character * [m_count];
                    for (size_t j = 0; j < m_count; j++)
                        tmp[j] = m_members[j];
                }
                delete[] m_members;
                m_members = tmp;
                break;
            }
        }
    }

    Character* Team::operator[](size_t idx) const {
        return idx < m_count ? m_members[idx] : nullptr;
    }

    void Team::showMembers() const {
        if (m_count == 0)
            std::cout << "No team." << std::endl;
        else {
            std::cout << "[Team] " << m_name << std::endl;
            for (size_t i = 0; i < m_count; i++) {
                std::cout << "    " << (i + 1) << ": " << *m_members[i] << std::endl;
            }
        }
    }
}
