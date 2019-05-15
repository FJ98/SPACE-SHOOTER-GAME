# Galaga

## Diagrama de Clases del Proyecto
UML(Agregar Link al diagrama de clases)
El proyecto fue probado en Ubuntu 18.04.1 LTS
- [UML]```(https://github.com/TISparta/Galaga/blob/master/uml_final.jpg) MODIFICAR!```

## Ejecutar Galaga
Instructiones para obtener una copia del proyecto y poder correrlo en tu computadora.

### Prerequisites
What things you need to install the software and how to install them

**Prerequisitos**
- [SFML](https://www.sfml-dev.org/)
En Ubuntu se puede instalar SFML con el siguiente comando:
```bash
sudo apt-get install libsfml-dev
```

**Ejecución**
```
git clone https://github.com/FJ98/Galaga.git
cd Galaga
bash run.sh
./Galaga.out
```

### Estilos seguidos para escribir del codigo

## Pequeño estilo a seguir:

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

## Autor
**Felix Jesus Solano Vergara 
- Ciencias de la Conputacion - Universidad de Ingenieria y Tecnologia (UTEC)**
**- Barranco, Lima - Peru** 

## Licencia

Este proyecto esta bajo **licencia MIT** - ver el folder [LICENSE.md](LICENSE.md) para mas informacion

[Referencia](https://www.youtube.com/watch?v=dvjapcHsqXY&t=142s)
