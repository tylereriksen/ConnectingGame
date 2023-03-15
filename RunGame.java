import java.util.Scanner;

public class RunGame{

    /**
     * checks if a string is an integer or not
     * @param s - string that we want to check whether or not is an int
     * @return boolean of whether or not the string is an int 
     */
    public static boolean isInt(String s){
        try{
            int i = Integer.parseInt(s);
            return true;
        }
        catch(NumberFormatException er){
            return false;
        }
    }

    public static void main(String[] args){
        final int cols = 12;
        final int rows = 6;
        final int players = 3;
        final int inarow = 3;
        BoardGame ConnectBoard = new BoardBuilder().withCols(cols).withRows(rows)
        .withPlayers(players).withInarow(inarow).build();
        ConnectBoard.displayBoard();

        while(!ConnectBoard.isWin() && !ConnectBoard.isBoardFull()){
            String move = "";
            boolean again = false;
            while(!isInt(move) || !ConnectBoard.checkValidMove(Integer.parseInt(move))){
                Scanner myObj = new Scanner(System.in);
                String currMove = ConnectBoard.currentTurn();

                if(again){
                    System.out.println("Please enter a valid move " + currMove + ":");
                }
                else{
                    System.out.println("Enter move for " + currMove + ":");
                }

                move = myObj.nextLine().trim();
                if(!again){
                    again = true;
                }
            }
            ConnectBoard.move(Integer.parseInt(move));
            System.out.println("");
            ConnectBoard.displayBoard();
        }

        if(ConnectBoard.isWin()){
            System.out.println("Congratulations!! Player " + ConnectBoard.prevTurn() + ", you have WON the game!");
        }
        else{
            System.out.println("Draw! Tie Game");
        }
    }
}