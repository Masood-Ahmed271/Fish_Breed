int res = 0;
int mode = 1; //closed loop by default
int current_speed = 0;
int current_current = 0;
int current_temperature = 0;
int current_vol = 0;
void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600); // which is the required baud rate
  Serial.println("ENAB 1");//enable the controller
  Serial.println("MMOD 11");//motor operation
}

void clearBuffer()
{
  Serial.readString();  
}

int process(int n )//removing the first digit of number
{
    if( n < 10 ) return 0 ;
    else return n%10 + process(n/10) * 10 ;
}

int extraction(){
  int result = Serial.parseInt();
  int tem = process(result);
  //Serial.println(tem);
  return tem;
  }


void getMode(){
  Serial.println("?MMOD 1");
  if(Serial.available()>3){
      mode = extraction();
    }
   clearBuffer();
}

void getSpeed(){
  Serial.println("?S 1");
  if(Serial.available()>0){
      current_speed = extraction();
    }
    clearBuffer();
}

void getVol(){
  Serial.println("?PV 1");
  if(Serial.available()>0){
      current_vol = extraction();
    }
    clearBuffer();
}

void getCurrent(){
  Serial.println("?A 1");
  if(Serial.available()>0){
      current_current = extraction();
    }
    clearBuffer();
}

void getTem(){
  Serial.println("?T 1");
  if(Serial.available()>0){
      current_temperature = extraction();
    }
    clearBuffer();
}

void loop() {
  // put your main code here, to run repeatedly:
  String cmd;
      //Serial.println(cmd)
      if(millis()%3000 == 0){
        getMode();
      }
    
}
