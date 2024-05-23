#include <iostream>
#include <string>
#include <vector>
#include <random>
#include <windows.h>
#include <stdlib.h>
#include <time.h>
#include <iomanip>
using namespace std;

class Player{
public:
    string Player_Name;
    int Health, Attack, Defense, Max_Health, LVL, STR, VLR, Cash;
    float Xp, Next_Xp;
    string Player_Race;
    string Player_Sex;
    Player(const string& name, const string& race, const string sex, int Health, int Attack, int Defense, int Max_Health, float Xp, int LVL,int STR,int VLR, int money, float Next_Xp) {
        Player_Name = name;
        Player_Race = race;
        Player_Sex = sex;
        this->Health = Health;
        this->Attack = Attack;
        this->Defense = Defense;
        this->Max_Health = Max_Health;
        this->Xp = Xp;
        this->LVL = LVL;
        this-> STR = STR;
        this-> VLR = VLR;
        this-> Cash = money;
        this-> Next_Xp = Next_Xp;
    }
};

class Enemy{
public:
    string Enemy_Name;
    string Enemy_Race;
    int Health, Attack, Defense, LVL, Max_Health, Heal_Num, Heal_Effect;
    float Xp;

    Enemy(const string& name, const string race, int Health, int Attack, int Defense, int Max_Health, int Heal_Num)
    {
        Enemy_Name = name;
        Enemy_Race = race;
        this->Health = Health;
        this->Attack = Attack;
        this->Defense = Defense;
        this->Max_Health = Max_Health;
        this->Heal_Num = Heal_Num;
    }
};

class Weapon{
public:
    string Weapon_Name;
    int Weapon_Damage;
    int Weapon_Price;
    int Weapon_Num;

    Weapon(string Weapon_Name, int Weapon_Damage, int Weapon_Price, int Weapon_Num){
        this->Weapon_Name = Weapon_Name;
        this->Weapon_Damage = Weapon_Damage;
        this->Weapon_Price = Weapon_Price;
        this->Weapon_Num = Weapon_Num;
    }
};

Weapon Weapons[] = {
        Weapon("Dagger", 3, 20,0),
        Weapon("Sword", 5, 25,0),
        Weapon("Axe", 7, 30,1),
        Weapon("Halberd", 10, 35,1),
        Weapon("Great Sword", 15, 40,0),
        Weapon("Great Axe", 17, 45,1),
};

class Armor{
public:
    string Armor_Name;
    int Armor_Defense;
    int Armor_Price;
    int Armor_Num;

    Armor(string Armor_Name, int Armor_Defense, int Armor_Price, int Armor_Num){
        this->Armor_Name = Armor_Name;
        this->Armor_Defense = Armor_Defense;
        this->Armor_Price = Armor_Price;
        this->Armor_Num = Armor_Num;
    }
};

Armor Armors[] = {
        Armor("Nigga Armor Set", 10, 20,0),
        Armor("Steel Armor Set", 15, 40,0),
        Armor("Mithril Armor Set", 20, 65,1),
        Armor("Adamant Armor Set", 25, 90,1),
        Armor("Dragon Armor Set", 30, 125,0),
};

class Consumable{
public:
    string Consumable_Name;
    int Consumable_Effect;
    int Consumable_Price;
    int Consumable_Num;

    Consumable(string Consumable_Name, int Consumable_Effect, int Consumable_Price,int Consumable_Num){
        this->Consumable_Name = Consumable_Name;
        this->Consumable_Effect = Consumable_Effect;
        this->Consumable_Price = Consumable_Price;
        this->Consumable_Num = Consumable_Num;
    }
};

Consumable Consumables[] = {
        Consumable("Health Potion", 50, 5,1),
        Consumable("Mana Potion", 50, 5,0),
};

class Magic {
public:
    string tome_name;
    int tome_heal;
    int tome_price;
    int tome_dmg;
    int tome_num;

    Magic(string name, int heal, int price, int dmg, int num) {
        tome_name=name;
        tome_heal=heal;
        tome_price=price;
        tome_num=num;
        tome_dmg=dmg;
    }

    void use_tome(Magic tome,Player &player,Enemy &enemy){
        player.Health+=tome_heal;
        enemy.Health-=tome_dmg;
    }
};

