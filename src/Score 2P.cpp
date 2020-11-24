//int score2j(int centerPointX, brick, rightPointX, brickWidth, posYBall, brickHeight, dy, speedBall, dx, posXBall, centerMiddleY, nextBrick, undefined) {
// Score de la partie
int score1 = 0;
int score2 = 0;

//Collisions si la balle tape la brique en bas
if ((centerPointX1 > brick.x) && (rightPointX1 < (brick.x + brickWidth)) && brick.visible && (posYBall1 <= (brick.y + brickHeight))) {
dy1 = -dy1 - speedBall1;
brick.visible == 0;
score1++;
}

if ((centerPointX2 > brick.x) && (rightPointX2 < (brick.x + brickWidth)) && brick.visible && (posYBall2 <= (brick.y + brickHeight))) {
dy2 = -dy2 - speedBall2;
brick.visible == 0;
score2++;
}

//Collisions côté droit de la brique
if ((posXBall1 < (brick.x + brickWidth)) && (centerMiddleY1 < (brick.y + brickHeight)) && (centerMiddleY1 > brick.y) && ((brick.visible && rightPointX1) > (brick.x + brickWidth))) {
dx1 = -dx1 - speedBall1;
brick.visible == 0;
score1++;
}

if ((posXBall2 < (brick.x + brickWidth)) && (centerMiddleY2 < (brick.y + brickHeight)) && (centerMiddleY2 > brick.y) && ((brick.visible && rightPointX2) > (brick.x + brickWidth))) {
dx2 = -dx2 - speedBall2;
brick.visible == 0;
score2++;
}

//Collision côté gauche
if ((rightPointX1 > brick.x) && (centerMiddleY1 < (brick.y + brickHeight)) && (centerMiddleY1 > brick.y) && brick.visible && (rightPointX1 < (brick.x + brickWidth))) {
dx1 = -dx1 - speedBall1;
brick.visible == 0;
score1++;
}

if ((rightPointX2 > brick.x) && (centerMiddleY2 < (brick.y + brickHeight)) && (centerMiddleY2 > brick.y) && brick.visible && (rightPointX2 < (brick.x + brickWidth))) {
dx2 = -dx2 - speedBall2;
brick.visible == 0;
score2++;
}

if endgame = 1 {
    if (score1 < score2) {
        printf("VAINQUEUR : J2");
        else
        printf("VAINQUEUR : J1");
    }
    printf("SCORE J1: %d", score1);
    printf("SCORE J2: %d", score2);
}



}