#include <iostream>
#define FIELD_WIDTH 100
#define BALL_SPRITE 'O'
#define EMPTY_SPRITE ' '

int main() {
    char field[FIELD_WIDTH];
    bool isBallMovingRight = true;

    for (char &sprite : field) {
        sprite = EMPTY_SPRITE;
    }
    field[0] = BALL_SPRITE;

    for(;;) {
        int fieldPosition = 0;

        for (char sprite : field) {
            std::cout << sprite;
        }
        std::cout << std::endl;

        while (field[fieldPosition] != BALL_SPRITE) {
            fieldPosition++;
        }

        if (field[fieldPosition] == BALL_SPRITE) {
            if (fieldPosition == 0) {
                field[fieldPosition] = EMPTY_SPRITE;
                field[fieldPosition + 1] = BALL_SPRITE;
                isBallMovingRight = true;
            } else if (fieldPosition == FIELD_WIDTH - 1) {
                field[fieldPosition] = EMPTY_SPRITE;
                field[fieldPosition - 1] = BALL_SPRITE;
                isBallMovingRight = false;
            } else {
                field[fieldPosition] = EMPTY_SPRITE;
                if (isBallMovingRight) {
                    field[fieldPosition + 1] = BALL_SPRITE;
                } else {
                    field[fieldPosition - 1] = BALL_SPRITE;
                }
            }
        }
    }

    return 0;
}
