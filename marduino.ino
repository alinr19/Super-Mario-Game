#include <SPI.h>
#include <Adafruit_GFX.h>
#include <Adafruit_PCD8544.h>
#include "marduinotypes.h"
#include "tilemap.h"
#include "mariobitmap.h"
#include "lvl.h"

Adafruit_PCD8544 display = Adafruit_PCD8544(8, 9, 10, 11, 12);
TileMap gamemap;

#define DELAY 75 
#define P_STILL 0
#define P_MOVE 1
#define P_JUMP 2
#define P_DEAD 3
#define GAME_INTRO 100
#define GAME_TITLE 101
#define GAME_CREDITS 102
#define GAME_LEVEL 103
#define GAME_PLAY 104
#define GAME_GAMEOVER 105
#define GAME_EXIT 106

unsigned int status = GAME_INTRO; 
int const imgmario1 = 16;
int const imgmario2 = 16;
long timer = 0; 
unsigned long timpul_curent = 0;
int player_status = P_STILL; 
int player_directie = 1;
int ultima_directie = 0;
long playertimer = 0;
long playertimer_prev = 0;
int viata = 5;
Vector2f position1(0,display.height()-imgmario2-8);
Vector2f position2(0,display.height()-imgmario2-8);
Vector2f ultima_position(0,display.height()-imgmario2-8);
float hspd = 0;
float hspd_speed = 2.5;
float grav = 0.6;
float jumpspd = 3.8;
float vspd = 0;
int frame = 0;
int frameMax = 3;
float frameSpd = 1;
float frameCounter = 0;
float pboxoffsetx = 3; 
int camera_player_side = 0;
boolean onAir = false;
boolean check_pulo = false;
Vector2f camera = {0,0};
Vector2f last_camera = {0,0};
boolean animInit = false;

float sign(float x) {
  if (x > 0)
    return 1;
  else if (x < 0)
    return -1;
  return 0;
};

