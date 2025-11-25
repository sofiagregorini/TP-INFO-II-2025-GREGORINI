# TP-INFO-2- Control de iluminación

# Memoria Descriptiva

Este proyecto implementa un sistema de iluminación de emergencia automático basado en un microcontrolador AVR (ATmega128). El sistema utiliza un sensor de luz para medir la intensidad lumínica del ambiente y, en función de un umbral predefinido, decide si debe activar o desactivar una luz de emergencia.

Cuando la luminosidad ambiente desciende por debajo del valor establecido, el microcontrolador enciende la luz de emergencia, garantizando iluminación en condiciones de baja visibilidad. Una vez que la luz ambiente vuelve a valores normales durante un tiempo determinado, el sistema apaga automáticamente la luz y retorna al modo de espera, optimizando el consumo energético.

# Diagrama

<img width="613" height="299" alt="image" src="https://github.com/user-attachments/assets/dacf7086-2dbe-4a33-a3ee-d3cda27aef8c" />


# Estados del Sistema

- *Estado 1: Espera / Monitoreo*
  - Sensor de luz mide intensidad lumínica.
  - Microcontrolador compara valor con umbral predefinido.
  - Luz de emergencia *apagada*.
  - Sistema en modo bajo consumo.

- *Estado 2: Activación de Emergencia*
  - Si luminosidad < umbral → transición a este estado.
  - Microcontrolador activa el relé.
  - Luz de emergencia *encendida*.

- *Estado 3: Apagado Automático*
  - Si luminosidad > umbral durante 5 segundos → transición a este estado.
  - Microcontrolador desactiva el relé.
  - Luz de emergencia *apagada*.
  - Sistema vuelve al Estado 1 (Espera).




# Materiales Utilizados

♦Sensor de luminosidad: 

♦Microcontrolador : ATMEGA128

♦Transistor: NPN 2N2222

♦Luz de emergencia:

# Esquemático en Proteus



# Video funcionando



