#include "stdafx.h"
#include "Juego.h"
#include "PantallaJuego.h"

enum class EstadoJuego {
    Inicio,
    Jugando,
    GameOver
};


void Instrucciones(sf::RenderWindow& ventana, PantallaJuego& estado);
void GameOver(sf::RenderWindow& ventana, int puntaje);
void BucleJuego(sf::RenderWindow& ventana, PantallaJuego& estado, int& puntaje, int& vidas);

int main() {
    sf::RenderWindow App(sf::VideoMode(800, 600), "GUNMAN");

    PantallaJuego estado = PantallaJuego::Inicio; 
    int puntaje = 0;
    int vidas = 3;

    while (App.isOpen()) {
        switch (estado) {
        case PantallaJuego::Inicio:
            Instrucciones(App, estado);
            break;
        case PantallaJuego::Jugando:
            BucleJuego(App, estado, puntaje, vidas);
            break;
        case PantallaJuego::GameOver:
            GameOver(App, puntaje);
            App.close(); 
            break;
        }
    }

    return 0;
}