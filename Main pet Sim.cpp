#include <cstdlib>     // For exit()
#include <iostream>    // For input/output
#include <string>      // For std::string

// ---------- ENUMS AND THEIR STRING CONVERTERS ----------

// Enum to represent different pet types
enum PetType {
    Dog = 1,
    Cat,
    Hamster,
    Bunny,
};

// Function to convert PetType to string
auto getPetType(PetType pt){
    switch(pt){
        case Dog: return "Dog";
        case Cat: return "Cat";
        case Hamster: return "Hamster";
        case Bunny: return "Bunny";
        default: return "Alien Pet ";  // If something wild happens
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

// Converts PetColor enum to readable string
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
        case Happy: return "Happy";
        case Sad: return "Sad";
        case Angry: return "Angry";
        case Sick: return "Sick";
        case Playful: return "Playful";
        default: return "You Ok? Buddy"; // fallback
    }
}

// Enum for hunger levels
enum PetHungerLvl {
    Full = 100,
    Satisfied = 60,
    Hungry = 30,
    Starving = 10,
};

// Converts hunger level enum to readable string
auto getPetHunger(PetHungerLvl phl){
    switch (phl) {
        case Full: return "Full";
        case Satisfied: return "Satisfied";
        case Hungry: return "Hungry";
        case Starving: return "Starving";
        default: return " Why you Ain't eating? ";
    }
}

// ---------- BASE CLASS: PETADOPTING ----------
class PetAdopting {
protected:
    std::string pName;
    int pAge;
    PetType pType;
    PetColor pColor;
    PetMood pMood;
    PetHungerLvl pHunger;

public:
    // Constructor for new pet
    PetAdopting(std::string nameP, int ageP, PetType typeP, PetColor colorP, PetMood moodP, PetHungerLvl hungerP)
        : pName(nameP), pAge(ageP), pType(typeP), pColor(colorP), pMood(moodP), pHunger(hungerP) {}

    virtual ~PetAdopting() = default; // So delete works properly with derived classes

    auto getMood() const { return pMood; }
    auto getHunger() const { return pHunger; }

    // Feed your pet
    void FeedPet() {
        std::cout << "\n[ Feeding Pet 🥩 ]\n";
        switch (pHunger) {
            case Starving: pHunger = Hungry; pMood = Angry; break;
            case Hungry: pHunger = Satisfied; pMood = Happy; break;
            case Satisfied: pHunger = Full; pMood = Playful; break;
            case Full:
                std::cout << " Ya pet is Already Full ";
                pMood = Playful;
                break;
            default:
                std::cout << " Ya pet ain't eating cux you ain't feeding it \n ";
                break;
        }
    }

    // Play with your pet
    void PlayWithPet() {
        std::cout << "\n[ Playing With Pet 🎾 ]\n";
        switch (pHunger) {
            case Full: pHunger = Satisfied; pMood = Happy; break;
            case Satisfied: pHunger = Hungry; pMood = Angry; break;
            case Hungry: pHunger = Starving; pMood = Sad; break;
            case Starving:
                std::cout << " Ya Pet is Starving feed it or it'll die of hunger \n ";
                pMood = Sick;
                break;
            default:
                std::cout << " Feed ya pet ";
                break;
        }
    }

    // Show pet stats
    void petStats() {
        std::cout << "\n[ 🐾 Pet Stats ]\n";
        std::cout << " Ya Pet's Name : " << pName
                  << "\n Ya Pet's Age : " << pAge
                  << "\n Ya Pet's a : " << getPetType(pType)
                  << "\n Ya Pet's Color : " << getPetColor(pColor)
                  << "\n Ya Pet's Mood : " << getPetMood(pMood)
                  << "\n Ya Pet's Hunger Lvl : " << getPetHunger(pHunger) << "\n";
    }

    // Abstract methods
    virtual void SpeakUp() = 0;
    virtual void Unsatisfied() = 0;
};

// ---------- DERIVED CLASSES ----------

class dogo : public PetAdopting {
public:
    dogo(std::string dName, int dAge, PetColor dColor)
        : PetAdopting(dName, dAge, Dog, dColor, Happy, Full) {}

    void SpeakUp() override {
        std::cout << "Woof Woof! \n ";
    }

    void Unsatisfied() override {
        std::cout << " Ruff... whimper... (why you do me like that, hooman)? \n ";
    }
};

