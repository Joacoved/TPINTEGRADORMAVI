#pragma once
#include "stdafx.h"
#include "Enemigos.h"
#include "Civiles.h"
#include "PantallaJuego.h"
#include "CROSSHAIR.h"


void BucleJuego(sf::RenderWindow& App, PantallaJuego& estado, int& puntaje, int& vidas) {

    Texture texturajuego;
    Sprite spritejuego;

    texturajuego.loadFromFile("fondo1.jpg");
    spritejuego.setTexture(texturajuego);

    Vector2u tamañoVentana = App.getSize();
    Vector2u tamañoTextura = texturajuego.getSize();

    
    spritejuego.setScale(
        static_cast<float>(tamañoVentana.x) / tamañoTextura.x,
        static_cast<float>(tamañoVentana.y) / tamañoTextura.y
    );

    std::vector<sf::Vector2f> posicionesEnemigos = {
    {100, 150}, {300, 200}, {500, 100}, {700, 400}
    };

    std::vector<sf::Vector2f> posicionesCiviles = {
    {200, 300}, {400, 100}, {600, 500}, {700, 50}
    };

    Enemigo enemigo;
    Civil civil;
    PlayerCrosshair crosshair;

    App.setMouseCursorVisible(false);

    

    enemigo.aparecerAleatorio(posicionesEnemigos);
    civil.aparecerAleatorio(posicionesCiviles);

    sf::Clock relojCambio;
    float intervaloCambio = 01.0f;

    int balas = 10;
    int enemigosAbatidos = 0;
    int civilesAbatidos = 0;
    

    while (App.isOpen() && estado == PantallaJuego::Jugando) {
        sf::Event evt;
        while (App.pollEvent(evt)) {
            if (evt.type == sf::Event::Closed)
                App.close();

            if (evt.type == sf::Event::MouseButtonPressed && evt.mouseButton.button == sf::Mouse::Left) {
                if (balas > 0) {
                    balas--;
                    sf::Vector2i click = sf::Mouse::getPosition(App);

                    
                        if (enemigo.obtenerSprite().getGlobalBounds().contains(static_cast<float>(click.x), static_cast<float>(click.y))) {
                            enemigo.aparecerAleatorio(posicionesEnemigos);
                            enemigosAbatidos++;

                        }
                    

                    
                        if (civil.obtenerSprite().getGlobalBounds().contains(static_cast<float>(click.x), static_cast<float>(click.y))) {
                            civil.aparecerAleatorio(posicionesCiviles);
                            civilesAbatidos++;
                            vidas--;
                        }
                    

                    if (puntaje < 0) {
                        puntaje = 0;
                    }

                    if (vidas <= 0 || balas <= 0) {
                        
                        puntaje = enemigosAbatidos - 2* civilesAbatidos;
 
                        estado = PantallaJuego::GameOver;
                        return;

                    }
                }
            }
        }

        if (relojCambio.getElapsedTime().asSeconds() >= intervaloCambio) {
            enemigo.aparecerAleatorio(posicionesEnemigos);  
            civil.aparecerAleatorio(posicionesCiviles);    
            relojCambio.restart();  
        }

        Vector2i mousePos = sf::Mouse::getPosition(App);
        crosshair.Posicion(static_cast<float>(mousePos.x), static_cast<float>(mousePos.y));

        App.clear();
        App.draw(spritejuego);
        App.draw(enemigo.obtenerSprite());
        App.draw(civil.obtenerSprite());
        Font fuente;
        fuente.loadFromFile("Pink Vapor.ttf");
          

        Text textoBalas("Balas restantes: " + std::to_string(balas), fuente, 30);
        textoBalas.setPosition(10, 10);
        textoBalas.setFillColor(sf::Color::White);
        App.draw(textoBalas);

        Text textoVidas("Vidas restantes: " + std::to_string(vidas), fuente, 30);
        textoVidas.setPosition(10, 50);  
        textoVidas.setFillColor(sf::Color::White);
        App.draw(textoVidas);
        
        crosshair.Dibujar(&App);
        App.display();
        
    }
   
  
    
}