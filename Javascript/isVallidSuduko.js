const solveSudoku = function(board) {
    solver(board);
  };
  
  const solver = board => {
    for (let i = 0; i < 9; i++) {
      for (let j = 0; j < 9; j++) {
        if (board[i][j] === ".") {
          let char = "1";
          while (+char <= 9) {
            if (isValidSudoku(i, j, board, char)) {
              board[i][j] = char;
              if (solver(board)) {
                return true;
              } else {
                board[i][j] = ".";
              }
            }
            char = (+char + 1).toString();
          }
          return false;
        }
      }
    }
    return true;
  };
  
  const isValidSudoku = (row, col, board, char) => {
    for (let i = 0; i < 9; i++) {
      if (board[row][i] == char) {
        return false;
      }
    }
  
    for (let i = 0; i < 9; i++) {
      if (board[i][col] == char) {
        return false;
      }
    }
  
    const x = ~~(row / 3) * 3;
    const y = ~~(col / 3) * 3;
    for (let i = 0; i < 3; i++) {
      for (let j = 0; j < 3; j++) {
        if (board[x + i][y + j] == char) {
          return false;
        }
      }
    }
  
    return true;
  };
  