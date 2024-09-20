#include <iostream>

#define FIELD_WIDTH 10
#define BALL_SPRITE 'O'
#define EMPTY_SPRITE '.'
#define EDGE_SPRITE '|'
#define FIELD_HAS_EDGES true
#define BALL_STARTING_POSITION 0 + (FIELD_HAS_EDGES ? 1 : 0)
#define BALL_STARTING_DIRECTION_RIGHT true

int main() {
    char field[FIELD_WIDTH];
    bool isBallMovingRight = BALL_STARTING_DIRECTION_RIGHT;

    for (char &sprite: field) {
        sprite = EMPTY_SPRITE;
    }
    if (FIELD_HAS_EDGES) {
        field[0] = EDGE_SPRITE;
        field[FIELD_WIDTH - 1] = EDGE_SPRITE;
    }
    field[BALL_STARTING_POSITION] = BALL_SPRITE;

    for (;;) {
        int fieldPosition = 0;

        for (char sprite: field) {
            std::cout << sprite;
        }
        std::cout << std::endl;

        while (field[fieldPosition] != BALL_SPRITE) {
            fieldPosition++;
        }
        if ((fieldPosition == 0 + (FIELD_HAS_EDGES ? 1 : 0)) && !isBallMovingRight) {
            isBallMovingRight = true;
        }
        if ((fieldPosition == FIELD_WIDTH - (1 + (FIELD_HAS_EDGES ? 1 : 0))) && isBallMovingRight) {
            isBallMovingRight = false;
        }
        field[fieldPosition] = EMPTY_SPRITE;
        if (isBallMovingRight) {
            field[fieldPosition + 1] = BALL_SPRITE;
        } else {
            field[fieldPosition - 1] = BALL_SPRITE;
        }
    }

    return 0;
}
