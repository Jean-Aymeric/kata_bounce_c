#include <iostream>
#include <string>

#define FIELD_WIDTH 10
#define BALL_SPRITE_RIGHT '\\'
#define BALL_SPRITE_LEFT '/'
#define EMPTY_SPRITE ' '
#define EDGE_SPRITE '|'
#define FIELD_HAS_EDGES true
#define BALL_STARTING_POSITION 0 + (FIELD_HAS_EDGES ? 1 : 0)
#define BALL_STARTING_DIRECTION_RIGHT true

int main() {
    std::string field;
    bool isBallMovingRight = BALL_STARTING_DIRECTION_RIGHT;
    bool bounceInProgress = false;

    field.resize(FIELD_WIDTH + (FIELD_HAS_EDGES ? 2 : 0));
    for (char &sprite: field) {
        sprite = EMPTY_SPRITE;
    }
    if (FIELD_HAS_EDGES) {
        field[0] = EDGE_SPRITE;
        field[FIELD_WIDTH - 1] = EDGE_SPRITE;
    }
    field[BALL_STARTING_POSITION] = BALL_STARTING_DIRECTION_RIGHT ? BALL_SPRITE_RIGHT : BALL_SPRITE_LEFT;

    for (;;) {
        int fieldPosition = 0;
        bounceInProgress = false;
        std::cout << field << std::endl;

        while (field[fieldPosition] != (isBallMovingRight ? BALL_SPRITE_RIGHT : BALL_SPRITE_LEFT)) {
            fieldPosition++;
        }
        if ((fieldPosition == 0 + (FIELD_HAS_EDGES ? 1 : 0)) && !isBallMovingRight) {
            isBallMovingRight = true;
            bounceInProgress = true;
            field[fieldPosition] = BALL_SPRITE_RIGHT;
        }
        if ((fieldPosition == FIELD_WIDTH - (1 + (FIELD_HAS_EDGES ? 1 : 0))) && isBallMovingRight) {
            isBallMovingRight = false;
            bounceInProgress = true;
            field[fieldPosition] = BALL_SPRITE_LEFT;
        }
        if (!bounceInProgress) {
            field[fieldPosition] = EMPTY_SPRITE;
            if (isBallMovingRight) {
                field[fieldPosition + 1] = BALL_SPRITE_RIGHT;
            } else {
                field[fieldPosition - 1] = BALL_SPRITE_LEFT;
            }
        }
    }

    return 0;
}
