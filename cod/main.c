#include "estados.h"
#include "config.h"
#include "hardware.h"
#include <stdint.h>

// Vector de punteros a funciones de estado
funcion_estado_t maquina_estados[] = {
    estado_init,      // INIT
    estado_espera,    // ESPERA
    estado_enfriando, // ENFRIANDO
    estado_error      // ERROR
};

int main(void) {
    estado_t estado_actual = INIT;
    
   
    cargar_configuracion();
    
    while (1) {
        // Ejecutar la función correspondiente al estado actual
        estado_actual = maquina_estados[estado_actual]();
    }
    
    return 0;
}
