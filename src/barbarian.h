//Name- Jeevan Victor Varghese
//ID- 142216225
//SEC-NCC
//Date- 10/13/2024


#ifndef SENECA_BARBARIAN_H
#define SENECA_BARBARIAN_H
#include "characterTpl.h"
namespace seneca
{
	template <typename T, typename Ability_t,typename Weapon_t>
	class Barbarian : public  CharacterTpL<T>
	{
		int m_baseAttack;
		int m_baseDefense;
		Ability_t m_ability;
		//Sword and Bow are the weapons handled by barbarian
		Weapon_t m_weapon[2];

	public:
		Barbarian(const char* name, int healthMax, int baseAttack, int baseDefense, Weapon_t primaryWeapon, Weapon_t secondaryWeapon) : CharacterTpL<T>(name, healthMax)
		{

			m_baseAttack = baseAttack;
			m_baseDefense = baseDefense;

			m_weapon[0] = primaryWeapon;
			m_weapon[1] = secondaryWeapon;
		}		
		int getAttackAmnt() const
		{
			return m_baseAttack + (static_cast<double>(m_weapon[0]) / 2 + static_cast<double>(m_weapon[1]) / 2);
		}

		int getDefenseAmnt() const
		{
			return m_baseDefense;
		}
		Character* clone() const
		{
			return new Barbarian(*this);

		}
		
		void attack(Character* enemy)
		{
			std::cout << CharacterTpL<T>::getName() << " is attacking "	<< enemy->getName() << ".\n";
			m_ability.useAbility(this);
			int dmg = getAttackAmnt();
			m_ability.transformDamageDealt(dmg);
			cout << "    Barbarian deals " << dmg << " melee damage!" << endl;
			enemy->takeDamage(dmg);
		}
		void takeDamage(int dmg)
		{
			cout << CharacterTpL<T>::getName() << " is attacked for " << dmg << " damage." << endl;
			cout << "    Barbarian has a defense of " << getDefenseAmnt() << ". Reducing damage received." << endl;
			dmg -= getDefenseAmnt();
			//The new value cannot be less than 0.
			if (dmg < 0)
			{
				dmg = 0;
			}
			m_ability.transformDamageReceived(dmg);
			CharacterTpL<T>::takeDamage(dmg);

		}

	};	
}

#endif