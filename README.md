# Proyecto1
proyecto algoritmos y estructuras de datos, UTN k1024 grupo 10
Video de youtube del proyecto: https://youtu.be/Dg7rPR5ivvM?feature=shared

Lucciano Campassi (213.555-3)

Mauro Nicolas Fernandez

Laureano Martinez Moreno

Agustin Mauricio Benitez

junto con los cuatro modulos se incluye un archivo llamado index.cpp que implemente los 4 modulos como uno con el fin de demostrar el funcionamiento mas realista de este sistema. (implementado por lucciano campassi)

#modulo 1
participantes Laureano Martinez Moreno

En la línea 10 declaramos un tipo de dato llamado estudiante que almacena los siguientes datos: legajo, email, nombre, clave y méritos (los cuales inician en el valor 1000 para todos los estudiantes.
Luego tenemos la declaración de un par de variables globales y un array de estudiantes, que usaremos mas adelante en el código.
En la línea 26 tenemos la función de tipo void, ver información, la cual tiene como parámetro una variable e tipo estudiante y que sirve para imprimir en pantalla los datos guardados del estudiante 
Luego. En la línea 34, tenemos a la función de tipo void modificar información, la cual hace que se pueda modificar la información almacenada del estudiante. Hay varias opciones, las cuales son modificar el nombre, la contraseña, o salir, las cuales se eligen comparando el numero que ingresamos con el numero que le asignamos a cada operación (ej.: hay que tocar 1 si queremos modificar el nombre) . para esto tenemos varios if en los cuales la condición compara el numero que introduce el usuario (que se almacena en la variable opción) con el asignado a cada operación. Si el usuario ingresa un numero no contemplado, se imprimirá en pantalla que el numero que esta ingresando no es valido
En la línea 63 tenemos la función de void, registrar estudiante, la cual como el nombre lo indica se encarga de crear las cuentas de los nuevos estudiantes. Todos los nuevos datos se almacenan en la variable nuevo estudiante. Tenemos también un if para averiguar si el mail es valido y luego un contador (for) que se asegura de que el mail que se guarda en nuevo estudiante no sea un mail ya registrado. En la línea 86 se le asignan los 1000 créditos correspondientes al nuevo estudiante y en la siguiente se guarda la información del nuevo estudiante en la posición siguiente del array
En la línea 91 esta la función de tipo void, guardar registros, la cual crea un archivo binario y si este es distinto del nulo (por eso el if) guarda los datos de estudiantes en el. Luego tenemos otra función en la línea 100 que se llama cargar registros. Esta función lee los datos del archivo binario anterior y los carga en memoria.

Por ultimo tenemos el int main, en el cual primero se llama a la función cargar registros y luego se crea un bucle (while true) en el que se imprime en pantalla el menú principal, mostrando las distintas operaciones a realizar por el usuario (iniciar sesión como estudiante, crear una cuenta o salir). Luego repetimos el proceso anterior, Declaramos la variable opción y con los if vamos comparando que numero puso el usuario con el asignado para la operación. Luego tenemos un for con un if dentro que hace que se compare (en caso de estar iniciando sesión) el email y la contraseña con los datos ya guardados en esa posición del array y luego se llama a las funciones modificar información y ver información pasándole el estudiante guardado en la posición del array. Luego se llama a la función guardar registro y se rompe el bucle. Si hay algo que falla en ese proceso saldrá la leyenda, credenciales incorrectas (si es que la contraseña o el mail no coinciden o se pone un numero que no corresponde a la hora de elegir la opción ) 
Luego si se quiere crear una cuenta directamente se llama a las funciones registrar estudiante y guardar registros. Por ultimo si elegimos la opción de salir, solamente se llama a la función guardar registros.

#modulo 2

Participantes: Benitez Agustin Mauricio

Se hicieron dos estructuras llamadas "Beneficio {}" con una variable de tipo global llamada "beneficio" y otra llamada "Aux {}" con otra variable global llamada "aux". 
Se crearon 4 funciones dentro del programa:
  -  "void agregar_beneficio();" Agrega beneficios al archivo 
  -  "void listar_beneficio();" Hace una lista de todos los beneficios guardados 
  -  "void modificar_beneficio();" Permite modificar el nombre y/o costo de los beneficios 
  -  "void eliminar_beneficio();" Te da la opción de eliminar cualquier beneficio almacenado 

Cada función es llamada dentro de un "switch ()2" que contiene 5 opciones, 4 de ellas se encargan de una función diferente. El "switch ()" esta dentro de un "Do while ()" para que se repita el programa siempre y cuando no se elija la ultima opción, la 5, que es donde se encuentra la opción de salir. 
Todas las funciones modifican el archivo "logrosYbeneficios.txt", que es donde se almacenan los beneficios agregados, se optó por el formato ".txt" para evitar fallos con el compilador, ya que no nos dejaba iniciar el programa con un archivo ".dat". 
Dentro de cada función se colocaron varíales de tipo "bool" para activar y desactivar diferentes condicionales "if()", permitiendo la opcion de que si no se puede abrir el archivo por un fallo externo no se ejecute el programa. 

#modulo 3
realizado por Mauro Nicolas Fernandez

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

realizado por lucciano campassi

esto es un plus al proyecto originalmente planteado q esta incluido en todos los otros modulos de una u otra forma

Descripción General:
Este código es una aplicación de gestión de estudiantes y beneficios universitarios. Proporciona una interfaz para administradores y estudiantes llevar un registro de datos, acreditar logros y consumir beneficios.

Función de los Administradores:
Los administradores tienen acceso a un menú especial donde pueden realizar las siguientes acciones:

    Modificar Datos de Estudiante: Esta función permite a los administradores cambiar la contraseña de un estudiante. Solicita el correo electrónico del estudiante y luego permite ingresar la nueva contraseña.

    Agregar Beneficio: Los administradores pueden agregar nuevos beneficios al sistema. Se les pide que ingresen el nombre y el costo del nuevo beneficio en créditos.

    Crear Cuenta de Estudiante: Permite a los administradores registrar nuevos estudiantes en el sistema. Deben ingresar el nombre, correo electrónico y contraseña del nuevo estudiante.

    Guardar Registros: Esta función guarda los datos de los estudiantes y beneficios en archivos específicos. Esto asegura que la información se conserve incluso después de cerrar la aplicación.

    Guardar Logros y Beneficios: Guarda la lista de beneficios disponibles en un archivo de texto legible.

Función de los Estudiantes:
Los estudiantes también tienen acceso a una serie de opciones:

    Ver Información de la Cuenta: Pueden consultar su información personal, que incluye su nombre, correo electrónico y la cantidad de créditos (méritos) disponibles.

    Acreditar Logros: Esta opción permite a los estudiantes ganar más créditos (méritos) al realizar ciertas actividades o logros académicos. Se les pedirá que ingresen la cantidad de créditos que desean acreditar.

    Consumir Beneficios: Los estudiantes pueden usar sus créditos (méritos) para obtener beneficios específicos. Deben proporcionar el nombre del beneficio que desean adquirir.

Guardando Registros:
El sistema garantiza que los registros estén seguros y disponibles para futuras sesiones. Para esto, utiliza dos tipos de archivos:

    registros.dat: Almacena información detallada sobre los estudiantes y los beneficios en un formato binario especial.

    logrosYbeneficios.txt: Guarda la lista de beneficios disponibles en un formato de texto fácil de leer.

En resumen, este código proporciona un sistema completo para administradores y estudiantes universitarios. Los administradores pueden gestionar cuentas de estudiantes, beneficios y registros, mientras que los estudiantes pueden ver su información y usar sus créditos para obtener beneficios. La información se guarda en archivos para asegurar su conservación.
