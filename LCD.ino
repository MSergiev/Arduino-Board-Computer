//Library import
  #include <UTFT.h>
  #include <UTFT_Geometry.h>
  #include <toneAC.h>
  #include <EasyTransfer.h>
  #include <TinyGPS++.h>

//Initialise transfer
  EasyTransfer Transfer;

//Initialise GPS
  TinyGPSPlus gps;

//Backlight pin
  int backlight = 2;
  int backlightLevel = 200;

//Library initialisation
  UTFT myGLCD(ILI9325D_16ALT,38,39,40,41);
  UTFT_Geometry geo(&myGLCD);

//myGLCD dimensions
  int size_x, size_y;

//Panel dimensions
  int panel1[] = {0, 23};
  int panel2[] = {25, 146};
  int panel3[] = {148, 169};
  int panel4[] = {171, 287};
  int panel5[] = {289, 319};
  int panel1Height = panel1[1] - panel1[0];
  int panel2Height = panel2[1] - panel2[0];
  int panel3Height = panel3[1] - panel3[0];
  int panel4Height = panel4[1] - panel4[0];
  int panel5Height = panel5[1] - panel5[0];

//Draw attributes
  int coords[] = {0, 0};
  int r = 40;
  word color = VGA_WHITE;
  String label = "";
  String dir = "N ";

//Data to receive
  struct TRANSFER_DATA{
    float roll;
    float pitch;
    float yaw;
    float temp;
    byte gear;
    byte warning;
  };
  
  TRANSFER_DATA sensors;

//GPS data
  int sats = 0, satsState = 0;
  float lat, lon;
  float speedVal, courseVal;  
  int year;
  float alt;
  byte month, day, hour, minute, second;
  unsigned long chars = 0;
  unsigned short sentences = 0;
  TinyGPSCustom satsInView(gps, "GPGSV", 3);   
  String satsInViewState;

//Sensor states
  int yawState = 2345;
  int pitchState = -181;
  byte gearState;
  int headerState;

//FPS
  int fps = 0;
  int fpsTime = 0;
  int fpsIterate = 0;

//Sound alert data
  int alert1[] = {1175};
  int alert2[] = {1319, 1760};
  int alert3[] = {1760, 1319, 1976};
  int alert4[] = {3520, 3520};
  int alert5[] = {680, 680};
  int alert6[] = {3500};

//Timers
  unsigned long resTimer = 0;
  unsigned long gyroTimer = 0;
  unsigned long compassTimer = 0;
  unsigned long gearTimer = 0;
  unsigned long demoTimer = 0;
  unsigned long drawTimer = 0;

//Sensor triggers
  bool gyroTrigger = 1;
  bool speedTrigger = 0;
  bool infoTrigger = 1;
  bool mapTrigger = 1;
  bool gearTrigger = 1;
  
  float altState, speedState;
  int limit = 999;
  int fuelLvl = 37;

//Refresh trigger
  boolean force = 1;
  boolean speedRedrawForce = 0;
  boolean pulseTrigger = 0;
  boolean panelState = 0;

//Gear attributes
  int gearInt[]={1, 2, 3, 4, 5};
  int lastGear = 0;

//Font initialisation
  extern uint8_t europebold[3044];
  extern uint8_t europebold_small[764];
  extern uint8_t europegear_numeric[324];
  extern uint8_t europelarge_numeric[5124];
  extern uint8_t europe_numeric[2004];
  extern uint8_t map_font[3044];

//Map attributes
  char* mapArray[6][1] = {
  {" !\"#$%&\'()"}, 
  {"0123456789"}, 
  {"@ABCDEFGH"}, 
  {"PQRSTUVWX"}, 
  {"`abcdefgh"}, 
  {"pqrstuv"}
  };
  
  float cityArray[][2] = {          
  {23.054810, 42.027738},  //"Blagoevgrad",
  {27.446594, 42.503355},  //"Burgas", 
  {27.908020, 43.210047},  //"Varna",         
  {25.611877, 43.074572},  //"V.Tarnovo",
  {22.859802, 43.991695},  //"Vidin",      
  {23.551941, 43.214051},  //"Vratsa",      
  {25.315247, 42.874824},  //"Gabrovo",    
  {27.828369, 43.569314},  //"Dobrich",   
  {25.378418, 41.629643},  //"Kardzhali",
  {22.689514, 42.286318},  //"Kyustendil",   
  {24.710999, 43.135934},  //"Lovech",   
  {23.225098, 43.401921},  //"Montana",   
  {24.326477, 42.192781},  //"Pazardzhik",  
  {23.035583, 42.605495},  //"Pernik", 
  {24.606628, 43.419878},  //"Pleven",
  {24.746704, 42.139851},  //"Plovdiv",      
  {26.537476, 43.533483},  //"Razgrad",     
  {25.968933, 43.841329},  //"Ruse",     
  {27.259827, 44.108164},  //"Silistra",    
  {26.320496, 42.677253},  //"Sliven",    
  {24.700012, 41.577306},  //"Smolian",      
  {23.323301, 42.690210},  //"Sofia",     
  {25.625610, 42.430417},  //"St.Zagora", 
  {26.570435, 43.250071},  //"Targovishte",    
  {25.556946, 41.931775},  //"Haskovo", 
  {26.943970, 43.270073},  //"Shumen",      
  {26.499023, 42.483103}   //"Yambol"
  };
  
  char* cityNames[]{    
  "BLAGOEVGRAD",
  "BURGAS", 
  "VARNA",         
  "V.TARNOVO",
  "VIDIN",      
  "VRATSA",      
  "GABROVO",    
  "DOBRICH",    
  "KARDZHALI",   
  "KYUSTENDIL",   
  "LOVECH",       
  "MONTANA",      
  "PAZARDZHIK", 
  "PERNIK",
  "PLEVEN",
  "PLOVDIV",      
  "RAZGRAD",     
  "RUSE",     
  "SILISTRA",    
  "SLIVEN",    
  "SMOLIAN",      
  "SOFIA",     
  "ST.ZAGORA",  
  "TARGOVISHTE",    
  "HASKOVO", 
  "SHUMEN",      
  "YAMBOL"
  };
  
  int cityCount = 27;
  
  unsigned long dist = 500;
  unsigned long tmpDist;
  unsigned long oldDist;
  int closest = 28;
  int oldClosest;
  
  int locX = 0;
  int locY = 0;

//Speed attributes
  int tmpspd;
  bool limitSet = 0;

//Info attributes
  const int bufferSize = 100;
  char infoStr[bufferSize];
  char serialBuf[bufferSize];
  int serialInd;
  char scrollBuf[bufferSize];
  int scrollSize = 15;
  bool crFound;
  bool parsedTrigger = false;
  char argBuf[5];
  int argInd;
  int commandArg;
  bool argTrigger = false;
  unsigned long infoTimer;
  char infoBuf[15];
  char oldInfo[15];
  char printChar;
  bool scrollTrigger = false;
  int scrollInt;
  unsigned long scrollTimer;
  
//Main color
  int red = 255;
  int green = 0;
  int blue = 0;
  unsigned int currentColor = VGA_RED;
  
//Test data
  bool testSpeed = false;
  float speedValx = 0;
  bool fakeLoc = false;
  float testLon = 27.355957;
  float testLat = 42.943824;
  
//-----------------   SETUP START   -----------------//
  void setup(){
    pinMode(backlight, OUTPUT);
    analogWrite(backlight, 0);
     
    Serial.begin(38400);
    Serial1.begin(38400);
    Serial2.begin(38400);
    
    Serial.println();
    Serial.println("==================================");
    Serial.println("===== AUDI 80 BOARD COMPUTER =====");
    Serial.println("==================================");
    Serial.println();
    Serial.println("===== INITIALIZATION STARTED =====");
    
    Transfer.begin(details(sensors), &Serial1);  
    Serial.println(" - MCU transfer started.");
      
    alert(2);
  
    myGLCD.InitLCD(PORTRAIT);     
    Serial.println(" - Display initialized.");
    myGLCD.setFont(europebold);
    myGLCD.clrScr();
    
    resTimer = millis();
  
    size_x = myGLCD.getDisplayXSize();
    size_y = myGLCD.getDisplayYSize();
    
    drawLogo(70, 200); 
    for(int i = 0; i < backlightLevel; i++){
      analogWrite(backlight, i);
      delay(2);
    }
  
    delay(1000);
      Serial.println(" - Splash screen called.");
    gpsData();
    
    for(int i = backlightLevel; i > 0; i--){
      analogWrite(backlight, i);
      delay(2);
    }
    analogWrite(backlight, 0);  
    initDefault(true, true, true, true, true); 
      Serial.println(" - Default screen drawn.");
    
    fpsTime = millis();
    drawTimer = millis();
    
    Serial.println("======= INITIALIZATION END =======");
    Serial.println();
    Serial.print(">> "); 
   
    for(int i = 0; i < backlightLevel; i++){
      analogWrite(backlight, i);
      delay(2);
    }
  }
