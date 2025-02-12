<div align="center">
    <img src="https://moodle.embarcatech.cepedi.org.br/pluginfile.php/1/theme_moove/logo/1733422525/Group%20658.png" alt="Logo Embarcatech" height="100">
</div>

<br>

# Projeto ServoMotor - Embarcatech

## 🌟 Descrição

Este projeto visa controlar um servomotor utilizando o Raspberry Pi Pico W, com o código desenvolvido em C e testado no simulador Wokwi. O sistema também inclui um LED indicador, que proporciona uma visualização do status do movimento do servo.

## 🔧 Funcionalidades Principais

- **Controle de Servomotor com PWM**:
  - Movimentação precisa do servomotor entre 0° e 180°.
  - Ajuste do ângulo do servomotor com controle PWM.

- **Controle de LED Azul**:
  - Um LED azul serve como indicador de operação do sistema.
  - O LED reflete a atividade do servomotor, mostrando o status do sistema.

## 🛠️ Tecnologias Utilizadas

- **Raspberry Pi Pico W**: Microcontrolador utilizado para gerenciar o servomotor e o LED.
- **Servo Motor**: Atuador controlado via PWM para realizar movimentos precisos.
- **LED Azul**: Indicador visual do status do sistema.
- **Resistor de 330Ω**: Para proteção do LED.
- **Simulador Wokwi**: Ambiente para testar e simular o hardware antes da implementação física.
- **Pico SDK e VS Code**: Ferramentas para programar e compilar o código em C.

## 🎯 Objetivos do Projeto

1. Implementar o controle de PWM para movimentação do servomotor.
2. Criar uma integração funcional do LED azul como indicador visual.
3. Validar a funcionalidade do sistema por meio da simulação no Wokwi antes da implementação física.

## 🚀 Como Utilizar

1. **Clone o Repositório**:

```bash
git clone https://github.com/viniciusaraujo75/ServoMotor.git
