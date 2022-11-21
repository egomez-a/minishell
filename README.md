# Minishell
Tan bonito como shell

Tu shell deberá:
- No interpretar comillas sin cerrar o caracteres especiales no especificados como \ o ;.
- No usar más de una variable global, piensa por qué y prepárate para explicar el uso que le das.
- Mostrar una entrada que espere introducir un comando nuevo.
- Tener un historial funcional.
- Busca y ejecuta el ejecutable correcto (basado en la variable PATH o mediante el uso de rutas relativas o absolutas).
- Deberá implementar los builtins:
  - echo con la opción -n.
  - cd solo con una ruta relativa o absoluta. ◦ pwd sin opciones.
  - export sin opciones.
  - unset sin opciones.
  - env sin opciones o argumentos.
  - exit sin opciones.
- ’ inhibiendo toda interpretación de una secuencia de caracteres.
-  " inhibiendo toda interpretación de una secuencia de caracteres excepto $.
-  Redirecciones:
  - < debe redirigir input.
  - > debe redirigir output.
  - “<<” debe leer del input de la fuente actual hasta que una línea que contenga solo el delimitador aparezca. No necesita actualizar el historial
  - “>>” debe redirigir el output en modo append.
- Pipes |. El output de cada comando en la pipeline se conecta a través de un pipe al input del siguiente comando.
- Las variables de entorno ($ seguidos de caracteres) deberán expandirse a sus valores.
- $? deberá expandirse al estado de salida del comando más reciente ejecutado en la pipeline.
- ctrl-C ctrl-D ctrl-\ deberán funcionar como en bash.
- Cuando sea interactivo:
  - ctrl-C imprime una nueva entrada en una línea nueva. ◦ ctrl-D termina el shell.
  - ctrl-\ no hace nada.

La función readline puede producir algunos leaks que no necesitas arreglar. Eso no significa que tu código pueda producir leaks.
- Limítate a hacer lo que pide el enunciado.
- Cualquier cosa no solicitada no se requiere.
