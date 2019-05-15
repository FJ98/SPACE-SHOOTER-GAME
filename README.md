# Galaga

## Diagrama de Clases del Proyecto
UML(Agregar Link al diagrama de clases)
El proyecto fue probado en Ubuntu 18.04.1 LTS
- [UML]```(https://github.com/TISparta/Galaga/blob/master/uml_final.jpg) MODIFICAR!```

## Ejecutar Galaga

Instructiones para obtener una copia del proyecto y poder correrlo en tu computadora will get you a copy of the project up and running on your local machine for development and testing purposes. See deployment for notes on how to deploy the project on a live system.

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
### Installing

A step by step series of examples that tell you how to get a development env running

Say what the step will be

```
Give the example
```

And repeat

```
until finished
```

End with an example of getting some data out of the system or using it for a little demo

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

## Deployment

Add additional notes about how to deploy this on a live system

## Built With

* [Dropwizard](http://www.dropwizard.io/1.0.2/docs/) - The web framework used
* [Maven](https://maven.apache.org/) - Dependency Management
* [ROME](https://rometools.github.io/rome/) - Used to generate RSS Feeds

## Contributing

Please read [CONTRIBUTING.md](https://gist.github.com/PurpleBooth/b24679402957c63ec426) for details on our code of conduct, and the process for submitting pull requests to us.

## Versioning

We use [SemVer](http://semver.org/) for versioning. For the versions available, see the [tags on this repository](https://github.com/your/project/tags). 

## Authors

* **Billie Thompson** - *Initial work* - [PurpleBooth](https://github.com/PurpleBooth)

See also the list of [contributors](https://github.com/your/project/contributors) who participated in this project.

## License

This project is licensed under the MIT License - see the [LICENSE.md](LICENSE.md) file for details

## Acknowledgments

* Hat tip to anyone whose code was used
* Inspiration
* etc


[Referencia](https://www.youtube.com/watch?v=bUPWWuI2EY4)