boolean buttonPressing[] = {false,false,false}; 
boolean buttonRelease[] = {false,false,false}; 
boolean buttonPressed[] = {false,false,false}; 
boolean buttonPressedCheck[] = {false,false,false};
boolean buttonReleaseCheck[] = {false,false,false};
void inputManager(unsigned int pin0, unsigned int pin1, unsigned int pin2) {
    int p[3] = {digitalRead(pin0), digitalRead(pin1), digitalRead(pin2)};
    for (int i = 0; i <3; i++) {
        if (buttonPressed[i]) {
            buttonPressed[i] = false;
            buttonPressedCheck[i] = true;
        }
        if (buttonRelease[i]) {
            buttonRelease[i] = false;
            buttonReleaseCheck[i] = true;
        }
        if (p[i] == LOW) {
            if (!buttonPressing[i]) {
                buttonPressed[i] = true;
            }
            buttonPressing[i] = true;
            buttonRelease[i] = false;
            buttonReleaseCheck[i] = false;
        } else {
            if (buttonPressing[i]) {
                buttonRelease[i] = true;
            }
            buttonPressing[i] = false;
            buttonPressed[i] = false;
            buttonPressedCheck[i] = false;
        }
    }
}
boolean intersectionRect(float* rect1, float* rect2) {
    return (rect1[0] + rect1[2] > rect2[0] && rect1[0] < rect2[0] + rect2[2] &&
            rect1[1] + rect1[3] > rect2[1] && rect1[1] < rect2[1] + rect2[3]);
}
void playerCollisionChecker(float hs, float vs) {
    float playerRect[4] = {position1.x + pboxoffsetx + hs + camera.x, position1.y + vs, 10, 16};
    for (int i = 0; i < CollisionMap0Size * 4; i += 4) {
        float rectTest[] = {
            pgm_read_word_near(&CollisionMap0[i]),
            pgm_read_word_near(&CollisionMap0[i + 1]),
            pgm_read_word_near(&CollisionMap0[i + 2]),
            pgm_read_word_near(&CollisionMap0[i + 3])
        };
        if (!intersectionRect(playerRect, rectTest)) continue;
        if (hs != 0) {
            hspd = (int)hspd;
            position1.x = (int)position1.x;

            while (intersectionRect(playerRect, rectTest)) {
                playerRect[0] = position1.x + pboxoffsetx + camera.x + sign(hspd);
                position1.x += sign(hspd);
            }
            hspd = 0;
            break;
        }
        if (vs != 0) {
            vspd = (int)vspd;
            position1.y = (int)position1.y;
            while (intersectionRect(playerRect, rectTest)) {
                playerRect[1] = position1.y + camera.y + sign(vspd);
                position1.y += sign(vspd);
            }
            vspd = 0;
            check_pulo = false;
            break;
        }
    }
}
boolean verifyCollision(float* rect) {
    for (int i = 0; i < CollisionMap0Size * 4; i += 4) {
        float rectTest[] = {
            pgm_read_word_near(&CollisionMap0[i]),
            pgm_read_word_near(&CollisionMap0[i + 1]),
            pgm_read_word_near(&CollisionMap0[i + 2]),
            pgm_read_word_near(&CollisionMap0[i + 3])
        };
        if (intersectionRect(rect, rectTest)) return true;
    }
    return false;
}
void playerLogic(boolean move_esq, boolean move_dir, boolean jump) {
  if (player_status != P_DEAD) {  
      hspd = 0;
      boolean moving = false;    
      if (move_esq == true && move_dir == false) {
          player_directie = 1;
          moving = true;
      } else if (move_dir == true && move_esq == false) {
          player_directie = -1;
          moving = true;
      }      
      if (moving)
          hspd = hspd_speed * (float)player_directie;   
      playerCollisionChecker(hspd,0);     
      position2.x += hspd;      
       if (camera_player_side == -1) {
          if (position1.x > (display.width()/2)-10)
            camera_player_side = 0;
          else
            position1.x += hspd;   
          if (position1.x < 0) {
            position1.x = 0;
            hspd = 0;
          }     
       } else if (camera_player_side == 1) {
          if (position1.x < (display.width()/2)-10)
            camera_player_side = 0;
          else
            position1.x += hspd;           
          if (position1.x > display.width()) {
            status= GAME_TITLE;
          }
        }       
        if (camera_player_side == 0) {
          if (camera.x >= 0 && camera.x <= gamemap.getMapWidth()*8-display.width()) {
            camera.x += hspd;
          } if (camera.x > gamemap.getMapWidth()*8-display.width()) {
            camera_player_side = 1;
            camera.x = gamemap.getMapWidth()*8-display.width();
            position1.x += hspd;
          } if (camera.x < 0) {
            camera_player_side = -1;
            position1.x += hspd; 
            camera.x = 0;  
          }
        }  
     float playerRect[4] = { camera.x+position1.x+pboxoffsetx,camera.y+position1.y+1, 10, 16 };    
      if (!verifyCollision(playerRect)) {
        vspd += grav;
        check_pulo = true;
        onAir = true;
      } else {
        onAir = false;
      }
      if (vspd != 0) {
          playerCollisionChecker(0,vspd);
      }   
      if (jump == true && check_pulo == false) {
        vspd -= jumpspd;
        check_pulo = true;  
      }
      position1.y += vspd;
      position2.y += vspd; 
      if (vspd == 0 && !onAir) {
          ultima_directie = player_directie;
          last_camera.x = camera.x;
          last_camera.y = position2.y;
          ultima_position.x = position1.x;
          ultima_position.y = position1.y;
      }     
      if (position1.y+camera.y > gamemap.getMapHeight()*gamemap.getTileHeight()) {
          if (player_status != P_DEAD)
              player_status = P_DEAD;
      }
    if (player_status != P_DEAD) {
       if (hspd == 0 && vspd == 0) {
        if (player_status != P_STILL) {
          player_status = P_STILL;
          animInit = true;
        }
      } else  if (hspd != 0 && vspd == 0) {
         if (player_status != P_MOVE) {
          player_status = P_MOVE;
          animInit = true;
        }
      } 
      if (vspd != 0) {
        if (player_status != P_JUMP) {
          player_status = P_JUMP;
          animInit = true;
         }   
      }
     }
  } else { 
   playertimer++; 
    if (playertimer > 1000/75) {  
          playertimer = 0;
          viata--;       
          if (viata > 0) {  
            position1.x = (int)((ultima_position.x/8)*8);/*+(8*-ultima_directie);*/
            position1.y = (int)((ultima_position.y/8)*8);
            position2.x = position1.x;
            camera.x = (int)((last_camera.x/8)*8);
            camera.y = 0;
            player_status = P_STILL;
            vspd = 0;
            hspd = 0;
            check_pulo = false;
        } else {
          status = GAME_GAMEOVER;
        }
   }
  }  
}
void playerDraw() {
  const unsigned char * frameAtual;
  if (animInit) {  
    frame = 0;
    frameCounter = 0;     
    if (player_status == P_STILL || player_status == P_JUMP) {
      frameSpd = 0.;
      frameMax = 1; 
    } else if (player_status == P_MOVE) {
      frameSpd = 0.8;
      frameMax = 4;
    }
     animInit = false;
  }
  if (frameMax > 1) {
    frameCounter += frameSpd*DELAY;  
    if (frameCounter > DELAY) {
      frame++;
      frameCounter = 0;
      if (frame > frameMax-1) {
        frame = 0;
      }
    }
  }
  if (player_status == P_STILL) {
   if (player_directie == 1) 
    frameAtual = frameMario0;
   else
    frameAtual = frameMario4;
  } else if (player_status == P_JUMP) {
    if (player_directie == 1) 
      frameAtual = frameMario3;
    else
      frameAtual = frameMario7;
  } else if (player_status == P_MOVE) {
  
    if (player_directie == 1) {
      switch (frame) {
        case 0: frameAtual = frameMario1; break;
        case 1: frameAtual = frameMario0; break;
        case 2: frameAtual = frameMario2; break;
        case 3: frameAtual = frameMario0; break;
      }
    } else {
      switch (frame) {
        case 0: frameAtual = frameMario5; break;
        case 1: frameAtual = frameMario4; break;
        case 2: frameAtual = frameMario6; break;
        case 3: frameAtual = frameMario4; break;
      }
    }
  }
  display.drawBitmap(position1.x, position1.y, frameAtual, imgmario1,imgmario2,1);
}

