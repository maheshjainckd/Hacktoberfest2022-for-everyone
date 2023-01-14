//Problem Statement : 
//we are given a number n, the size of a chess board.
//we are given a row and a column, as a starting point for a knight piece.
//we are required to generate the all moves of a knight starting in (row, col) such that knight visits 
//all cells of the board exactly once.

/* 
sample input : 5
               2
               0
sample output : 25 2 13 8 23 
                12 7 24 3 14 
                1 18 15 22 9 
                6 11 20 17 4 
                19 16 5 10 21 
                .
                .
                more paths like these
*/

import java.io.*;
import java.util.*;

public class Main {

    public static void main(String[] args) throws Exception {
        Scanner scn = new Scanner(System.in);
        int n = scn.nextInt();
        int[][] chess = new int[n][n];
        int r = scn.nextInt();
        int c = scn.nextInt();
        printKnightsTour(chess,r,c,1);
    }

    public static void printKnightsTour(int[][] chess, int r, int c, int upcomingMove) {
        if(r<0 || c<0 || r >= chess.length || c>=chess.length || chess[r][c]>0){
            return;
        }
        else if(upcomingMove == chess.length*chess.length){
            chess[r][c]=upcomingMove;
            displayBoard(chess);
            chess[r][c]=0;
            return;
        }
        chess[r][c]=upcomingMove;
        printKnightsTour(chess,r-2,c+1,upcomingMove+1);
        printKnightsTour(chess,r-1,c+2,upcomingMove+1);
        printKnightsTour(chess,r+1,c+2,upcomingMove+1);
        printKnightsTour(chess,r+2,c+1,upcomingMove+1);
        printKnightsTour(chess,r+2,c-1,upcomingMove+1);
        printKnightsTour(chess,r+1,c-2,upcomingMove+1);
        printKnightsTour(chess,r-1,c-2,upcomingMove+1);
        printKnightsTour(chess,r-2,c-1,upcomingMove+1);
        chess[r][c]=0;
    }

    public static void displayBoard(int[][] chess){
        for(int i = 0; i < chess.length; i++){
            for(int j = 0; j < chess[0].length; j++){
                System.out.print(chess[i][j] + " ");
            }
            System.out.println();
        }
        System.out.println();
    }
}