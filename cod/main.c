#include "estados.h"
#include "config.h"
#include "driver.h"
#include <stdint.h>

// Vector de punteros a funciones de estado
funcion_estado_t maquina_estados[] = {
    estado_espera_luminosidad,    // ESPERA_LUMINOSIDAD
    estado_activacion_emergencia, // ACTIVACION_EMERGENCIA
    estado_apagado_progresivo,    // APAGADO_PROGRESIVO
    estado_error                  // ERROR
};

int main(void) {
    estado_t estado_actual = ESPERA_LUMINOSIDAD;

   
    cargar_configuracion();

    while (1) {
        // Ejecutar la función correspondiente al estado actual
        estado_actual = maquina_estados[estado_actual]();
    }

    return 0;
}