//-----------------   SETUP END   -----------------//



//-----------------   LOOP START   -----------------//
  void loop(){
    
  //  if(millis() - resTimer >= 1000*60*1)
  //    reset(); 
      
    gpsData();
    
  //  if(sensors.gear == 2)
  //    reset();
  
    if(testSpeed){
      if(speedValx > 800)
        speedValx = 0;
      speedVal = speedValx;
    }
    
        
    if(fakeLoc){
      lon = testLon;
      lat = testLat;
    }
    
    if(Transfer.receiveData()){       
      warning(sensors.warning); 
      drawGear(sensors.gear);
      if((millis() - drawTimer) >= 200){
        
        if(testSpeed)
          speedValx++;
        
        parseInfo();
        drawHeader(sensors.yaw, sensors.temp); 
        drawGyro(sensors.pitch);
        drawSpeed(speedVal);    
        drawMap();
        drawInfo(infoStr);
        drawTimer = millis();
      }
    }
    
      force = 0;
      
      sensors.roll = 0;
      sensors.pitch = 0;
      sensors.yaw = 0;
      sensors.temp = 0;
      sensors.gear = 0;
      sensors.warning = 0;
  }
//-----------------   LOOP END   -----------------//



//-----------------   INITIALISE DEFAULT START   -----------------//
  void initDefault(bool p1, bool p2, bool p3, bool p4, bool p5){ 
  
    force = 1;
    
    if(p1 == 1 && p2 == 1 && p3 == 1 && p4 == 1 && p5 == 1)
      myGLCD.clrScr();
  
    if(p1){
      myGLCD.setColor(VGA_BLACK);
      myGLCD.fillRect(0, 0, size_x, panel1[1]);   
      myGLCD.setColor(currentColor);
      myGLCD.fillRect(0, panel1[1], size_x, panel2[0]);
      drawHeader(0, 0);}   
    if(p2){
      myGLCD.setColor(VGA_BLACK);
      myGLCD.fillRect(0, panel2[0], size_x, panel2[1]);   
      myGLCD.setColor(currentColor);
      myGLCD.fillRect(0, panel2[1], size_x, panel3[0]);
      drawGyro(0);}   
    if(p3){
      myGLCD.setColor(VGA_BLACK);
      myGLCD.fillRect(0, panel3[0], size_x, panel3[1]);   
      myGLCD.setColor(currentColor);
      myGLCD.fillRect(0, panel3[1], size_x, panel4[0]);
      drawInfo("-------------");}   
    if(p4){
      myGLCD.setColor(VGA_BLACK);
      myGLCD.fillRect(0, panel4[0], size_x, panel4[1]);   
      myGLCD.setColor(currentColor);
      myGLCD.fillRect(0, panel4[1], size_x, panel5[0]);
      drawMap();}   
    if(p5){
      myGLCD.setColor(VGA_BLACK);
      myGLCD.fillRect(0, panel5[0], size_x, panel5[1]);
      drawGear(0);}
    
      yawState = 2345;
      pitchState = 0;
      gearState = 0;
      headerState = 0;
      //satsState = 0;
      //satsInViewState = "";
      panelState = 0;
      altState = 0;
      headerState = 0;
  }
//-----------------   INITIALISE DEFAULT END   -----------------//



//-----------------   DRAW HEADER START   -----------------//
  void drawHeader(float yaw, float alt){
      
    if(round(headerState) != round(alt) || round(yawState) != round(yaw)){
    
    myGLCD.setColor(VGA_BLACK);
    
    if(abs(yaw) > 157.5){
      dir = "N ";
      myGLCD.fillRect(39, 0, 61, 18);
    } else if(abs(yaw) > 112.5){
      yaw < 0 ? dir = "NW" : dir = "NW";      
    } else if(abs(yaw) > 67.5){
      yaw < 0 ? dir = "W" : dir = "E";
      myGLCD.fillRect(39, 0, 61, 18);      
    } else if(abs(yaw) > 22.5){
      yaw < 0 ? dir = "SW" : dir = "SE";      
    } else {
      dir = "S ";
      myGLCD.fillRect(39, 0, 61, 18);
    }
    
    myGLCD.setColor(VGA_WHITE);
    myGLCD.setBackColor(VGA_BLACK);
    myGLCD.setFont(europebold);
    
    myGLCD.print(dir, 24, 3, 2);
  
    drawCompArrow(3, 3, yaw);
    
    if(alt < 10 && alt >= 0)
      coords[0] = 32;
    else if((alt < 100 && alt >= 0) || (alt < 0 && alt > -10))   
      coords[0] = 48;
    else if((alt < 1000 && alt >= 0) || (alt < 0 && alt > -100))
      coords[0] = 64;
    else 
      coords[0] = 80;
    
           
    if((int)headerState % 1000 != (int)alt % 1000 || (int)headerState % 100 != (int)alt % 100 || (int)headerState % 10 != (int)alt % 10){
      myGLCD.setColor(VGA_BLACK);
      myGLCD.fillRect(96, 0, size_x, 22);
    }
    
    myGLCD.setColor(VGA_WHITE);
    myGLCD.setBackColor(VGA_BLACK);
    
    myGLCD.printNumI(alt, (size_x - coords[0]), 4, 1);
    
    if(alt >= 40)
      drawTemp(size_x - coords[0]-16, 5, 1);
    else if(alt <= 0)
      drawTemp(size_x - coords[0]-16, 5, -1);
    else
      drawTemp(size_x - coords[0]-16, 5, 0);
      
    myGLCD.setColor(VGA_BLACK);
    myGLCD.fillRect((size_x - coords[0]-32), 0, (size_x - coords[0]-16), 22);
    
    myGLCD.setColor(VGA_WHITE);
    myGLCD.drawCircle(size_x - 9, 9, 3);
    //myGLCD.print("C", (size_x - 20), 4);
    }
    headerState = alt;
    yawState = yaw;
  }
//-----------------   DRAW HEADER END   -----------------//



//-----------------   DRAW GYRO START   -----------------//
  void drawGyro(int pitch){
    
    if(gyroTrigger || (gyroTrigger && force)){
      
      if(force == 1){
        coords[0] = size_x/2 - 30;
        coords[1] = panel2Height/2 + panel1Height + 3;
        drawGauge(coords[0], coords[1]);
      }
      
    if(round(pitchState) != round(pitch)){
    
    coords[0] = size_x/2 - 40;
    coords[1] = panel2Height/2 + panel1Height + 3;
    
    gyroTimer = millis();
    
      drawArrow(coords[0], coords[1], pitchState, true);
      drawpitch(coords[0], coords[1]);
      drawArrow(coords[0], coords[1], pitch, false);
      
    myGLCD.setColor(VGA_WHITE);
    myGLCD.setBackColor(VGA_BLACK);
    myGLCD.setFont(europebold);
    
    if(pitch <= 0){
      myGLCD.setColor(VGA_BLACK);
      myGLCD.fillRect(size_x-55, panel1Height+panel2Height/2+4, size_x-5, panel1Height+panel2Height/2+22);
      myGLCD.setColor(VGA_WHITE);
      myGLCD.setBackColor(VGA_BLACK);
      myGLCD.printNumI(-pitch, size_x-55, panel1Height+panel2Height/2-19, 3);
    }
    else if(pitch > 0){
      myGLCD.setColor(VGA_BLACK);
      myGLCD.fillRect(size_x-55, panel1Height+panel2Height/2-20, size_x-5, panel1Height+panel2Height/2-3);
      myGLCD.setColor(VGA_WHITE);
      myGLCD.setBackColor(VGA_BLACK);
      myGLCD.printNumI(-pitch, size_x-55, panel1Height+panel2Height/2+8, 3);
    }
    pitchState = pitch;
    }
    }
  }
//-----------------   DRAW GYRO END   -----------------//



