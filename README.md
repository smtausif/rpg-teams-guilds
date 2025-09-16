# ⚔️ RPG Teams and Guilds — C++17

A C++17 simulation that builds **Teams** and **Guilds** of characters, tests copy/move semantics (Rule of 5), and runs a logged combat system with abilities like **Berserk** and **Heal**.  
This project was developed as part of an Object-Oriented Programming assignment and demonstrates advanced C++ concepts including templates, polymorphism, and memory management.

---

## ✨ Features

- Build Teams and Guilds of characters with stats (health, attack, defense).  
- Add and remove members dynamically.  
- Demonstrates the **Rule of 5**:
  - Copy Constructor  
  - Copy Assignment  
  - Move Constructor  
  - Move Assignment  
  - Destructor  
- **Battle Engine** with round-by-round combat:
  - Berserk (double damage, reduced incoming)  
  - Heal (restore health up to max)  
  - Defense mitigation (damage reduction)  
- Deterministic logging for testing and comparison (`sample_output.txt`).  

---

## 🧱 Project Structure

| File                | Purpose 
|---------------------|---------
| `tester_1.cpp`      | Main driver, runs scenarios T1–T11 and prints logs 
| `team.cpp/h`        | Team container, implements Rule of 5, manages members 
| `guild.cpp/h`       | Guild container, similar to Team with Rule of 5 
| `character.h`       | Base abstract class for characters 
| `characterTpl.h`    | Templated character class (`CharacterTpl<T>`) with generic health type 
| `barbarian.h`       | Barbarian class with Berserk ability 
| `archer.h`          | Archer class 
| `rogue.h`           | Rogue class 
| `abilities.h`       | Ability definitions and cooldown logic 
| `health.h`          | Health helpers, clamps values between 0 and max 
| `weapons.h`         | Weapon stats for combat calculations 
| `sample_output.txt` | Reference log of expected output 

---

## 🧠 Key Concepts Demonstrated

- **C++17 Standard**  
- **Rule of 5** (deep copy, move semantics, destructor)  
- **Templates** (`CharacterTpl<T>`)  
- **Polymorphism** (base `Character` with derived classes)  
- **File organization** across multiple `.cpp`/`.h` modules  
- **Combat simulation** with abilities and defense logic  

---

## 🏗️ Build & Run

### Compile
```bash
# Compile all source files
g++ -Wall -std=c++17 -g -o game *.cpp

### run
./game


## 📊 Example Output

T1: Building the Teams of Characters
[Team] The Procrastinators
    1: Quick Silver   Health: 100% (950/950)   Attack: 58   Defense: 77
    2: Rogue Ronin    Health: 100% (800/800)   Attack: 75   Defense: 50
...

T10: Epic battle between Master Chief and Mercy Less
[Round 1]
Master Chief is attacking Mercy Less.
    Berserk is activated for the next 6 seconds. Cooldown is 10 seconds.
    Berserk is active; increasing damage dealt from [121] to [242].
    Barbarian deals 242 melee damage!
Mercy Less took 234 damage, 966 health remaining.