Magic tome[]={
    Magic("Dark Magic",3,50,10,0), 
    Magic("Healing staff",15,10,0,0),
    Magic("Light Magic",0,25,8,0)
};

Enemy Enemies[]={
    Enemy("Dire Wolf", "Wolf", 100, 10, 5, 100,3),
    Enemy("Goblin", "Goblin", 150, 15, 10,150,3),
    Enemy("Skeleton", "Skeleton", 200, 20, 15,200,3),
    Enemy("Headless Knight", "Headless Knight", 300, 25, 20,300,3),
};

string Locations[] = {
    "Wild Forest",
    "Dark Cave",
    "Abandoned Dungeon",
    "Haunted Castle",
};

class Function_Manager{
public:
    static void inv(Player &player, Weapon Weapons[],Armor Armors[], Consumable Consumables[]){
        cout << "1.Weapons" << endl;
        cout << "2.Armor" << endl;
        cout << "3.Consumables" << endl;
        cout << "0.Back" << endl; 

        string choice;
        cin >> choice;
        if (choice.length() == 1 && choice[0] >= '0' && choice[0] <= '3') {
            switch (choice[0])
            {
                case '1':
                    inv_weapons(player, Weapons);
                    break;
                case '2':
                    inv_Armor(player, Armors);
                    break;
                case '3':
                    inv_cons(player, Consumables);
                    break;
                case '0':
                    IdleMenu(player);
                    break;
            }
        } else {
            cout << "\nInvalid choice\n\n";
            inv(player, Weapons, Armors, Consumables);
        }
    }

    static void inv_weapons(Player &player, Weapon Weapons[]) {
        string Weapon_Choice;
        
        for (int i = 0; i < 6; i++) {
            if (Weapons[i].Weapon_Num > 0) {
                cout << i + 1 << ". " << Weapons[i].Weapon_Name << " | +" << Weapons[i].Weapon_Damage << " ATK | Amount Carried: " << Weapons[i].Weapon_Num << endl;
            }
        }
        cout << "0. Back" << endl;

        cin >> Weapon_Choice;

        if (Weapon_Choice.length() == 1 && isdigit(Weapon_Choice[0])) {

            int choice = Weapon_Choice[0] - '0'; // 0 is 48 in ascii, so 48 - 48 = 0, 49 - 48 = 1, 50 - 48 = 2, etc.

            if (choice > 6 || choice < 0) {
                cout << "Invalid choice" << endl;
                inv_weapons(player ,Weapons);
            }    
            
            else if (choice == 0) {
                inv(player, Weapons, Armors, Consumables);
            }

            else if (Weapons[choice - 1].Weapon_Num > 0) {
                player.Attack = Weapons[choice - 1].Weapon_Damage + player.STR;
                cout << Weapons[choice - 1].Weapon_Name << " has been equipped\n";
                cout << "this is the attack "<< player.Attack << endl;
                inv_weapons(player, Weapons);
            }
            else if (Weapons[choice - 1].Weapon_Num == 0) {
                cout << "You don't have that weapon\n";
                inv_weapons(player, Weapons);
            }
        } else { 
            cout << "\nInvalid choice\n\n";
            inv_weapons(player, Weapons);
            }
    }

    static void inv_Armor(Player &player, Armor armor[]) {

        string Armor_Choice;

        for (int i = 0; i < 5; i++) {
            if (Armors[i].Armor_Num > 0) {
                cout << i + 1 << ". " << Armors[i].Armor_Name << " | +" << Armors[i].Armor_Defense << " DEF | Amount Carried: " << Armors[i].Armor_Num << endl;
            }
        }
        cout << "0. Back" << endl;

        cin >> Armor_Choice;

        if (Armor_Choice.length() == 1 && isdigit(Armor_Choice[0])) {
            int choice = Armor_Choice[0] - '0';

            if (choice > 5 || choice < 0) { // if choice is 6 infinite fucking defense. if choice is 7 or more it dies. cant back out when 0.
                cout << "Invalid choice" << endl;
                inv_Armor(player ,Armors);
            }

            else if (choice == 0) {
                inv(player, Weapons, Armors, Consumables);
            }

            else if (Armors[choice - 1].Armor_Num > 0) {
                player.Defense = Armors[choice - 1].Armor_Defense + player.VLR;
                cout << Armors[choice - 1].Armor_Name << " has been equipped\n";
                cout << "this is the defense "<< player.Defense << endl;
                inv_Armor(player, Armors);
            }
            else if (Armors[choice - 1].Armor_Num == 0) {
                cout << "You don't have that Armor\n";
                inv_Armor(player, Armors);
            }
        } else { 
            cout << "\nInvalid choice\n\n";
            inv_Armor(player, Armors);
            }
    }

