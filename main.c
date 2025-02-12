#include "pico/stdlib.h"
#include "hardware/pwm.h"
#include "hardware/clocks.h"
#include <stdint.h>
#include <stdbool.h>

#define PIN_SERVO 22
#define PIN_LED 12
#define FREQ_SERVO 50.0f   // Frequência para o servomotor
#define FREQ_LED 1000.0f    // Frequência do PWM para o LED
#define CLOCK_DIV 64.0f     // Divisor do clock do PWM
#define STEP 5              // Passo do incremento
#define INTERVALO 10        // Tempo de espera entre movimentações

// Função para inicializar o PWM em um pino específico
void inicializa_pwm(uint pin, float frequencia, uint32_t *slice, uint32_t *canal, uint32_t *wrap) {
    gpio_set_function(pin, GPIO_FUNC_PWM);
    *slice = pwm_gpio_to_slice_num(pin);
    *canal = pwm_gpio_to_channel(pin);
    uint32_t clock_freq = clock_get_hz(clk_sys);
    *wrap = (clock_freq / (CLOCK_DIV * frequencia)) - 1;
    pwm_set_clkdiv(*slice, CLOCK_DIV);
    pwm_set_wrap(*slice, *wrap);
    pwm_set_enabled(*slice, true);
}

// Define o nível do PWM baseado em microsegundos
void ajusta_pwm(uint slice, uint canal, uint32_t wrap, float largura_pulso) {
    uint32_t nivel = (largura_pulso * wrap) / 20000;
    pwm_set_chan_level(slice, canal, nivel);
}

int main() {
    stdio_init_all();
    
    uint32_t servo_slice, servo_canal, servo_wrap;
    uint32_t led_slice, led_canal, led_wrap;
    inicializa_pwm(PIN_SERVO, FREQ_SERVO, &servo_slice, &servo_canal, &servo_wrap);
    inicializa_pwm(PIN_LED, FREQ_LED, &led_slice, &led_canal, &led_wrap);
    
    ajusta_pwm(servo_slice, servo_canal, servo_wrap, 2400); // Servo a 180°
    pwm_set_gpio_level(PIN_LED, led_wrap); // LED no máximo
    sleep_ms(5000);

    ajusta_pwm(servo_slice, servo_canal, servo_wrap, 1470); // Servo a 90°
    pwm_set_gpio_level(PIN_LED, led_wrap / 2); // LED médio
    sleep_ms(5000);

    ajusta_pwm(servo_slice, servo_canal, servo_wrap, 500); // Servo a 0°
    pwm_set_gpio_level(PIN_LED, 0); // LED desligado
    sleep_ms(5000);

    bool crescente = true;
    uint32_t largura_pulso = 500;
    uint32_t intensidade_led = 0;

    while (true) {
        ajusta_pwm(servo_slice, servo_canal, servo_wrap, largura_pulso);
        pwm_set_gpio_level(PIN_LED, intensidade_led);
        sleep_ms(INTERVALO);
        
        if (crescente) {
            largura_pulso += STEP;
            intensidade_led += (led_wrap / (2400 - 500)) * STEP;
            if (largura_pulso >= 2400) crescente = false;
        } else {
            largura_pulso -= STEP;
            intensidade_led -= (led_wrap / (2400 - 500)) * STEP;
            if (largura_pulso <= 500) crescente = true;
        }
    }
}