//#include "barbarian.h"
//
//namespace seneca
//{
//	template <typename T, typename Ability_t, typename Weapon_t>
//	Barbarian<T, Ability_t,Weapon_t>::Barbarian(const char* name, int healthMax, int baseAttack, int baseDefense, Weapon_t primaryWeapon, Weapon_t secondaryWeapon): CharacterTpl<T>(name,healthMax)
//	{
//
//		m_baseAttack = baseAttack;
//		m_baseDefence = baseDefence;
//	
//		m_weapon[0] = primaryWeapon;
//		m_weapon[1] = secondaryWeapon;
//	}
//
//	template <typename T, typename Ability_t, typename Weapon_t>
//	int Barbarian<T, Ability_t, Weapon_t> ::getAttackAmnt()const
//	{
//		return m_baseAttack+((static_cast <double>(m_weapon[0])/2)+ (static_cast<double>(m_weapon[1]/2)))
//	}
//	template <typename T, typename Ability_t, typename Weapon_t>
//	{
//
//	}
//
//
//}