#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

class Lieu {
private:
    string name;
    string description;
    int difficulty;
    int lieux[2];
    bool buildCamp;
    bool haveRepos;


public:
    Lieu(string n, string desc, int diff, int lieux[2], bool repos) {
        name = n;
        description = desc;
        difficulty = diff;
        lieux = lieux;
        buildCamp = false;
        haveRepos = repos;
    }

    void affichage(){

        cout << "------------------------------------\n";
        cout << "Vous etes dans le lieu : " << this->name << "\n\n";
        cout << this->description << "\n";
        cout << "------------------------------------\n";

    }

    void etablirCampement() {
        if (this->buildCamp == false) {
            this->buildCamp == true;
            this->difficulty == floor(this->difficulty / 2);
        }
    }

    void repos(int * endurance) {
        if (this->haveRepos) {
            if (*endurance < 50) {
                *endurance += 50;
            }
            else {
                *endurance = 100;
            }
        }
    }

    int * getLieux(){
        return this->lieux;
    }

    string getName(){
        return this->name;
    }

    int getDifficulty() {
        return this->difficulty;
    }


/*
    virtual void feed() = 0;
    virtual void play() = 0;

    void show_status() {
        cout << name << " is " << age << " years old. Hunger level is " << hunger_level << ", happiness level is " << happiness_level << "." << endl;
    }
*/
};

Lieu deplacement(int numLieu, vector<Lieu> lieux, Lieu lieuAct, int * endurance){

    for (int i = 0; i< sizeof(lieuAct.getLieux()); i++){
        if (lieuAct.getLieux()[i] == numLieu){
            endurance -= (lieuAct.getDifficulty() + lieux[i].getDifficulty());
            return lieux[i];
         

        }
    }
    return lieuAct;

}

int main() {

    bool over = true;

    int endurance = 100;

    int l_village[2]{2,3};
    int l_foret[2]{1,3};
    int l_chateau[2]{1,2};

    Lieu village_1 = * new Lieu("Village", "Un beau petit village plein de vie...", 1, l_village, false);
    Lieu foret_2 = * new Lieu("Foret", "Une foret sombre et terrifiante...", 8, l_foret, true);
    Lieu chateau_3 = * new Lieu("Chateau", "Un chateau dangereux...", 17, l_chateau, true);

    vector<Lieu> toutLieux{

        village_1, foret_2, chateau_3
    
    };

    Lieu lieuActuel = village_1;

    while( over ){
        
        lieuActuel.affichage();
        cout << "Ou voulez-vous aller ? \n\n";
        cout << lieuActuel.getLieux()[1];
        for (int num = 0; num < sizeof(lieuActuel.getLieux()-1); num++){
            if (lieuActuel.getLieux()[num] == num){
                cout << num << " - " << toutLieux[num].getName() << "\n";
            }
        }

        int choix;
        cin >> choix;

        lieuActuel = deplacement(choix, toutLieux, lieuActuel);

    }

     

}

//Bon Rien ne marche, mais y'a un peu de code... :'(

