/*thiago de lira - batalha pokemon   12-05 v1*/
/*thiago de lira - batalha pokemon   22-05 v2*/

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

      POK Voltorb(4,60,5,4,3,"Voltorb","Electric"),Pikachu(7,80,6,5,8,"Pikachu","Electric");
      POK Psyduck(3,50,4,7,5,"Psyduck","Water"),Golduck(8,90,5,8,7,"Golduck","Water");
      POK Ninetales(7,70,8,5,6,"Ninetales","Fire"),Charizard(9,80,4,7,9,"Charizard","Fire");
      POK Butterfee(6,50,8,3,6,"Butterfee","Flying"),Spearow(8,70,9,4,7,"Spearow","Flying");
      POK Alakazam(7,80,4,5,9,"Alakazam","Psychic"),MrMime(8,70,4,9,7,"MrMime","Psychic");
      POK Golem(7,90,3,8,7,"Golem","Rock"),Kabutops(9,70,6,9,8,"Kabutops","Rock");
