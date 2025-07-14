#include <cctype>       // For toupper() to handle case-insensitive input
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

// Convert PetType enum to string for easy display
auto getPetType(PetType pt){
    switch(pt){
        case Dog: return "Dog";
        case Cat: return "Cat";
        case Hamster: return "Hamster";
        case Bunny: return "Bunny";
        default: return "Alien Pet ";  // Just in case something wild happens
    }
}

// Enum for pet colors
enum PetColor {
    Black = 1,
    Brown,
    Gray,
    White,
    Beige,
};

// Convert PetColor enum to readable string
auto getPetColor(PetColor pc){
    switch (pc) {
        case Black: return "Black";
        case Brown: return "Brown";
        case White: return "White";
        case Gray: return "Gray";
        case Beige: return "Beige";
        default: return " Cool new color "; // fallback for unexpected values
    }
}

// Enum for pet moods
enum PetMood {
    Happy = 1,
    Sad,
    Angry,
    Sick,
    Playful,
};

// Convert PetMood enum to string
auto getPetMood(PetMood pm){
    switch(pm){
        case Happy: return "Happy";
        case Sad: return "Sad";
        case Angry: return "Angry";
        case Sick: return "Sick";
        case Playful: return "Playful";
        default: return "You Ok? Buddy"; // fallback if mood unknown
    }
}

// Enum for hunger levels, with numeric values for easier comparison
enum PetHungerLvl {
    Full = 100,
    Satisfied = 60,
    Hungry = 30,
    Starving = 10,
};

// Convert hunger enum to string for display
auto getPetHunger(PetHungerLvl phl){
    switch (phl) {
        case Full: return "Full";
        case Satisfied: return "Satisfied";
        case Hungry: return "Hungry";
        case Starving: return "Starving";
        default: return " Why you Ain't eating? ";
    }
}

// New enum for pet energy levels
enum PetEnergy{
    Hyper = 100,
    Energized = 60,
    Kinda_Tired = 30,
    Dead_Inside = 10,
};

// Convert energy enum to string for showing pet's energy status
auto getPetEnergyLvl(PetEnergy pe){
    switch (pe) {
        case Hyper: return "Hyper";
        case Energized: return "Energized";
        case Kinda_Tired: return "Kinda Tired";
        case Dead_Inside: return "Dead Inside";
        default: return " Ya Pet can't even Breath Anymore";
    }
}

// ---------- BASE CLASS: PETADOPTING ----------

class PetAdopting {
protected:
    std::string pName;       // Pet's name
    int pAge;                // Pet's age
    PetType pType;           // Type of pet (dog, cat, etc)
    PetColor pColor;         // Color of the pet
    PetMood pMood;           // Current mood of pet
    PetHungerLvl pHunger;    // Hunger level
    PetEnergy pEnergy;       // Energy level

public:
    // Constructor initializes all pet attributes
    PetAdopting(std::string nameP, int ageP, PetType typeP, PetColor colorP, PetMood moodP, PetHungerLvl hungerP, PetEnergy energyP)
        : pName(nameP), pAge(ageP), pType(typeP), pColor(colorP), pMood(moodP), pHunger(hungerP),pEnergy(energyP) {}

    virtual ~PetAdopting() = default; // Virtual destructor for proper cleanup

    // Getters for mood, hunger, energy
    auto getMood() const { return pMood; }
    auto getHunger() const { return pHunger; }
    auto getEnergy() const { return pEnergy; }

    // Feed pet to increase hunger level and change mood accordingly
    void FeedPet() {
        std::cout << "\n[ Feeding Pet 🥩 ]\n";
        switch (pHunger) {
            case Starving: pHunger = Hungry; pMood = Angry; break;       // From starving to hungry, mood angry (hangry lol)
            case Hungry: pHunger = Satisfied; pMood = Happy; break;      // Hungry to satisfied, mood happy
            case Satisfied: pHunger = Full; pMood = Playful; break;       // Satisfied to full, mood playful
            case Full:
                std::cout << " Ya pet is Already Full ";
                pMood = Playful;                                         // If full, keep playful mood
                break;
            default:
                std::cout << " Ya pet ain't eating cux you ain't feeding it \n ";
                break;
        }
    }

