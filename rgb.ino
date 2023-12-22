// Pins connected to the RGB ribbon
const int redPin = 9;
const int greenPin = 10;
const int bluePin = 11;

// Pin connected to the button
const int buttonPin = 2;

// Variable to store the current color index
int currentColorIndex = 0;

// Array of RGB colors
const int colors[][3] = {
  {255, 0, 0},    // Red
  {0, 255, 0},    // Green
  {0, 0, 255},    // Blue
  {255, 255, 0},  // Yellow
  {255, 0, 255},  // Magenta
  {0, 255, 255}   // Cyan
};

void setup() {
  pinMode(redPin, OUTPUT);
  pinMode(greenPin, OUTPUT);
  pinMode(bluePin, OUTPUT);
  pinMode(buttonPin, INPUT_PULLUP);
  
  // Initialize the RGB ribbon to the first color
  setColor(0);
}

void loop() {
  // Read the button state
  int buttonState = digitalRead(buttonPin);
  
  // Check if the button is pressed
  if (buttonState == LOW) {
    // Increment the current color index
    currentColorIndex = (currentColorIndex + 1) % (sizeof(colors) / sizeof(colors[0]));
    
    // Set the new color
    setColor(currentColorIndex);
    
    // Delay to avoid rapid switching
    delay(200);
  }
}

void setColor(int colorIndex) {
  analogWrite(redPin, colors[colorIndex][0]);
  analogWrite(greenPin, colors[colorIndex][1]);
  analogWrite(bluePin, colors[colorIndex][2]);
}

