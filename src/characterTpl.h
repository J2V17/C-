//Name- Jeevan Victor Varghese
//ID- 142216225
//SEC-NCC
//Date- 10/13/2024

#ifndef SENECA_CHARACTERTPL_H
#define SENECA_CHARACTERTPL_H
#include <iostream>
#include "character.h"

namespace seneca
{
	template<typename T>
	class CharacterTpL : public Character
	{
		int m_healthMax;
		T m_health;


	public:
		CharacterTpL(const char* name, int healthMax) : Character(name)
		{
			m_healthMax = healthMax;
			//m_health(static_cast<T>(healthMax);
			m_health = static_cast<int>(m_healthMax);
		}
		void takeDamage(int dmg) override
		{
			m_health = m_health -(dmg);
			if (m_health < 0)
			{
				m_health = 0;
			}
			//	std::cout << getName() << "has been defeated!" << std::endl;
			if (Character::isAlive() == true)
			{
				cout <<"    " << Character::getName() << " took " << dmg
					<< " damage, " << getHealth() << " health remaining.\n";
			}
			else
			{
				cout << "    " << Character::getName() << " has been defeated!\n";
			}
			
			
		}
		int getHealth() const override
		{
			return static_cast<int>(m_health);
		}
		int getHealthMax() const override
		{
			return m_healthMax;
		}
		void setHealth(int health) override
		{
			m_health = health;
		}
		void setHealthMax(int health) override
		{
			m_healthMax = health;
			m_health = health;
		}

	};
}

#endif