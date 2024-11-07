**RPG Game Workshop - C++ OOP and Templates**
This project is a simplified RPG (Role-Playing Game) simulation developed in C++ as part of an advanced programming workshop. It showcases key OOP principles, template programming, memory management practices, and design patterns in C++17. The project includes different character classes, such as Barbarian, Archer, and Rogue, each with unique health, attack, defense, weapon, and ability configurations.

Features
Character Templates: A templated CharacterTpl class manages character health and damage calculations, supporting fundamental and custom health types like SuperHealth.
Specialized Classes: Derived classes for each character type:
Barbarian with melee abilities and defensive skills.
Archer with ranged attacks and defense multipliers.
Rogue equipped with dual special abilities and enhanced attack tactics.
Memory Management: All code is compiled with debugging symbols and optimized for Valgrind to identify potential memory leaks.
Combat System: Each character has a unique attack method, managing abilities and weapon stats to deal variable damage to enemies.
Error Handling and Testing: Command-line testing using diff and Valgrind for debugging.
Tech Stack
Language: C++17
Tools: GCC 10.2.0, Valgrind, Git
Design Patterns: Template-based inheritance, Encapsulation, Modular Design
