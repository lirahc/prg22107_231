#include<iostream>
#include<stdlib.h>
#include<string.h>

using namespace std;

int user_score=0,cpu_score=0;

void pok_logo(void);
void pok_assign(void);
void pok_display(void);
void pok_display(int);
void  play(int);

class POK
{
	private:
		int power;
		float health;
		int speed;
		int defence;
		int offence;
		char name[10];

	public:
		int pow(){return power;}
		float hlt(){return health;}
		int spd(){return speed;}
		int def(){return defence;}
		int off(){return offence;}
		char *getname(){return name;};
		void special(int);
		void attack(int);
		void defend(int);
		void agility(int);

		POK(){}

		POK(int p, float h,int s,int d,int o,char n[10])
		{
			power=p;
			health=h;
			speed=s;
			defence=d;
			offence=o;
			strcpy(name,n);
		}

};