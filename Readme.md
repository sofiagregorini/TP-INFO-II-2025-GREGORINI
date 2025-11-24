# TP-INFO-2- Control de temperatura

# Memoria Descriptiva

Este proyecto implementa un sistema de enfriamiento automático basado en un microcontrolador AVR (ATmega128 ). El sistema monitorea la temperatura y activa un ventilador cuando la temperatura supera un umbral predefinido. El sistema se controla mediante un botón que permite encenderlo/apagarlo.

# Diagrama

![image](https://github.com/user-attachments/assets/0eec9e40-11ef-4170-89e1-ca1ad5d8a208)

# Estados del Sistema

1. **INIT (Inicialización)**
   - Inicializa puertos, ADC y variables
   - Cambia al estado ESPERA

2. **ESPERA**
   - Espera a que se presione el botón para activar el sistema
   - Si la temperatura supera el umbral, cambia a ENFRIANDO
   - Permanece en espera si el sistema está apagado

3. **ENFRIANDO**
   - Activa el ventilador
   - Se mantiene activo mientras la temperatura esté por encima del umbral
   - Si la temperatura baja, vuelve a ESPERA
   - Si se apaga el sistema, vuelve a ESPERA

4. **ERROR**
   - Se activa si hay una falla
   - Detiene todos los dispositivos
   - Vuelve al estado INIT



# Materiales Utilizados

♦Sensor de temperatura: LM35

♦Microcontrolador : ATMEGA128

♦Transistor: NPN 2N2222

♦Ventilador/rotor: FAN-DC

# Esquemático en Proteus

![image](https://github.com/user-attachments/assets/361d70f4-db1a-4fd5-9a82-ae10f082d451)

# Video funcionando

https://www.youtube.com/watch?v=LIuPFKk9Mck

