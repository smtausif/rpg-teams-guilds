// Name: SM Tausif
// Seneca Email: stausif@myseneca.ca
// Student ID: 187699236
// Date: 11.06.25

// I declare that this submission is the result of my own work and I only copied the code that my professor provided to complete my assignments. This submitted piece of work has not been shared with any other student or 3rd party content provider.

#include "guild.h"

namespace seneca {

    Guild::Guild() : m_name{}, m_members{nullptr}, m_count{0} {}

    Guild::Guild(const char* name) : m_name(name), m_members{nullptr}, m_count{0} {}

    Guild::~Guild() {
        delete[] m_members;
    }

    Guild::Guild(const Guild& other) : m_name(other.m_name), m_count(other.m_count) {
        m_members = new Character*[m_count];
        for (size_t i = 0; i < m_count; i++)
            m_members[i] = other.m_members[i];
    }

    Guild& Guild::operator=(const Guild& other) {
        if (this != &other) {
            delete[] m_members;
            m_name = other.m_name;
            m_count = other.m_count;
            m_members = new Character*[m_count];
            for (size_t i = 0; i < m_count; i++)
                m_members[i] = other.m_members[i];
        }
        return *this;
    }

    Guild::Guild(Guild&& other) noexcept : m_name(std::move(other.m_name)), m_members(other.m_members), m_count(other.m_count) {
        other.m_members = nullptr;
        other.m_count = 0;
    }

    Guild& Guild::operator=(Guild&& other) noexcept {
        if (this != &other) {
            delete[] m_members;

            m_name = std::move(other.m_name);
            m_members = other.m_members;
            m_count = other.m_count;

            other.m_members = nullptr;
            other.m_count = 0;
        }
        return *this;
    }

    void Guild::addMember(Character* c) {
        for (size_t i = 0; i < m_count; i++) {
            if (m_members[i]->getName() == c->getName()) return;
        }
        Character** temp = new Character*[m_count + 1];
        for (size_t i = 0; i < m_count; i++)
            temp[i] = m_members[i];
        temp[m_count] = c;
        delete[] m_members;
        m_members = temp;
        m_count++;

        c->setHealthMax(c->getHealthMax() + 300);
    }

    void Guild::removeMember(const std::string& name) {
        for (size_t i = 0; i < m_count; i++) {
            if (m_members[i]->getName() == name) {
                m_members[i]->setHealthMax(m_members[i]->getHealthMax() - 300);
                for (size_t j = i; j < m_count - 1; j++)
                    m_members[j] = m_members[j + 1];
                m_count--;
                Character** temp = nullptr;
                if (m_count > 0) {
                    temp = new Character*[m_count];
                    for (size_t j = 0; j < m_count; j++)
                        temp[j] = m_members[j];
                }
                delete[] m_members;
                m_members = temp;
                break;
            }
        }
    }

    Character* Guild::operator[](size_t idx) const {
        return idx < m_count ? m_members[idx] : nullptr;
    }

    void Guild::showMembers() const {
        if (m_name.empty()) {
            std::cout << "No guild." << std::endl;
        } else {
            std::cout << "[Guild] " << m_name << std::endl;
            for (size_t i = 0; i < m_count; i++) {
                std::cout << "    " << (i + 1) << ": " << *m_members[i] << std::endl;
            }
        }
    }
}
