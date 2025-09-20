# 🕹️ Reaction Game on Arduino

A fast-paced reaction game built with Arduino, featuring LED prompts, buzzer feedback, and score tracking on an LCD display. Players must press the correct button within 1 second of the LED lighting up — or face a game over.

---

## 🚀 Features

- Real-time reaction challenge with 1-second timeout
- Score tracking displayed on a 16×2 LCD
- Buzzer countdown before each round
- Game over screen with final score
- Manual restart via button press

---

## 🧰 Hardware Requirements

| Component           | Quantity | Notes                          |
|--------------------|----------|--------------------------------|
| Arduino Uno/Nano   | 1        | Main controller                |
| 16×2 LCD Display    | 1        | Connected via digital pins    |
| Push Buttons        | 2        | For player input              |
| LEDs                | 2        | Visual prompts (green & blue) |
| Buzzer              | 1        | Audio feedback                |
| Potentiometer       | 1        | Contrast Change on LCD        |
| Breadboard + Wires  | As needed | For connections              |

---

## 🔌 Pin Configuration

| Component   | Pin         |
|------------|-------------|
| Green LED  | D12         |
| Blue LED   | D3          |
| Button 1   | D13         |
| Button 2   | D2          |
| Buzzer     | D11         |
| LCD        | D4–D9       |

---

## 📦 Setup Instructions

1. Clone the repository:
   ```bash
   git clone https://github.com/your-username/reaction-game-arduino.git
2. Open <code>main.cpp</code> in your preferred IDE (e.g. PlatformIO or Arduino IDE with .cpp support).
3. Wire up the components as per the pin configuration'
4. Upload the code to your arduino board
5. And play!
