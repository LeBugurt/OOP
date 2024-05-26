#ifndef OOP_GAME_H
#define OOP_GAME_H
#pragma once

#include "grid.h"
#include "tetramino.cpp"

class Game {
public:
    // Метод для получения единственного экземпляра класса
    static Game& GetInstance() {
        static Game instance;
        return instance;
    }

    // Удаляем возможность копирования и присваивания
    Game(const Game&) = delete;
    Game& operator=(const Game&) = delete;

    void Draw();

    void HandleInput();

    void MoveBlockDown();

    bool gameOver;
    int score;

private:

    Game();

    void MoveBlockLeft();

    void MoveBlockRight();

    Block GetRandomBlock();

    std::vector<Block> GetAllBlocks();

    bool IsBlockOutside();

    void RotateBlock();

    void LockBlock();

    bool BlockContact();

    void UpdateScore(int linesCleared, int moveDownPoints);

    Grid grid;
    std::vector<Block> blocks;
    Block currentBlock;
    Block nextBlock;
    Sound rotateSound;
    Sound clearSound;
};

#endif //OOP_GAME_H
