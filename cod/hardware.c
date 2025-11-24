#include "hardware.h"
#include "avr_api.h"
#include <stddef.h>


void (*avr_adc_handler)(void) = 0;
void (*tim3irq_user_handler)(void) = 0;
void (*tim2irq_user_handler)(void) = 0;
void (*tim1irq_user_handler)(void) = 0;
void (*tim0irq_user_handler)(void) = 0;
void (*avr_pwm_handler)(void) = 0;
void (*timer_irq_handler)(void) = 0;
void (*avr_systick_handler)(void) = 0;
void (*interrupcion_external7)(void) = 0;
void (*interrupcion_external6)(void) = 0;
void (*interrupcion_external5)(void) = 0;
void (*interrupcion_external4)(void) = 0;
void (*interrupcion_external3)(void) = 0;
void (*interrupcion_external2)(void) = 0;
void (*interrupcion_external1)(void) = 0;
void (*interrupcion_external0)(void) = 0;
void (*avr_ext_interrupt_handler)(void) = 0;


#include "../lib/avr_Adc.c"
#include "../lib/avr_Gpio.c"


void inicializar_hardware(void) {
    //GPIO para el botón como entrada
    GpioInitStructure_AVR config_boton = {
        .port = avr_GPIO_D,
        .modo = avr_GPIO_mode_Input,
        .pines = (1 << PIN_BOTON)
    };
    init_gpio(config_boton);
    
    set_pin(avr_GPIOD_OUT, (1 << PIN_BOTON));
    
    // estructura de GPIO para el ventilador como salida
    GpioInitStructure_AVR config_ventilador = {
        .port = avr_GPIO_D,
        .modo = avr_GPIO_mode_Output,
        .pines = (1 << PIN_VENTILADOR)
    };
    init_gpio(config_ventilador);
    
    // Aseguro que el ventilador esté apagado inicialmente
    clear_pin(avr_GPIOD_OUT, (1 << PIN_VENTILADOR));
    
    // Inicializar ADC
    AdcInitStructure_AVR config_adc = {
        .mode = avr_ADC_MODE_Single_Conversion,
        .prescaler = avr_ADC_Prescaler_64,
        .channel = (ADC_CANAL_t)PIN_SENSOR_TEMPERATURA, 
        .resolution = avr_ADC_RES_10Bit,
        .reference = avr_ADC_REF_AVcc,
        .avr_adc_handler = 0
    };
    
    init_adc(config_adc);
}


float leer_temperatura(void) {
    
    avr_ADC_Value_t valor_adc = leer_ADC((ADC_CANAL_t)PIN_SENSOR_TEMPERATURA);
    
    // Convierto el valor ADC a temperatura 
    
    float temperatura = (valor_adc * 5.0 / 1024.0) * 100.0;
    
    return temperatura;
}


void activar_ventilador(void) {
    set_pin(avr_GPIOD_OUT, (1 << PIN_VENTILADOR));
}


void desactivar_ventilador(void) {
    clear_pin(avr_GPIOD_OUT, (1 << PIN_VENTILADOR));
}


unsigned char leer_boton(void) {
  
    if (PIN_BOTON == 0) return avr_GPIOD_IN_0;
    else if (PIN_BOTON == 1) return avr_GPIOD_IN_1;
    else if (PIN_BOTON == 2) return avr_GPIOD_IN_2;
    else if (PIN_BOTON == 3) return avr_GPIOD_IN_3;
    else if (PIN_BOTON == 4) return avr_GPIOD_IN_4;
    else if (PIN_BOTON == 5) return avr_GPIOD_IN_5;
    else if (PIN_BOTON == 6) return avr_GPIOD_IN_6;
    else if (PIN_BOTON == 7) return avr_GPIOD_IN_7;
    else return 0;
}


void esperar_soltar_boton(void) {
  
    while (!leer_boton());
}