//-----------------   DRAW SPEED START   -----------------//
  void drawSpeed(int speedVal){
   if(speedTrigger || (speedTrigger && force)){ 
     
    if(sensors.gear == 4){
      if(limitSet){
        limit = 999;
        drawInfo("LIMIT REMOVED");
        limitSet = 0;
      }
      else {
        limitSet = 1;
        limit = speedVal + 10;
        sprintf(infoStr, "LIMIT SET:%d", limit);
        drawInfo(infoStr);
        memset(infoStr, 0, strlen(infoStr));
        alert(4);
        delay(2000);
      }
    }
    
    if(speedState >= 100 && speedVal < 100 ||
        speedState >= 10 && speedVal < 10 ||
        speedState < 100 && speedVal >= 100 ||
        speedState < 10 && speedVal >= 10 ||
        speedRedrawForce == true){
      myGLCD.setColor(VGA_BLACK);
      myGLCD.fillRect(0, panel2[0], size_x, panel2[1]-1);
    }
    
    if(speedVal != speedState || force == 1 || speedRedrawForce == false){
      if(speedVal >= limit)
        pulseTrigger = true;
      else
        pulseTrigger = false;
      
      if(pulseTrigger == true){
        color = currentColor;
        alert(4); }
      else
        color = VGA_WHITE;
      
      if(speedVal >= 100)
        tmpspd = 2;
      else if(speedVal >= 10)
        tmpspd = 1;
      else 
        tmpspd = 0;
    }
    
    myGLCD.setFont(europelarge_numeric);
    myGLCD.setColor(color);    
    myGLCD.setBackColor(VGA_BLACK);
    myGLCD.printNumI(speedVal, 60-30*tmpspd, panel2[0]+20, tmpspd+1);
    myGLCD.setFont(europebold);
    myGLCD.print("km", 140+30*tmpspd, panel2[0]+35);
    myGLCD.print("h", 148+30*tmpspd, panel2[0]+55);
    myGLCD.fillRect(142+30*tmpspd, panel2[0]+53, 170+30*tmpspd, panel2[0]+55);   
      
    if((int)altState % 1000 != (int)alt % 1000 || (int)altState % 100 != (int)alt % 100 || (int)altState % 10 != (int)alt % 10){
      myGLCD.setColor(VGA_BLACK);
      myGLCD.fillRect(24, panel2[1]-20, 120, panel2[1]-1);
    }
    
    tmpspd = 0;
    
    myGLCD.setColor(VGA_WHITE);    
    drawMount(3, panel2[1]-17);
    myGLCD.setFont(europebold);
    
    if(alt < 10 && alt >= 0)
      tmpspd = 0;
    else if((alt < 100 && alt >= 0) || (alt < 0 && alt > -10))   
      tmpspd = 1;
    else if((alt < 1000 && alt >= 0) || (alt < 0 && alt > -100))
      tmpspd = 2;
    else 
      tmpspd = 3;
    
    myGLCD.setColor(VGA_WHITE); 
    myGLCD.setBackColor(VGA_BLACK);
    myGLCD.printNumI(alt, 22, panel2[1]-18, tmpspd+1);
    myGLCD.print("m", 40+16*tmpspd, panel2[1]-18);
      
    drawFuel(174, panel2[1]-19);
    myGLCD.setFont(europebold);
    myGLCD.setColor(VGA_WHITE); 
    myGLCD.setBackColor(VGA_BLACK);
    myGLCD.printNumI(fuelLvl, 192, panel2[1]-18);
    myGLCD.print("l", 225, panel2[1]-19);
    
    altState = alt;
    speedState = speedVal;
    speedRedrawForce = false;
    pulseTrigger = false;
    }
  }
//-----------------   DRAW SPEED END   -----------------//



//-----------------   DRAW INFO START   -----------------//
  void drawInfo(char* info){
    if(infoTrigger || force){
    
    if(strlen(info) > 14 || scrollTrigger == 1){
      
      if(scrollInt == false){
        scrollTrigger = true;
        scrollSize = strlen(info);
        memset(scrollBuf, 0, strlen(scrollBuf));
        sprintf(scrollBuf, info);
      }
        
        memset(infoBuf, 0, strlen(infoBuf));
        
        for(int i = 0; i < 14; i++){
          infoBuf[i] = scrollBuf[i+scrollInt];
        }
        scrollInt++;
      }
    
    else {
      memset(infoBuf, 0, strlen(infoBuf));
      sprintf(infoBuf, info);
    }
    
    if(strcmp(oldInfo,infoBuf) != 0 && millis() - infoTimer > 3000 || scrollTrigger || parsedTrigger || force){
      myGLCD.setColor(VGA_BLACK);
      myGLCD.fillRect(0, panel3[0]+1, size_x, panel3[1]-1);
      
      if(parsedTrigger)
        myGLCD.setColor(VGA_WHITE);
      else
        myGLCD.setColor(VGA_WHITE);
        
      myGLCD.setBackColor(VGA_BLACK);
      myGLCD.setFont(europebold);
      myGLCD.print(infoBuf, (size_x-strlen(infoBuf)*16)/2, panel3[0]+3);
      infoTimer = millis();
      parsedTrigger = false;
      memset(oldInfo, 0, sizeof(oldInfo));
      sprintf(oldInfo, infoBuf);
    }
    
    if(scrollInt > scrollSize-14){
      scrollInt = 0;
      scrollSize = 15;
      scrollTrigger = false;
      infoTimer = millis();
    }
    }
  }
//-----------------   DRAW INFO END   -----------------//



//-----------------   PARSE INFO START   -----------------//
  void parseInfo(){
    
    if(Serial.available()){
      while(Serial.available() && serialInd < sizeof(serialBuf) && !crFound){
        
        if((Serial.peek() == 10 || Serial.peek() == 13) && serialInd != 0){  //New Line/Carriage Return
          crFound = true;
          Serial.read();}
        else if(Serial.peek() == 127 && serialInd != 0){ //Backspace
          serialInd--;
          serialBuf[serialInd] = '\0';
          Serial.print((char)Serial.read());}        
        else if(Serial.peek() == 61 && serialInd != 0){ //Equal
          argTrigger = true;
          Serial.print((char)Serial.read());}
        else {
          printChar = toupper(Serial.read());
          Serial.print(printChar);
          if(argTrigger){
            argBuf[argInd] = printChar;
            argInd++;
          } else {
            serialBuf[serialInd] = printChar;
            serialInd++;
          }
        }
        
      }
      
      if(crFound){
        Serial.println();
        commandArg = atoi(argBuf);
        memset(infoStr, 0, strlen(infoStr));
        alert(6);
        checkCommand(serialBuf);
        sprintf(infoStr, serialBuf);
        serialInd = 0;
        parsedTrigger = true;
        memset(serialBuf, 0, sizeof(serialBuf));
        argInd = 0;
        memset(argBuf, 0, sizeof(argBuf));
        commandArg = 0;
        argTrigger = false;
        crFound = false;
      }
    }
    else if((closest != oldClosest || dist != oldDist) && dist < 200 && gps.location.isValid()){
      memset(infoStr, 0, strlen(infoStr));
      if(dist < 3)
        sprintf(infoStr, "- %s -\0", cityNames[closest]);
      else
        sprintf(infoStr, "%s %dKM\0", cityNames[closest], dist);}
    else {
      sprintf(infoStr, "NO GPS FIX\0");}
            
//    else if((gps.location.isValid() || dist != oldDist) && dist < 380){
      
    oldDist = dist;
    oldClosest = closest;
  }
//-----------------   PARSE INFO END   -----------------//



//-----------------   DRAW MAP START   -----------------//
  void drawMap(){
    if(mapTrigger == true){
    if(round(sensors.yaw)/2 != round(yawState)/2 || force == 1){
      
    static int x = 5;
    static int y = panel4[0]+10;
  
    locX = lonCoord(lon)+x;
    locY = latCoord(lat)+y;
    
    constrain(locX, x, x+156);
    constrain(locY, y, y+96);
    
      myGLCD.setColor(VGA_WHITE);
      myGLCD.setBackColor(VGA_BLACK);
      myGLCD.setFont(map_font);
      
      for(int i = 0; i < 6; i++){
          myGLCD.print(("%c", mapArray[i][0]), x, y+16*i);
      }
      
      myGLCD.setColor(currentColor);
      for(int i = 0; i < cityCount; i++){
        myGLCD.fillCircle(lonCoord(cityArray[i][0])+x, latCoord(cityArray[i][1])+y, 2);
        tmpDist = getDistance(lon, lat, cityArray[i][0], cityArray[i][1]);
        if(gps.location.isValid()){
          if(tmpDist < dist){
            dist = tmpDist;
            closest = i;
          }
        }
      }
      
      if(gps.location.isValid())
      drawComp(locX, locY, sensors.yaw, 15); 
      
      if(satsState != sats || satsInViewState != satsInView.value() || force == 1)
        drawGPS(x+160, y+5);
          
      if(alt < 10 && alt >= 0)
        tmpspd = 0;
      else if((alt < 100 && alt >= 0) || (alt < 0 && alt > -10))   
        tmpspd = 1;
      else if((alt < 1000 && alt >= 0) || (alt < 0 && alt > -100))
        tmpspd = 2;
      else 
        tmpspd = 3;
        
      if(sats > 0)
        myGLCD.setColor(VGA_WHITE);
      else
        myGLCD.setColor(currentColor);
        
      drawMount(size_x-56-16*tmpspd, panel4[1]-23);
      myGLCD.setFont(europebold);
      myGLCD.setBackColor(VGA_BLACK);
      myGLCD.printNumI(alt, size_x-38-16*tmpspd, panel4[1]-24, tmpspd+1);
      myGLCD.print("m", size_x-20, panel4[1]-24);
      
      satsState = sats;
      satsInViewState = satsInView.value();
    }
    }
  }
