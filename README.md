# Proyecto1
proyecto algoritmos y estructuras de datos, UTN k1024 grupo 10
Lucciano Campassi
Mauro Nicolas Fernandez
Laureano Martinez Moreno
Agustin Mauricio Benitez


#modulo 1

#modulo 2

#modulo 3
En esta explicación, vamos a dar detalles técnicos sobre la funcionalidad de nuestro código.
Como objetivos en este módulo, propusimos que el usuario pueda iniciar sesión mediante el uso de un mail y una clave la cual tuvo que crear con anterioridad. Esto lo pudimos hacer haciendo un struct llamado “Estudiante”, en el cual tenía estos términos dentro del mismo: static int numero_legajo; int legajo; string email; string clave; string nombre; int méritos. Para iniciar sesión, al usuario se le darán 2 opciones. La primera sería que el usuario inicie sesión y la segunda opción sería salir del programa lo cual terminaría la programación.
En el inicio de sesión, se toma en cuenta todos los datos guardados en el archivo “Registros.dat” y se chequea que el mail y clave ingresados son los correctos. En el caso de no serlo, el programa te dirá que tus credenciales no son las correctas.

Al ingresar sesión, se despliega el menú de beneficios, el cual tiene varias opciones de las cuales elegir. 
La primera sería “mostrar créditos disponibles”. Si el usuario elige esta opción, entonces se le mostrará los méritos que tiene a su nombre (todos los usuarios empiezan con 1000 puntos). 
Luego, el segundo llamado “mostrar beneficios disponibles”, lo que hace es mostrarle al usuario todos los beneficios disponibles para comprar y el precio al que se encuentran.
El tercero es llamado “consumir beneficio", y en este lo que se hace es que se le da la libertad al usuario de elegir el beneficio que más le guste, a cambio de tener que pagarlo con los méritos que tiene guardados.
El cuarto, “Acreditar los logros”. Al elegir esta opción, el usuario tiene la libertad de elegir los méritos que tenga ganas de acreditar. Por ejemplo, si el usuario debe acreditarse 1000 méritos, el deberá acreditarse manualmente los méritos escribiendo “1000”. 
El quinto es llamado “ver mi información” y en este se muestra toda la información del usuario (Nombre, mail, legajo, méritos). Inmediatamente eliges esta opción, se muestra toda esta información al usuario.
El sexto es llamado “Modificar mi información”. Al ingresar esta opción, se te mostrará un menú llamado “modificar información del estudiante” y tiene 3 opciones posibles: La primera sería cambiar el nombre; el segundo sería cambiar la clave y el último sería salir devuelta al menú de beneficios.
La séptima y última opción sería la de “Cerrar sesión”. Esta te devuelve al menú de iniciar sesión.

Para cada cosa que haces, se abren los archivos y la información se guarda cuando salimos completamente del programa (“Registros.dat” y “LogrosyBeneficios.txt”).

#modulo 4
