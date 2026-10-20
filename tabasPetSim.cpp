/*  Dyanne Emanuella Sumaryono Gantohe
    NRP 5025261247

    RIVAL Internship Phase - OOP Project
    "Tabas Pet Simulator"
*/

#include <iostream>
#include <string>
#include <iomanip>
using namespace std;

void clearScreen(){cout << "\x1B[2J\x1B[H";}

class Tabas {
private:
    string name;
    int hungerBar;
    int happiness;
    int energy;
    bool isSick;
    bool elated;
    bool medsEaten;
    bool overdosed;

public:
    Tabas(string petName){
    // you can set tabas' name but not stats, also start at half stats
    name = petName;

    hungerBar = 50;
    happiness = 50;
    energy = 50;
    isSick = false;
    elated = false;
    medsEaten = false;
    overdosed = false;
    }

    void feed(){
        clearScreen();
        cout<< endl;

        if(name == "Tabas"){
            hungerBar -= 10;
        }

        if(elated == true){
            energy -= 10;
        }

        // conditional starts here
        if(isSick == true){
            cout<< name << " feels ill, food is tasteless..." << endl;
            hungerBar -= 25;
            happiness -= 5;
        }

        else if(hungerBar > 75){
            cout<< name << " is already so full..." << endl;
            isSick = true;
            medsEaten = false;
        }

        else if(hungerBar > 50){
            cout<< name << " is being fed, so happy :D" << endl;
        }

        else if(hungerBar > 25){
            cout<< name << " is munching happily!" << endl;
        }

        else if(hungerBar > 0){
            cout<< name << " is absolutely obliterating the plate! Hungry cat!" << endl;
        }

        else {
            cout<< name << " was STARVING!!! Food inhaled!!!" << endl;
        }

        hungerBar = min(100, hungerBar + 25);
        happiness = min(100, happiness + 5);
        energy = max (0, energy - 15);

        cout<< "\n\n" << right << setw(24) << "[^=>v<=^]/\n\n";
    }

    void play(){
        clearScreen();
        cout<< endl;

        if(name == "Tabas"){
            hungerBar -= 10;
        }

        if(elated == true){
            energy -= 10;
        }

        // conditional starts here
        if(isSick == true){
            cout<< name << " feels ill, it's no fun at all..." << endl;
            happiness -= 25;
        }

        else if(hungerBar == 0){
            cout<< name << " is starving, feed it first..." << endl;
            happiness -= 20;
        }

        else if(energy == 0){
            cout<< name << " is too tired and wants to go for a nap..." << endl;
        }

        else if(hungerBar > 75){
            cout<< name << " is HAVING TOO MUCH FUN, ENTERING HYPERACTIVITY MODE" << endl;
            elated = true;
        }

        else if(hungerBar > 50){
            cout<< name << " is having sooo much fun playing with you!" << endl;
        }

        else if(hungerBar > 25){
            cout<< name << " thinks it's about time to play!!!" << endl;
        }

        else if(hungerBar > 0){
            cout<< name << " was waiting for this moment to play with you!" << endl;
        }

        else {
            cout<< name << " was SOOO BORED that it's so happy to play!" << endl;
        }

        hungerBar = max(0, hungerBar - 10);
        happiness = min(100, happiness + 25);
        energy = max(0, energy - 10);

        cout<< "\n\n" << right << setw(24) << "[^=>w<=^]/\n\n";
    }

    void rest(){
        clearScreen();
        cout<< endl;

        if(name == "Tabas"){
            hungerBar -= 10;
        }

        if(elated == true){
            energy -= 10;
        }

        // conditional starts here
        if(isSick == true){
            cout<< name << " feels ill, doesn't feel well-rested at all :C" << endl;
            energy -= 25;
        }

        else if(hungerBar == 0){
            cout<< name << " is starving, the nap wasn't very effective..." << endl;
            energy -= 15;
        }

        else if(energy > 75){
            cout<< name << " is brimming with energy after all that rest!" << endl;
        }

        else if(energy > 50){
            cout<< name << " is feeling well-rested!" << endl;
        }

        else if(energy > 25){
            cout<< name << " had a nice nap and dreamt of an endless buffet!" << endl;
        }

        else if(energy > 0){
            cout<< name << " was sooo tired that felt like catnip!" << endl;
        }

        else {
            cout<< name << " was so sleep deprived! Finally some rest..." << endl;
        }

        hungerBar = max(0, hungerBar - 10);
        happiness = max(0, happiness - 5);
        energy = min(100, energy +25);

        cout<< "\n\n" << right << setw(24) << "Zzz [^=uwu=^]_\n\n";
    }

