#include <sl.h>
#include <iostream>
#include <Windows.h>
#include <vector>
#include <random>
#include <string>


using namespace std;

struct Button {
    int x, y, width, height;
};
struct Cloud
{
    double posX;
    double posY;
    double radius;
};

struct Background
{
    double posX1;
    double posX2;
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

struct Slime {
    double posX;
    double posY;
};

// sound asset
 void ingame()
{

    int bgm = slLoadWAV("D:\\sweetheart\\asset\\bgm\\battle.wav");
    slSoundLoop(bgm);
};

enum class SlimeState
{
    Moving,
    Attacking,

};

SlimeState slimeState = SlimeState::Moving;

enum MenuState
{

    MAIN_MENU,
    PLAY_MENU,
    ABOUT_MENU
};

MenuState currentMenu = MAIN_MENU;

void judul()
{
    static int animationCounter = 0;
    int y = 600 + 10 * sin(animationCounter * 0.1);

    
    slText(400, y, "SWEET HEART");

    animationCounter++;

}

void displayLoadingRotate1(int x, int y, int radius, int loadingAnimationCounter, const char* loadingText)
{
    slSetForeColor(1, 1, 1, 1);

    // Draw the rotating loading circle
    slPush();
    slTranslate(x+45, y+125);
    slRotate(loadingAnimationCounter);  // Rotate based on the loading animation counter
    slSemiCircleFill(10, 10, radius, 1, 20.0);
    slPop();

    // Display loading text
    slText(x - 100, y - 10, loadingText);
}

void displayLoadingRotate2(int x, int y, int radius, int loadingAnimationCounter2, const char* loadingText)
{
    slSetForeColor(1, 1, 1, 1);

    // Draw the rotating loading circle
    slPush();
    slTranslate(x + 45, y + 125);
    slRotate(loadingAnimationCounter2);  // Rotate based on the loading animation counter
    slSemiCircleFill(10, 10, radius, 1, 30.0);
    slPop();

    // Display loading text
    slText(x - 100, y - 10, loadingText);
}

void displayLoadingRotate3(int x, int y, int radius, int loadingAnimationCounter3, const char* loadingText)
{
    slSetForeColor(1, 1, 1, 1);

    // Draw the rotating loading circle
    slPush();
    slTranslate(x + 45, y + 125);
    slRotate(loadingAnimationCounter3);  // Rotate based on the loading animation counter
    slSemiCircleFill(10, 10, radius, 1, 50.0);
    slPop();

    // Display loading text
    slText(x - 100, y - 10, loadingText);
}

void displayMenu()
{
    //letak tulisan


 
    slText(580, 480, "PLAY");
    slText(580, 380, "CREDIT");
    slText(580, 280, "EXIT");

}

//tampilan credits
void animateText()
{
    static int animationCounter = 0;
    int y = 380 + 10 *
        sin(animationCounter * 0.1);

   
    slText(550, 430 + 10 *
        sin(animationCounter * 0.1), "Danni");
    slText(550, 530 + 10 *
        sin(animationCounter * 0.1), "Rafiq");
    slText(550, 630 + 10 *
        sin(animationCounter * 0.1), "Radinal");
    slText(550, 330 + 10 *
        sin(animationCounter * 0.1), "Nibras");

    slText(430, 180, "press Q to menu");


    animationCounter++;


}

int getUserInput(const Button& playButton, const Button& aboutButton, const Button& exitButton) {
    int choice = 0;

    if (currentMenu == MAIN_MENU && slGetMouseButton(SL_MOUSE_BUTTON_1))
    {
        int mouseX = slGetMouseX();
        int mouseY = slGetMouseY();

        if (mouseX > playButton.x && mouseX < playButton.x + playButton.width &&
            mouseY > playButton.y && mouseY < playButton.y + playButton.height) {
            choice = 1;
        }
        else if (mouseX > aboutButton.x && mouseX < aboutButton.x + aboutButton.width &&
            mouseY > aboutButton.y && mouseY < aboutButton.y + aboutButton.height) {
            choice = 2;
        }
        else if (mouseX > exitButton.x && mouseX < exitButton.x + exitButton.width &&
            mouseY > exitButton.y && mouseY < exitButton.y + exitButton.height) {
            choice = 3;
        }

    }

    return choice;
}
bool isInGame = false;
bool isInCredit = false;
int main()
{
    slWindow(1714, 952, "Sweetheart", false);

    int bg = slLoadTexture("D:\\sweetheart\\asset\\bg\\backgp.png");
    int cursor = slLoadTexture("D:\\sweetheart\\asset\\bg\\cursor.png");
    int font = slLoadFont("D:\\sweetheart\\asset\\font\\Minecraft.ttf");
    int lagu = slLoadWAV("D:\\sweetheart\\asset\\bgm\\boa.wav");

    //sound bg
    slSoundLoop(lagu);
    if (currentMenu == PLAY_MENU) 
    {
        // Stop the background sound and start playing ingame sound only once
        slSoundStop(lagu);
    }


    //button click areanya
    Button playButton{ 580, 480, 160, 60 };
    Button aboutButton{ 580, 380, 200, 60 };
    Button exitButton{ 580, 280, 140, 60 };
    //loading
    int loadingAnimationCounter = 120;
    int loadingAnimationCounter2 = 240;
    int loadingAnimationCounter3 = 360;
    const char* loadingText = "Loading....";


    //button about
    while (!slShouldClose() && !slGetKey(SL_KEY_ESCAPE)) {


        slSprite(bg, 860, 486, 1714, 952);

        if (currentMenu == MAIN_MENU)
        {
            isInGame = false;
            

            slSetFont(font, 100);
            judul();
            
            slSetFont(font, 70);
            displayMenu();
        }
        else if (currentMenu == ABOUT_MENU)
        {
            isInGame = false;

          
            animateText();
            if (slGetKey('Q'))
            {
                currentMenu = MAIN_MENU;
                isInCredit = false;
            }

        }

        else if (currentMenu == PLAY_MENU)
        {
            if (!isInGame) 
            {
                // Stop the background sound and start playing ingame sound only once
                slSoundStop(lagu);
                
                isInGame = true;
            }

            //loading1
            slSetFont(font, 80);
            displayLoadingRotate1(650, 400, 55, loadingAnimationCounter, loadingText);
            displayLoadingRotate2(650, 400, 55, loadingAnimationCounter2, loadingText);
            displayLoadingRotate3(650, 400, 55, loadingAnimationCounter3, loadingText);
            // Increase loading animation counter
            loadingAnimationCounter += 2;  // Adjust the increment value for the desired rotation speed
            loadingAnimationCounter2 += 2;
            loadingAnimationCounter3 += 2;
            
            if (slGetKey('Q'))
            {
                currentMenu = MAIN_MENU;
                isInGame = false;
            }
            
            


            //jeda waktu sebelum game
            if (loadingAnimationCounter > 300)
            {
                ingame();
                //add code game

                int jump = slLoadWAV("D:\\sweetheart\\asset\\bgm\\jump2.wav");
                int dead = slLoadWAV("D:\\sweetheart\\asset\\bgm\\end.wav");
                int sword1 = slLoadWAV("D:\\sweetheart\\asset\\bgm\\sword.wav");
                int sword2 = slLoadWAV("D:\\sweetheart\\asset\\bgm\\slash.wav");
                int deadfamale = slLoadWAV("D:\\sweetheart\\asset\\bgm\\deadfamale.wav");

                // untuk memunculkan secara random
                random_device rd;

                //font 

                int fontkecil = slLoadFont("D:\\sweetheart\\asset\\font\\sweetheart123.ttf");
                slSetFont(slLoadFont("D:\\sweetheart\\asset\\font\\sweetheart123.ttf"), 70);
                // vector to image bg,awan,ground
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
                    slLoadTexture("D:\\sweetheart\\asset\\caracter\\ded\\ded4.png")
                };

                //Mati Kiri
                vector<int> matikiri = {
                    slLoadTexture("D:\\sweetheart\\asset\\caracter\\ded\\dedright\\ded1.png"),
                    slLoadTexture("D:\\sweetheart\\asset\\caracter\\ded\\dedright\\ded2.png"),
                    slLoadTexture("D:\\sweetheart\\asset\\caracter\\ded\\dedright\\ded3.png"),
                    slLoadTexture("D:\\sweetheart\\asset\\caracter\\ded\\dedright\\ded4.png")
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
                //menyerang jurus ke dua kanan
                vector<int> attack2kanan = {
                   slLoadTexture("D:\\sweetheart\\asset\\caracter\\attack2\\attack0.png"),
                   slLoadTexture("D:\\sweetheart\\asset\\caracter\\attack2\\attack1.png"),
                   slLoadTexture("D:\\sweetheart\\asset\\caracter\\attack2\\attack2.png"),
                   slLoadTexture("D:\\sweetheart\\asset\\caracter\\attack2\\attack3.png"),

                };
                //menyerang jurus kedua kiri
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


                //enemy
                //enemy slime jalan
                vector<int> walkslime = {
                    slLoadTexture("D:\\sweetheart\\asset\\enemy\\walk\\slime0.png"),
                    slLoadTexture("D:\\sweetheart\\asset\\enemy\\walk\\slime1.png"),
                    slLoadTexture("D:\\sweetheart\\asset\\enemy\\walk\\slime2.png"),
                    slLoadTexture("D:\\sweetheart\\asset\\enemy\\walk\\slime3.png"),
                };

                //enemy slime dead
                vector<int> deadslime = {
                   slLoadTexture("D:\\sweetheart\\asset\\enemy\\dead\\slime0.png"),
                   slLoadTexture("D:\\sweetheart\\asset\\enemy\\dead\\slime1.png"),
                   slLoadTexture("D:\\sweetheart\\asset\\enemy\\dead\\slime2.png"),
                   slLoadTexture("D:\\sweetheart\\asset\\enemy\\dead\\slime3.png"),
                };
                //enemy slime idle
                vector<int> idleslime = {
                   slLoadTexture("D:\\sweetheart\\asset\\enemy\\idle\\slime-idle-0.png"),
                   slLoadTexture("D:\\sweetheart\\asset\\enemy\\idle\\slime-idle-1.png"),
                   slLoadTexture("D:\\sweetheart\\asset\\enemy\\idle\\slime-idle-2.png"),
                   slLoadTexture("D:\\sweetheart\\asset\\enemy\\idle\\slime-idle-3.png"),
                };
                //enmy slime attack
                vector<int> attackslime = {
                   slLoadTexture("D:\\sweetheart\\asset\\enemy\\attack\\slime-attack-0.png"),
                   slLoadTexture("D:\\sweetheart\\asset\\enemy\\attack\\slime-attack-1.png"),
                   slLoadTexture("D:\\sweetheart\\asset\\enemy\\attack\\slime-attack-2.png"),
                   slLoadTexture("D:\\sweetheart\\asset\\enemy\\attack\\slime-attack-3.png"),
                   slLoadTexture("D:\\sweetheart\\asset\\enemy\\attack\\slime-attack-4.png"),
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

                Slime slime;
                slime.posX = 1500;
                slime.posY = 180;

                // awan muncul 3
                vector<Cloud> cloud;
                for (int i = 0; i < 3; i++)
                {
                    double x = awan.posX * i / 4.0 + 100 * i;
                    double y = grnd.posY + 50 + static_cast<double>(rd() % 3) * 150 + 250;
                    cloud.push_back({ x, y, 30 });
                }

                vector<Slime> slimes;
                int numSlimes = rd() % 5 + 1;

                for (int i = 0; i < numSlimes; i++)
                {
                    double x = 1500 + i * 200;
                    double y = 200 + static_cast<double>(rd() % 3);
                    slimes.push_back({ x, y });
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
                //deead
                bool isPlayerDead = false;
                int playerDeathFrame = 0;
                double playerDeathAnimationDelay = 0.0;
                int playerLives = 3;

                //slime
                int slimeCurrentFrame = 0;
                double slimeAnimationDelay = 0.2;
                double slimeAttackTimer = 4.0;
                //deadslime
                int slimeDeathFrame = 0.2;
                double slimeDeathAnimationDelay = 0.2;
                double slimeDeathAnimationTimer = 0.0;
                //game over
                bool isGameOver = false;
                double gameOverTimer = 5.0;

                //poin
                int playerScore = 0;


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
                    player.posY = max(player.posY, 190);

                    bool isMoving = slGetKey(SL_KEY_LEFT) || slGetKey(SL_KEY_RIGHT);
                    bool isJumpKey = slGetKey(' ') || slGetKey(SL_KEY_UP);

                    if (isJumpKey && !player.isJumping && player.posY == 190)
                    {
                        //  jumping only when on the ground
                        player.isJumping = true;
                        player.velocityY = 15.0;
                    }

                    if (slGetKey('Q'))
                    {
                        isAttacking = true;
                        attackAnimationTimer = attackAnimationDelay;

                    }
                    else if (slGetKey('W'))
                    {
                        isAttacking2 = true;
                        attackAnimationTimer = attackAnimationDelay;

                    }
                    for (const Slime& s : slimes)
                    {
                        if (playerLives > 0 && !isPlayerDead && player.posX < s.posX + 83 && player.posX + 50 > s.posX &&
                            player.posY < s.posY + 98 && player.posY + 195 > s.posY)
                        {
                            playerLives--;




                            if (playerLives == 0)
                            {
                                isPlayerDead = true;

                                slSoundPlay(deadfamale);


                            }



                        }

                    }if (isPlayerDead)
                    {
                        // Display dead player animation
                        slSetForeColor(1, 1, 1, 1);
                        slSprite(matikanan[playerDeathFrame], player.posX, player.posY, 165, 195);

                        playerDeathAnimationDelay -= slGetDeltaTime();

                        if (playerDeathAnimationDelay <= 0)
                        {
                            playerDeathFrame = (playerDeathFrame + 1) % matikanan.size();
                            playerDeathAnimationDelay = 0.2;



                            if (playerLives > 0)
                            {
                                player.posX;
                                player.posY;

                                isPlayerDead = false;

                            }


                        }
                    }





                    else {
                        if (isAttacking || isAttacking2)
                        {
                            // ... (previous code)
                            double playerAttackX = player.posX + (slGetKey(SL_KEY_LEFT) ? -50 : 50);
                            double playerAttackY = player.posY;
                            // Iterate through each slime in the slimes vector
                            for (Slime& slime : slimes)
                            {
                                // Check if the player's attack position overlaps with the current slime's position
                                if (playerAttackX < slime.posX + 83 && playerAttackX + 50 > slime.posX &&
                                    playerAttackY < slime.posY + 98 && playerAttackY + 50 > slime.posY)
                                {
                                    playerScore += 10;

                                    slSetForeColor(1, 1, 1, 1);
                                    slSprite(deadslime[slimeDeathFrame], slime.posX, slime.posY, 83, 98);

                                    slimeDeathAnimationTimer -= slGetDeltaTime() * 2;
                                    if (slimeDeathAnimationTimer <= 0)
                                    {
                                        slimeDeathFrame = (slimeDeathFrame + 1) % deadslime.size();
                                        slimeDeathAnimationTimer = slimeDeathAnimationDelay;
                                    }

                                    // Move the slime off-screen
                                    slime.posX = -1000;
                                    slime.posY = -1000;

                                }


                            }
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
                                slSoundPlay(jump);

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
                                    slSoundPlay(sword1);
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
                                    slSoundPlay(sword2);
                                }
                            }
                            else
                            {
                                attackAnimationTimer -= slGetDeltaTime();
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


                    slimeAttackTimer -= slGetDeltaTime();

                    // Check if the slime should attack
                    if (slimeAttackTimer <= 0)
                    {
                        // Slime is attacking
                        slimeState = SlimeState::Attacking;
                        slimeAttackTimer = 0;
                    }

                    for (Slime& s : slimes)
                    {
                        s.posX -= 4;
                        if (slimeState == SlimeState::Moving)
                        {


                            if (s.posX <= -100)
                            {
                                s.posX = 1800;
                                s.posY = 190 + static_cast<double>(rd() % 3);
                            }


                            if (s.posX > player.posX - 50 && s.posX < player.posX + 100)
                            {

                                slSetForeColor(1, 1, 1, 1);
                                slSprite(idleslime[slimeCurrentFrame], s.posX, s.posY, 83, 98);


                                if (s.posX + 41 > player.posX - 50 && s.posX + 41 < player.posX + 150)
                                {

                                    s.posX += 3;
                                }
                            }
                            else
                            {
                                // Animate walking slime
                                slSetForeColor(1, 1, 1, 1);
                                slSprite(walkslime[slimeCurrentFrame], s.posX, s.posY, 83, 98);
                            }
                        }
                        else if (slimeState == SlimeState::Attacking)
                        {

                            if (s.posX > player.posX - 50 && s.posX < player.posX + 120)
                            {
                                // Animate slime attack
                                slSetForeColor(1, 1, 1, 1);
                                slSprite(attackslime[slimeCurrentFrame], s.posX, s.posY, 83, 98);


                                if (slimeCurrentFrame >= attackslime.size() - 1)
                                {

                                    slimeCurrentFrame = 0;
                                    slimeState = SlimeState::Moving;
                                }
                            }
                            else
                            {

                                slimeState = SlimeState::Moving;
                            }

                        }


                        // Update slime animation frame
                        slimeAnimationDelay -= slGetDeltaTime();
                        if (slimeAnimationDelay <= 0)
                        {
                            slimeCurrentFrame = (static_cast<unsigned long long>(slimeCurrentFrame) + 1) % walkslime.size();
                            slimeAnimationDelay = 0.2;
                        }
                    }
                    if (playerLives <= 0 && !isGameOver)
                    {
                        isGameOver = true;
                        gameOverTimer = 2.0;

                    }

                    if (playerLives <= 0 && !isGameOver)
                    {
                        isGameOver = true;
                        gameOverTimer = 2.0;




                    }
                    if (!isGameOver) {

                        slSetFontSize(50);
                        slSetForeColor(1, 1, 1, 1);
                        slSetTextAlign(SL_ALIGN_LEFT);
                        slText(0, 550, ("Score: " + to_string(playerScore)).c_str());

                    }
                    if (isGameOver)
                    {
                        slSetTextAlign(SL_ALIGN_CENTER);
                        slSetFontSize(70);
                        slSetForeColor(0, 0, 0, 1);
                        fontkecil;
                        slText(800, 600, "Game Over");

                        slSetTextAlign(SL_ALIGN_LEFT);
                        gameOverTimer -= slGetDeltaTime();

                        if (gameOverTimer <= 0)
                        {
                            slSetFontSize(50);
                            slSetForeColor(1, 1, 1, 1);
                            slSetTextAlign(SL_ALIGN_CENTER);
                            slText(800, 500, ("Score: " + to_string(playerScore)).c_str());
                            slSetTextAlign(SL_ALIGN_CENTER);
                            slText(800, 400, "Press ENTER key to continue...");
                            slText(800, 300, "Press Q key to quit game...");

                            if (slGetKey('Q'))
                            {
                                slClose();
                            }

                            if (slGetKey(SL_KEY_ENTER))
                            {
                                isGameOver = false;
                                playerLives = 3;
                                player.posX = 50;
                                player.posY = 860;
                                playerScore = 0;
                            }
                        }

                    }


                    slRender();
                }
                currentMenu = MAIN_MENU;
                loadingAnimationCounter = 0;
            }
        }


        slSprite(cursor, slGetMouseX(), slGetMouseY(), 40, 40);
        slRender();

        int choice = getUserInput(playButton, aboutButton, exitButton);

        if (choice == 1)
        {

            currentMenu = PLAY_MENU;
        }
        else if (choice == 2) {
            currentMenu = ABOUT_MENU;
        }
        else if (choice == 3)
        {

            slClose();
        }
    }

    slClose();
    return 0;

}
