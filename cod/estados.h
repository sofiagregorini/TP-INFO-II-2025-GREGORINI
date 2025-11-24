#ifndef ESTADOS_H
#define ESTADOS_H

// Definición de estados del sistema
typedef enum {
    INIT,
    ESPERA,
    ENFRIANDO,
    ERROR
} estado_t;

// Definición del tipo de puntero a función para estados
typedef estado_t (*funcion_estado_t)(void);

// Prototipos de funciones de estados
estado_t estado_init(void);
estado_t estado_espera(void);
estado_t estado_enfriando(void);
estado_t estado_error(void);

#endif
