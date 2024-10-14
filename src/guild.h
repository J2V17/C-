//Name- Jeevan Victor Varghese
//ID- 142216225
//SEC-NCC
//Date- 10/13/2024

#ifndef SENECA_GUILD_H
#define SENECA_GUILD_H
#include "character.h"
#include <string>
using namespace std;
namespace seneca
{
	class Guild
	{
		size_t m_size=0;
		size_t m_capacity=0;
		std::string m_guildName;
		Character** m_members= nullptr;	

	public:
		Guild() = default;
		Guild(const char* name);
		Guild(const Guild&);
		Guild& operator=(const Guild&);
		Guild(Guild&&) noexcept;
		Guild& operator=(Guild&&) noexcept;
		~Guild();

		void addMember(Character* c);
		void removeMember(const std::string& c);
		Character* operator[](size_t idx) const;
		void showMembers()const;

		//utility
		int findNameIndex(const string& c);
	};
	

}
#endif // !SENECA_GUILD_H