class cato : public PetAdopting {
public:
    cato(std::string cName, int cAge, PetColor cColor)
        : PetAdopting(cName, cAge, Cat, cColor, Happy, Full) {}

    void SpeakUp() override {
        std::cout << " Meow Meow! \n ";
    }

    void Unsatisfied() override {
        std::cout << " Mreeeoooww! (You forgot to feed me AGAIN? Do you even want me to LIVE?) \n ";
    }
};

class hamstero : public PetAdopting {
public:
    hamstero(std::string hName, int hAge, PetColor hColor)
        : PetAdopting(hName, hAge, Hamster, hColor, Happy, Full) {}

    void SpeakUp() override {
        std::cout << " Squeak Squeak! \n ";
    }

    void Unsatisfied() override {
        std::cout << " ...squeak... (I miss my sunflower seeds... you're soo CRUEL Hooman) \n ";
    }
};

class bunnyy : public PetAdopting {
public:
    bunnyy(std::string bName, int bAge, PetColor bColor)
        : PetAdopting(bName, bAge, Bunny, bColor, Happy, Full) {}

    void SpeakUp() override {
        std::cout << " Purrs Purrs! \n ";
    }

    void Unsatisfied() override {
        std::cout << " *Thump!* (I'm not vibing with this energy, human. You're all same CRUEL Beings) \n ";
    }
};

// ---------- MAIN FUNCTION ----------

PetAdopting* pet = nullptr;

int main() {
    int age,color;
    std::string name;
    char op;

    std::cout << "\n========= WELCOME TO VIRTUAL PET ADOPTION SIM =========\n";

    // Input pet name
    std::cout << " What's Pet's name ?: ";
    std::getline(std::cin >> std::ws, name);

    // Input color
    std::cout << " What's ya Pet's Color ?\n";
    std::cout << "Black[1] | Brown[2] | Gray[3] | White[4] | Biege[5] : ";
    std::cin >> color;

    // Input age
    std::cout << " What's ya Pet's Age ? : ";
    std::cin >> age;

    // Loop until valid pet is created
    while(!pet){
        std::cout << "\nChoose ya Pet \n";
        std::cout << "Dog[1] \nCat[2] \nHamster[3] \nBunny[4] : ";
        std::cin >> op;

        switch (op) {
            case '1': pet = new dogo(name, age, static_cast<PetColor>(color)); break;
            case '2': pet = new cato(name, age, static_cast<PetColor>(color)); break;
            case '3': pet = new hamstero(name, age, static_cast<PetColor>(color)); break;
            case '4': pet = new bunnyy(name, age, static_cast<PetColor>(color)); break;
            default:
                std::cout << "bruh dude what're you doing ? there's nothing as " << op << " here use ya eyes fr fr \n";
                continue;
        }
    }

    int dangerWarning = 0; // Hunger warning counter

    // Game loop
    while (true) {
        char choice;

        std::cout << "\n========== What do you wanna do? ==========\n";
        std::cout << "Feed The Pet[F]\nPlay With Pet[P]\nDisplay Pet's Stats[S]\nQuit[Q]\n";
        std::cout << " Note : \"When Death Warning reaches 3 ya pet will die. So, to keep it alive \" \n ";
        std::cout << "Death Warning : " << dangerWarning << "\n";
        std::cin >> choice;

        switch (choice) {
            case 'F':
                pet->FeedPet();
                dangerWarning = 0; // Reset after feeding
                break;

            case 'P':
                pet->PlayWithPet();

                // Check mood and respond
                if (pet->getMood() == Happy) {
                    pet->SpeakUp();
                } else if (pet->getMood() == Sad || pet->getMood() == Sick || pet->getMood() == Angry) {
                    pet->Unsatisfied();
                }

                // Starving check
                if (pet->getHunger() == Starving) {
                    dangerWarning++;
                }

                if (dangerWarning >= 3) {
                    std::cout << " Ya Pet died 💀\n";
                    delete pet;
                    exit(EXIT_SUCCESS);
                }
                break;

            case 'S':
                pet->petStats();
                break;

            case 'Q':
                std::cout << " Exiting...\n";
                delete pet;
                exit(EXIT_SUCCESS);

            default:
                std::cout << " Bruh You're blind even with ya eyes there's no such option as " << choice << " \n ";
        }
    }

    return 0;
}

