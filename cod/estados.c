#include "estados.h"
#include "hardware.h"
#include "config.h"

static unsigned char sistema_encendido = 0;  // Estado del sistema (apagado = 0, encendido = 1)


estado_t estado_init(void) {
    inicializar_hardware();
    sistema_encendido = 0;
    return ESPERA;
}


estado_t estado_espera(void) {
    
    if (!leer_boton()) { // Botón presionado (
        sistema_encendido = !sistema_encendido;
        esperar_soltar_boton();
    }

    if (!sistema_encendido) {
        return ESPERA; // Si el sistema está apagado, permanece en espera
    }

    // Si la temperatura supera el límite, pasa al estado de enfriamiento
    if (leer_temperatura() > TEMPERATURA_LIMITE) {
        return ENFRIANDO;
    }
    return ESPERA;
}


estado_t estado_enfriando(void) {
    if (!sistema_encendido) {
        desactivar_ventilador();
        return ESPERA; // Si se apaga el sistema, vuelve a espera
    }

    activar_ventilador();
    if (leer_temperatura() <= TEMPERATURA_LIMITE) {
        desactivar_ventilador();
        return ESPERA;
    }
    return ENFRIANDO;
}


estado_t estado_error(void) {
    desactivar_ventilador();
    // vuelve al estado inicial
    return INIT;
}
