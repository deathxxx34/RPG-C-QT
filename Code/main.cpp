#include <QApplication>
#include <QtWidgets>
#include "Game.h"
#include "magicien.h"

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);

    Magicien *perso = new Magicien;

    Game *game = new Game(nullptr);
    game->SetPersoMagicien(perso);
    game->show();

    return app.exec();
}
