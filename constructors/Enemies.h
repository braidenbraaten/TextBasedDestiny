#pragma once
#include <iostream>
#include <cmath>
#include <ctime>
#include <string>
using namespace std;

enum enemyTypes  { FALLEN   , HIVE         , VEX           , CABAL                                              };
enum fallenTypes { DREG     , VANDAL       , STEALTH_VANDAL, CAPTAIN , SHANK   , SERVITOR , SKIFF               };
enum hiveTypes   { THRALL   , CURSED_THRALL, ACOLYTE       , KNIGHT  , WIZARD  , OGRE     , SHRIEKER, TOMB_SHIP };
enum vexTypes    { GOBLIN   , HOBGOBLIN    , HARPY         , HYDRA   , MINOTAUR                                 };
enum cabalTypes  { LEGIONARY, PHALANX      , CENTURION     , COLOSSUS, PSION   , HARVESTER                      };

class Enemy
{
	//Level and Experience give out
	string catagory;
	string name;
	string combinedName;
	int xp, level;
	//basic stats
	float health, damage, shield;
	//Scaling things
	float  levelScale = 1, damageScale = 1, xpScale = 1, healthScale = 1, shieldScale = 1;
	int eType; // enemy type

			   //struct = big container

public:
	//what catagory of enemy
	Enemy(enemyTypes a)
	{
		//different RNG's required for the various amounts of enemy types in each enum
		int RNG_FALLEN = rand() % 6;
		int RNG_HIVE   = rand() % 7;
		int RNG_VEX    = rand() % 4;
		int RNG_CABAL  = rand() % 5;
		switch (a)
		{
		case FALLEN:
			catagory = " Fallen";
			switch (RNG_FALLEN)
			{
				//{ DREG, VANDAL, STEALTH_VANDAL, CAPTAIN, SHANK, SERVITOR, SKIFF };
			case DREG:
				name = " Dreg";
				health = 5  * healthScale;
				damage = 2   * damageScale;
				shield = 100 * shieldScale;
				xp     = 5   * xpScale;
				break;
			case VANDAL:
				name = " Vandal";
				health = 5  * healthScale;
				damage = 3   * damageScale;
				shield = 150 * shieldScale;
				xp     = 10  * xpScale;

			case STEALTH_VANDAL:
				name = " Stealth Vandal";
				xp     = 15  * xpScale;
				break;
			case CAPTAIN:
				name = " Captain";
				health = 5  * healthScale;
				damage = 4   * damageScale;
				shield = 150 * shieldScale;
				xp	   = 20  * xpScale;
				break;
			case SHANK:
				name = " Shank";
				health = 5 * healthScale;
				damage = 2  * damageScale;
				shield = .5 * shieldScale;
				xp	   = 5  * xpScale;
				break;
			case SERVITOR:
				name = " Servitor";
				health = 5 * healthScale;
				damage = 4 * damageScale;
				shield = 2  * shieldScale;
				xp	   = 25 * xpScale;
				break;
			case SKIFF:
				name = " Skiff";
				health = 5 * healthScale;
				damage = 2  * damageScale;
				shield = .5 * shieldScale;
				xp	   = 5  * xpScale;
				break;
			}
			break;
		case HIVE:
			catagory = " Hive";
			switch (RNG_HIVE)
			{
			case THRALL:
				name = " Thrall";
				health = 10  * healthScale;
				damage = 2   * damageScale;
				shield = 100 * shieldScale;
				xp	   = 5   * xpScale;
				break;
			case CURSED_THRALL:
				name = " Cursed Thrall";
				health = 2  * healthScale;
				damage = 5  * damageScale;
				shield = 50 * shieldScale;
				xp	   = 10 * xpScale;
				break;
			case ACOLYTE:
				name = " Acolyte";
				health = 15  * healthScale;
				damage = 3   * damageScale;
				shield = 150 * shieldScale;
				xp	   = 15  * xpScale;
				break;
			case KNIGHT:
				name = " Knight";
				health = 20  * healthScale;
				damage = 4   * damageScale;
				shield = 100 * shieldScale;
				xp	   = 20  * xpScale;
				break;
			case WIZARD:
				name = " Wizard";
				health = 2   * healthScale;
				damage = 4   * damageScale;
				shield = 200 * shieldScale;
				xp	   = 25  * xpScale;
				break;
			case OGRE:
				name = " Ogre";
				health = 20  * healthScale;
				damage = 3   * damageScale;
				shield = 100 * shieldScale;
				xp	   = 25  * xpScale;
				break;
			case SHRIEKER:
				name = " Shrieker";
				health = 15  * healthScale;
				damage = 4   * damageScale;
				shield = 300 * shieldScale;
				xp	   =  35 * xpScale;
				break;
			case TOMB_SHIP:
				name = " Tomb Ship";
				health = 10 * healthScale;
				damage = 2  * damageScale;
				shield = 50 * shieldScale;
				xp	   = 5  * xpScale;
				break;
			}
			break;
		case VEX:
			catagory = " Vex";
			switch (RNG_VEX)
			{
			case GOBLIN:
				health = 10  * healthScale;
				damage = 2   * damageScale;
				shield = 100 * shieldScale;
				xp	   = 5   * xpScale;
				break;
			case HOBGOBLIN:
				health = 5   * healthScale;
				damage = 4   * damageScale;
				shield = 150 * shieldScale;
				xp	   = 10  * xpScale;
				break;
			case HARPY:
				health = 10  * healthScale;
				damage = 3   * damageScale;
				shield = 200 * shieldScale;
				xp	   = 15  * xpScale;
				break;
			case HYDRA: 
				health = 20  * healthScale;
				damage = 3   * damageScale;
				shield = 200 * shieldScale;
				xp	   = 35  * xpScale;
				break;
			case MINOTAUR:
				health = 15  * healthScale;
				damage = 3   * damageScale;
				shield = 150 * shieldScale;
				xp	   = 20  * xpScale;
				break;
			}
			break;
		case CABAL:
			catagory = " Cabal";
			switch (RNG_CABAL)
			{
			case LEGIONARY:
				name = " Legionary";
				health = 10  * healthScale;
				damage = 2   * damageScale;
				shield = 100 * shieldScale;
				xp	   = 5   * xpScale;
				break;
			case PHALANX:
				name = " Phalanx";
				health = 10  * healthScale;
				damage = 3   * damageScale;
				shield = 200 * shieldScale;
				xp	   = 10  * xpScale;
				break;
			case CENTURION:
				name = " Centurion";
				health = 15  * healthScale;
				damage = 3   * damageScale;
				shield = 250 * shieldScale;
				xp	   = 20  * xpScale;
				break;
			case COLOSSUS:
				name = " Colossus";
				health = 15  * healthScale;
				damage = 4   * damageScale;
				shield = 150 * shieldScale;
				xp	   = 30  * xpScale;
				break;
			case PSION:
				name = " Psion";
				health = 5   * healthScale;
				damage = 4   * damageScale;
				shield = 200 * shieldScale;
				xp	   = 15  * xpScale;
				break;
			case HARVESTER:
				name = " Harvester";
				health = 10  * healthScale;
				damage = 2   * damageScale;
				shield = 100 * shieldScale;
				xp	   = 5   * xpScale;
				break;
			}
			break;
		}

		combinedName = catagory + name;

	}

