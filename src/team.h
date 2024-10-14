//Name- Jeevan Victor Varghese
//ID- 142216225
//SEC-NCC
//Date- 10/13/2024

#ifndef SENECA_TEAM_H
#define SENECA_TEAM_H
#include "character.h"

using namespace std;
namespace seneca
{
	class Team
	{
		size_t m_size = 0;
		size_t m_capacity = 0;
		Character** m_members;
		string m_name;

	public:
		Team()=default;
		Team(const char* name);
		//rule of 5
		//copy construcor
		Team(const Team& other);
		Team& operator=(const Team& other);
		//move
		Team( Team&& other)noexcept;
		Team& operator=( Team&& other)noexcept;
		//destructor
		~Team();

		

		void addMember(const Character* c);
		void removeMember(const std::string& c);
		Character* operator[](size_t idx) const;
		void showMembers() const;


		//UTILITY

		int findNameIndex(const string& c);
	};
}
#endif // !SENECA_TEAM_H
