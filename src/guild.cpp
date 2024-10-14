//Name- Jeevan Victor Varghese
//ID- 142216225
//SEC-NCC
//Date- 10/13/2024

#include "guild.h"
using namespace std;
namespace seneca
{
	int Guild::findNameIndex(const string & c)
	{
		for (size_t i = 0; i < m_size; i++)
		{
			if (m_members[i]->getName() == c)
			{
				return i;
			}
		}
		return -1;
	}
	Guild::Guild(const char* name)
	{
		m_guildName = name;
		m_size = 0;
		m_capacity = 0;
		m_members =nullptr;
	}

	Guild::Guild(const Guild& other)
	{
		m_guildName = other.m_guildName;
		m_size = other.m_size;
		m_capacity = other.m_capacity;
		m_members = new Character * [m_capacity];
		for (size_t i = 0; i < m_size; i++)
		{
			m_members[i] = other.m_members[i];
		}

	}
	Guild& Guild::operator=(const Guild& other)
	{
		if (this != &other)
		{
			delete[]m_members;
			m_size = other.m_size;
			m_capacity = other.m_capacity;
			m_guildName = other.m_guildName;
			/*for (size_t i = 0; i < m_size; i++)
			{
				delete[]m_members;
			}*/
			m_members = new Character * [m_capacity];
			for (size_t i = 0; i < m_size; i++)
			{
				m_members[i] = other.m_members[i];
			}

		}
		return *this;
	}
	Guild::Guild(Guild&& other)noexcept
	{
		m_guildName = other.m_guildName;
		m_size = other.m_size;
		m_capacity = other.m_capacity;
		//m_members = new Character * [m_capacity];
		//
		m_members = other.m_members;

		other.m_capacity = 0;
		other.m_size = 0;
		other.m_guildName = "";
		other.m_members = nullptr;

	}
	Guild &Guild::operator=(Guild&& other)noexcept
	{
		if (this != &other)
		{
			m_size = other.m_size;
			m_capacity = other.m_capacity;
			m_guildName = other.m_guildName;
			delete[]m_members;
			m_members = other.m_members;

			other.m_capacity = 0;
			other.m_size = 0;
			other.m_guildName = "";
			other.m_members = nullptr;

		}
		return *this;
	}
	Guild::~Guild()
	{
		delete[] m_members;
		m_members = nullptr;
	}
	void Guild::addMember(Character* c)
	{
		if (findNameIndex(c->getName())!=-1)
		{
			return ;
		}

		if (m_size == m_capacity)
		{
			m_capacity = (m_capacity == 0) ? 1 : m_capacity * 2;
			Character** resized = new Character * [m_capacity];
			for (size_t i = 0; i < m_size; i++)
			{
				resized[i] = m_members[i];
			}
			delete[] m_members;
			m_members = resized;
		}


		//c->getHealthMax()
		c->setHealthMax((c->getHealthMax()) + 300);
		//set to increased
		c->setHealth(c->getHealthMax());
		m_members[m_size++] = c;


	}
	void Guild::removeMember(const std::string& c)
	{
		int index = findNameIndex(c);
		if (index != -1)
		{
			//before removing reduce health
			m_members[index]->setHealthMax(m_members[index]->getHealthMax() - 300);
			//set the health'
			m_members[index]->setHealth(m_members[index]->getHealthMax());

			for (size_t i = index; i < m_size; i++)
			{
				m_members[i] = m_members[i + 1];
			}
			m_size--;
		}
		else
		{
			return;
		}
	}

	Character* Guild::operator[](size_t idx)const
	{
		if (idx > m_size)
		{
			return nullptr;
		}
		else
		{
			return m_members[idx];
		}
	}

	void Guild::showMembers() const
	{
		if (m_guildName.empty())
		{
			// If the guild name is empty, don't print anything
			cout << "No guild.\n";
			return;
		}

		/*if (m_capacity == 0)
		{
			cout << "No Guild."<< "\n";
			return;
		}*/

		cout << "[Guild] " << m_guildName << "\n";
		for (size_t i = 0; i < m_size; i++)
		{
			cout << "    " << i + 1 << ": " << *m_members[i] << "\n";
		}
	}
}