    // Play with pet, decreases hunger but affects mood and energy
    void PlayWithPet() {
        std::cout << "\n[ Playing With Pet 🎾 ]\n";
        switch (pHunger) {
            case Full: pHunger = Satisfied; pMood = Happy; pEnergy = Hyper; break;
            case Satisfied: pHunger = Hungry; pMood = Angry; pEnergy = Energized ;break;
            case Hungry: pHunger = Starving; pMood = Sad; pEnergy = Kinda_Tired ;break;
            case Starving:
                std::cout << " Ya Pet's Starving and Tired feed it and let it rest it's not a machine  or it'll die of hunger \n ";
                pMood = Sick; pEnergy = Dead_Inside; break;
            default:
                std::cout << " Feed ya pet ";
                break;
        }
    }

    // Let pet sleep to regain energy (energy improves step by step)
    void SleepPet() {
        std::cout << "\n [Ya Pet's Sleeping 😴]\n";
        switch (pEnergy) {
            case Dead_Inside: pEnergy = Kinda_Tired; break;     // Sleep ups energy from dead inside to kinda tired
            case Kinda_Tired: pEnergy = Energized; break;       // Then energized
            case Energized: pEnergy = Hyper; break;             // Then hyper (max energy)
            case Hyper: std::cout << " Ya pet's full of energy \n "; // If already max energy, no change
            default: std::cout << " What did you expect? you ain't letting ya pet to sleep so ofc it can't play \n ";
        }
    }

    // Display all pet stats nicely formatted
    void petStats() {
        std::cout << "\n[ 🐾 Pet Stats ]\n";
        std::cout << " Ya Pet's Name : " << pName
                  << "\n Ya Pet's Age : " << pAge
                  << "\n Ya Pet's a : " << getPetType(pType)
                  << "\n Ya Pet's Color : " << getPetColor(pColor)
                  << "\n Ya Pet's Mood : " << getPetMood(pMood)
                  << "\n Ya Pet's Hunger Lvl : " << getPetHunger(pHunger)
                  << "\n Ya Pet's Energy Lvl : " << getPetEnergyLvl(pEnergy) << "\n";
    }

    // Virtual methods to be implemented by each specific pet type
    virtual void SpeakUp() = 0;
    virtual void Unsatisfied() = 0;
    virtual void sleep() = 0;
};

// ---------- DERIVED CLASSES ----------

class dogo : public PetAdopting {
public:
    // Constructor sets default pet type, mood, hunger and energy
    dogo(std::string dName, int dAge, PetColor dColor)
        : PetAdopting(dName, dAge, Dog, dColor, Happy, Full,Hyper) {}

    void SpeakUp() override {
        std::cout << "Woof Woof! \n ";
    }

    void Unsatisfied() override {
        std::cout << " Ruff... whimper... (why you do me like that, hooman)? \n ";
    }

    void sleep() override {
        std::cout << "grrrr... 😒 huff... huff... 💤 boof... (Why hooman? let me sleep 😔) “rrrRRRffff...” tail thump \n ";
    }
};

class cato : public PetAdopting {
public:
    cato(std::string cName, int cAge, PetColor cColor)
        : PetAdopting(cName, cAge, Cat, cColor, Happy, Full,Hyper) {}

    void SpeakUp() override {
        std::cout << " Meow Meow! \n ";
    }

    void Unsatisfied() override {
        std::cout << " Mreeeoooww! (You forgot to feed me AGAIN? Do you even want me to LIVE?) \n ";
    }

    void sleep()override {
        std::cout << "  mrmmmmmrrrpphhh... 💤 mehh... mrrrp...” Stares at you like you're the biggest disappointment in its life 💀   ";
    }
};

class hamstero : public PetAdopting {
public:
    hamstero(std::string hName, int hAge, PetColor hColor)
        : PetAdopting(hName, hAge, Hamster, hColor, Happy, Full,Hyper) {}

    void SpeakUp() override {
        std::cout << " Squeak Squeak! \n ";
    }

    void Unsatisfied() override {
        std::cout << " ...squeak... (I miss my sunflower seeds... you're soo CRUEL Hooman) \n ";
    }

    void sleep() override {
        std::cout << "   skrrrr skkrrrr *🛌🐹 tikitikitikitik  (tiny foot slaps as it dives deeper WHO DARES DISTURB THE NEST\?\?\?)   chipchipchip!! 🐹💢 (tiny bite threat) \n ";
    }
};

