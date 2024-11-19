import processing.serial.*;
Serial myPort;
String datos="";  //variable para almacenar los datos recibidos

void setup(){
  myPort= new Serial(this,"COM5",9600);
  
  myPort.bufferUntil('\n');     //lee hasta encontrar una nueva linea
  
  size(400,200);
}
void draw(){
  background(2,60,104);
  textSize(32);    //tamaño del texto
  fill(255);  //color del texto
  text(datos,20,70);
  
}
void serialEvent(Serial myPort){      //funcion que se ejecuta cuando se recibe un nuevo dato en el puerto serial
  datos=myPort.readStringUntil('\n');
  
  if(datos!=null){
    datos=trim(datos);      //elimna espacios en blanco al principio y al final
  }
}
