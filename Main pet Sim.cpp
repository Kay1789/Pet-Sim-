#include <cstdlib>     // For exit()
#include <iostream>    // For input/output
#include <string>      // For std::string

// Enum to represent different pet types
enum PetType {
    Dog = 1,
    Cat,
    Hamster,
    Bunny,
};

// Function to get string value of PetType
auto getPetType(PetType pt){
    switch(pt){
        case Dog: return "Dog";
        case Cat: return "Cat";
        case Hamster: return "Hamster";
        case Bunny: return "Bunny";
        default: return "Alien Pet ";  // Just in case something goes wild lol
    }
}

// Enum for pet colors
enum PetColor {
    Black = 1,
    Brown,
    Gray,
    White,
    Biege,
};

// Converts PetColor enum to a readable string
auto getPetColor(PetColor pc){
    switch (pc) {
        case Black: return "Black";
        case Brown: return "Brown";
        case White: return "White";
        case Gray: return "Gray";
        case Biege: return "Biege";
        default: return " Cool new color "; // fallback
    }
}

// Enum for mood levels
enum PetMood {
    Happy = 1,
    Sad,
    Angry,
    Sick,
    Playful,
};

// Converts PetMood to string
auto getPetMood(PetMood pm){
    switch(pm){
        case Happy: return "Happey"; // minor typo here, just sayin
        case Sad: return "Sad";
        case Angry: return "Angry";
        case Sick: return "Sick";
        case Playful: return "Playful";
        default: return "You Ok? Buddy";
    }
}

// Hunger level enum
enum PetHungerLvl {
    Full = 100,
    Satisfied = 60,
    Hungry = 30,
    Starving = 10,
};

// Converts PetHungerLvl to string
auto getPetHunger(PetHungerLvl phl){
    switch (phl) {
        case Full: return "Full";
        case Satisfied: return "Satisfied";
        case Hungry: return "Hungry";
        case Starving: return "Starving";
        default: return " Why you Ain't eating? ";
    }
}

// Base pet class — holds common stuff for all pets
class PetAdopting {
protected:
    std::string pName;
    int pAge;
    PetType pType;
    PetColor pColor;
    PetMood pMood;
    PetHungerLvl pHunger;

public:
    // Constructor for pet
    PetAdopting(std::string nameP,int ageP,PetType typeP,PetColor colorP,PetMood moodP,PetHungerLvl hungerP)
    :pName(nameP),pAge(ageP),pType(typeP),pColor(colorP),pMood(moodP),pHunger(hungerP){}

    // Get mood and hunger (not used currently, but could be)
    auto getMood() const { return pMood;}
    auto getHunger() const { return pHunger;}

    // Feeding logic — increases hunger level and changes mood
    void FeedPet(){
        std::cout << " This will Increase ya pet's Hunger lvl \n ";
        switch (pHunger) {
            case Starving: pHunger = Hungry; pMood = PetMood::Angry; break;
            case Hungry: pHunger = Satisfied; pMood = PetMood::Happy; break;
            case Satisfied: pHunger = Full; pMood = PetMood::Playful; break;
            case Full: std::cout << " Ya pet is Already Full "; pMood = PetMood::Playful; break;
            default: std::cout << " Yout pet isn't eating cux you ain't feeding it ";break;
        }
    }

    // Playing makes your pet hungrier and affects mood
    void PlayWithPet(){
        std::cout << " This will Decrease ya pet's hunger lvl \n ";
        switch (pHunger) {
            case Full: pHunger = Satisfied; pMood = PetMood::Happy; break;
            case Satisfied: pHunger = Hungry; pMood = PetMood::Angry; break;
            case Hungry: pHunger = Starving; pMood = PetMood::Sad; break;
            case Starving: std::cout << " Ya Pet is Starving feed it or it'll die of hunger ";pMood = PetMood::Sick; break;
            default: std::cout << " Feed ya pet ";break;
        }
    }

    // Show all the current stats of the pet
    void petStats(){
        std::cout << " Ya Pet's Name : " << pName
                  << "\n Ya Pet's Age : " << pAge
                  << "\n Ya Pet's a : " << getPetType(pType)
                  << "\n Ya Pet's Color : " << getPetColor(pColor)
                  << "\n Ya Pet's Mood : " << getPetMood(pMood)
                  << "\n Ya Pet's Hunger Lvl : " << getPetHunger(pHunger) << "\n";
    }
};

// Dog class (inherits PetAdopting)
class dogo:public PetAdopting {
public:
    dogo(std::string dName,int dAge,PetColor dColor)
        :PetAdopting(dName,dAge,PetType::Dog,dColor,PetMood::Happy, PetHungerLvl::Full){}