    static void inv_cons(Player &player, Consumable[]){

        string Consumable_Choice;

        for (int i = 0; i<2; i++){
            if (Consumables[i].Consumable_Num > 0){
                cout << i+1 << ". " << Consumables[i].Consumable_Name << " | +" << Consumables[i].Consumable_Effect << " HP | Amount Carried:" << Consumables[i].Consumable_Num << endl;
            }
        }
        cout << "0. Back" << endl;
        cin >> Consumable_Choice;

        if (Consumable_Choice.length() == 1 && isdigit(Consumable_Choice[0])) {
            int choice = Consumable_Choice[0] - '0';

            if (choice > 2 || choice < 0) {
                cout << "Invalid choice" << endl;
                inv_cons(player ,Consumables);
            }

            if (choice == 0) {
                inv(player, Weapons, Armors, Consumables);
            }

            if (Consumables[choice - 1].Consumable_Num > 0) {
                if (player.Health + Consumables[choice - 1].Consumable_Effect > player.Max_Health){
                    player.Health = player.Max_Health;
                } else {
                    player.Health += Consumables[choice - 1].Consumable_Effect;
                }
                Consumables[choice - 1].Consumable_Num -= 1;
                cout << "You used " << Consumables[choice - 1].Consumable_Name << " and gained " << Consumables[choice - 1].Consumable_Effect << " HP!\n";
                inv_cons(player, Consumables);
            }

            if (Consumables[choice - 1].Consumable_Num == 0) {
                cout << "You don't have that Consumable\n";
                inv_cons(player, Consumables);
            }
        }else { 
            cout << "\nInvalid choice\n\n";
            inv_cons(player, Consumables);
            }
    }

    static void use_consumable(Player &player, Consumable[], Enemy &enemy){

        string Consumable_Choice;

        for (int i = 0; i<2; i++){
            if (Consumables[i].Consumable_Num > 0){
                cout << i+1 << ". " << Consumables[i].Consumable_Name << " | +" << Consumables[i].Consumable_Effect << " HP | Amount Carried:" << Consumables[i].Consumable_Num << endl;
            }
        }
        cout << "0. Back\n\n";
        cin >> Consumable_Choice;

        if (Consumable_Choice.length() == 1 && isdigit(Consumable_Choice[0])) {
            int choice = Consumable_Choice[0] - '0';

            if (choice > 2 || choice < 0) {
                cout << "\nInvalid choice\n\n";
                use_consumable(player, Consumables, enemy);
            }
            else if (choice == 0) {
                FightMenu(player,enemy);
            }

            else if (Consumables[choice - 1].Consumable_Num > 0) {
                if (player.Health + Consumables[choice - 1].Consumable_Effect > player.Max_Health){
                    player.Health = player.Max_Health;
                } else {
                    player.Health += Consumables[choice - 1].Consumable_Effect;
                }
                Consumables[choice - 1].Consumable_Num -= 1;
                cout << "You used " << Consumables[choice - 1].Consumable_Name << " and gained " << Consumables[choice - 1].Consumable_Effect << " HP!\n";
                EnemyReaction(player,enemy);
            }

            else if (Consumables[choice - 1].Consumable_Num == 0) {
                cout << "You don't have that Consumable\n";
                use_consumable(player, Consumables, enemy);
            }
        }else{ 
            cout << "\nInvalid choice\n\n";
            use_consumable(player, Consumables, enemy);
            }
    }

