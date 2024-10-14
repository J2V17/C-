//Name- Jeevan Victor Varghese
//ID- 142216225
//SEC-NCC
//Date- 10/13/2024

#ifndef SENECA_ROGUE_H
#define SENECA_ROGUE_H
#include "characterTpl.h"
#include "weapons.h"
using namespace std;
namespace seneca
{
	template <typename T, typename FirstAbility_t, typename SecondAbility_t>
	class Rogue : public CharacterTpL<T>
	{
		int m_baseDefense;
		int m_baseAttack;
		FirstAbility_t m_firstAbility;
		SecondAbility_t m_secondAbility;
		seneca::Dagger m_weapon;

	public:
			Rogue(const char* name, int healthMax, int baseAttack, int baseDefense):CharacterTpL<T>(name, healthMax)
		{
			m_baseAttack = baseAttack;
			m_baseDefense = baseDefense;
		}

		int getAttackAmnt()const
		{
			return m_baseAttack + 2 * (static_cast<double>(m_weapon));
		}
		int getDefenseAmnt() const
		{
			return m_baseDefense;
		}
		Character* clone() const
		{
			return new Rogue(*this);
		}

		void attack(Character* enemy)override
		{
			cout << CharacterTpL<T>::getName() << " is attacking " << enemy->getName() << "." << endl;
			m_firstAbility.useAbility(this);
			m_secondAbility.useAbility(this);
			
			int dmg = getAttackAmnt();
			m_firstAbility.transformDamageDealt(dmg);
			m_secondAbility.transformDamageDealt(dmg);

			cout << "    Rogue deals " << dmg << " melee damage!" << endl;
			enemy->takeDamage(dmg);
				
		}

		void takeDamage(int dmg)
		{
			cout << CharacterTpL<T>::getName() << " is attacked for " << dmg << "." << endl;
			cout << "    Rogue has a defense of " << m_baseDefense << ". Reducing damage received." << endl;
			dmg -= m_baseDefense;
			if (dmg < 0)
			{
				dmg = 0;
			}
			m_firstAbility.transformDamageReceived(dmg);
			m_secondAbility.transformDamageReceived(dmg);
			CharacterTpL<T>::takeDamage(dmg);
		}


		};
}
#endif // !SENECA_ROGUE_H