	//Setting this scale will set all of the scales to that scale
	void SetScaleForPlanet(float globalScale)
	{
		healthScale = globalScale;
		health = health * healthScale;
		damageScale = globalScale;
		damage = damage * damageScale;
		shieldScale = globalScale;
		shield = shield * shieldScale;
		xpScale = globalScale;
		xp = xp * xpScale;
	}


	string getEnemyName() { return name; }
	string getEnemyCatagory() { return catagory; }
	string getCombinedName() { return combinedName; }

	//Enemy Health
	int getEnemyHealth()					   { return health; }
	void setEnemyHealth(int newHp)			   { health = newHp; }
	int getEnemyHealthScale()				   { return healthScale; }
	void setEnemyHealthScale(float newHpScale) { healthScale = newHpScale; }


	//Enemy Damage
	int getEnemyDamage()						   { return damage; }
	void setEnemyDamage(int newDamage)			   { damage = newDamage; }
	int getEnemyDamageScale()					   { return damageScale; }
	void setEnemyDamageScale(float newDamageScale) { damageScale = newDamageScale; }

	//Enemy Shields
	int getEnemyShield()							    { return shield; }
	void setEnemyShield(int newShieldAmount)			{ shield = newShieldAmount; }
	int getEnemyShieldScale()							{ return shieldScale; }
	void setEnemyShieldScale(float newEnemyShieldScale) { shieldScale = newEnemyShieldScale; }

	//Enemy xp
	int getEnemyXP()				{ return xp; }
	void setEnemyXP(int newEnemyXP) { xp = newEnemyXP; }


	//Enemy Stats Scaling
	int getEnemyScale()				 { return levelScale; }
	void setEnemyScale(int newScale) { levelScale = newScale; }
};
