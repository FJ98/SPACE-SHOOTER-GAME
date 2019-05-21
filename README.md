# Galaga

## Diagrama de Clases del Proyecto
- [UML](https://github.com/FJ98/Galaga/blob/master/UML-Galaga.pdf)
El proyecto fue probado en Ubuntu 18.04.1 LTS

## Ejecutar Galaga
Instructiones para obtener una copia del proyecto y poder correrlo en tu computadora.

### Prerequisitos
**Instalar SFML**
- [SFML](https://www.sfml-dev.org/)
En Ubuntu se puede instalar SFML con el siguiente comando:
```bash
sudo apt-get install libsfml-dev
```

- Para unir SFML con Clion seguir el siguiente tutorial: [Como linkear SFML con Clion](https://github.com/FJ98/Galaga/blob/master/Como%20linkear%20SFML%20con%20Clion.pdf) 
Creditos: Luis Ponce Contreras - alumno de Ciencias de la Computacion - Universidad de Ingenieria y Tecnologia (UTEC) - Barranco, Lima-Peru

**Asegurate de tener instalado g++**
- [g++](https://linuxconfig.org/how-to-install-g-the-c-compiler-on-ubuntu-18-04-bionic-beaver-linux)
En Ubuntu se puede instalar g++ con el siguiente comando:
```
sudo apt-get install g++
```

**Ejecución del juego**
```
git clone https://github.com/FJ98/Galaga.git
cd Galaga
bash run.sh
./Galaga.out
```

## Estilos seguidos para escribir del codigo
1. Poner tab como 2 espacios en tu editor (para que se vea bien cuando lo subas
   a github)
2. Estilo seguido para el nombre de cada class: **PascalCase**
3. Estilo seguido para el nombre de las funciones y las variables: **camelCase**
4. Estilo de Indentacion: [K & R style - Variant: Stroustrup](https://en.wikipedia.org/wiki/Indentation_style#Variant:_Stroustrup)
5. Entre llamados a estructuras de repeticion, de control, operadores,
   parentesis, asignacion, definicion de funcion (donde veas necesario)
   poner 1 espacio. Por ejemplo:
   
```c++
  void foo () { return 1; }

  void myFunction (int a, int b) {
    for (int i = a; i <= b; i++) {
      if (a % 2 == 0) foo();
    }
  }

```
6. Si una linea es muy ancha separarla a criterio propio

### Autor
**Felix Jesus Solano Vergara - Facultad de Ciencias de la Computacion - Universidad de Ingenieria y Tecnologia (UTEC) - Barranco, Lima - Peru (2019)**

#### Licencia

Este proyecto esta bajo **licencia MIT** - ver el folder [LICENSE.md](LICENSE.md) para mas informacion

[Referencia](https://www.youtube.com/watch?v=dvjapcHsqXY&t=)
