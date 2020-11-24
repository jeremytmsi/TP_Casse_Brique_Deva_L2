/*
//int score(int centerPointX, brick, rightPointX, brickWidth, posYBall, brickHeight, dy, speedBall, dx, posXBall, centerMiddleY, nextBrick, undefined) {
// Score de la partie
    char nom[21] = {0};
    printf("Nom du joueur ?");
    scanf("%s", nom);
    int score = 0;

    //Collisions si la balle tape la brique en bas
    if ((centerPointX > brick.x) && (rightPointX < (brick.x + brickWidth)) && brick.visible && (posYBall <= (brick.y + brickHeight))) {
        dy = -dy - speedBall;
        brick.visible == 0;
        score++;
    }

    //Collisions côté droit de la brique
    if ((posXBall < (brick.x + brickWidth)) && (centerMiddleY < (brick.y + brickHeight)) && (centerMiddleY > brick.y) && ((brick.visible && rightPointX) > (brick.x + brickWidth))) {
        dx = -dx - speedBall;
        brick.visible == 0;
        score++;
    }

    //Collision côté gauche
    if ((rightPointX > brick.x) && (centerMiddleY < (brick.y + brickHeight)) && (centerMiddleY > brick.y) && brick.visible && (rightPointX < (brick.x + brickWidth))) {
        dx = -dx - speedBall;
        brick.visible == 0;
        score++;
    }

    if endgame = 1 {
    printf("Score de %s : %d", score);
    }
}

    



*/