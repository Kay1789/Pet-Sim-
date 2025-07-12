# Pet-Sim-

# 🐾 Pet Simulator - C++ Edition

A small but wholesome C++ project where you can adopt a virtual pet, feed it, play with it, and watch it slowly descend into hunger if you forget to care 😭

## 💡 What It Does

This console-based game lets you:
- Adopt a **dog**, **cat**, **hamster**, or **bunny**
- Choose their **name**, **age**, and **color**
- Feed and play with them (yes, they have moods and hunger levels 💀)
- Watch your pet evolve as you care for it (or not...)

## 🧠 Concepts Practiced

- OOP (Object-Oriented Programming)
  - Classes & Inheritance
- Enums (for types, moods, hunger levels, colors, etc.)
- Conditionals (switch statements, if/else galore)
- Constructors (parametric ones too)
- Basic simulation logic

## ⚠️ Current Limitations

- Too many if-else and switch cases (I know 😭)
- No polymorphism yet, but that’s in the plan!
- No dynamic memory (`new/delete`) used... *yet*

## 🔧 Future Upgrades (Coming soon™️)

- Use of **polymorphism** to cut down the if-else spam
- Apply **dynamic memory** management with `new` and `delete`
- Maybe save pet data? (👀 files incoming?)
- Add random events (like mood swings, sickness, surprise cuddles etc.)
- GUI version... maybe... someday

## 📷 Preview

```cpp
// Sample interaction
What's ya pet's Name:  Luna
What's ya pet's age:  2
What's ya pet's color:
Black[1]
Brown[2]
Gray[3]
White[4]
Biege[5]
2
Dog[1]
Cat[2]
Bunny[3]
Hamster[4]
1

What do you wanna do?
Play with ya dog [P]
Feed ya dog [F]
Show pet stats [S]
Quit [Q]
P
Woof Woof!
This will Decrease ya pet's hunger lvl

✨ Why I Made This

Just practicing OOP and enums, getting comfy with inheritance before I dive into polymorphism. This is part of my daily grind to level up my C++ skills and build small fun projects that actually make me want to code 😎

📦 How to Run

Compile it with g++:

g++ -o petsim main.cpp
./petsim
