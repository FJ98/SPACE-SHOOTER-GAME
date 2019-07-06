// Created by felix on 7/5/2019.
#ifndef JUEGOFINAL_FUNCIONES_H
#define JUEGOFINAL_FUNCIONES_H

// Funciones Utiles se utilizan para minimizar el codigo
// al cargar (inicializar) las texturas, fonts y musica.
template<typename T>
void cargar(T &target, const sf::String& path) {
    target.loadFromFile(path);
}

template <>
inline void cargar<sf::Music>(sf::Music& target, const sf::String& path) {
    target.openFromFile(path);
}

// FUNCION QUE ACEPTA VECTOR
template <typename T>
void confText(T& text,
              sf::Font* font, int tamLetra,
              std::vector<T>* textVector,
              const sf::String& str = "Def Txt",
              sf::Color color = sf::Color::White,
              sf::Vector2f position = {0.0f,0.0f},
              sf::Uint32 style = sf::Text::Italic){
    text.setFont(*font);
    text.setString(str);
    text.setCharacterSize(tamLetra);
    text.setFillColor(color);
    text.setStyle(style);
    text.setPosition(position);
    textVector->emplace_back(text);
}
// FUNCION QUE NO ACEPTA VECTOR
template <typename T>
void confText(T& text,
              sf::Font* font, int tamLetra,
              const sf::String& str = "Def Txt",
              sf::Color color = sf::Color::White,
              sf::Vector2f position = {0.0f,0.0f},
              sf::Uint32 style = sf::Text::Regular){
    text.setFont(*font);
    text.setString(str);
    text.setCharacterSize(tamLetra);
    text.setFillColor(color);
    text.setStyle(style);
    text.setPosition(position);
}

#endif //JUEGOFINAL_FUNCIONES_H
