"""
Se requiere identificar y contar cuantas palabras tiene un párrafo dando el siguiente patrón
**palabra** sin repetir ninguna palabra y debe regresar una lista. Ejemplo.
Node.js es un **entorno** en tiempo de ejecución multiplataforma, **de** código abierto, para la
capa del servidor basado en el lenguaje de programación **JavaScript**, asíncrono, con E/S
**de** datos en una arquitectura orientada a eventos y basado en el motor V8.
Resultado:
[ ‘entorno’, ‘de’, ‘Javascript’ ]
"""

import re # RegEx

def buscarPalabras(string: str):
    lista = set(re.findall("\*\*(.*?)\*\*", string))
    return list(lista), len(lista)

cadena = """Node.js es un **entorno** en tiempo de ejecución 		
        multiplataforma, **de** código abierto, para la
	    capa del servidor basado en el lenguaje de programación 			
        **JavaScript**, asíncrono, con E/S **de** datos en una 
	    arquitectura orientada a eventos y basado en el motor V8."""

lista, nElems = buscarPalabras(cadena)

print(lista)
print(nElems)