#include <string>
#include <iostream>
#include <vector>


using namespace std;
class Unit
{
protected:
	int   level, averageDamage;
	
public :
	string name;
	int hp, maxHp;
	int Hit()
	{
		int b = rand() % 2;
		if (b)
		{
			return averageDamage + rand() % 10;
		}
		else
		{
			return averageDamage - rand() % 6;
		}
	}
};
class Hero :public Unit
{

public:
	int experience, expToNextLevel;
	Hero(string name)
	{
		this->name = name;
		level = 1;
		hp = 100;
		experience = 0;
		expToNextLevel = 100;
		averageDamage = 15;
		maxHp = hp;
	}
	Hero()
	{
		this->name = "Peter";
	}
	void LevelUp()
	{
		
		level++;
		experience = 0;
		expToNextLevel *= 2;
		averageDamage *= 2;
		maxHp *= 2;

	}
	void ShowParams()
	{
		cout << "Level: " << level<<endl;
		cout << "Max Health Points: " << maxHp << endl;
		cout << "Average Damage: " << averageDamage << endl;
		cout << "Experience to next level:" << expToNextLevel << endl;
	}
	

};
class Monster : public Unit
{
public:
	int givenExp;
	Monster(string name)
	{
		this->name = name;
		level = 1;
		hp = 100;
		averageDamage = 7;
		givenExp = 50;
	}
	void LevelUp()
	{
		level++;
		averageDamage *= 3 / 2;
		maxHp *= 4 / 3;
		givenExp *= 3 / 2;
	}
};
class Game
{
private:
	Hero* hero;
	vector<Monster> monsters;
	void PrintMonsters(vector<Monster> monsters)
	{
		for (int i = 0; i < monsters.size(); i++)
		{
			cout<< (i+1)<<". "<<monsters[i].name<< " - "<<monsters[i].hp<<" hp" << endl;

		}
	}
public:
	Game(Hero* hero)
	{
		this->hero = hero;
	}
	void Battle()
	{
		bool won;
		string choise = "";
		int n, whichMonsterToHit, earnedExp=0;
		cout << "Welcome to IceWar world, " << hero->name << "!" << endl;
		while (choise !="quit")
		{
			won = false;
			earnedExp = 0;
			monsters = vector<Monster>();
			hero->hp = hero->maxHp;
			cout << "Choose a number of monsters which you want to fight with! Remember that they are really strong." << endl;
			cin >> n;
			for (int i = 0; i < n; i++)
			{
				monsters.push_back(Monster("Vurdalak"));

			}
			while (won==false)
			{
				cout << "You: " << hero->name << " hp: " << hero->hp << endl;
				PrintMonsters(monsters);
				cout << "choose a monster which would you like to hit: (hint: use their positions)" << endl;
				cin >> whichMonsterToHit;
				for (int i = 0; i < monsters.size(); i++)
				{
					if (whichMonsterToHit == (i + 1))
					{
						monsters[i].hp -= hero->Hit();
						hero->hp -= monsters[i].Hit();
						if (hero->hp < 0)
							hero->hp = 0;
						if (monsters[i].hp < 0)
							monsters[i].hp = 0;
					}
				}
				for (int i = 0; i < monsters.size(); i++)
				{
					if (monsters[i].hp > 0)
					{
						won = false;
						break;

					}
					else
						won = true;
				}
				if (hero->hp == 0)
					break;

			}
			if (won)
			{
				for (int i = 0; i < monsters.size(); i++)
				{
					earnedExp += monsters[i].givenExp;
				}
				hero->experience += earnedExp;
				cout << "You have got " << earnedExp << "points of experience in this battle!"<<endl<<" To next level you need " << (hero->expToNextLevel - hero->experience) << "points more."<<endl;

			}
			if (hero->experience >= hero->expToNextLevel)
			{
				hero->LevelUp();
				cout << "Congratulations! You have got levelUp!" << endl << "Your current parameters is:" << endl;
				hero->ShowParams();
			}
			cout << "Use 'quit' command to quit the game either you will battle one more time"<<endl;
			cin >> choise;
			
			
		}
	}
};
int main(void) {
	Hero* hero = new Hero("Roman");
	Game game(hero);
	game.Battle();
	return 0;
}
