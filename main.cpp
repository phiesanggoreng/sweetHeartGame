#include <sl.h>
#include <iostream>
#include <Windows.h>
#include <vector>
#include <random>

using namespace std;


struct Cloud
{
    double posX;
    double posY;
    double radius;
};

struct Background
{
    double posX1;  // initial background position
    double posX2;  // second background position
    double posY;
};

struct Ground
{
    double posX;
    double posY;
};

struct Player
{
    double posX;
    double posY;
    double velocityY;
    double gravity;
    double isJumping;
};

// sound asset
void backGroundSound()
{
    int bgm = slLoadWAV("D:\\sweetheart\\asset\\bgm\\rafiq.wav");
    slSoundLoop(bgm);
}


int main()
{
    slWindow(1714, 952, "sweetheart", false);
    backGroundSound();

    // untuk memunculkan secara random
   random_device rd;

    // vector to store image IDs
    vector<int> imgAll(3);
    imgAll[0] = slLoadTexture("D:\\sweetheart\\asset\\bg\\backgp.png");
    imgAll[1] = slLoadTexture("D:\\sweetheart\\asset\\bg\\ground.png");
    imgAll[2] = slLoadTexture("D:\\sweetheart\\asset\\bg\\cloud.png");

    // player
    // kiri
    vector<int> leftPlayer = {
        slLoadTexture("D:\\sweetheart\\asset\\caracter\\run\\left\\run1.1.png"),
        slLoadTexture("D:\\sweetheart\\asset\\caracter\\run\\left\\run2.2.png"),
        slLoadTexture("D:\\sweetheart\\asset\\caracter\\run\\left\\run3.3.png"),
        slLoadTexture("D:\\sweetheart\\asset\\caracter\\run\\left\\run4.4.png"),
        slLoadTexture("D:\\sweetheart\\asset\\caracter\\run\\left\\run5.5.png"),
        slLoadTexture("D:\\sweetheart\\asset\\caracter\\run\\left\\run6.6.png"),
        slLoadTexture("D:\\sweetheart\\asset\\caracter\\run\\left\\run7.7.png"),
        slLoadTexture("D:\\sweetheart\\asset\\caracter\\run\\left\\run8.8.png")
    };
    // kanan
    vector<int> rightPlayer = {
        slLoadTexture("D:\\sweetheart\\asset\\caracter\\run\\right\\run1.png"),
        slLoadTexture("D:\\sweetheart\\asset\\caracter\\run\\right\\run2.png"),
        slLoadTexture("D:\\sweetheart\\asset\\caracter\\run\\right\\run3.png"),
        slLoadTexture("D:\\sweetheart\\asset\\caracter\\run\\right\\run4.png"),
        slLoadTexture("D:\\sweetheart\\asset\\caracter\\run\\right\\run5.png"),
        slLoadTexture("D:\\sweetheart\\asset\\caracter\\run\\right\\run6.png"),
        slLoadTexture("D:\\sweetheart\\asset\\caracter\\run\\right\\run7.png"),
        slLoadTexture("D:\\sweetheart\\asset\\caracter\\run\\right\\run8.png")
    };

    //diam Kanan
    vector<int> diamKananPlayer = {
        slLoadTexture("D:\\sweetheart\\asset\\caracter\\idle\\idle0.png"),
        slLoadTexture("D:\\sweetheart\\asset\\caracter\\idle\\idle1.png"),
        slLoadTexture("D:\\sweetheart\\asset\\caracter\\idle\\idle2.png"),
        slLoadTexture("D:\\sweetheart\\asset\\caracter\\idle\\idle3.png"),
        slLoadTexture("D:\\sweetheart\\asset\\caracter\\idle\\idle4.png"),
        slLoadTexture("D:\\sweetheart\\asset\\caracter\\idle\\idle5.png")
    };

    //Diam Kiri
    vector<int> diamKiriPlayer = {
        slLoadTexture("D:\\sweetheart\\asset\\caracter\\idle\\right\\idle0.png"),
        slLoadTexture("D:\\sweetheart\\asset\\caracter\\idle\\right\\idle1.png"),
        slLoadTexture("D:\\sweetheart\\asset\\caracter\\idle\\right\\idle2.png"),
        slLoadTexture("D:\\sweetheart\\asset\\caracter\\idle\\right\\idle3.png"),
        slLoadTexture("D:\\sweetheart\\asset\\caracter\\idle\\right\\idle4.png"),
        slLoadTexture("D:\\sweetheart\\asset\\caracter\\idle\\right\\idle5.png")
    };

    //Mati kanan
    vector<int> matikanan = {
        slLoadTexture("D:\\sweetheart\\asset\\caracter\\ded\\ded1.png"),
        slLoadTexture("D:\\sweetheart\\asset\\caracter\\ded\\ded2.png"),
        slLoadTexture("D:\\sweetheart\\asset\\caracter\\ded\\ded3.png"),
        slLoadTexture("D:\\sweetheart\\asset\\caracter\\ded\\ded4.png")////
    };

    //Mati Kiri
    vector<int> matikiri = {
        slLoadTexture("D:\\sweetheart\\asset\\caracter\\ded\\dedright\\ded1.png"),
        slLoadTexture("D:\\sweetheart\\asset\\caracter\\ded\\dedright\\ded2.png"),
        slLoadTexture("D:\\sweetheart\\asset\\caracter\\ded\\dedright\\ded3.png"),
        slLoadTexture("D:\\sweetheart\\asset\\caracter\\ded\\dedright\\ded4.png")////
    };

    //Mennyerang 1 Kanan
    vector<int> attackkanan = {
        slLoadTexture("D:\\sweetheart\\asset\\caracter\\attack\\attack1.png"),
        slLoadTexture("D:\\sweetheart\\asset\\caracter\\attack\\attack2.png"),
        slLoadTexture("D:\\sweetheart\\asset\\caracter\\attack\\attack3.png"),
        slLoadTexture("D:\\sweetheart\\asset\\caracter\\attack\\attack4.png"),
        slLoadTexture("D:\\sweetheart\\asset\\caracter\\attack\\attack5.png"),
        slLoadTexture("D:\\sweetheart\\asset\\caracter\\attack\\attack6.png"),
        slLoadTexture("D:\\sweetheart\\asset\\caracter\\attack\\attack7.png")
    };

    //Menyerang 1 Kiri
    vector<int> attackkiri = {
       slLoadTexture("D:\\sweetheart\\asset\\caracter\\attack\\rightattack\\attack1.png"),
       slLoadTexture("D:\\sweetheart\\asset\\caracter\\attack\\rightattack\\attack2.png"),
       slLoadTexture("D:\\sweetheart\\asset\\caracter\\attack\\rightattack\\attack3.png"),
       slLoadTexture("D:\\sweetheart\\asset\\caracter\\attack\\rightattack\\attack4.png"),
       slLoadTexture("D:\\sweetheart\\asset\\caracter\\attack\\rightattack\\attack5.png"),
       slLoadTexture("D:\\sweetheart\\asset\\caracter\\attack\\rightattack\\attack6.png"),
       slLoadTexture("D:\\sweetheart\\asset\\caracter\\attack\\rightattack\\attack7.png")
    };
    vector<int> attack2kanan = {
       slLoadTexture("D:\\sweetheart\\asset\\caracter\\attack2\\attack0.png"),
       slLoadTexture("D:\\sweetheart\\asset\\caracter\\attack2\\attack1.png"),
       slLoadTexture("D:\\sweetheart\\asset\\caracter\\attack2\\attack2.png"),
       slLoadTexture("D:\\sweetheart\\asset\\caracter\\attack2\\attack3.png"),
       
    };
    vector<int> attack2kiri = {
       slLoadTexture("D:\\sweetheart\\asset\\caracter\\attack2\\right\\attack0.png"),
       slLoadTexture("D:\\sweetheart\\asset\\caracter\\attack2\\right\\attack1.png"),
       slLoadTexture("D:\\sweetheart\\asset\\caracter\\attack2\\right\\attack2.png"),
       slLoadTexture("D:\\sweetheart\\asset\\caracter\\attack2\\right\\attack3.png"),
       
    };
    

    //Lompat Kanan
    vector<int> jumpkanan = {
       slLoadTexture("D:\\sweetheart\\asset\\caracter\\jump\\jump0.png"),
       slLoadTexture("D:\\sweetheart\\asset\\caracter\\jump\\jump1.png"),
       slLoadTexture("D:\\sweetheart\\asset\\caracter\\jump\\jump2.png"),
       slLoadTexture("D:\\sweetheart\\asset\\caracter\\jump\\jump3.png"),
       slLoadTexture("D:\\sweetheart\\asset\\caracter\\jump\\jump4.png"),
       slLoadTexture("D:\\sweetheart\\asset\\caracter\\jump\\jump5.png"),
       slLoadTexture("D:\\sweetheart\\asset\\caracter\\jump\\jump6.png"),
       slLoadTexture("D:\\sweetheart\\asset\\caracter\\jump\\jump7.png"),
       slLoadTexture("D:\\sweetheart\\asset\\caracter\\jump\\jump8.png")
    };

    //Lompat Kiri
    vector<int> jumpkiri = {
       slLoadTexture("D:\\sweetheart\\asset\\caracter\\jump\\rightjump\\jump0.png"),
       slLoadTexture("D:\\sweetheart\\asset\\caracter\\jump\\rightjump\\jump1.png"),
       slLoadTexture("D:\\sweetheart\\asset\\caracter\\jump\\rightjump\\jump2.png"),
       slLoadTexture("D:\\sweetheart\\asset\\caracter\\jump\\rightjump\\jump3.png"),
       slLoadTexture("D:\\sweetheart\\asset\\caracter\\jump\\rightjump\\jump4.png"),
       slLoadTexture("D:\\sweetheart\\asset\\caracter\\jump\\rightjump\\jump5.png"),
       slLoadTexture("D:\\sweetheart\\asset\\caracter\\jump\\rightjump\\jump6.png"),
       slLoadTexture("D:\\sweetheart\\asset\\caracter\\jump\\rightjump\\jump7.png"),
       slLoadTexture("D:\\sweetheart\\asset\\caracter\\jump\\rightjump\\jump8.png")
    };
 


    Cloud awan;
    awan.posX = 856;
    awan.posY = 671;

    Background bg;
    bg.posX1 = 0;   // mulai dari kiri
    bg.posX2 = 1714; // mulai dari kanan
    bg.posY = 471;

    Ground grnd;
    grnd.posX = 856;
    grnd.posY = 80;

    Player player;
    player.posX = 50;
    player.posY = 860;
    player.velocityY = 0;
    player.gravity = -0.5; // set nilai gravitasi
    player.isJumping = false;

    // awan muncul 3
    vector<Cloud> cloud;
    for (int i = 0; i < 3; i++)
    {
        double x = awan.posX * i / 4.0 + 100 * i;
        double y = grnd.posY + 50 + static_cast<double>(rd() % 3) * 150 + 250;
        cloud.push_back({ x, y, 30 });
    }
    //jalan
    int currentFrame = 0;

    //diam 
    int currentIdleFrame = 0;
    double idleAnimationDelay = 0.2;
    //jalan
    double walkAnimationDelay = 0.2;
    //jump
    bool isJumping = false;
    int jumpFrame = 0;
    //attack
    bool isAttacking = false;
    bool isAttacking2 = false;
    int attackFrame = 0;
    double attackAnimationDelay = 0.01;
    double attackAnimationTimer = 0.0;



    while (!slShouldClose())
    {
        // gambar bacground
        slSetForeColor(1, 1, 1, 1);
        slSprite(imgAll[0], bg.posX1, bg.posY, 1714, 952);
        slSprite(imgAll[0], bg.posX2, bg.posY, 1714, 952);

        // Update background position
        bg.posX1 -= 0.5; // kecepatan latar belakang
        bg.posX2 -= 0.5;

        // Saat satu latar belakang mencapai batas layar, atur posisi untuk latar belakang kedua
        if (bg.posX1 <= -1000)
        {
            bg.posX1 = bg.posX2 + 1714;
        }

        if (bg.posX2 <= -1000)
        {
            bg.posX2 = bg.posX1 + 1714;
        }
        slSetForeColor(1, 1, 1, 1);
        slSprite(imgAll[1], grnd.posX, grnd.posY, 1714, 145);

        // gravity player
        player.velocityY += player.gravity;
        player.posY += player.velocityY;

        // collision ground
        if (player.posY < grnd.posY)
        {
            player.posY = grnd.posY;
            player.velocityY = 0;
        }
        //batasan ground jatuh
        player.posY = max(player.posY, 180);

        bool isMoving = slGetKey(SL_KEY_LEFT) || slGetKey(SL_KEY_RIGHT);
        bool isJumpKey = slGetKey(' ');

        if (isJumpKey && !player.isJumping && player.posY == 180)
        {
            //  jumping only when on the ground
            player.isJumping = true;
            player.velocityY = 10.0;
        }

        if (slGetKey('Q'))
        {
            isAttacking = true;
            attackAnimationTimer = attackAnimationDelay; 
        }else if (slGetKey('W'))
        {
            isAttacking2 = true;
            attackAnimationTimer = attackAnimationDelay;

        }

        
       
       
       
        if (player.isJumping)
        {
            // Player is jumping
            const vector<int>& jumpPlayerTextures = (slGetKey(SL_KEY_LEFT)) ? jumpkiri : jumpkanan;

            // Animate jump player
            slSprite(jumpPlayerTextures[currentFrame], player.posX, player.posY, 165, 195);

            // Update jump animation frame
            jumpFrame += 1;
            if (jumpFrame <= jumpPlayerTextures.size())
            {
                // Jump animation completed, 
                player.isJumping = false;
                jumpFrame = 0;

            }
                


        }
        else if (isAttacking)
        {
            const vector<int>& attackTextures = (slGetKey(SL_KEY_LEFT)) ? attackkiri : attackkanan;

            slSprite(attackTextures[attackFrame], player.posX, player.posY, 165, 195);

            if (attackAnimationTimer <= 0)
            {
                // Update attack animation frame
                attackFrame += 1;
                attackAnimationTimer = attackAnimationDelay * slGetDeltaTime();
                if (attackFrame >= attackTextures.size())
                {
                    isAttacking = false;
                    attackFrame = 0;
                }if (!player.isJumping && isJumpKey && player.posY == grnd.posY)
                {
                    // Player starts jumping
                    player.isJumping = true;
                    player.velocityY = 5.0;
                }
            }
            else
            {
  
                attackAnimationTimer -= slGetDeltaTime();
            }
        }
        else if (isAttacking2) {
            const vector<int>& attack2Textures = (slGetKey(SL_KEY_LEFT)) ? attack2kiri : attack2kanan;

            slSprite(attack2Textures[attackFrame], player.posX, player.posY, 165, 195);

            if (attackAnimationTimer <= 0)
            {
                // Update attack animation frame
                attackFrame += 1;
                attackAnimationTimer = attackAnimationDelay * slGetDeltaTime();
                if (attackFrame >= attack2Textures.size())
                {
                    isAttacking2 = false;
                    attackFrame = 0;
                }
            }
            else
            {
                attackAnimationTimer -= slGetDeltaTime();
            }
        }

        else if (isMoving)
        {
            // Player is moving
            if (slGetKey(SL_KEY_LEFT))
            {
                player.posX -= 7;
               
                
            }
            else if (slGetKey(SL_KEY_RIGHT))
            {
                player.posX += 7;
                
            }

            // untuk mengetahui gerak kanan atau kiri direction
            const vector<int>& playerTextures = (slGetKey(SL_KEY_LEFT)) ? leftPlayer : rightPlayer;

            // Animate the player
            slSprite(playerTextures[currentFrame], player.posX, player.posY, 165, 195);

            // Update animation frame
            walkAnimationDelay -= slGetDeltaTime();
            if (walkAnimationDelay <= 0) {

                currentFrame = (currentFrame + 1) % playerTextures.size();
                walkAnimationDelay = 0.1;
            }

        }
        
        else
        {
            // Player is idle
            const vector<int>& idlePlayerTextures = (slGetKey(SL_KEY_LEFT)) ? diamKiriPlayer : diamKananPlayer;

            // Animate idle player
            slSprite(idlePlayerTextures[currentIdleFrame], player.posX, player.posY, 165, 195);

            // Update idle animation frame dengan delay
            idleAnimationDelay -= slGetDeltaTime();
            if (idleAnimationDelay <= 0) 
            {
                currentIdleFrame = (currentIdleFrame + 1) % idlePlayerTextures.size();
                idleAnimationDelay = 0.1; //  delay
            }
        }





        // gerak awan dari kiri ke kanan
        for (Cloud& c : cloud)
        {
            c.posX -= 2;
            if (c.posX <= -100)
            {
                c.posX = 1800;
                c.posY = grnd.posY + 50 + static_cast<double>(rd() % 3) * 150 + 200;
            }

            slSetForeColor(1, 1, 1, 0.2);
            slSprite(imgAll[2], c.posX, c.posY, 860, 484);
        }

        slRender();
    }

    return 0;
}
