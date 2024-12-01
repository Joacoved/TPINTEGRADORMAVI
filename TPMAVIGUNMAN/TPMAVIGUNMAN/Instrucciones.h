#pragma once
#include "stdafx.h"
#include "PantallaJuego.h"

void Instrucciones(sf::RenderWindow& App, PantallaJuego& estado) {
    Texture texturaInstrucciones;
    texturaInstrucciones.loadFromFile("Instrucciones.jpg");
     
    Sprite spriteInstrucciones;
    spriteInstrucciones.setTexture(texturaInstrucciones);

    Vector2u tama�oTextura = texturaInstrucciones.getSize();
    Vector2u tama�oVentana = App.getSize();
    spriteInstrucciones.setScale(
        static_cast<float>(tama�oVentana.x) / tama�oTextura.x,
        static_cast<float>(tama�oVentana.y) / tama�oTextura.y
    );

    while (App.isOpen() && estado == PantallaJuego::Inicio) {
        sf::Event evt;
        while (App.pollEvent(evt)) {
            if (evt.type == sf::Event::Closed) {
                App.close();  
            }

            
            if (evt.type == sf::Event::MouseButtonPressed && evt.mouseButton.button == sf::Mouse::Left) {
                estado = PantallaJuego::Jugando;  
                return;  
            }
        }

        App.clear();
        App.draw(spriteInstrucciones);
        App.display();
    }
}