    static void IdleMenu(Player &player){
        string choice;
        cout << "\n1. Embark on an adventure\n";
        cout << "2. Inventory\n";
        cout << "3. Shop\n";
        cout << "4. Stats\n";
        cout << "5. Save\n";
        cout << "0. Quit\n";
        cin >> choice;

        if (choice.length() == 1 && choice[0] >= '0' && choice[0] <= '5') {
        switch (choice[0])
        {
            case '1':
                LocationIntro(player);
                break;
            case '2':
                inv(player, Weapons, Armors, Consumables);
                break;
            case '3':
                merchant(player);
                break;
            case '4':
                PlayerStats(player);
                break;
            case '5':
                cout << "\nPlayer progress saved\n\n";
                IdleMenu(player);
                break;
            case '0':
                cout << "\nGoodbye\n\n";
                exit(1);
                break;
        }
    } else {
        cout << "\nInvalid choice\n\n";
        IdleMenu(player);
    }
    }

    static void LocationIntro(Player &player){
        cout << "You leave the safety of the town.. Where do you go?\n";
        cout << "1. Wild Forest\n";
        cout << "2. Dark Cave\n";
        cout << "3. Abandoned Dungeon\n";
        cout << "4. Haunted Castle\n";
        string Location;
        cin >> Location;
        if (Location.length() == 1 && Location[0] >= '1' && Location[0] <= '4') {
                int choice = Location[0] - '0';
                cout << "You walk into the " << Locations[choice-1] << "...\n";
                cout << Enemies[choice-1].Enemy_Name << " Encountered!\n";

                Enemy enemy(Enemies[choice-1]);
                enemy.Xp = player.Xp*0.25;
                enemy.LVL = player.LVL+(rand()%3);
                FightMenu(player, enemy);

            } else {
            cout << "You wander somewhere else.. You found nothing and came back..\n";
            IdleMenu(player);
        }
    }


    static void PlayerStats(Player &player) {
        string XpXpNext=to_string(player.Xp)+"/"+to_string(player.Next_Xp);
        string HealthXpMaxHealth=to_string(player.Health)+"/"+to_string(player.Max_Health);
        cout << "\nName:   " << player.Player_Name << "\n";
        cout << "Race:   " << player.Player_Race << "\n";
        cout << "Sex:    " << player.Player_Sex << "\n\n";
        cout << "Cash:   " << setw(10) << setfill(' ') << left << player.Cash << "         |" << "ATK: " << setw(10) << setfill(' ') << left << player.Attack << "\n";
        cout << "XP:     " << setw(10) << setfill(' ') << left << XpXpNext <<"  |"<< "DEF: " << setw(10) << setfill(' ') << left << player.Defense << "\n";
        cout << "LVL:    " << setw(10) << setfill(' ') << left << player.LVL << "         |"<< "STR: " << setw(10) << setfill(' ') << left << player.STR << "\n";
        cout << "Health: " << setw(10) << setfill(' ') << left << HealthXpMaxHealth << "         |"<< "VLR: " << setw(10) << setfill(' ') << left << player.VLR << "\n\n";
        cout << "0.Back\n";

        int choice;
        cin >> choice;

        if (choice == 0){
            IdleMenu(player);
        }
        else
        {
            cout << "\nInvalid choice\n\n";
            PlayerStats(player);
        }
    }