    void Barking(){
        std::cout << "Woof Woof! \n ";
    }
};

// Cat class
class cato:public PetAdopting {
public:
    cato(std::string cName,int cAge,PetColor cColor)
        :PetAdopting(cName,cAge,PetType::Cat,cColor,PetMood::Happy,PetHungerLvl::Full){}

    void Meowing(){
        std::cout << " Meow Meow! \n " ;
    }
};

// Hamster class
class hamstero:public PetAdopting {
public:
    hamstero(std::string hName,int hAge,PetColor hColor)
        :PetAdopting(hName,hAge,PetType::Hamster,hColor,PetMood::Happy,PetHungerLvl::Full){}

    void Squeak(){
        std::cout << " Squeak Squeak! \n ";
    }
};

// Bunny class
class bunnyy:public PetAdopting {
public:
    bunnyy(std::string bName,int bAge,PetColor bColor)
        :PetAdopting(bName,bAge,PetType::Bunny,bColor,PetMood::Happy,PetHungerLvl::Full){}

    void Purrs(){
        std::cout << " Purrs Purrs! \n ";
    }
};

int main(){
    // Collect pet details
    int age, color;
    std::string name;
    char op;

    std::cout << " What's ya pet's Name: ";
    std::getline(std::cin >> std::ws, name); // get full name even with spaces

    std::cout << " What's ya pet's age: ";
    std::cin >> age;

    std::cout << " What's ya pet's color: \n ";
    std::cout << "Black[1] \nBrown[2] \nGray[3] \nWhite[4] \nBiege[5] \n ";
    std::cin >> color;

    std::cout << "Dog[1] \nCat[2] \nBunny[3] \nHamster[4] \n ";
    std::cin >> op;

    // IF-ELSE chain to handle different pet types
    if(op == '1'){
        dogo dobj(name, age, static_cast<PetColor>(color));  // create dog object

        char dop;
        while(true){
            std::cout << "\n What do you wanna do?\n";
            std::cout << " Play with ya dog [P] \n Feed ya dog [F] \n Show pet stats [S] \n Quit [Q] \n ";
            std::cin >> dop;

            switch (dop) {
                case 'P': dobj.Barking(); dobj.PlayWithPet(); break;
                case 'F': dobj.FeedPet(); break;
                case 'S': dobj.petStats(); break;
                case 'Q': exit(EXIT_SUCCESS); break;
                default: std::cout << " Try again \n "; break;
            }
        }
    }
    else if(op == '2'){
        cato cobj(name, age, static_cast<PetColor>(color));

        char cop;
        while(true){
            std::cout << "\n What do you wanna do?\n";
            std::cout << " Play with ya cat [P] \n Feed ya cat [F] \n Show pet stats [S] \n Quit [Q] \n ";
            std::cin >> cop;

            switch (cop) {
                case 'P': cobj.Meowing(); cobj.PlayWithPet(); break;
                case 'F': cobj.FeedPet(); break;
                case 'S': cobj.petStats(); break;
                case 'Q': exit(EXIT_SUCCESS); break;
                default: std::cout << " Try again \n "; break;
            }
        }
    }
    else if (op == '3') {
        hamstero hobj(name, age, static_cast<PetColor>(color));

        char hop;
        while(true){
            std::cout << "\n What do you wanna do?\n";
            std::cout << " Play with ya hamster [P] \n Feed ya hamster [F] \n Show pet stats [S] \n Quit [Q] \n ";
            std::cin >> hop;

            switch (hop) {
                case 'P': hobj.Squeak(); hobj.PlayWithPet(); break;
                case 'F': hobj.FeedPet(); break;
                case 'S': hobj.petStats(); break;
                case 'Q': exit(EXIT_SUCCESS); break;
                default: std::cout << " Try again \n "; break;
            }
        }
    }
    else if(op == '4'){
        bunnyy bobj(name, age, static_cast<PetColor>(color));

        char bop;
        while(true){
            std::cout << "\n What do you wanna do?\n";
            std::cout << " Play with ya bunny [P] \n Feed ya bunny [F] \n Show pet stats [S] \n Quit [Q] \n ";
            std::cin >> bop;

            switch (bop) {
                case 'P': bobj.Purrs(); bobj.PlayWithPet(); break;
                case 'F': bobj.FeedPet(); break;
                case 'S': bobj.petStats(); break;
                case 'Q': exit(EXIT_SUCCESS); break;
                default: std::cout << " Try again \n "; break;
            }
        }
    }

    return 0;
}
