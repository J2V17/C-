//Name- Jeevan Victor Varghese
//ID- 142216225
//SEC-NCC
//Date- 10/13/2024

#ifndef SENECA_ARCHER_H
#define SENECA_ARCHER_H
#include "characterTpl.h"

using namespace std;
namespace seneca
{
	template <typename Weapon_t>
	class Archer:public CharacterTpL<seneca::SuperHealth>
	{
		int m_baseDefense;
		int m_baseAttack;
		Weapon_t m_weapon;


	public:
		Archer(const char* name, int healthMax, int baseAttack, int baseDefense, Weapon_t weapon):CharacterTpL<SuperHealth>(name, healthMax)
		{
			m_baseDefense = baseDefense;
			m_baseAttack = baseAttack;
			m_weapon = weapon;
		}
		int getAttackAmnt() const
		{
			return 1.3 * m_baseAttack;
		}
		int getDefenseAmnt() const
		{
			return 1.2 * m_baseDefense;
		}
		Character* clone()const
		{
			return new Archer(*this);
		}
		void attack(Character* enemy)
		{
			cout << CharacterTpL<SuperHealth>::getName() << " is attacking " << enemy->getName() << "." << endl;
			int dmg = getAttackAmnt();
			cout << "Archer deals " << dmg << " ranged damage!" << endl;
			//applyuing damage to the enemy
			enemy->takeDamage(dmg);
		}

		void takeDamage(int dmg)
		{
			cout << CharacterTpL<SuperHealth>::getName() << " is attacked for " << dmg << " damage." << endl;
			cout << "    Archer has a defense of " << m_baseDefense << "." << " Reducing damage received.";
		
			dmg -= getDefenseAmnt();
			if (dmg < 0)
			{
				dmg = 0;
			}
			CharacterTpL<SuperHealth>::takeDamage(dmg);
			
		}
	};
}
#endif // !SENECA_ARCHER_H

