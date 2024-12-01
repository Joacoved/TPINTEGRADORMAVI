#include "GameOver.h"

void GameOver::mostrar(sf::RenderWindow& App, int puntaje)
{
}
void GameOver(sf::RenderWindow& App, int puntaje) {
    Texture texturaGameOver;
    Sprite spritegameover;

    texturaGameOver.loadFromFile("game over.jpg");
    spritegameover.setTexture(texturaGameOver);

    Vector2u tamañoTextura = texturaGameOver.getSize();
    Vector2u tamañoVentana = App.getSize();
    spritegameover.setScale(
        static_cast<float>(tamañoVentana.x) / tamañoTextura.x,
        static_cast<float>(tamañoVentana.y) / tamañoTextura.y
    );




    Font fuente;
    fuente.loadFromFile("Pink Vapor.ttf");

    Text textoPuntaje;
    textoPuntaje.setFont(fuente);
    textoPuntaje.setString("Puntaje: " + std::to_string(puntaje));
    textoPuntaje.setCharacterSize(50);
    textoPuntaje.setFillColor(sf::Color::White);
    textoPuntaje.setPosition(100, 400);

    while (App.isOpen()) {
        sf::Event evt;
        while (App.pollEvent(evt)) {
            if (evt.type == sf::Event::Closed)
                App.close();
        }

        App.clear();
        App.draw(spritegameover);
        App.draw(textoPuntaje);
        App.display();
    }
}