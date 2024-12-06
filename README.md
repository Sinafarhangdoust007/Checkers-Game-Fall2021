# Checkers Game in C++

## Description
This project is a two-player Checkers game implemented in C++. It features a traditional 8x8 board, where players take turns moving their pieces, capturing opponent pieces, and promoting pieces to kings.
The game strictly adheres to the classic rules of Checkers and is played via a simple and interactive command-line interface.

The project is designed for educational purposes and demonstrates the implementation of game logic, user input validation, and algorithmic thinking.

---

## Features
### Gameplay Features
- **Customizable Symbols**: Players can choose their own symbols to represent their pieces (e.g., X, O).
- **Turn Management**: Alternating turns ensure fair play.
- **Piece Movement**:
  - Normal pieces move diagonally forward.
  - Kings, upon promotion, can move diagonally in all directions.
- **Capture Rules**:
  - Players can capture opponent pieces by jumping over them diagonally.
  - Supports multi-capture sequences in a single turn.
  - Enforces mandatory captures when available.
- **King Promotion**:
  - Pieces are promoted to kings when they reach the opponent’s back row.
  - Kings have extended movement capabilities.
- **Winning Conditions**:
  - A player wins when the opponent has no valid moves or pieces left.
  - The game detects winners automatically.

### Technical Features
- **Interactive Command-Line Interface**:
  - Displays the game board after every turn.
  - Provides clear prompts and feedback for player actions.
- **Real-Time Error Handling**:
  - Validates all inputs and game actions.
  - Offers descriptive error messages for invalid moves or incorrect inputs.
- **Modular Code**:
  - The program is structured with reusable functions for board management, movement validation, and game state checks.
- **Scalable Design**:
  - The logic can be extended to include additional features like AI opponents or custom rules.

---

## How to Install and Run
1. Clone the repository to your local machine:
   ```bash
   git clone <repository-url>
   cd checkers-game-cpp
