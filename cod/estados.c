#include "estados.h"
#include "driver.h"
#include "config.h"
#include <stdint.h>

static unsigned char luz_encendida = 0;          // Estado de la luz (apagada = 0, encendida = 1)
static uint16_t tiempo_luz_encendida = 0;        // Contador para el tiempo que la luz está encendida


estado_t estado_espera_luminosidad(void) {
    // Apagar la luz en este estado
    if (luz_encendida) {
        desactivar_luz();
        luz_encendida = 0;
        tiempo_luz_encendida = 0;  
    }

    // Si la luminosidad es menor que el umbral, pasar a activación de emergencia
    if (leer_luminosidad() < UMBRAL_LUMINOSIDAD) {
        return ACTIVACION_EMERGENCIA;
    }

    return ESPERA_LUMINOSIDAD;
}


estado_t estado_activacion_emergencia(void) {
    // Encender la luz en este estado
    if (!luz_encendida) {
        activar_luz();
        luz_encendida = 1;
        tiempo_luz_encendida = 0;  
    }

   
    tiempo_luz_encendida++;

    // Si la luminosidad es mayor que el umbral durante 5 segundos (en ciclos), pasar a apagado progresivo
    if (leer_luminosidad() > UMBRAL_LUMINOSIDAD && tiempo_luz_encendida >= TIEMPO_DESHABILITACION) {
        return APAGADO_PROGRESIVO;
    }

    // Si la luminosidad sigue siendo baja, permanecer en este estado
    if (leer_luminosidad() < UMBRAL_LUMINOSIDAD) {
        return ACTIVACION_EMERGENCIA;
    }

    return ACTIVACION_EMERGENCIA;
}


estado_t estado_apagado_progresivo(void) {
    // Apagar la luz
    if (luz_encendida) {
        desactivar_luz();
        luz_encendida = 0;
    }

    // Volver al estado de espera de luminosidad
    return ESPERA_LUMINOSIDAD;
}


estado_t estado_error(void) {
    // Apagar la luz en caso de error
    desactivar_luz();
    luz_encendida = 0;
    tiempo_luz_encendida = 0;

   
    return ESPERA_LUMINOSIDAD;
}