//-----------------   DRAW MAP END   -----------------//



//-----------------   DRAW GEAR START   -----------------//
  void drawGear(int gear){
     
    static int currGear;
    if(gearState != gear || force == 1){
    
      currGear = 0;
      
    for(int i = 5; i >= 0; i--){
      if(bitRead(gear, i) == 1)
        currGear = i+1;
    }
      
    myGLCD.setFont(europegear_numeric);
    
    for(int i = 0; i < 5; i++){
      myGLCD.setColor(VGA_BLACK);
      myGLCD.fillRect((30*i + 10 + 10*i), (size_y - 30), (30*i + 10 + 10*i + 20), size_y);
      myGLCD.setColor(VGA_WHITE);
      myGLCD.setBackColor(VGA_BLACK);
      myGLCD.printNumI(gearInt[i], (40*i + 12), (size_y - 22), 1);
      
      
    if(currGear == gearInt[i] && currGear < 6){
      myGLCD.setColor(currentColor);
      myGLCD.fillRect((30*i + 10 + 10*i), (size_y - 30), (30*i + 10 + 10*i + 20), size_y);
      myGLCD.setColor(VGA_WHITE);
      myGLCD.setBackColor(currentColor);
      myGLCD.printNumI(gearInt[i], (40*i + 12), (size_y - 22), 1);
      }
      }
      
      myGLCD.setColor(VGA_BLACK);
      myGLCD.fillRect((30*5 + 10 + 10*5), (size_y - 30), (30*5 + 10 + 10*5 + 20), size_y);
      myGLCD.setColor(VGA_WHITE);
      myGLCD.setBackColor(VGA_BLACK);
      myGLCD.printNumI(0, (40*5 + 12), (size_y - 22), 1);
      
    if(currGear == 6){
      myGLCD.setColor(currentColor);
      myGLCD.fillRect((30*5 + 10 + 10*5), (size_y - 30), (30*5 + 10 + 10*5 + 20), size_y);
      myGLCD.setColor(VGA_WHITE);
      myGLCD.setBackColor(currentColor);
      myGLCD.printNumI(0, (40*5 + 12), (size_y - 22), 1);
    }
    
    gearState = gear;
    gearTimer = millis();
    
    }
  }
//-----------------   DRAW GEAR END   -----------------//



//-----------------   PANELCHECK START   -----------------//
  void panelCheck(int speedVal){
    
    if(speedVal > 5){
      gyroTrigger = 0;
      speedTrigger = 1;
    } else {
      gyroTrigger = 1;
      speedTrigger = 0;
    }
    
    if(speedTrigger != panelState){
      initDefault(0, 1, 0, 0, 0);
      force = 1;
    }
    
    panelState = speedTrigger;
  }
//-----------------   PANELCHECK END   -----------------//



//-----------------   RESET START   -----------------//
  void reset(){
    analogWrite(backlight, 0);
    myGLCD.InitLCD(PORTRAIT);
    delay(150);
    analogWrite(backlight, 200);  
    resTimer = millis();
  }
//-----------------   RESET END   -----------------//



//-----------------   ALERT START   -----------------//
  void alert(int alertTrigger){
    switch(alertTrigger){
      case 1:
      for (int i = 0; i < 1; i++) {
        for (int j = 9; j >= 2; j--){
         toneAC(alert1[i], j, 1000/1, true);
         delay(70);
     }
     noToneAC();
     }
     noToneAC();
     break;
     
     case 2:
      for (int i = 0; i < 2; i++) {
         toneAC(alert2[i], 10, 1000/1, true);
         delay(100);
     }
     noToneAC();
     break;
     
     case 3:
      for (int i = 0; i < 3; i++) {
         toneAC(alert3[i], 10, 1000/1, true);
         delay(100);
     }
     noToneAC();
     break;
     
     case 4:
      for (int i = 0; i < 2; i++) {
         toneAC(alert4[i], 10, 1000/1, true);
         delay(50);
     }
     noToneAC();
     break;
     
     case 5:
      for (int i = 0; i < 2; i++) {
        for (int j = 9; j >= 0; j--){
         toneAC(alert5[i], j, 1000/1, true);
         delay(20);
       }
     }
     noToneAC();
     break;
        
     case 6:
     toneAC(alert6[0], 10, 1000/1, true);
     delay(20);
     noToneAC();
     break;
     
     default:
     noToneAC();
     break;
    }
  }
//-----------------   ALERT END   -----------------//



//-----------------   GPSDATA START   -----------------//
  void gpsData(){    
    while(!Serial2){}
    
    while(Serial2.available())
       gps.encode(Serial2.read());
     
     if(gps.satellites.isValid())
       sats = gps.satellites.value();
       
     if(gps.location.isValid()){
       lat = gps.location.lat();
       lon = gps.location.lng(); }
       
     if(gps.speed.isValid())
       speedVal =gps.speed.kmph();
       
     if(gps.course.isValid())
       courseVal =gps.course.deg();
       
     if(gps.altitude.isValid())
       alt =gps.altitude.meters();
     
     if(gps.date.isValid()){
      year = gps.date.year();
      month = gps.date.month();
      day = gps.date.day(); }
      
     if(gps.time.isValid()){
      hour = gps.time.hour();
      minute = gps.time.minute();
      second = gps.time.second(); }
      
     chars = gps.charsProcessed(); 
     sentences = gps.sentencesWithFix();
  }
//-----------------   GPSDATA END   -----------------//



//-----------------   GPS UTILS START   -----------------//
  int latCoord(float lat){
    return map(lat*10, 44.214555*10, 41.236022*10, 0, 96);
  }
  
  int lonCoord(float lon){
    return map(lon*10, 22.360067*10, 28.607050*10, 0, 156);
  }
  
  unsigned long getDistance(float lonA, float latA, float lonB, float latB){ 
    return (unsigned long)TinyGPSPlus::distanceBetween(latA, lonA, latB, lonB)/1000;
  }
//-----------------   GPS UTILS END   -----------------//



//-----------------   WARNING START   -----------------//
  void warning(byte warning){
    
    static byte currActive;
    static unsigned long warningTimer;
    static unsigned long alertTimer;
    static byte activeCount;
    static byte count;
    static byte oldWarning;
    
    if(warning == 0){
      currActive = 0;
      activeCount = 0;    
      panelCheck(speedVal);   
      infoTrigger = 1;   
      mapTrigger = 1;
      if(oldWarning != 0)
        initDefault(false, true, true, true, false);
    }
    else {
      gyroTrigger = 0;
      speedTrigger = 0;
      infoTrigger = 0;
      mapTrigger = 0;
    }
    
    if(warning != oldWarning)
      currActive = 0;
    
    activeCount = 0;
    for(int i = 0; i < 8; i++){
      if(bitRead(warning, i) == 1)
        activeCount++;
    }
    
    if(warning != 0 && millis() - warningTimer > 1000){  
        
      if(warning == currActive){
        currActive = 0;
        count = 0;
      }
      
      while(bitRead(currActive, count) == bitRead(warning, count)){
        count++;
      }
      
      bitSet(currActive, count);
  
      drawAlert(count+1, 0);
      
      if(millis()-alertTimer > 5000){
        alert(1);
        alertTimer = millis();
      }
      
      warningTimer = millis();
      
  }
    oldWarning = warning;
  }
//-----------------   WARNING END   -----------------//



//-----------------   FPS START   -----------------//
  void fpsCalc(){
    if ((millis() - fpsTime) >= 1000){
      fps = fpsIterate;
      fpsIterate = 0;    
      fpsTime = millis();
    }
    fpsIterate++;
  }
//-----------------   FPS START   -----------------//