class bunnyy : public PetAdopting {
public:
    bunnyy(std::string bName, int bAge, PetColor bColor)
        : PetAdopting(bName, bAge, Bunny, bColor, Happy, Full,Hyper) {}

    void SpeakUp() override {
        std::cout << " Purrs Purrs! \n ";
    }

    void Unsatisfied() override {
        std::cout << " *Thump!* (I'm not vibing with this energy, human. You're all same CRUEL Beings) \n ";
    }

    void sleep() override {
        std::cout << "huff... huff...” THUMP 🐇(I hate you but I’m too tired to fight rn and Don’t talk to me or my hay again.) sniff... huff... THUMP (the bunny version of slamming a door) \n ";
    }
};

// ---------- MAIN FUNCTION ----------

PetAdopting* pet = nullptr;

int main() {
    int age,color;
    std::string name;
    char op;

    std::cout << "\n========= WELCOME TO VIRTUAL PET ADOPTION SIM =========\n";

    // Get pet name from user input
    std::cout << " What's Pet's name ?: ";
    std::getline(std::cin >> std::ws, name);

    // Get pet color selection from user
    std::cout << " What's ya Pet's Color ?\n";
    std::cout << "Black[1] | Brown[2] | Gray[3] | White[4] | Beige[5] : ";
    std::cin >> color;

    // Get pet age
    std::cout << " What's ya Pet's Age ? : ";
    std::cin >> age;

    // Loop until user picks a valid pet type, then create pet object
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

    int dangerWarning = 0; // Counts how many times pet is close to dying

    // Game loop: runs until user quits or pet dies
    while (true) {
        char choice;

        std::cout << "\n========== What do you wanna do? ==========\n";
        std::cout << "Feed The Pet[F]\nPlay With Pet[P]\nDisplay Pet's Stats[S] \nSleep[Z] \nQuit[Q]\n";
        std::cout << " Note : \"When Death Warning reaches 3 ya pet will die. So, keep it alive \" \n ";
        std::cout << "Death Warning : " << dangerWarning << "\n";
        std::cin >> choice;
        choice = std::toupper(choice);  // make input uppercase for easier comparison

        switch (choice) {
            case 'F':
                pet->FeedPet();          // Feed pet to increase hunger and improve mood
                dangerWarning = 0;       // Reset danger warning since pet got food
                break;

            case 'P':
                pet->PlayWithPet();      // Play with pet to use energy but affects hunger

                // React to pet's mood with appropriate sounds or messages
                if (pet->getMood() == Happy) {
                    pet->SpeakUp();
                } else if (pet->getMood() == Sad || pet->getMood() == Sick || pet->getMood() == Angry) {
                    pet->Unsatisfied();
                }

                // If pet is starving, increase danger warning counter
                if (pet->getHunger() == Starving) {
                    dangerWarning++;
                }

                // If danger warning hits 3, pet dies
                if (dangerWarning >= 3) {
                    std::cout << " Ya Pet died 💀 of Hunger\n";
                    delete pet;           // Free memory
                    exit(EXIT_SUCCESS);
                }
                break;

            case 'S':
                pet->petStats();         // Show pet's current stats
                break;

            case 'Z': 
                pet->SleepPet();         // Let pet sleep to regain energy

                if(pet->getEnergy() == Hyper || pet->getEnergy() == Energized){
                    std::cout << " I'm full of energy Hooman \n ";
                } else if(pet->getEnergy() == Kinda_Tired || pet->getEnergy() == Dead_Inside){
                    pet->sleep();        // Show pet's sleepy messages
                }

                // If pet is super tired, increase danger warning
                if(pet->getEnergy() == Dead_Inside){
                    dangerWarning++;
                }

                // Pet dies if danger warning hits 3 due to no sleep
                if(dangerWarning >= 3){
                    std::cout << " Ya Pet Died 💀 Cux Lack of Sleep \n ";
                    delete pet;
                    exit(EXIT_SUCCESS);
                }
                break;

            case 'Q':
                std::cout << " Exiting...\n";
                delete pet;               // Clean up memory before quitting
                exit(EXIT_SUCCESS);

            default:
                std::cout << " Bruh You're blind even with ya eyes there's no such option as " << choice << " \n ";
        }
    }

    return 0;
}
