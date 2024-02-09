#include <pages/gamePage.h>

GamePage *InitGamePage()
{
    GamePage *gamepage = malloc(sizeof(GamePage));
    if (gamepage == NULL) {
        puts("Fail to Init GamePage");
        exit(EXIT_FAILURE);
    }

    gamepage->frog.image = InitImage(GP_FROG_IMG, GP_FROG_HEIGHT, GP_FROG_WIDTH, GP_FROG_NAME, GP_FROG_X, GP_FROG_Y);
    gamepage->frog.speedX = 0;
    gamepage->frog.speedY = 0;

    gamepage->curFlorr = 1;
    gamepage->minFlorr = 1;
    gamepage->maxFlorr = 1;
    gamepage->florr = malloc(sizeof(Obj) * MAX_FLORR_NUM);

    gamepage->curScoreStr = malloc(sizeof(char) * MAX_SCORE_STR_LEN);
    gamepage->maxScoreStr = malloc(sizeof(char) * MAX_SCORE_STR_LEN);

    gamepage->curScore = InitText(app.font, app.fontColor, GP_CURSCORE_X, GP_CURSCORE_Y, GP_CURSCORE_FONTSIZE, GP_CURSCORE_FONTSTYLE);
    gamepage->maxScore = InitText(app.font, app.fontColor, GP_MAXSCORE_X, GP_MAXSCORE_Y, GP_MAXSCORE_FONTSIZE, GP_MAXSCORE_FONTSTYLE);
    return gamepage;
}

void DrawGamePage(App *app)
{
    app->curScene = GameScene;

    ChangeBgColor(app, app->bgColor);
    sprintf(app->gamepage->curScoreStr, "Score: %d", app->curScore);
    sprintf(app->gamepage->maxScoreStr, "MaxScore: %d", app->maxScore);
    Write(app, app->gamepage->curScore, app->gamepage->curScoreStr);
    Write(app, app->gamepage->maxScore, app->gamepage->maxScoreStr);

    for (int i = 1; i <= 3; i++) {
        InitFlorr(i);
        LoadObject(app, &(app->gamepage->florr[i]));
    }

    LoadObject(app, &(app->gamepage->frog));
}

void InitNewGame(App *app)
{
    UpdateImage(app->gamepage->frog.image, GP_FROG_IMG, GP_FROG_HEIGHT, GP_FROG_WIDTH, GP_FROG_NAME, GP_FROG_X, GP_FROG_Y);
    app->gamepage->frog.speedX = 0;
    app->gamepage->frog.speedY = 0;

    app->gamepage->curFlorr = 1;
    app->gamepage->minFlorr = 1;
    app->gamepage->maxFlorr = 1;
    free(app->gamepage->florr);
    app->gamepage->florr = malloc(sizeof(Obj) * MAX_FLORR_NUM);
    app->curScore = 0;
    DrawGamePage(app);
}

void InitFlorr(int florrID)
{
    if (florrID == 1) {
        app.gamepage->florr[florrID].image = InitImage(GP_FLOWER_IMG, GP_IMG_HEIGHT, GP_IMG_WIDTH, "Flower", GP_IMG_X_FIRST, GP_IMG_Y_FIRST);
        return;
    }

    int florrpic = RanInt(1, 1000);
    int distance = RanInt(10, 20) * 10;
    app.gamepage->maxFlorr++;
    switch (florrpic % 2) {
    case 1:
        app.gamepage->florr[florrID].image = InitImage(GP_FLOWER_IMG, GP_IMG_HEIGHT, GP_IMG_WIDTH, "Flower", (app.gamepage->florr[florrID - 1].image->x + distance * 2), (app.gamepage->florr[florrID - 1].image->y - distance));
        break;
    case 0:
        app.gamepage->florr[florrID].image = InitImage(GP_LEAF_IMG, GP_IMG_HEIGHT, GP_IMG_WIDTH, "Leaf", (app.gamepage->florr[florrID - 1].image->x + distance * 2), (app.gamepage->florr[florrID - 1].image->y - distance));
        break;
    }
}

void MoveFlorrAndFrog(App *app, int frogHopTime, int minFlorr, int maxFlorr)
{

    double vFrogY = floor(-0.5 * frogHopTime / 32);
    double vFrogDY = FROG_HOP_DY;
    double times = 4 * fabs(vFrogY) + 1;
    for (int i = 0; i < times; i++) {
        LoadBgColor(app, app->bgColor);
        for (int j = minFlorr; j <= maxFlorr; j++) {
            Move(app, &(app->gamepage->florr[j]), GP_FLORR_SPEED_X, GP_FLORR_SPEED_Y, 0, 0, 1, 0);
        }

        // move frog (only Y)
        Move(app, &(app->gamepage->frog), 0, vFrogY, 0, vFrogDY, 1, 0);
        vFrogY += vFrogDY;
        SDL_RenderPresent(app->renderer);
    }
}

void DestroyFlorr(App *app, int florrID)
{
    app->gamepage->curFlorr = florrID + 1;
}