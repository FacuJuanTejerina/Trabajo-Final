#include"frecuencias.h"
class mini_piano{
  private:
  int pin_buzzer;
  int pin_pulsadores[8];
  char *notas[8]={"do","re","mi","fa","sol","la","si"};
  int frecuencias[8]={NOTA_DO4,NOTA_RE4 ,NOTA_MI4 ,NOTA_FA4 ,NOTA_SOL4,NOTA_LA4,NOTA_SI4,NOTA_DO5}; // frecuencias

  public:
  mini_piano(int pin_buzzer,int pin_pulsadores[8]);  //constructor
  
  void tocar_nota();   //declaracion de metodo
};
mini_piano :: mini_piano(int pin_buzzer,int pin_pulsadores[8]){  //inicializacion del constructor
  this->pin_buzzer=pin_buzzer;
  for(int i=0;i<8;i++){
    this->pin_pulsadores[i]=pin_pulsadores[i];
    pinMode(pin_pulsadores[i],INPUT_PULLUP);
  } 
  pinMode(pin_buzzer,OUTPUT);
}
void mini_piano :: tocar_nota(){
  bool pulsador_presionado=false;  //variable de estado para ver si un boton esta presionado
  for(int i=0;i<8;i++){
    int estado_pulsador=digitalRead(pin_pulsadores[i]);
    if(estado_pulsador==LOW){  //significa que el boton esta presionado
      
      tone(pin_buzzer,frecuencias[i],100);  //reproduce la nota correspondiente
      pulsador_presionado=true;
      Serial.print("nota: ");
      Serial.print(notas[i]);
      Serial.print("  frecuencia: ");
      Serial.println(frecuencias[i]);
      
      break;  //sale del bucle cundo el boton esta presionada
 
    }
  }
  if(!pulsador_presionado){  //apaga el buzzer si ningun pulsador esta presionado
    noTone(pin_buzzer);
  }
}

int pin_buzzer=11;
int pin_pulsadores[8]={2,3,4,5,6,7,8,9};

mini_piano piano(pin_buzzer,pin_pulsadores); //crea el objeto piano
void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
}

void loop() {
  
  piano.tocar_nota();
  delay(50);
  

}