    void cure(){
        clearScreen();
        if(isSick == true){
            cout<< endl << "You gave " << name << " some medicine! Healthy again :D" << endl;
            cout<< "-> Sickness cured!" << endl;
            isSick = false;

            cout<< "\n\n" << right << setw(24) << "[^=- w -=^]_\n\n";
        }

        else if(medsEaten == true){
            cout<< endl << "You just overdosed " << name << "..." << endl;
            overdosed = true;

            cout<< "\n\n" << right << setw(24) << "[^=x_x=^]_\n\n";
        }

        else {
            cout<< endl << name << " didn't need that!" << endl;
            cout<< "-> It did nothing. Don't do that again! The Tabas is healthy!" << endl;
            medsEaten = true;

            cout<< "\n\n" << right << setw(24) << "[^=>n<=^]_\n\n";
        }
    }

    void relax(){
        clearScreen();
        if(elated == true){
            cout<< endl << "Chill out, " << name << "! Patpatpatpat" << endl;
            cout<< "-> Exited hyperactivity mode." << endl;
            elated = false;

            cout<< "\n\n" << right << setw(24) << "[^=- w -=^]_\n\n";
        }

        else {
            cout<< endl << "Isn't " << name << " already too chilled out?!" << endl;
            cout<< "-> -10 Happiness!" << endl;
            happiness = max(0, happiness - 10);

            cout<< "\n\n" << right << setw(24) << "[^=o-o=^]/\n\n";
        }
    }

    void pat(){
        clearScreen();
        cout<< endl << "You gave " << name << " a pat! It heals your soul :]" << endl;
        cout<< "\n\n" << right << setw(24) << "[^=>w<=^]_\n\n";
    }

    void displayStats() const {
        cout<< "\n===== " << name << "'s CURRENT STATUS =====\n";
        cout<< "Fullness  : " << hungerBar << "/100" << endl;
        cout<< "Happiness : " << happiness << "/100" << endl;
        cout<< "Energy    : " << energy << "/100" << endl;

        if(isSick == true){
            cout<< endl << name << " is currently SICK! \n-> Feeding and playing will only worsen it!" << endl;
        }
        if(elated == true){
            cout<< endl << name << " is HYPERACTIVE! \n-> Energy will reduce on every action, even rest!" << endl;
        }
        if(name == "Tabas"){
            cout<< endl << "Your Tabas is called Tabas... A very greedy specimen indeed... \n-> Hunger will reduce on every action, even feed!" << endl;
        }
        cout<< "============================================" << endl;
    }

    bool isDead() const {
        return ((hungerBar == 0 && happiness == 0 && energy == 0) || (isSick == true && (hungerBar == 0 || energy == 0)) || (overdosed == true));
    }
};

int main() {
    cout<< "\n\n\n" << right << setw(37) << "[^=owo=^]_" << endl;
    cout<< "\n\n" << right << setw(55) << "This is a Tabas, your very own fat square cat!" << endl;

    string name;
    cout<< "Give your Tabas a name! (Who knows what happens if you name it Tabas...?)\n>> ";
    cin >> name;

    clearScreen();

    Tabas myPet(name); // your pet is tabas now :P
    int choice{};

    cout<< "\n\n" << right << setw(24) << "[^=owo=^]_\n\n";

    while (!myPet.isDead() && choice != 7) {
        myPet.displayStats();

        cout<< endl << "Actions:" << endl;
        cout<< "1. Feed the Tabas" << endl;
        cout<< "2. Play with the Tabas" << endl;
        cout<< "3. Naptime for Tabas" << endl;
        cout<< "4. Give Tabas Medicine" << endl;
        cout<< "5. Calm Down the Tabas" << endl;
        cout<< "6. Pat the Tabas" << endl;
        cout<< "7. Leave (Exit)" << endl;
        cout<< endl << "What do you do next?\n-> ";

        cin >> choice;

        switch (choice) {
            case 1:
                myPet.feed();
                break;
            case 2:
                myPet.play();
                break;
            case 3:
                myPet.rest();
                break;
            case 4:
                myPet.cure();
                break;
            case 5:
                myPet.relax();
                break;
            case 6:
                myPet.pat();
                break;
            case 7:
                clearScreen();
                cout<< "\n\n" << right << setw(24) << "Zzz [^=uwu=^]_\n\n";
                cout<< endl << "Aww... See you next time!" << endl;
                break;
            default:
                clearScreen();
                cout<< endl << "What are you doing? That's not in the script!!" << endl;
                // pls don't enter a non-integer value LOL
        }
    }

    if (myPet.isDead()){
        cout<< endl << "R.I.P. " << name << "... It will be missed...";
    }

    return 0;
}