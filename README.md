# 🎰 Wheel of Fortune (C++)

**Author:** Maya Jairam  
A fun console-based version of the classic game show *Wheel of Fortune*, written in C++. The game features puzzles, money spins, vowels and consonants, and even the chance to go bankrupt — all while trying to guess the hidden phrase!

---

## 🕹️ How the Game Works

- The player gets **3 rounds**, each with a hidden puzzle (from the category: *Fun and Games*).
- For each round, the player can:
  1. **Spin the Wheel** — land on a random dollar value, bankrupt, or lose a turn.
  2. **Buy a Vowel** — spend $250 to reveal vowels in the puzzle.
  3. **Solve the Puzzle** — attempt to guess the full phrase.

Each correct letter guessed earns money, and solving the puzzle gives a bonus.

---

## 🧠 Features

- Randomly selected puzzles from a predefined list
- Realistic wheel values including bankrupt, free play, and cash
- Input validation for vowels vs consonants
- Score tracking across rounds
- Case-insensitive puzzle solving
- Custom helper functions to keep logic modular and clear

---

## 🛠️ Key Functions

| Function | Purpose |
|---------|---------|
| `underscore(string x)` | Replaces letters with underscores for puzzle display |
| `iscorrect(string x, string y)` | Checks if the guessed sentence matches the puzzle |
| `isvowel(char x)` | Returns true if the letter is a vowel |
| `count(char x, string z)` | Counts the occurrences of a guessed letter |
| `reveal(char x, string known, string unknown)` | Reveals letters in the puzzle if guessed correctly |

---