//-----------------   RAD START   -----------------//
  float rad(int deg){
    return -(deg*0.0174532925);
  }
//-----------------   RAD END   -----------------//



//-----------------   CHECK COMMAND START   -----------------//
  void checkCommand(char* buf){
    if(strcmp(buf,"REDRAW") == 0){
        delay(100);
        alert(6);
        delay(100);
        alert(6);
        currentColor = (round(red/8) << 11) | (round(green/4) << 5) | round(blue/8);
        Serial.print("<< CURRENT COLOR (");
        Serial.print(red);
        Serial.print(", ");
        Serial.print(green);
        Serial.print(", ");
        Serial.print(blue);
        Serial.println(")");
        initDefault(true, true, true, true, true);}
        
    else if(strcmp(buf, "RESET") == 0){
        delay(100);
        alert(6);
        delay(100);
        alert(6);
        Serial.println("<< DISPLAY RESET");
        reset();}
        
    else if(strcmp(buf, "COLORTEST") == 0){
        delay(100);
        alert(6);
        delay(100);
        alert(6);
        Serial.println("<< RUNNING COLOR TEST");
        colorTest();
        initDefault(true, true, true, true, true);}    
        
    else if(strcmp(buf, "PRINT") == 0){
        delay(100);
        alert(6);
        delay(100);
        alert(6);
        printData();}

    else if(strcmp(buf, "SETRED") == 0){
        delay(100);
        alert(6);
        delay(100);
        alert(6);
        red = commandArg;
        Serial.print("<< RED SET TO ");
        Serial.println(red);} 
        
    else if(strcmp(buf, "SETGREEN") == 0){
        delay(100);
        alert(6);
        delay(100);
        alert(6);
        green = commandArg;
        Serial.print("<< GREEN SET TO ");
        Serial.println(green);} 
        
    else if(strcmp(buf, "SETBLUE") == 0){
        delay(100);
        alert(6);
        delay(100);
        alert(6);
        blue = commandArg;
        Serial.print("<< BLUE SET TO ");
        Serial.println(blue);}    
        
    else if(strcmp(buf, "SOUND") == 0){
     toneAC(commandArg, 10, 1000/1, true);
     delay(1000);
     noToneAC();}
        
    else if(strcmp(buf, "ALERT") == 0){
        Serial.print("<< PLAYING ALERT");
        Serial.println(commandArg);
        alert(commandArg);}  
        
    else if(strcmp(buf, "PANEL") == 0){
        delay(100);
        alert(6);
        delay(100);
        alert(6);
        Serial.println("<< SWITCHING PANELS");
        testSpeed = !testSpeed;
      }  
      
    else if(strcmp(buf, "FAKELOC") == 0){
        delay(100);
        alert(6);
        delay(100);
        alert(6);
        Serial.println("<< FAKING LOCATION");
        fakeLoc = !fakeLoc;
      }      
      
    else if(strcmp(buf, "SWITCHLOC") == 0){
        delay(100);
        alert(6);
        delay(100);
        alert(6);
        testLon = cityArray[random(30)][0];
        testLat = cityArray[random(30)][1];
        Serial.println("<< SWITCHING LOCATION");
      }
        
    else if(strcmp(buf, "BLINK") == 0){
        delay(100);
        alert(6);
        delay(100);
        alert(6);
        Serial.println("<< BLINKING DISPLAY");
        for(int j = 0; j < 5; j++){
          for(int i = backlightLevel; i > 0; i--){
            analogWrite(backlight, i);
            delay(1);
          }
          for(int i = 0; i < backlightLevel; i++){
            analogWrite(backlight, i);
            delay(1);
          }
        }
    }
    Serial.print(">> "); 
  }
//-----------------   CHECK COMMAND END   -----------------//



//-----------------   PRINT DATA START   -----------------//
  void printData(){
      Serial.print("<< X:");
      Serial.print(sensors.pitch);
      Serial.print(" Y:");
      Serial.print(sensors.roll);
      Serial.print(" Z:");
      Serial.print(sensors.yaw);
      Serial.print(" T:");
      Serial.print(sensors.temp);
      Serial.print(" G:");
      Serial.print(sensors.gear);
      Serial.print(" W:");
      Serial.print(sensors.warning);    
      Serial.print(" Sat:");
      Serial.print(sats);
      Serial.print(" SV:");
      Serial.print(satsInView.value());
      Serial.print(" Lat:");
      Serial.print(lat); 
      Serial.print(" Lon:");
      Serial.print(lon);
      Serial.print(" Speed:");
      Serial.print(speedVal);
      Serial.print(" Course:");
      Serial.print(courseVal);
      Serial.print(" Alt:");
      Serial.print(alt);
      Serial.print(" Time:");
      Serial.print(hour);
      Serial.print(":");
      Serial.print(minute);
      Serial.print(":");
      Serial.print(second);
      Serial.print(" Date:");      
      Serial.print(day);
      Serial.print("/");      
      Serial.print(month);
      Serial.print("/");      
      Serial.print(year);
      Serial.print(" C:");
      Serial.print(chars);
      Serial.print(" S:");
      Serial.print(sentences);      
      Serial.println(); 
  }
//-----------------   PRINT DATA END  -----------------//



//-----------------  COLOR TEST START  -----------------//
  void colorTest(){
    myGLCD.clrScr();
    
    for(int i = 0; i < 255; i++){
      myGLCD.setColor(i, 0, 0);
      myGLCD.drawLine(0, i, size_x, i);
      delay(10);
    }  
    for(int i = 0; i < 255; i++){
      myGLCD.setColor(0, i, 0);
      myGLCD.drawLine(0, i, size_x, i);
      delay(10);
    }  
    for(int i = 0; i < 255; i++){
      myGLCD.setColor(0, 0, i);
      myGLCD.drawLine(0, i, size_x, i);
      delay(10);
    }    
    for(int i = 0; i < 255; i++){
      myGLCD.setColor(i, i, 0);
      myGLCD.drawLine(0, i, size_x, i);
      delay(10);
    }  
    for(int i = 0; i < 255; i++){
      myGLCD.setColor(i, 0, i);
      myGLCD.drawLine(0, i, size_x, i);
      delay(10);
    }  
    for(int i = 0; i < 255; i++){
      myGLCD.setColor(0, i, i);
      myGLCD.drawLine(0, i, size_x, i);
      delay(10);
    }
    for(int i = 0; i < 255; i++){
      myGLCD.setColor(i, i, i);
      myGLCD.drawLine(0, i, size_x, i);
      delay(10);
    }
  }
//-----------------  COLOR TEST END  -----------------//





/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////





//=================================================================
//=================================================================
//========================= OBJECTS DRAW ==========================
//=================================================================
//=================================================================

//Splash logo
void drawLogo(int x, int y){
   
  for(int i = 0; i < 4; i++){
    for(int j = 0; j < 4; j++){
      if(j == 0)
        myGLCD.setColor(200, 200, 200);
      else if(j == 1 || j == 2)
        myGLCD.setColor(220, 220, 220);
      else
        myGLCD.setColor(VGA_WHITE);
      myGLCD.drawCircle(x + i*35, y, 20 + j);
      myGLCD.drawCircle(x + i*35, y, 25 - j);
    }
  }
}

//Gyro crosshair
void drawpitch(int x, int y){    
  myGLCD.setColor(VGA_WHITE);
  myGLCD.drawCircle(x, y, r);
  myGLCD.drawCircle(x, y, r-1);
  myGLCD.drawCircle(x, y, r-2);
  
  myGLCD.setColor(VGA_WHITE);
  //myGLCD.drawLine(x-r-10, y, x+r+10, y);
  myGLCD.drawLine(0, y, size_x, y);
  myGLCD.drawLine(x, y-r-10, x, y+r+10);
}

//Gyro gauge
void drawGauge(int x, int y){
  myGLCD.setColor(VGA_RED);
  geo.drawArc(x, y, r+41, 50, 130, 10);
  myGLCD.setColor(0, 190, 0);
  geo.drawArc(x, y, r+41, 70, 110, 10);
  myGLCD.setColor(VGA_WHITE);
  geo.drawArc(x, y, r+41, 89, 91, 10);
}

