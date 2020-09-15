#define HAZARD_INPUT A1
#define LEFT_SIGNAL_INPUT A2
#define RIGHT_SIGNAL_INPUT A3
#define LOW_BEAM_INPUT A4
#define BRAKE_INPUT A5


#define DRIVER_LOW_BEAM_OUTPUT 2
#define DRIVER_FRONT_SIGNAL_OUTPUT 3
#define PASS_LOW_BEAM_OUTPUT 4
#define PASS_FRONT_SIGNAL_OUTPUT 5

#define DRIVER_SOLID_OUTPUT 6
#define DRIVER_FLASHING_OUTPUT 7
#define PASS_SOLID_OUTPUT 8
#define PASS_FLASHING_OUTPUT 9

void setup() {
  pinMode(HAZARD_INPUT,       INPUT);
  pinMode(LEFT_SIGNAL_INPUT,  INPUT);
  pinMode(RIGHT_SIGNAL_INPUT, INPUT);
  pinMode(LOW_BEAM_INPUT,     INPUT);
  pinMode(BRAKE_INPUT,        INPUT);

  pinMode(DRIVER_LOW_BEAM_OUTPUT,     OUTPUT);
  pinMode(DRIVER_FRONT_SIGNAL_OUTPUT, OUTPUT);
  pinMode(PASS_LOW_BEAM_OUTPUT,       OUTPUT);
  pinMode(PASS_FRONT_SIGNAL_OUTPUT,   OUTPUT);
  pinMode(DRIVER_SOLID_OUTPUT,        OUTPUT);
  pinMode(DRIVER_FLASHING_OUTPUT,     OUTPUT);
  pinMode(PASS_SOLID_OUTPUT,          OUTPUT);
  pinMode(PASS_FLASHING_OUTPUT,       OUTPUT);
}

void loop() {
  bool leftTurn  = digitalRead(LEFT_SIGNAL_INPUT) == HIGH;
  bool rightTurn = digitalRead(RIGHT_SIGNAL_INPUT) == HIGH;

  bool hazard    = digitalRead(HAZARD_INPUT) == HIGH;
  if(hazard){
    leftTurn = rightTurn = true;
  }

  bool lowBeam = digitalRead(LOW_BEAM_INPUT) == HIGH;
  
  bool brake = digitalRead(BRAKE_INPUT) == HIGH;

  if((leftTurn && !rightTurn) || (leftTurn && !brake)){
    digitalWrite(DRIVER_FLASHING_OUTPUT, HIGH);
  }else{
    digitalWrite(DRIVER_FLASHING_OUTPUT, LOW);
  }
  if((!leftTurn && brake) || (rightTurn && brake)){
    digitalWrite(DRIVER_SOLID_OUTPUT, HIGH);
  }else{
    digitalWrite(DRIVER_SOLID_OUTPUT, LOW);
  }

  if((!leftTurn && rightTurn) || (rightTurn && !brake)){
    digitalWrite(PASS_FLASHING_OUTPUT, HIGH);
  }else{
    digitalWrite(PASS_FLASHING_OUTPUT, LOW);
  }
  if((!rightTurn && brake) || (leftTurn && brake)){
    digitalWrite(PASS_SOLID_OUTPUT, HIGH);
  }else{
    digitalWrite(PASS_SOLID_OUTPUT, LOW);
  }

  if(leftTurn){
    digitalWrite(DRIVER_FRONT_SIGNAL_OUTPUT, HIGH);
  }else{
    digitalWrite(DRIVER_FRONT_SIGNAL_OUTPUT, LOW);
  }
  if(rightTurn){
    digitalWrite(PASS_FRONT_SIGNAL_OUTPUT, HIGH);
  }else{
    digitalWrite(PASS_FRONT_SIGNAL_OUTPUT, LOW);
  }

  if(lowBeam && !leftTurn){
    digitalWrite(DRIVER_LOW_BEAM_OUTPUT, HIGH);
  }else{
    digitalWrite(DRIVER_LOW_BEAM_OUTPUT, LOW);
  }

  if(lowBeam && !rightTurn){
    digitalWrite(PASS_LOW_BEAM_OUTPUT, HIGH);
  }else{
    digitalWrite(PASS_LOW_BEAM_OUTPUT, LOW);
  }
}
