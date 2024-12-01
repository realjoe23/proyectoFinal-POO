# Registro de Bienes Inmuebles - README  

## Descripción del Proyecto  
Este proyecto es una solución orientada a objetos en C++ para gestionar un registro de bienes inmuebles administrados por una empresa inmobiliaria. Los inmuebles pueden ser de diferentes tipos: **Casa Habitación**, **Local Comercial**, **Edificio** o **Departamento**, cada uno con características específicas.  

El sistema permite realizar las siguientes operaciones:  
- Añadir nuevos inmuebles.  
- Eliminar inmuebles existentes.  
- Ordenar los inmuebles por clave catastral.  
- Listar los inmuebles registrados.  
- Leer y escribir los registros en disco para garantizar la persistencia de los datos.  

## Características  
### Tipos de Inmuebles  
Cada tipo de inmueble tiene atributos específicos:  

- **Casa Habitación**  
  - Clave catastral  
  - Domicilio  
  - Dueño  
  - Superficie de terreno  
  - Superficie construida  
  - Número de habitaciones  

- **Local Comercial**  
  - Clave catastral  
  - Domicilio  
  - Dueño  
  - Superficie de terreno  
  - Superficie construida  
  - Giro comercial  

- **Edificio**  
  - Clave catastral  
  - Domicilio  
  - Dueño  
  - Superficie de terreno  
  - Superficie construida  
  - Número de pisos  

- **Departamento**  
  - Clave catastral  
  - Domicilio  
  - Dueño  
  - Superficie de terreno  
  - Superficie construida  
  - Número interior  

### Datos Compuestos  
- **Dueño**: Incluye CURP, nombre completo y apellidos.  
- **Domicilio**: Incluye calle, número y código postal.  

### Funcionalidades  
- Inserción y eliminación de inmuebles de cualquier tipo.  
- Ordenamiento de inmuebles por clave catastral.  
- Listado de inmuebles en pantalla.  
- Persistencia de datos mediante lectura y escritura en disco.  

## Estructura del Proyecto  
### Clases Implementadas  
1. **Inmueble (Clase Base):** Representa atributos comunes a todos los tipos de inmuebles.  
2. **Casa, Local, Edificio, Departamento (Clases Derivadas):** Extienden la clase base y añaden atributos específicos.  
3. **Contenedor:** Clase genérica que almacena objetos de cualquier tipo de inmueble, con métodos para insertar, eliminar, ordenar y listar.  
4. **Interfaz:** Gestiona la interacción con el usuario y permite realizar las operaciones sobre el registro.  

### Diagrama UML  
El diagrama UML incluye las relaciones entre las clases, destacando el uso de **herencia**, **composición** y **dependencia**.  

## Requisitos  
- **Lenguaje:** C++  
- **Compilador:** Compatible con C++11 o superior  
- **Sistema Operativo:** Multiplataforma (Windows, Linux, macOS)  