//Gyro arrow
void drawArrow(int x, int y, int ang, bool neg){
  
  float a = -rad(ang);
  
  if(ang > 40)
    a = 0.69813;
  else if (ang < -40)
    a = -0.69813;
  
  if(neg == true)
    myGLCD.setColor(VGA_BLACK);
  else if(abs(ang) < 2)
    myGLCD.setColor(VGA_WHITE);
  else if(abs(ang) < 20)
    myGLCD.setColor(0, 190, 0); 
  else
    myGLCD.setColor(VGA_RED); 
    
    //Line
    geo.fillTriangle(x-(r+20)*cos(a), y+3-(r+20)*sin(a), x+(r+20)*cos(a), y+3+(r+20)*sin(a), x-(r+20)*cos(a), y-3-(r+20)*sin(a));
    geo.fillTriangle(x-(r+20)*cos(a), y-3-(r+20)*sin(a), x+(r+20)*cos(a), y+3+(r+20)*sin(a), x+(r+20)*cos(a), y-3+(r+20)*sin(a));
    
    //Arrow
    geo.fillTriangle(x+(r+20)*cos(a+0.1), y+(r+20)*sin(a+0.1), x+(r+20)*cos(a-0.1), y+(r+20)*sin(a-0.1), x+(r+30)*cos(a), y+(r+30)*sin(a));
}

//Header compass icon
void drawCompArrow(int x, int y, int a){  
  myGLCD.setColor(VGA_BLACK);
  myGLCD.fillRect(x-2, y-2, x+18, y+18);
  myGLCD.setColor(VGA_WHITE);
  geo.fillTriangle(x+8+9*-cos(rad(a)+rad(90)), y+10+9*-sin(rad(a)+rad(90)), 
                   x+8+1/4*-cos(-rad(a)+rad(90)), y+10+1/4*-sin(-rad(a)+rad(90)), 
                   x+8+9*-cos(rad(a)+rad(135)+rad(90)), y+10+9*-sin(rad(a)+rad(135)+rad(90)));
  geo.fillTriangle(x+8+9*-cos(rad(a)+rad(90)), y+10+9*-sin(rad(a)+rad(90)), 
                   x+8+1/4*-cos(-rad(a)+rad(90)), y+10+1/4*-sin(-rad(a)+rad(90)), 
                   x+8+9*-cos(rad(a)-rad(135)+rad(90)), y+10+9*-sin(rad(a)-rad(135)+rad(90)));
}

//Header altitude icon
void drawMount(int x, int y){
  //myGLCD.setColor(VGA_WHITE);
  geo.fillTriangle(x+3, y+5, x, y+12, x+12, y+12);
  geo.fillTriangle(x+8, y, x+5, y+12, x+12, y+12);
}

//Header temperature icon
void drawTemp(int x, int y, int type){
  switch (type){
  //Snowflake
  case -1:
    myGLCD.setColor(VGA_WHITE);
    myGLCD.drawLine(x+7, y, x+7, y+13);
    myGLCD.drawLine(x, y+7, x+13, y+7);
    myGLCD.drawLine(x+3, y+3, x+11, y+11);
    myGLCD.drawLine(x+3, y+11, x+11, y+3);
    
    myGLCD.drawLine(x+9, y+12, x+7, y+10);
    myGLCD.drawLine(x+5, y+12, x+7, y+10);
    myGLCD.drawLine(x+9, y+1, x+7, y+4);
    myGLCD.drawLine(x+5, y+1, x+7, y+4);
    
    myGLCD.drawLine(x+12, y+5, x+10, y+7);
    myGLCD.drawLine(x+12, y+9, x+10, y+7);
    myGLCD.drawLine(x+1, y+5, x+4, y+7);
    myGLCD.drawLine(x+1, y+9, x+4, y+7);
    break;
  
  //Thermometer
  case 0:
    myGLCD.setColor(VGA_WHITE);
    myGLCD.drawCircle(x+7, y+9, 3);
    myGLCD.drawCircle(x+7, y+2, 1);
    myGLCD.fillRect(x+6, y+7, x+8, y+2);
    break;
    
  //Sun
  case 1:
    myGLCD.fillCircle(x+6, y+7, 3);
    for(int i = 0; i < 8; i++){
          myGLCD.drawLine(x+6+5*cos(i*rad(45)), y+7+5*sin(i*rad(45)), x+6+6*cos(i*rad(45)), y+7+6*sin(i*rad(45)));
    }
    break;
    
  }
}

//Fuel icon
void drawFuel(int x, int y){
  myGLCD.setColor(VGA_WHITE);
  myGLCD.fillRect(x+8-4, y, x+8+4, y+6);
  myGLCD.fillRect(x+8-3, y+4, x+8+3, y+14);
  myGLCD.fillRect(x+8-4, y+14, x+8+4, y+16);
  
  myGLCD.setColor(VGA_BLACK);
  myGLCD.fillRect(x+8-2, y+1, x+8+2, y+4);
}

//GPS pointer
void drawComp(int x, int y, int a, int r){
  myGLCD.setColor(VGA_BLACK);
  geo.fillTriangle(x+r*-cos(rad(a)+rad(90)), y+r*-sin(rad(a)+rad(90)), 
                   x+1/4*-cos(-rad(a)+rad(90)), y+1/4*-sin(-rad(a)+rad(90)), 
                   x+r*-cos(rad(a)+rad(135)+rad(90)), y+r*-sin(rad(a)+rad(135)+rad(90)));
  geo.fillTriangle(x+r*-cos(rad(a)+rad(90)), y+r*-sin(rad(a)+rad(90)), 
                   x+1/4*-cos(-rad(a)+rad(90)), y+1/4*-sin(-rad(a)+rad(90)), 
                   x+r*-cos(rad(a)-rad(135)+rad(90)), y+r*-sin(rad(a)-rad(135)+rad(90)));
                   
  myGLCD.setColor(37, 159, 209);
  geo.fillTriangle(x+r*-cos(rad(a)+rad(90)), y-4+r*-sin(rad(a)+rad(90)), 
                   x+1/4*-cos(-rad(a)+rad(90)), y-4+1/4*-sin(-rad(a)+rad(90)), 
                   x+r*-cos(rad(a)+rad(135)+rad(90)), y-4+r*-sin(rad(a)+rad(135)+rad(90)));
  myGLCD.setColor(59, 198, 238);
  geo.fillTriangle(x+r*-cos(rad(a)+rad(90)), y-4+r*-sin(rad(a)+rad(90)), 
                   x+1/4*-cos(-rad(a)+rad(90)), y-4+1/4*-sin(-rad(a)+rad(90)), 
                   x+r*-cos(rad(a)-rad(135)+rad(90)), y-4+r*-sin(rad(a)-rad(135)+rad(90)));
}

//GPS icon
void drawGPS(int x, int y){
  if(sats > 0)
    color = VGA_WHITE;
  else
    color = currentColor;
  
  myGLCD.setColor(color);
  myGLCD.fillCircle(x+32, y+32, 32);
  myGLCD.setColor(VGA_BLACK);
  myGLCD.fillCircle(x+32, y+32, 30);
  
  coords[0] = x+17;
  coords[1] = y+48;
  
  myGLCD.setColor(color);
  geo.fillTriangle(coords[0]+12+18*cos(rad(145)), coords[1]-12+18*sin(rad(145)), 
                   coords[0]+12+18*cos(rad(320)), coords[1]-12+18*sin(rad(320)), 
                   coords[0]+8+18*cos(rad(320)), coords[1]-8+18*sin(rad(320)));
  geo.fillTriangle(coords[0]+12+18*cos(rad(145)), coords[1]-12+18*sin(rad(145)), 
                   coords[0]+12+18*cos(rad(320)), coords[1]-12+18*sin(rad(320)), 
                   coords[0]+16+18*cos(rad(145)), coords[1]-16+18*sin(rad(145)));
                   
  myGLCD.setColor(VGA_BLACK);
  geo.fillTriangle(coords[0]+16+8*cos(rad(135)), coords[1]-16+8*sin(rad(135)), 
                   coords[0]+16+8*cos(rad(320)), coords[1]-16+8*sin(rad(320)), 
                   coords[0]+4+8*cos(rad(320)), coords[1]-4+8*sin(rad(320)));
  geo.fillTriangle(coords[0]+16+8*cos(rad(135)), coords[1]-16+8*sin(rad(135)), 
                   coords[0]+4+8*cos(rad(320)), coords[1]-4+8*sin(rad(320)), 
                   coords[0]+4+8*cos(rad(135)), coords[1]-4+8*sin(rad(135)));
                   
  myGLCD.setColor(color);
  geo.fillTriangle(coords[0]+16+4*cos(rad(135)), coords[1]-16+4*sin(rad(135)), 
                   coords[0]+16+4*cos(rad(320)), coords[1]-16+4*sin(rad(320)), 
                   coords[0]+4+4*cos(rad(320)), coords[1]-4+4*sin(rad(320)));
  geo.fillTriangle(coords[0]+16+4*cos(rad(135)), coords[1]-16+4*sin(rad(135)), 
                   coords[0]+4+4*cos(rad(320)), coords[1]-4+4*sin(rad(320)), 
                   coords[0]+4+4*cos(rad(135)), coords[1]-4+4*sin(rad(135)));
                   
  myGLCD.setColor(VGA_BLACK);
  myGLCD.fillCircle(coords[0]+2, coords[1]-2, 12);
  myGLCD.setColor(color);
  myGLCD.fillCircle(coords[0]+2, coords[1]-2, 7);
  
  myGLCD.setColor(VGA_BLACK);
  for(int i = 0; i < 10; i++){
    myGLCD.drawLine(coords[0]+2+10*cos(rad(135)), coords[1]-2+i+10*sin(rad(135)), coords[0]+2+10*cos(rad(315)), coords[1]-2+i+10*sin(rad(315)));
  }
  
  myGLCD.setColor(color);
  myGLCD.setBackColor(VGA_TRANSPARENT);
  myGLCD.setFont(europebold);
  if(sats > 0)
    myGLCD.printNumI(sats, coords[0]+16, coords[1]-36, 0);
  else
    myGLCD.print(satsInView.value(), coords[0]+2, coords[1]-38, 0);
}


