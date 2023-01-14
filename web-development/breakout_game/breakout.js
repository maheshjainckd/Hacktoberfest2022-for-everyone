const canvas = document.getElementById("canvas");
      const ctx = canvas.getContext("2d");
      const canvasH = canvas.height;
      const canvasW = canvas.width;
      let scoreAudio= new Audio('score.mp3');
      let hitAudio= new Audio('hit.mp3');
      let paddlehit= new Audio('paddlehit.mp3');
      let rightPressed = false;
      let leftPressed = false;
      let x,
        y,
        dy,
        dx,
        interval,
        radius,
        paddleW,
        paddleX,
        paddleY,
        brickW,
        brickH,
        brickOffset;
      let bricks = [];
      let score = 0;
      let brickCount = 14;
      let brickRows = 9;
      setVariables();
      drawBall();
      drawPaddle();
      createBrickArray();
      drawBricks();
      drawScore();
      paddleNavigation();
      // startGame()

      function drawScore() {
        ctx.beginPath();
        ctx.fillStyle = "#000";
        ctx.fill();
        ctx.fillText("Score: " + score, 9, 10);
        ctx.closePath();
      }
      function createBrickArray() {
        for (let j = 0; j < brickRows; j++) {
          bricks[j] = [];
          for (let i = 0; i < brickCount; i++) {
            bricks[j][i] = { x: 0, y: 0, isVisible: true };
          }
        }
      }

      function drawBricks() {
        for (let j = 0; j < brickRows; j++) {
          for (let i = 0; i < brickCount; i++) {
            if (bricks[j][i].isVisible) {
              const brickX = 18 + i * (brickW + brickOffset);
              const brickY = (10 + brickOffset) * (j + 1);
              bricks[j][i].x = brickX;
              bricks[j][i].y = brickY;
              ctx.beginPath();
              ctx.rect(brickX, brickY, brickW, brickH);
              ctx.fillStyle = "green";
              ctx.fill();
              ctx.closePath();
            }
          }
        }
      }

      function paddleNavigation() {
        document.addEventListener("keydown", handleKeyDown);
        document.addEventListener("keyup", handleKeyUp);

        function handleKeyDown(e) {
          if (e.key === "ArrowRight") {
            rightPressed = true;
          }
          if (e.key === "ArrowLeft") {
            leftPressed = true;
          }
        }

        function handleKeyUp(e) {
          if (e.key === "ArrowRight") {
            rightPressed = false;
          }
          if (e.key === "ArrowLeft") {
            leftPressed = false;
          }
        }
      }

      function detectCollision() {
        if (x + dx >= canvasW || x + dx < 0) {
          dx = -dx;
        }

        if (y + dy > canvasH - radius) {
          if (x + dx > paddleX && x + dx < paddleX + paddleW) {
            paddlehit.play();
            dy = -dy;
            dx = dx + (x + dx - paddleX) / 100;
          }
        }

        if (y + dy < 0
          ) {
          dy = -dy;
        }

        for (let b = 0; b < bricks.length; b++) {
          for (let i = 0; i < bricks[b].length; i++) {
            const brick = bricks[b][i];
            if (brick.isVisible) {
              if (
                x > brick.x &&
                x < brick.x + brickW &&
                y > brick.y &&
                y < brick.y + brickH
              ) {
                bricks[b][i].isVisible = false;
                score += 1;
                scoreAudio.play();
                document.getElementById("score").innerHTML="Score: "+score;
                dy = -dy;
                checkYouWon();
              }
            }
          }
        }
      }

      function startGame() {
        if (!interval) {
          interval = setInterval(() => {
            if (rightPressed) {
              paddleX = paddleX + 6;
            }
            if (leftPressed) {
              paddleX = paddleX - 6;
            }
            detectCollision();
            x = x + dx;
            y = y + dy;
            checkGameover();
            ctx.clearRect(0, 0, canvasW, canvasH);
            drawPaddle();
            drawBall();
            drawBricks();
            drawScore();
          }, 20);
        }
      }

      function checkGameover() {
        if (y === canvasH) {
          hitAudio.play();
          alert("game over");
          clearInterval(interval);
          interval = null;
          setVariables();
        }
      }

      function checkYouWon() {
        if (score === 126) {
          alert("You Won !!");
          clearInterval(interval);
          interval = null;
          setVariables();
        }
      }

      function setVariables() {
        x = canvasW / 2;
        y = canvasH - 40;
        dx = 5;
        dy = -5;
        radius = 15;
        paddleW = 100;
        paddleX = canvasW / 2 - paddleW / 2;
        paddleY = canvasH - 25;

        brickW = 40;
        brickH = 10;
        brickOffset = 8;
      }

      function drawBall() {
        ctx.beginPath();
        ctx.arc(x, y, radius, 0, 2 * Math.PI, false);
        ctx.fillStyle = "rgb(145, 216, 31)";
        ctx.fill();
        ctx.closePath();
      }

      function drawPaddle() {
        ctx.beginPath();
        ctx.rect(paddleX, paddleY, paddleW, 20);
        ctx.fillStyle = "rgb(58, 8, 45)";
        ctx.fill();
        ctx.closePath();
      }