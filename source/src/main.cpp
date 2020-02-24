#include "game.hpp"
#include "menu_state.hpp"

int main()
{
    Game game;

    game.pushState(new MenuState(&game));
    game.gameLoop();

    return 0;
}