void drawAlert(int alert, int type){
  
  if(type == 1) {
    color = VGA_YELLOW;
    label = "CHECKING"; }
  else {
    color = VGA_RED;
    label = "WARNING!"; }
    
  myGLCD.setColor(VGA_WHITE);
  myGLCD.fillRect(0, 27, size_x, 31);
  myGLCD.fillRect(0, 282, size_x, 286);
  myGLCD.setColor(color);
  myGLCD.fillRect(0, 32, size_x, 281);
  
  switch(alert){
    //Battery
    case 1:    
      myGLCD.setColor(VGA_WHITE);
      myGLCD.fillRect(size_x*1/5, size_y/2-70, size_x*4/5, size_y/2+30);
      myGLCD.fillRect(size_x/2-50, size_y/2-80, size_x/2-30, size_y/2-70); 
      myGLCD.fillRect(size_x/2+30, size_y/2-80, size_x/2+50, size_y/2-70);  
      myGLCD.setColor(color);
      myGLCD.fillRect(size_x*1/5+7, size_y/2-63, size_x*4/5-7, size_y/2+23); 
      myGLCD.setColor(VGA_WHITE); 
      myGLCD.fillRect(size_x/2-50, size_y/2-40, size_x/2-30, size_y/2-45); 
      myGLCD.fillRect(size_x/2+30, size_y/2-40, size_x/2+50, size_y/2-45);  
      myGLCD.fillRect(size_x/2+37, size_y/2-33, size_x/2+43, size_y/2-53);  
      
      myGLCD.setFont(europebold);  
      myGLCD.setColor(VGA_WHITE); 
      myGLCD.setBackColor(color);  
      myGLCD.print(label, size_x/2*1/2, size_y*3/4-10);
      break;
     
    //Brakes 
    case 2:      
      myGLCD.setColor(VGA_WHITE);
      myGLCD.fillCircle(size_x*1/3+15, size_y/2-30, 60);
      myGLCD.setColor(color);
      myGLCD.fillCircle(size_x*1/3+15, size_y/2-30, 50);
      myGLCD.setColor(VGA_WHITE);
      myGLCD.fillCircle(size_x*1/3+15, size_y/2-30, 40);
      myGLCD.setColor(color);
      myGLCD.fillCircle(size_x*1/3+15, size_y/2-30, 35);
      myGLCD.setColor(VGA_WHITE);
      myGLCD.fillCircle(size_x*1/3+15, size_y/2-30, 20);
      myGLCD.setColor(color);
      myGLCD.fillCircle(size_x*1/3+15, size_y/2-30, 17);      
      myGLCD.setColor(VGA_WHITE);
      myGLCD.fillCircle(size_x*1/3+15, size_y/2-30, 5);
      for(int i = 0; i < 5; i++){
        myGLCD.fillCircle(size_x*1/3+15 + 11*cos((-PI/2)+i*(1.2566)), size_y/2-29 + 11*sin((-PI/2)+i*(1.2566)), 2);
      }
      
      geo.fillTriangle(size_x*2/3-15, size_y/2+16, size_x*2/3+30, size_y/2-8, size_x*2/3+35, size_y/2-15);
      geo.fillTriangle(size_x*2/3-10, size_y/2+19, size_x*2/3+35, size_y/2+10, size_x*2/3+40, size_y/2+5);
      geo.fillTriangle(size_x*2/3-30, size_y/2+25, size_x*2/3+34, size_y/2+26, size_x*2/3+30, size_y/2+29);
      
      myGLCD.setFont(europebold);  
      myGLCD.setColor(VGA_WHITE); 
      myGLCD.setBackColor(color); 
      myGLCD.print(label, size_x/2*1/2, size_y*3/4-10);
      break;
     
    //Fuel  
    case 3:      
      myGLCD.setColor(VGA_WHITE);      
      myGLCD.fillCircle(size_x/2+34-15, size_y/2-35, 15);
      myGLCD.fillCircle(size_x/2+55-15, size_y/2, 15);
      myGLCD.setColor(color);
      myGLCD.fillCircle(size_x/2+34-15, size_y/2-35, 7); 
      myGLCD.fillRect(size_x/2+25-15, size_y/2-35, size_x/2+45-15, size_y/2-20);  
      myGLCD.fillCircle(size_x/2+55-15, size_y/2, 7);
      myGLCD.fillRect(size_x/2+40-15, size_y/2, size_x/2+70-15, size_y/2-20);    

      myGLCD.setColor(VGA_WHITE); 
      myGLCD.fillRect(size_x/2+41-15, size_y/2-35, size_x/2+48-15, size_y/2);
      myGLCD.fillRect(size_x/2+62-15, size_y/2-35, size_x/2+69-15, size_y/2);
      
      geo.fillTriangle(size_x/2+62-15, size_y/2-35, size_x/2+69-15, size_y/2-35, size_x/2+74-15, size_y/2-50);
      geo.fillTriangle(size_x/2+62-15, size_y/2-35, size_x/2+74-15, size_y/2-50, size_x/2+66-15, size_y/2-50);
      geo.fillTriangle(size_x/2+74-15, size_y/2-50, size_x/2+66-15, size_y/2-50, size_x/2+74-15, size_y/2-65);
      geo.fillTriangle(size_x/2+74-15, size_y/2-57, size_x/2+74-15, size_y/2-65, size_x/2+90-15, size_y/2-70);
      geo.fillTriangle(size_x/2+74-15, size_y/2-59, size_x/2+91-15, size_y/2-68, size_x/2+90-15, size_y/2-70);

      myGLCD.fillRect(size_x/2-30-15, size_y/2-100, size_x/2+30-15, size_y/2+30);
      myGLCD.fillRect(size_x/2-45-15, size_y/2+20, size_x/2+45-15, size_y/2+30);
      
      myGLCD.fillRect(size_x/2+25-15, size_y/2-41, size_x/2+35-15, size_y/2-49);
      
      myGLCD.setColor(color);
      myGLCD.fillRect(size_x/2-25-15, size_y/2-95, size_x/2+25-15, size_y/2-50);
      
      myGLCD.setFont(europebold);  
      myGLCD.setColor(VGA_WHITE); 
      myGLCD.setBackColor(color); 
      myGLCD.print(label, size_x/2*1/2, size_y*3/4-10);
      break;
      
    //Tachometer  
    case 4:    
      myGLCD.setColor(VGA_WHITE);
      myGLCD.fillCircle(size_x/2, size_y/2-30, 80);
      myGLCD.setColor(color);
      myGLCD.fillCircle(size_x/2, size_y/2-30, 73);
      geo.fillTriangle(size_x/2, size_y/2, size_x/2-60, size_y/2+60, size_x/2+60, size_y/2+60);
      
      myGLCD.setColor(VGA_WHITE);      
      for(int i = 0; i < 12; i++){
        if(i != 9)
        myGLCD.drawLine(size_x/2 + 75*cos(i*rad(30)), size_y/2-30 + 75*sin(i*rad(30)), 
                        size_x/2 + 50*cos(i*rad(30)), size_y/2-30 + 50*sin(i*rad(30)));
      }
      
      geo.fillTriangle(size_x/2 + 60*cos(rad(137)), size_y/2-30 + 60*sin(rad(137)), 
                       size_x/2 + 10*cos(rad(137+20)), size_y/2-30 + 10*sin(rad(137+20)), 
                       size_x/2 + 10*cos(rad(137-20)), size_y/2-30 + 10*sin(rad(137-20)));
                       
      myGLCD.setColor(color); 
      myGLCD.fillCircle(size_x/2, size_y/2-30, 13);                       
      myGLCD.setColor(VGA_WHITE); 
      myGLCD.fillCircle(size_x/2, size_y/2-30, 10);
          
      myGLCD.setFont(europebold);  
      myGLCD.setColor(VGA_WHITE); 
      myGLCD.setBackColor(color); 
      myGLCD.print(label, size_x/2*1/2, size_y*3/4-10);
      break;
      
    //Temperature 
    case 5:                      
      myGLCD.setColor(VGA_WHITE); 
          
      for(int i = 0; i < 160; i++){
        myGLCD.fillCircle(size_x/2-80+i, size_y/2+7*(-cos(rad(i)*6.8)), 2);
        myGLCD.fillCircle((size_x+i)*4/5-135, size_y/2+30+6*(-cos(rad(i)*6.8)), 2);
      }
            
      myGLCD.setColor(color);      
      myGLCD.fillCircle(size_x/2, size_y/2, 18); 
      myGLCD.setColor(VGA_WHITE);
      myGLCD.fillCircle(size_x/2, size_y/2, 15);
      myGLCD.fillRect(size_x/2-3, size_y/2, size_x/2+3, size_y/2-90);
      myGLCD.fillCircle(size_x/2, size_y/2-90, 3);
      
      myGLCD.fillRect(size_x/2, size_y/2-80, size_x/2+20, size_y/2-76);
      myGLCD.fillCircle(size_x/2+20, size_y/2-78, 2);
      myGLCD.fillRect(size_x/2, size_y/2-70, size_x/2+20, size_y/2-66);
      myGLCD.fillCircle(size_x/2+20, size_y/2-68, 2);
      myGLCD.fillRect(size_x/2, size_y/2-60, size_x/2+20, size_y/2-56);
      myGLCD.fillCircle(size_x/2+20, size_y/2-58, 2);
      
      myGLCD.setFont(europebold);  
      myGLCD.setColor(VGA_WHITE); 
      myGLCD.setBackColor(color); 
      myGLCD.print(label, size_x/2*1/2, size_y*3/4-10);
      break;
      
    //Oil
    case 6:                      
      myGLCD.setColor(VGA_WHITE);       
      myGLCD.fillRect(size_x/2-40-15, size_y/2-40, size_x/2+20-15, size_y/2+10);
      geo.fillTriangle(size_x/2+20-15, size_y/2-40, size_x/2+20-15, size_y/2+10, size_x/2+30-15, size_y/2+10);
      geo.fillTriangle(size_x/2-30-15, size_y/2+10, size_x/2+30-15, size_y/2+10, size_x/2+70-15, size_y/2-50);
      
      geo.fillTriangle(size_x/2+70-15, size_y/2-50, size_x/2+64-15, size_y/2-42, size_x/2+82-15, size_y/2-45);
      geo.fillTriangle(size_x/2+64-15, size_y/2-42, size_x/2+82-15, size_y/2-45, size_x/2+78-15, size_y/2-40);
      
      myGLCD.fillRect(size_x/2-25-15, size_y/2-55, size_x/2+5-15, size_y/2-50);
      myGLCD.fillRect(size_x/2-15-15, size_y/2-55, size_x/2-5-15, size_y/2-40);
      
      geo.fillTriangle(size_x/2-40-15, size_y/2-42, size_x/2-65-15, size_y/2-55, size_x/2-70-15, size_y/2-40);
      geo.fillTriangle(size_x/2-40-15, size_y/2-42, size_x/2-40-15, size_y/2-23, size_x/2-70-15, size_y/2-40);
      
      myGLCD.fillCircle(size_x/2+60, size_y/2-10, 6);
      geo.fillTriangle(size_x/2+54, size_y/2-10, size_x/2+66, size_y/2-10, size_x/2+60, size_y/2-24);
      
      myGLCD.setColor(color);       
      myGLCD.fillRect(size_x/2-36-15, size_y/2-36, size_x/2+18-15, size_y/2+6);
      
      geo.fillTriangle(size_x/2+18-15, size_y/2-36, size_x/2+18-15, size_y/2+6, size_x/2+26-15, size_y/2+6);
      geo.fillTriangle(size_x/2-16-15, size_y/2+6, size_x/2+28-15, size_y/2+6, size_x/2+62-15, size_y/2-42);
      
      geo.fillTriangle(size_x/2-46-15, size_y/2-42, size_x/2-63-15, size_y/2-51, size_x/2-66-15, size_y/2-41);
      geo.fillTriangle(size_x/2-46-15, size_y/2-42, size_x/2-46-15, size_y/2-29, size_x/2-66-15, size_y/2-41);
      
      myGLCD.setFont(europebold);  
      myGLCD.setColor(VGA_WHITE); 
      myGLCD.setBackColor(color); 
      myGLCD.print(label, size_x/2*1/2, size_y*3/4-10);
      break;      
      
    //Wiper fluid
    case 7:      
      myGLCD.setColor(VGA_WHITE);
      myGLCD.fillRect(size_x/2-60, size_y/2-70, size_x/2+60, size_y/2+40);
      myGLCD.fillRect(size_x/2-60, size_y/2-60, size_x/2-70, size_y/2-45);
      myGLCD.fillRect(size_x/2+35, size_y/2-70, size_x/2+50, size_y/2-80);
      myGLCD.fillRect(size_x/2+30, size_y/2-80, size_x/2+55, size_y/2-85);
      
      myGLCD.setColor(color);
      myGLCD.fillRect(size_x/2-55, size_y/2-65, size_x/2+55, size_y/2+35);
      myGLCD.fillRect(size_x/2-55, size_y/2-55, size_x/2-70, size_y/2-50);
      myGLCD.fillRect(size_x/2+40, size_y/2-65, size_x/2+45, size_y/2-80);
      
      myGLCD.setColor(VGA_WHITE);
      for(int i = 0; i < 111; i++){
        myGLCD.drawLine(size_x/2-55+i, size_y/2+40, size_x/2-55+i, size_y/2+5+7*(-cos(rad(i)*5.5)));
      }
      
      myGLCD.setFont(europebold);  
      myGLCD.setColor(VGA_WHITE); 
      myGLCD.setBackColor(color); 
      myGLCD.print(label, size_x/2*1/2, size_y*3/4-10);
      break;    
    
    //OK
    case 8:
      myGLCD.setColor(VGA_WHITE);
      myGLCD.fillRect(0, 27, size_x, 31);
      myGLCD.fillRect(0, 282, size_x, 286);
      myGLCD.setColor(VGA_GREEN);
      myGLCD.fillRect(0, 32, size_x, 281);
      
      myGLCD.setColor(VGA_WHITE);
      myGLCD.fillCircle(size_x/2-80, size_y/2-30, 10);
      myGLCD.fillCircle(size_x/2-80, size_y/2+30, 10);
      myGLCD.fillCircle(size_x/2-15, size_y/2+30, 10);
      myGLCD.fillCircle(size_x/2-15, size_y/2-30, 10);
      
      myGLCD.fillRect(size_x/2-80, size_y/2-30, size_x/2-15, size_y/2-40);
      myGLCD.fillRect(size_x/2-80, size_y/2+30, size_x/2-15, size_y/2+40);
      myGLCD.fillRect(size_x/2-80, size_y/2+30, size_x/2-90, size_y/2-30);
      myGLCD.fillRect(size_x/2-15, size_y/2+30, size_x/2-5, size_y/2-30);
      
      myGLCD.fillRect(size_x/2+15, size_y/2+40, size_x/2+25, size_y/2-40);
      myGLCD.fillRect(size_x/2+20, size_y/2+5, size_x/2+40, size_y/2-5);
      
      geo.fillTriangle(size_x/2+25, size_y/2, size_x/2+40, size_y/2, size_x/2+90, size_y/2-40);
      geo.fillTriangle(size_x/2+25, size_y/2, size_x/2+75, size_y/2-40, size_x/2+90, size_y/2-40);
      geo.fillTriangle(size_x/2+25, size_y/2, size_x/2+40, size_y/2, size_x/2+90, size_y/2+40);
      geo.fillTriangle(size_x/2+25, size_y/2, size_x/2+75, size_y/2+40, size_x/2+90, size_y/2+40);
      
      myGLCD.setColor(VGA_GREEN);
      myGLCD.fillRoundRect(size_x/2-80, size_y/2-30, size_x/2-15, size_y/2+30);

      break;
  }
}
