# Computação Móvel (Mobile Computing)

Embedded-systems activities with Arduino and introductory apps with React and React Native.

## Arduino

The `.brd` files are the Eagle circuit layouts for the matching sketches.

| Activity | Sketch | Description |
| --- | --- | --- |
| [Atividade 02](Arduino/Atividade%2002) | `Ex1.ino` | Blinks two LEDs alternately every second. |
| | `Ex2.ino` | Lights ten LEDs in sequence, then turns them off in reverse order. |
| | `Ex3.ino` | "Back-and-forth" light across ten LEDs, with the turning point moving down every cycle. |
| [Atividade 03](Arduino/Atividade%2003) | `semaforo_pedestre.ino` | Traffic light with a pedestrian button; a potentiometer sets the crossing time. |
| [Atividade 04](Arduino/Atividade%2004) | `alarme_ultrassonico.ino` | Proximity alarm with two HC-SR04 ultrasonic sensors, a buzzer and status LEDs. |
| [Atividade 05](Arduino/Atividade%2005) | `controle_motor_lcd.ino` | DC motor speed control by PWM from a potentiometer, with the estimated speed shown on an LCD. |

## React / React Native

| Class | Stack | Description |
| --- | --- | --- |
| [Aula 01](React/Aula%2001) | React (Create React App) | First static page written in JSX. |
| [Aula 03](React/Aula%2003) | React | Calculator built from class components (display, buttons, one module per operation). |
| [Aula 04](React/Aula%2004) | React Native (Expo) | The same calculator ported to React Native. |
| [Aula 05](React/Aula%2005) | React Native (Expo) | Clock that shows state, timers and the component lifecycle. |
| [Aula 06](React/Aula%2006) | React Native (Expo) | Bottom-tab navigation (React Navigation) with sign-up and login screens persisted in AsyncStorage. |

## Running

```bash
cd "React/Aula 03" && npm install && npm start      # React (web)
cd "React/Aula 06" && npm install && npm start       # React Native (Expo SDK 39)
```

The Arduino sketches can be opened in the Arduino IDE or simulated in Tinkercad Circuits.
