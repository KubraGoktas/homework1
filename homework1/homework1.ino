int buttons[3]={8,9,10};
int leds[5]={2,3,4,5,6};

int buttonState;

void setup() {
  //ledler
  for(int i=0;i<5;i++){
  pinMode(leds[i], OUTPUT);
  }
  //butonlar
  for(int j=0;j<3;j++){
  pinMode(buttons[j], INPUT);
  }
}


void loop() {
  buttonState=0;
  for(int a=0;a<3;a++){
    if(digitalRead(buttons[a])){
      buttonState=buttons[a]; 
       switch (buttonState) {
        case 9: 
          Animations("left");
          break;
         case 8: 
          Animations("right");
          break;
         case 10: 
          Animations("flash");
          break;
        default:
          break;
    }
    }
  } 
  
 
}

void Animations(String type){
  if(type=="right"){
    for(int k=0;k<5;k++){
      digitalWrite(leds[k],HIGH);
      delay(500);
      //digitalWrite(leds[k],LOW);
    }for(int a=0;a<5;a++){
      digitalWrite(leds[a],LOW);
    }
    
  }else if(type=="left"){
    for(int k=5;k>=0;k--){
      digitalWrite(leds[k],HIGH);
      delay(500);
    }for(int a=0;a<5;a++){
      digitalWrite(leds[a],LOW);
    }
    
  }else if(type=="flash"){
    for (int k=0;k < 10;k++) {
      for (int i = 0; i < 5; i++) {
        digitalWrite(leds[i], HIGH);
      }
      delay(400);
      for (int i = 0; i < 5; i++){
        digitalWrite(leds[i], LOW);
      }
      delay(300);
       
    }
  }
  
}