void drawGui() {
    display.setTextSize(1.1);
    display.setCursor(0, 0);
     display.setTextColor(BLACK, WHITE);
    display.print("x" + String(viata));
}
void sceneIntro() {
  display.clearDisplay(); 
  float sizex = 12*6;
  display.setTextSize(1);
  display.setTextColor(BLACK);
  display.setCursor((display.width()-sizex)/2,display.height()/2-10);
  display.print("Proiect-Mario");
  sizex = 6*5;
  display.display();
  timpul_curent  = millis();
   if (timpul_curent-timer>2500) { 
        timer = timpul_curent ;
        display.clearDisplay();
        status = GAME_TITLE;
   }
}
void sceneTitle() {
    int select = 0;
    const int selectMax = 2; 
    int triggerSelect = 0;
    int counter = 0;
    int counterMax = 0;
    while (status == GAME_TITLE) {
        if (millis() - timer > DELAY) {
            timer = millis();
            inputManager(5, 6, 7); 
            if (triggerSelect == 0) {
                select += (buttonPressed[2]) - (buttonPressed[0]); 
                select = (select + selectMax) % selectMax; 
                if (buttonPressed[1]) { 
                    triggerSelect = 1;
                    counterMax = 3;
                }
            }
            const char *menuText[] = {"< Start >", "< Exit >"};
            display.clearDisplay();
            display.drawBitmap(0, 0, gameLogo, 84, 24, 1);
            display.setTextSize(1);
            display.setTextColor(triggerSelect ? WHITE : BLACK, triggerSelect ? BLACK : WHITE);
            display.setCursor((display.width() - strlen(menuText[select]) * 6) / 2, 32);
            display.print(menuText[select]);
            display.display();

            if (triggerSelect && ++counter > counterMax) {
                counter = 0;
                triggerSelect++;
            }

            if (triggerSelect == 3) {
                if (select == 0) { 
                    status = GAME_LEVEL;
                } else if (select == 1) { 
                    status = GAME_EXIT;
                }
            }
        }
    }
}
void sceneLevel() {
    while (status == GAME_LEVEL) {
        display.clearDisplay();
        display.fillRect(0, 0, display.width(), display.height(), BLACK);
        display.setTextSize(1);
        display.setTextColor(WHITE, BLACK);
        display.setCursor((display.width() - 6) / 2, (display.height() / 2) - 3);
        display.print("LEVEL 1");
        display.display();
        if (millis() - timer > 2250) {
            timer = millis();
            status = GAME_PLAY;
        }
    }
}
void sceneGameOver() {
  float sizex = 9*6;
  while (status == GAME_GAMEOVER) {
         display.clearDisplay();
          display.fillRect(0, 0, display.width(), display.height(), BLACK);
          display.setTextSize(1);
          display.setTextColor(WHITE,BLACK);
          display.setCursor((display.width()-sizex)/2,(display.height()/2)-3);
          display.print("GAME OVER");
         display.display();    
   timpul_curent  = millis();
      if (timpul_curent  - timer > 3000) {   
        timer = timpul_curent ;
        status = GAME_TITLE;
      }        
  }
}
void resetGame() {
  player_status = P_STILL; 
  viata = 3;
  player_directie = 1;
  position1.x = 0;
  position1.y = display.height()-imgmario2-8;
  vspd = 0;
  hspd = 0;
  camera.x = 0;
  camera.y = 0;
  camera_player_side = -1;
  check_pulo = false;
}
void sceneGame() {
  resetGame();
  while (status == GAME_PLAY) {
    timpul_curent  = millis();  
      if(timpul_curent  - timer > DELAY) { 
      
        timer = timpul_curent ;     
        inputManager(5,6,7);       
        if (buttonPressing[2] && buttonPressing[1] && buttonPressing[0]) 
            status = GAME_TITLE; 
        playerLogic(buttonPressing[2],buttonPressing[0],buttonPressed[1]); 
        display.clearDisplay();        
        gamemap.drawMap(camera.x,camera.y);
        playerDraw();
        drawGui();     
        display.display();
    }
  }
}
void setup()   {
  Serial.begin(9600);
  display.begin();
  display.setContrast(50);
  pinMode(7, INPUT);
  digitalWrite(7, HIGH);
  pinMode(6, INPUT);
  digitalWrite(6, HIGH);
  pinMode(5, INPUT);
  digitalWrite(5, HIGH);
  gamemap.setMapSize(100,6);
  gamemap.setDisplayPointer(&display);
  gamemap.setTileMap(TileMap0);
};
void loop() {
   switch (status) { 
    case GAME_INTRO: {sceneIntro(); break;}
    case GAME_TITLE: {sceneTitle(); break;}
    case GAME_LEVEL: {sceneLevel(); break;}
    case GAME_PLAY: {sceneGame(); break;}
    case GAME_GAMEOVER: {sceneGameOver(); break;}
  } 
}


