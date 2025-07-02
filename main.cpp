#include <iostream>
#include <string>
#include <random>
#include <windows.h>
//#include <stdlib.h>
#include <time.h>
#include <iomanip>
#include <fstream>
//#include <mmsystem.h>
using namespace std;


void print(string text) {
    for(char c: text) {
        cout << c;
        Sleep(50);
        /*PlaySound(TEXT(
             "C:\\Users\\theme\\OneDrive\\Desktop\\game\\Sound Effects - Single keyboard type [FREE].wav")
             , NULL, SND_FILENAME | SND_ASYNC | SND_LOOP ); */
        }
    //PlaySound(0 ,0 ,0);
}


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

Enemy Enemies[]={
    Enemy("Dire Wolf", "Wolf", 100, 10, 5, 100,3),
    Enemy("Goblin", "Goblin", 150, 20, 10,150,3),
    Enemy("Skeleton", "Skeleton", 200, 30, 15,200,3),
    Enemy("Headless Knight", "Headless Knight", 300, 50, 20,300,3),
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
        Weapon("Dagger", 10, 20,1),
        Weapon("Sword", 30, 25,0),
        Weapon("Axe", 35, 30,1),
        Weapon("Halberd", 45, 35,0),
        Weapon("Great Sword", 60, 40,0),
        Weapon("Great Axe", 70, 45,0),
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
        Armor("Iron Armor Set", 10, 20,1),
        Armor("Steel Armor Set", 15, 40,0),
        Armor("Mithril Armor Set", 20, 65,0),
        Armor("Adamant Armor Set", 25, 90,0),
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
        Consumable("Health Potion", 50, 5, 3),
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
        cout << "\n1.Weapons" << endl;
        cout << "2.Armor" << endl;
        cout << "3.Consumables" << endl;
        cout << "0.Back\n" << endl; 

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
        cout << "\n";
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
                cout << Weapons[choice - 1].Weapon_Name;
                print(" has been equipped\n");
                inv_weapons(player, Weapons);
            }
            else if (Weapons[choice - 1].Weapon_Num == 0) {
                print( "You don't have that weapon\n");
                inv_weapons(player, Weapons);
            }
        } else { 
            cout << "\nInvalid choice\n\n";
            inv_weapons(player, Weapons);
            }
    }

    static void inv_Armor(Player &player, Armor armor[]) {
        cout << "\n";
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

            if (choice > 5 || choice < 0) { 
                cout << "Invalid choice" << endl;
                inv_Armor(player ,Armors);
            }

            else if (choice == 0) {
                inv(player, Weapons, Armors, Consumables);
            }

            else if (Armors[choice - 1].Armor_Num > 0) {
                player.Defense = Armors[choice - 1].Armor_Defense + player.VLR;
                cout << Armors[choice - 1].Armor_Name;
                print(" has been equipped\n");
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
        cout << "\n";
        string Consumable_Choice;

        for (int i = 0; i<1; i++){
            if (Consumables[i].Consumable_Num > 0){
                cout << i+1 << ". " << Consumables[i].Consumable_Name << " | +" << Consumables[i].Consumable_Effect << " HP | Amount Carried:" << Consumables[i].Consumable_Num << endl;
            }
        }
        cout << "0. Back" << endl;
        cin >> Consumable_Choice;

        if (Consumable_Choice.length() == 1 && isdigit(Consumable_Choice[0])) {
            int choice = Consumable_Choice[0] - '0';

            if (choice > 1 || choice < 0) {
                cout << "Invalid choice" << endl;
                inv_cons(player ,Consumables);
            }
            
            else if (choice == 0) {
                inv(player, Weapons, Armors, Consumables);
            }

            else if (Consumables[choice - 1].Consumable_Num > 0) {
                if (player.Health + Consumables[choice - 1].Consumable_Effect > player.Max_Health){
                    player.Health = player.Max_Health;
                } else {
                    player.Health += Consumables[choice - 1].Consumable_Effect;
                }
                Consumables[choice - 1].Consumable_Num -= 1;
                print("You used ");
                cout<< Consumables[choice - 1].Consumable_Name;
                print(" and gained ");
                cout<< Consumables[choice - 1].Consumable_Effect << " HP!\n";
                inv_cons(player, Consumables);
            }

            else if (Consumables[choice - 1].Consumable_Num == 0) {
                print( "You don't have that Consumable\n");
                inv_cons(player, Consumables);
            }
        }else { 
            cout << "\nInvalid choice\n\n";
            inv_cons(player, Consumables);
            }
    }

    static void use_consumable(Player &player, Consumable[], Enemy &enemy){
        string Consumable_Choice;
        cout << "\n";
        for (int i = 0; i<1; i++){
            if (Consumables[i].Consumable_Num > 0){
                cout << i+1 << ". " << Consumables[i].Consumable_Name << " | +" << Consumables[i].Consumable_Effect << " HP | Amount Carried:" << Consumables[i].Consumable_Num << endl;
            }
        }
        cout << "0. Back\n\n";
        cin >> Consumable_Choice;

        if (Consumable_Choice.length() == 1 && isdigit(Consumable_Choice[0])) {
            int choice = Consumable_Choice[0] - '0';

            if (choice > 1 || choice < 0) {
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
        cout << "6. Load\n";
        cout << "0. Quit\n\n";
        cin >> choice;

        if (choice.length() == 1 && choice[0] >= '0' && choice[0] <= '6') {
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
                save(player);
                IdleMenu(player);
                break;
            case '6':
                load(player);
                IdleMenu(player);
                break;
            case '0':
                print("\nGoodbye\n\n");
                exit(1);
                break;
        }
    } else {
        cout << "\nInvalid choice\n\n";
        IdleMenu(player);
    }
    }

    static void LocationIntro(Player &player){
        cout<<"\nYou leave the safety of the town.. Where do you go?\n\n";
        cout<<"1. Wild Forest\n";
        cout<<"2. Dark Cave\n";
        cout<<"3. Abandoned Dungeon\n";
        cout<<"4. Haunted Castle\n\n";
        string Location;
        cin >> Location;
        if (Location.length() == 1 && Location[0] >= '1' && Location[0] <= '4') {
                int choice = Location[0] - '0';
                cout << "\n";
                cout << "You walk into the " << Locations[choice-1] << "...\n";
                cout << Enemies[choice-1].Enemy_Name << " Encountered!\n";

                Enemy enemy(Enemies[choice-1]);
                enemy.Xp = player.Xp*0.25;
                enemy.LVL = player.LVL+(rand()%3);
                FightMenu(player, enemy);

            } else {
            print("You wander somewhere else.. You found nothing and came back..\n");
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
        cout << "\nName:   "<< setw(15) << setfill(' ') << left << player.Player_Name <<"|     "<<"Enemy Name:   "<<enemy.Enemy_Name<<"\n";
        cout << "Health: " << setw(15) << setfill(' ') << left << phealth << "|     " << "Enemy Health: " << ehealth <<"\n";
        cout << "Level:  " << setw(15) << setfill(' ') << left << player.LVL << "|     " << "Enemy Level:  " << enemy.LVL <<"\n";
        cout << "1. Attack\n";
        cout << "2. Use Item\n";
        cout << "3. Escape\n\n";
        cin >> Fight_Choice;
        if (Fight_Choice.length() == 1 && Fight_Choice[0] >= '1' && Fight_Choice[0] <= '3' && isdigit(Fight_Choice[0])) {
            int choice = Fight_Choice[0] - '0';
            switch (choice)
            {
                case 1:
                    enemy.Health -= player.Attack;
                    if (enemy.Health<=0){
                        enemy.Health=0;
                    }
                    cout << "\n\nYou attack the enemy dealing " << player.Attack << " damage!\n" << "Enemy Health: " << enemy.Health << "/" << enemy.Max_Health << "\n";
                    if (enemy.Health <= 0){
                        print("\nENEMY VANQUISHED!\n\n");
                        cout << enemy.Xp;
                        print(" XP Gained!\n\n");
                        player.Xp += enemy.Xp;
                        player.Cash+= enemy.LVL*5;
                        cout << enemy.LVL*5 << "$ ";
                        print("Cash Gained!\n");
                        if (player.Xp >= player.Next_Xp){
                            player.LVL++;
                            player.Next_Xp = player.Next_Xp * 1.5;
                            player.Max_Health += 10;
                            player.Health = player.Max_Health;
                            player.Attack += 1;
                            player.Defense += 1;
                            player.STR += 1;
                            player.VLR += 1; 
                            cout << "LEVEL UP!\n" << "New Level: " << player.LVL << "\n" << "Stats Increased!\n";
                        }
                        IdleMenu(player);
                    } else {
                        EnemyReaction(player, enemy);
                    }
                    break;
                case 2:
                    use_consumable(player, Consumables, enemy);
                    break;
                case 3:
                    cout << "\nYou try to escape..\n\n";
                    if (rand()%4 == 0){
                        cout << "You escaped!\n";
                        IdleMenu(player);
                    } else {
                        cout << "You couldn't escape!\n";
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
            cout << "\nEnemy used a healing item and gained " << enemy.Heal_Effect << " HP!\n";
            FightMenu(player, enemy);
        } else {
            int enemyAttack = enemy.Attack - player.Defense;
            if (enemyAttack <= 0) {
                enemyAttack = 1;
            }
            cout << "\nEnemy attacks you dealing " << enemyAttack << " damage!\n";
            player.Health -= enemyAttack;
            if (player.Health <= 0) {
                print("\nYOU HAVE BEEN DEFEATED!\n");
            } else {
                FightMenu(player, enemy);
            }
        }
    }

    static void buy(Player &player){
        cout<<"\t\t\t\tCash: ";
        cout<<player.Cash<<"$"<<endl;
        print("Merchant: Looks like I'll be making money today!\n");
        cout <<"1. View Weapons\n";
        cout<<"2. View Armor\n";
        cout<<"3. View Consumables\n";
        cout<<"0. Exit\n";

        string choice;
        string player_choice;

        cin >> choice;
        int choice_num=(int)choice[0]-48;

        if(choice.length()==1 && choice_num<=3 && choice_num>=0 ){
            switch (choice_num) {
                case 1:
                    cout<<"\t\t\t\tCash: ";
                cout <<player.Cash<<"$"<<endl;

                    for(int i=0;i<6;i++)
                    {
                        cout<<i+1<<". "<<Weapons[i].Weapon_Name<<"\t|ATK: "<<Weapons[i].Weapon_Damage<<"\t| Price: "<<Weapons[i].Weapon_Price<<endl;
                    }
                    cout<<"0. Exit\n"<<endl;
                    cin>>player_choice;
                    if(player_choice.length()==1 && player_choice[0]<='6' && player_choice[0]>='0'){
                        int Index= (int)player_choice[0]-48;
                        if(Index==0)
                            IdleMenu(player);

                        else{
                            Index--;

                            if(player.Cash<Weapons[Index].Weapon_Price){
                                print("Merchant: you do not have enough money sorry\n");
                                merchant(player);
                            }
                            else {Weapons[Index].Weapon_Num+=1;
                                cout<<"Weapon price: "<<Weapons[Index].Weapon_Price<< "\nCash: "<<player.Cash<<"\nReceipt: "<<player.Cash<< " - "<<Weapons[Index].Weapon_Price<<" = "<<player.Cash-Weapons[Index].Weapon_Price<<endl;

                                player.Cash-=Weapons[Index].Weapon_Price;
                                cout<<"You bought "<<Weapons[Index].Weapon_Name<<" !"<<endl;
                                print("Merchant: Enjoy your new weapon, it once belonged to a great warrior..\n");
                                cout<<"\t\t\t\tRemaining Cash: "<<player.Cash<<"$"<<endl;

                                IdleMenu(player);}

                        }}
                    else{
                        print("Merchant: Not sure if I got that right.\n");
                        buy(player);
                    }

                    break;

                case 2:
                    print("\t\t\t\tCash: ");
                cout<<player.Cash<<"$"<<endl;

                    for(int i=0;i<5;i++)
                        cout<<i+1<<". "<<Armors[i].Armor_Name<<"\t|DEF: "<<Armors[i].Armor_Defense<<"\t| Price: "<<Armors[i].Armor_Price<<endl;

                    cout<<"6. Exit\n"<<endl;
                    cin>>player_choice;
                    if(player_choice.length()==1 && player_choice[0]>='0' && player_choice[0]<='5' ){
                        int Index=(int)player_choice[0]-48;
                        if(Index==0)
                            IdleMenu(player);

                        else {

                            Index--;
                            if(player.Cash<Armors[Index].Armor_Price){
                                print("Merchant: you do not have enough money sorry\n");
                                merchant(player);
                            }
                            else {Armors[Index].Armor_Num+=1;
                                cout<<"Armor price: "<<Armors[Index].Armor_Price<< "\nCash: "<<player.Cash<<"\nReceipt: "<<player.Cash<< " - "<<Armors[Index].Armor_Price<<" = "<<player.Cash-Armors[Index].Armor_Price<<endl;

                                player.Cash-=Armors[Index].Armor_Price;
                                cout<<"New Armour "<<Armors[Index].Armor_Name<<" Acquired!\n";
                                print("Merchant: Come by again! You are my only source of income..\n");
                                cout<<"\t\t\t\t Remaining Cash: "<<player.Cash<<"$"<<endl;

                                IdleMenu(player);}

                        }}
                    else{
                        print("Merchant: Huh? I didn't quite catch that.\n");
                        buy(player);

                    }
                    break;

                case 3:
                    cout<<"\t\t\t\tCash: "<<player.Cash<<"$"<<endl;

                    for(int i=0;i<1;i++)
                        cout<<i+1<<". "<<Consumables[i].Consumable_Name<<"\t|EFFECT: "<<Consumables[i].Consumable_Effect<<"\t| Price: "<<Consumables[i].Consumable_Price<<endl;

                    cout<<"0. Exit\n"<<endl;
                    cin>>player_choice;
                    if(player_choice.length()==1 && player_choice[0]>='0' && player_choice[0]<='2' ){
                        int Index=(int)player_choice[0]-48;
                        if(Index==0)
                            IdleMenu(player);


                        else{
                            Index--;

                            if(player.Cash<Consumables[Index].Consumable_Price){
                                print("Merchant: this is no charity work..get out of my shop\n");
                                merchant(player);
                            }
                            else {Consumables[Index].Consumable_Num+=1;
                                cout<<"Consumable price: "<<Consumables[Index].Consumable_Price<< "\nCash: "<<player.Cash<<"\nReceipt: "<<player.Cash<< " - "<<Consumables[Index].Consumable_Price<<" = "<<player.Cash-Consumables[Index].Consumable_Price<<endl;
                            player.Cash-=Consumables[Index].Consumable_Price;
                            cout<<Consumables[Index].Consumable_Name;
                                print(" has been added to your inventory !\n");
                            print("Merchant: I was worried no one would buy this..\n");
                            cout<<"\t\t\t\tRemaining Cash: "<<player.Cash<<"$"<<endl;

                            IdleMenu(player);}
                        }}
                    else{
                        print("Merchant: Errmm...What?\n");
                        buy(player);

                    }
                    break;
                case 0:
                    print("Merchant: See you later!\n");
                    IdleMenu(player);
            }
        }
        else{
            cout<<"Invalid choice.\n";
            buy(player);}

    }

    static void sell_items(Player &player) {
        print("\nMerchant: Show me what you've got!!\n");
        cout<<"\t\t\t\tCash: "<<player.Cash<<"$"<<endl;
        cout<<"1. Show Weapons"<<endl;
        cout<<"2. Show Armor"<<endl;
        cout<<"3. Show Consumables"<<endl;
        cout<<"0. Exit"<<endl;

        string choice;
        string player_choice;
        cin >> choice;
        int choice_num=(int)choice[0]-48;

        if(choice.length()==1 && choice[0]<='3' && choice[0]>='0'){
            switch (choice_num) {
                case 1:
                    cout<<"\t\t\t\tCash: "<<player.Cash<<"$"<<endl;

                    for(int i=0;i<6;i++) {
                        if(Weapons[i].Weapon_Num>0)
                            cout<<i+1<<". "<<Weapons[i].Weapon_Name<<"\t|ATK: "<<Weapons[i].Weapon_Damage<<"\t| Price: "<<Weapons[i].Weapon_Price<<endl;
                    }
                    cout<<"0. Exit\n";
                    cin>>player_choice;
                    if(player_choice.length()==1 && player_choice[0]<='6' && player_choice[0]>='0'){
                        int Index= (int)player_choice[0]-48;
                        if(Index==0)
                            IdleMenu(player);

                        else {
                            Index--;
                            if(Weapons[Index].Weapon_Num==0){
                                cout<<"WHO DO YOU MISTAKE ME FOR??? IM THE ONE WHO CREATED SCAMMING!!\n";
                                sell_items(player);
                            }
                            else{
                                Weapons[Index].Weapon_Num-=1;
                                player.Cash+=Weapons[Index].Weapon_Price;}
                                cout<<"You have sold "<<Weapons[Index].Weapon_Name<<" and gained: "<<Weapons[Index].Weapon_Price<<" Coins!\n";
                                cout<<"\t\t\t\tCash Carried: "<<player.Cash<<"$"<<endl;

                                print("Merchant: Come back again!! ...What an idiot he doesn't know how much this weapon is worth\n");
                                IdleMenu(player);

                            }
                        }



                    else{
                        print("Merchant: Does this option even exist?\n");
                        sell_items(player);}
                    break;

                case 2:
                    cout<<"\t\t\t\tCash: "<<player.Cash<<"$"<<endl;

                    for(int i=0;i<5;i++) {
                        if(Armors[i].Armor_Num>0)
                            cout<<i+1<<". "<<Armors[i].Armor_Name<<"\t|DEF: "<<Armors[i].Armor_Defense<<"\t| Price: "<<Armors[i].Armor_Price<<endl;
                    }
                    cout<<"0. Exit\n";
                    cin>>player_choice;
                    if(player_choice.length()==1 && player_choice[0]>='0' && player_choice[0]<='5' ){
                        int Index=(int)player_choice[0]-48;
                        if(Index==0)
                            IdleMenu(player);

                        else {
                            Index--;
                            if (Armors[Index].Armor_Num == 0) {
                                print("Merchant: scamming ME?? how foolish of you ..that's MY thing!\n");
                                sell_items(player);
                            } else {
                                Armors[Index].Armor_Num -= 1;
                                player.Cash += Armors[Index].Armor_Price;

                                print("You have sold ");
                                cout<< Armors[Index].Armor_Name;
                                print(" and gained: ");
                                cout<< Armors[Index].Armor_Price << " Coins!\n";
                                cout<<"\t\t\t\tCash Carried: "<<player.Cash<<"$"<<endl;

                                print("Merchant: Come back again!! ...What an idiot he doesn't know how much this weapon is worth\n");
                                IdleMenu(player);
                            }
                        }}

                    else {
                        print("Merchant: Try again.\n");
                        sell_items(player);}
                    break;

                case 3:
                    cout<<"\t\t\t\tCash: "<<player.Cash<<"$"<<endl;

                    for(int i=0;i<1;i++) {
                        if(Consumables[i].Consumable_Num>0)
                            cout<<i+1<<". "<<Consumables[i].Consumable_Name<<"\t|EFFECT: "<<Consumables[i].Consumable_Effect<<"\t| Price: "<<Consumables[i].Consumable_Price<<endl;
                    }
                    cout<<"0. Exit\n";

                    cin>>player_choice;
                    if(player_choice.length()==1 && player_choice[0]>='0' && player_choice[0]<='1'){
                        int Index=(int)player_choice[0]-48;
                        if(Index==0)
                            IdleMenu(player);

                        else {
                            Index--;
                            if (Consumables[Index].Consumable_Num == 0) {
                                print( "Merchant: You cant fool me by selling me something that doesnt exist..\n");
                                sell_items(player);
                            } else {
                                Consumables[Index].Consumable_Num -= 1;
                                player.Cash += Consumables[Index].Consumable_Price;

                                cout << "You have sold " << Consumables[Index].Consumable_Name << " and gained: "
                                     << Consumables[Index].Consumable_Price << " Coins!\n";
                                cout<<"\t\t\t\tCash Carried: "<<player.Cash<<"$"<<endl;

                                print( "Merchant: Come back again!! ...What an idiot he doesn't know how much this weapon is worth\n");
                                IdleMenu(player);
                            }
                        }}
                    else {
                        print("Merchant: I don't think that's an option...\n");
                        sell_items(player);
                    }
                    break;



                case 0:
                    print("Merchant: See ya again!\n");
                    IdleMenu(player);
            }}
        else {
            cout<<"Invalid choice\n";
            sell_items(player);
        }
    }

    static void merchant(Player &player) {
        string b_s;
        print("\nMerchant: Welcome to my humble shop, how can I be of help?\n");
        cout<<"1. Buy"<<endl<<"2. Sell items"<<endl<<"0. Exit\n";
        cin>>b_s;
        if(b_s.length()==1 && b_s[0]>='0' && b_s[0]<='2'){
            int b_s_num= (int)b_s[0]-48;
            switch (b_s_num) {
                case 1:
                    buy(player);
                    break;
                case 2:
                    sell_items(player);
                    break;
                case 0:
                    IdleMenu(player);
                    break;}}
        else{
            cout<<"Invalid choice\n";
            merchant((player));
        }
    }

    static void load(Player &player) {
        ifstream inFile("savegame.txt");
        if (inFile.is_open()) {
            getline(inFile, player.Player_Name);
            getline(inFile, player.Player_Race);
            getline(inFile, player.Player_Sex);
            inFile >> player.Cash;
            inFile >> player.Xp;
            inFile >> player.Next_Xp;
            inFile >> player.Health;
            inFile >> player.Max_Health;
            inFile >> player.Attack;
            inFile >> player.Defense;
            inFile >> player.LVL;
            inFile >> player.STR;
            inFile >> player.VLR;
            inFile.close();
            print("\nPlayer progress loaded!\n\n");
        } else {
            print("\nNo save file found\n\n");
        }
    }

    static void save(Player &player) {
        ofstream outFile("savegame.txt");
        if (outFile.is_open()) {
            outFile << player.Player_Name << endl;
            outFile << player.Player_Race << endl;
            outFile << player.Player_Sex << endl;
            outFile << player.Cash << endl;
            outFile << player.Xp << endl;
            outFile << player.Next_Xp << endl;
            outFile << player.Health << endl;
            outFile << player.Max_Health << endl;
            outFile << player.Attack << endl;
            outFile << player.Defense << endl;
            outFile << player.LVL << endl;
            outFile << player.STR << endl;
            outFile << player.VLR << endl;
            outFile.close();
            print("\nPlayer progress saved!\n\n");
        } else {
            print ("\nFailed to open save file\n\n");
        }
    }

};

int main(){
    string Player_Name;
    string Player_Race;
    string Player_Sex;

    srand(static_cast<unsigned>(time(nullptr)));

    print("Please enter your player's name..\n");
    getline(cin, Player_Name);
    print("Please enter your player's race..\n");
    getline(cin, Player_Race);
    print("Please enter your player's sex..\n");
    getline(cin, Player_Sex);
    print("\nYou Rise from the ashes, a new hero is born..\n\n");
     print("You come across a rusty dagger and a tattered iron armor..\n\n");
    print("You wander into a nearby town, it seems safe and lively..\n");


    Player player(Player_Name, Player_Race, Player_Sex,75,1,1,100,1,1,1,1,75,2);
    Function_Manager::IdleMenu(player);

    return 0;
}