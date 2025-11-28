#ifndef ESTADOS_H
#define ESTADOS_H

// Definición de estados del sistema
typedef enum {
    ESPERA_LUMINOSIDAD,        // Estado 1: espera monitoreo de luminosidad ambiental luz apagada
    ACTIVACION_EMERGENCIA,     // Estado 2: activacion de emergencia luz encendida
    APAGADO_PROGRESIVO,        // Estado 3: apagado progresivo de la luz
    ERROR
} estado_t;

// Definición del tipo de puntero a función para estados
typedef estado_t (*funcion_estado_t)(void);

// Prototipos de funciones 
estado_t estado_espera_luminosidad(void);
estado_t estado_activacion_emergencia(void);
estado_t estado_apagado_progresivo(void);
estado_t estado_error(void);

#endif