    static void FightMenu(Player &player, Enemy &enemy){
        string Fight_Choice;
        string phealth;
        phealth = to_string(player.Health)+"/" +to_string(player.Max_Health);
        string ehealth;
        ehealth = to_string(enemy.Health)+"/" +to_string(enemy.Max_Health);
        cout << "Name:   "<< setw(15) << setfill(' ') << left << player.Player_Name <<"|     "<<"Enemy Name:   "<<enemy.Enemy_Name<<"\n";
        cout << "Health: " << setw(15) << setfill(' ') << left << phealth << "|     " << "Enemy Health: " << ehealth <<"\n";
        cout << "Level:  " << setw(15) << setfill(' ') << left << player.LVL << "|     " << "Enemy Level:  " << enemy.LVL <<"\n";
        cout << "1. Attack\n";
        cout << "2. Defend\n";
        cout << "3. Use Item\n";
        cout << "4. Escape\n";
        cin >> Fight_Choice;
        if (Fight_Choice.length() == 1 && Fight_Choice[0] >= '1' && Fight_Choice[0] <= '4' && isdigit(Fight_Choice[0])) {
            int choice = Fight_Choice[0] - '0';
            switch (choice)
            {
                case 1:
                    enemy.Health -= player.Attack;
                    if (enemy.Health<=0){
                        enemy.Health=0;
                    }
                    cout << "You attack the enemy dealing " << player.Attack << " damage!\n" << "Enemy Health: " << enemy.Health << "/" << enemy.Max_Health << "\n";
                    if (enemy.Health <= 0){
                        cout << "ENEMY VANQUISHED!\n";
                        cout << enemy.Xp << " XP Gained!\n";
                        player.Xp += enemy.Xp;
                        IdleMenu(player);
                    } else {
                        EnemyReaction(player, enemy);
                    }
                    break;
                case 2:
                    cout << "You prepare to defend\n";
                    break;
                case 3:
                    use_consumable(player, Consumables, enemy);
                    break;
                case 4:
                    cout << "\nYou try to escape..\n\n";
                    if (rand()%4 == 0){
                        cout << "You escaped!\n\n";
                        IdleMenu(player);
                    } else {
                        cout << "You couldn't escape!\n\n";
                        EnemyReaction(player,enemy);
                    }
                    break;
                default:
                    cout << "\nInvalid choice\n\n";
                    FightMenu(player, enemy);
                    break;
            }
        } else {
            cout << "\nInvalid choice\n\n";
            FightMenu(player, enemy);
        }
    }

    static void EnemyReaction(Player &player, Enemy &enemy){
        if (enemy.Health <= enemy.Max_Health * 0.3 && enemy.Heal_Num > 0) {
            enemy.Heal_Effect = enemy.Max_Health * 0.20;
            enemy.Health += enemy.Heal_Effect;
            enemy.Heal_Num--;
            cout << "Enemy used a healing item and gained " << enemy.Heal_Effect << " HP!\n";
            FightMenu(player, enemy);
        } else {
            int enemyAttack = enemy.Attack - player.Defense;
            if (enemyAttack <= 0) {
                enemyAttack = 1;
            }
            cout << "Enemy attacks you dealing " << enemyAttack << " damage!\n";
            player.Health -= enemyAttack;
            if (player.Health <= 0) {
                cout << "YOU HAVE BEEN DEFEATED!\n";
                // Game over logic here
            } else {
                FightMenu(player, enemy);
            }
        }
    }

    static void buy(Player &player){
        cout<<"1. View Weapons"<<endl;
        cout<<"2. View Armor"<<endl;
        cout<<"3. View Consumables"<<endl;
        cout<<"4. View Magic tomes"<<endl;

        string choice;
        int player_choice;

        cin >> choice;
        if (choice.length()== 1 && choice[0] >= '1' && choice[0] <= '4'){
            switch (choice[0]) {
            case '1':
                for(int i=0;i<5;i++) 
                {
                    cout<<i+1<<". "<<Weapons[i].Weapon_Name<<endl;
                }
                cout<<"6. Exit"<<endl;
                cin>>player_choice;

                if(player_choice==6) 
                {
                    IdleMenu(player);
                }

                else{ 
                Weapons[player_choice].Weapon_Num+=1;
                cout<<"You bought shit"<<endl;
                }
            break;

            case '2':
                for(int i=0;i<5;i++) 
                {
                    cout<<i+1<<". "<<Armors[i].Armor_Name<<endl;
                }
                cout<<"6. Exit"<<endl;
                cin>>player_choice;
                if(player_choice==6) 
                {
                    IdleMenu(player);
                }
                else
                Armors[player_choice].Armor_Num+=1;
            break;

            case '3':
                for(int i=0;i<3;i++) {
                    cout<<i+1<<". "<<Consumables[i].Consumable_Name<<endl;
                }
                cout<<"6. Exit"<<endl;
                cin>>player_choice;

                if(player_choice==6) 
                {
                    IdleMenu(player);
                }
                else
                Consumables[player_choice].Consumable_Num+=1;
            break;

            case '4':
                for(int i=0;i<4;i++) 
                {
                    cout<<i+1<<". "<<tome[i].tome_name<<endl;
                }        
                cout<<"6. Exit"<<endl;
                cin>>player_choice;
                if(player_choice==6) {
                    IdleMenu(player);
                }
                else
                tome[player_choice].tome_num+=1;
            break;

            default:
                cout<<"Invalid choice";
                buy(player);
        }
        }
    }

