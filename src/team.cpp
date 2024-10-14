//Name- Jeevan Victor Varghese
//ID- 142216225
//SEC-NCC
//Date- 10/13/2024

#include "team.h"
using namespace std;
namespace seneca
{

	//UTILITY
	//start
	int Team::findNameIndex(const string& c)
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
	//END
	/*Team::Team()
	{
		m_size = 0;
		m_capacity = 0;
		m_name = " ";
		m_members = nullptr;
	}*/

	Team::Team(const char* name)
	{
		m_size = 0; 
		m_capacity = 0;
		m_members = nullptr;
		m_name = name;
	}

	Team::Team(const Team& other)
	{
		m_size = other.m_size;
		m_capacity = other.m_capacity;
		m_members = new Character * [m_capacity];
		for (size_t i = 0; i < m_size; i++)
		{
			m_members[i] = other.m_members[i]->clone();
		}
		m_name = other.m_name;
	}

	Team& Team::operator=(const Team& other)
	{
		if (this != &other)
		{
			for (size_t i = 0; i < m_size; i++)
			{
				delete m_members[i];
			}

			m_size = other.m_size;
			m_capacity = other.m_capacity;
			m_name = other.m_name;
			delete[]m_members;
			m_members = new Character * [m_capacity];
			for (size_t i = 0; i < m_size; i++)
			{
				m_members[i] = other.m_members[i]->clone();
			}
		}
		return *this;

	}
	Team::Team(Team&& other) noexcept
	{
		m_size = other.m_size;
		m_capacity = other.m_capacity;
		m_members = other.m_members;
		m_name = other.m_name;
		other.m_members = nullptr;
		other.m_size = 0;
		other.m_name = "";
		other.m_capacity = 0;
	}

	Team& Team::operator=(Team&& other) noexcept
	{

		if (this != &other)
		{
			for (size_t i = 0; i < m_size; i++)
			{
				delete m_members[i];
			}
			delete[]m_members;
			m_size = other.m_size;
			m_capacity = other.m_capacity;
			m_name = other.m_name;
			m_members = other.m_members;
			other.m_members = nullptr;
			other.m_size = 0;
			other.m_name = "";
			other.m_capacity = 0;
		}
		return *this;
	}
	Team::~Team()
	{
		for (size_t i = 0; i < m_size; i++)
		{
			delete m_members[i];
		}
		delete[] m_members;
	}

	

	void Team::addMember(const Character* c)
	{
		if (findNameIndex(c->getName()) == -1)
		{
			if (m_size == m_capacity)
			{
				// increase size
				m_capacity = (m_capacity == 0) ? 1 : m_capacity * 2;
				// resize
				Character** resize = new Character * [m_capacity];
				for (size_t i = 0; i < m_size; i++)
				{
					resize[i] = m_members[i];
				}
				delete[] m_members;
				m_members = resize;
			}
			m_members[m_size++] = c->clone();
		}
	}

	void Team::removeMember(const std::string& c)
	{
		int index = findNameIndex(c);
		if (index != -1)
		{
			delete m_members[index];
			for (size_t i = index; i < m_size - 1; i++)
			{
				//it sends the empty slot to the back of array
				m_members[i] = m_members[i + 1];
			}
			m_size--;
		}
		else
		{
			return;
		}
	}
	Character* Team::operator[](size_t idx)const
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
	void Team::showMembers() const
	{
		if (m_capacity == 0)
		{
			cout << "No team." << endl;
		}
		else
		{
			//cout << m_name << " TEAM_NAME" << endl;
			cout <<"[Team] " << m_name << endl;
			for (size_t i = 0; i < m_size; i++)
			{ 
				cout << "    " << (i + 1) << ": "<< *m_members[i] << endl;
			}
		}
	}
}