    static void sell_items(Player &player) {
        cout<<"Show me what you've got!!"<<endl;
        cout<<"1. Show Weapons"<<endl;
        cout<<"2. Show Armor"<<endl;
        cout<<"3. Show Consumables"<<endl;
        cout<<"4. Show Magic tomes"<<endl;

        string choice;
        int player_choice;
        cin >> choice;
        
        if (choice.length()== 1 && choice[0] >= '1' && choice[0] <= '4') {

            switch (choice[0]) {
            case '1':
                for(int i=0;i<5;i++) {
                    if (Weapons[i].Weapon_Num>0)
                    cout<<i+1<<". "<<Weapons[i].Weapon_Name<<endl;
                }
            cout<<"6. Exit";

            cin>>player_choice;

            /*if(player_choice==6) {
                IdleMenu(player);
            }
            else */Weapons[player_choice].Weapon_Num-=1;
            player.Cash+=Weapons[player_choice].Weapon_Price;

            break;

            case '2':
                for(int i=0;i<5;i++) {
                    if(Armors[i].Armor_Num>0)

                    cout<<i+1<<". "<<Armors[i].Armor_Name<<endl;
                }
            cout<<"6. Exit";

            cin>>player_choice;
            /*if(player_choice==6) {
                IdleMenu(player);
            }
            else*/
                Armors[player_choice].Armor_Num-=1;
            player.Cash+=Armors[player_choice].Armor_Price;

            break;

            case '3':
                for(int i=0;i<3;i++) {
                    if(Consumables[i].Consumable_Num>0)

                    cout<<i+1<<". "<<Consumables[i].Consumable_Name<<endl;
                }
            cout<<"6. Exit";

            cin>>player_choice;
            /*if(player_choice==6) {
                IdleMenu(player);
            }
            else*/
                Consumables[player_choice].Consumable_Num-=1;
            player.Cash+=Consumables[player_choice].Consumable_Price;
            break;

            case '4':
                for(int i=0;i<4;i++) {
                    if(tome[i].tome_num>0)

                    cout<<i+1<<". "<<tome[i].tome_name<<endl;
                }        cout<<"6. Exit";

            cin>>player_choice;
            /*if(player_choice==6) {
                IdleMenu(player);
            }
            else*/
                tome[player_choice].tome_num-=1;
            player.Cash+=tome[player_choice].tome_price;
            break;

            default:
                cout<<"Invalid choice";
                sell_items(player);
            break;
        }
        }
    }

    static void merchant(Player &player) {
        string b_s;
        cout<<"Welcome to my humble shop, how can I be of help?"<<endl;
        cout<<"1. Buy"<<endl<<"2. Sell items"<<endl;
        cin>>b_s;
        if (b_s.length()==1 && b_s[0] >= '1' && b_s[0] <= '2'){
            switch (b_s[0]) {
                case '1':
                    buy(player);
                    break;

                case '2':
                    sell_items(player);
                    break;
            }
        }
    }
};

int main(){
    string Player_Name;
    string Player_Race;
    string Player_Sex;

    srand(static_cast<unsigned>(time(nullptr)));

    Sleep(300);
    cout << "Please enter your player's name..\n";
    cin >> Player_Name;
    Sleep(300);
    cout << "Please enter your player's race..\n";
    cin >> Player_Race;
    Sleep(300);
    cout << "Please enter your player's sex..\n";
    cin >> Player_Sex;
    Sleep(300);
    cout << "\nYou Rise from the ashes, a new hero is born..\n\n";
    Sleep(300);
    cout << "You wander into a nearby town, it seems safe and lively..\n";


    Player player(Player_Name, Player_Race, Player_Sex,75,1,1,100,1,1,1,1,75,2);
    Function_Manager::IdleMenu(player);



    return 0;
}

