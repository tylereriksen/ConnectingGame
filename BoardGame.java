/**
 * class of the boardgame and its functionalities
 * overall this class defines the board and the overall premise
 * of the game to be played
 */
public class BoardGame{

    /**
     * instance variables of the class
     */
    private int rows;
    private int cols;
    private int inarow;
    private int players;
    private String[] tokens = new String[]{"R", "Y", "B", "G", "P", "S", "T"}; // tokens for players
    private int move;
    private String[][] board;

    /**
     * Constructor for the board and game
     * @param rows - number of rows the board will have
     * @param cols - number of cols the board will have
     * @param inarow - the number of tokens in a row you need to get to win
     * @param players - the number of players playing in a game
     */
    public BoardGame(int rows, int cols, int inarow, int players){
        this.rows = rows;
        this.cols = cols;
        this.inarow = inarow;
        this.players = players;
        this.move = 1;
        this.board = new String[this.rows][this.cols];
        for(int i = 0; i < this.rows; i ++){
            for(int j = 0; j < this.cols; j ++){
                this.board[i][j] = ".";
            }
        }
    }

    /**
     * returns the board
     * @return the board
     */
    private String[][] getBoard(){
        return this.board;
    }

    /**
     * puts the player's token in a column
     * @param c - the column index shown in the display
     */
    public void move(int c){
        for(int i = this.rows - 1; i >= 0; i --){
            if(this.getBoard()[i][c - 1].equals(".")){
                this.board[i][c - 1] = this.tokens[(this.move - 1) % this.players];
                this.move ++;
                break;
            }
        }
    }

    /**
     * checks if a move is valid
     * @param c - the column index shown in the display
     * @return boolean of whether or not you can place a token in the column
     */
    public boolean checkValidMove(int c){
        if(c <= 0 || c > this.cols){
            return false;
        }
        else if(this.checkColFull(c)){
            return false;
        }
        return true;
    }

    /**
     * checks if the entire board is filled by checking if the
     * top row is filled
     * @return boolean of whether or not the board is filled
     */
    public boolean isBoardFull(){
        for(int i = 0; i < this.cols; i++){
            if(this.getBoard()[0][i].equals(".")){
                return false;
            }
        }
        return true;
    }

    /**
     * checks if a column is full or not
     * @param c - the column index that we want to see if it is full or not
     * @return boolean of wheather or not the column is full
     */
    private boolean checkColFull(int c){
        for(int i = this.rows - 1; i >= 0; i --){
            if(this.getBoard()[i][c - 1].equals(".")){
                return false;
            }
        }
        return true;
    }

    /**
     * outputs the token of the player's turn
     * @return token of the current player's turn
     */
    public String currentTurn(){
        return this.tokens[(this.move - 1) % this.players];
    }

    /**
     * outputs the token of the previous player's turn
     * @return token of the previous player's turn
     */
    public String prevTurn(){
        return this.tokens[(this.move +this.players - 2) % this.players];
    }

    /**
     * checks if there is a inarow in-a-row amount of the same tokens
     * @return boolean is there is a winner or not
     */
    public boolean isWin(){
        if(this.isRowWin() || this.isColWin()
        || this.isDiagonalBTWin() || this.isDiagonalTBWin()){
            return true;
        }
        return false;
    }

    /**
     * checks to see if there is any rows in-a-row
     * @return boolean of whether or not there is a row of in-a-row tokens
     */
    private boolean isRowWin(){
        if(this.cols < this.inarow){
            return false;
        }

        for(int i = 0; i < this.rows; i++){
            int p1 = 0;
            int p2 = 0;
            while(p2 < this.cols - 1){
                if(this.getBoard()[i][p2].equals(".")){
                    p2 ++;
                    p1 = p2;
                }
                else if(!this.getBoard()[i][p2].equals(this.getBoard()[i][p2 + 1])){
                    p2 ++;
                    p1 = p2;
                }
                else if(this.getBoard()[i][p2].equals(this.getBoard()[i][p2 + 1])){
                    p2 ++;
                    if(p2 + 1 - p1 == this.inarow){
                        return true;
                    }
                }
            }
        }
        return false;
    }

    /**
     * checks to see if there is any column in-a-row
     * @return boolean of whether or not there is a column of in-a-row tokens
     */
    private boolean isColWin(){
        if(this.rows < this.inarow){
            return false;
        }

        for(int i = 0; i < this.cols; i++){
            int p1 = 0;
            int p2 = 0;
            while(p2 < this.rows - 1){
                if(this.getBoard()[p2][i].equals(".")){
                    p2 ++;
                    p1 = p2;
                }
                else if(!this.getBoard()[p2][i].equals(this.getBoard()[p2 + 1][i])){
                    p2 ++;
                    p1 = p2;
                }
                else if(this.getBoard()[p2][i].equals(this.getBoard()[p2 + 1][i])){
                    p2 ++;
                    if(p2 + 1 - p1 == this.inarow){
                        return true;
                    }
                }
            }
        }
        return false;
    }

    /**
     * checks to see if there is any top-to-bottom diagonal in-a-row
     * @return boolean of whether or not there is a top-to-bottom diagonal of in-a-row tokens
     */
    private boolean isDiagonalTBWin(){
        if(this.rows < this.inarow || this.cols < this.inarow){
            return false;
        }
        for(int i = 0; i <= this.rows - this.inarow; i++){
            for(int j = 0; j <= this.cols - this.inarow; j++){
                int rowC = i;
                int colC = j;
                int counter = 1;
                while(true){
                    if(counter == this.inarow){
                        return true;
                    }
                    if(this.getBoard()[rowC][colC].equals(this.getBoard()[rowC + 1][colC + 1])
                    && !this.getBoard()[rowC][colC].equals(".")){
                        counter ++;
                        rowC ++;
                        colC ++;
                    }
                    else{
                        break;
                    }
                }
            }
        }
        return false;
    }

    /**
     * checks to see if there is any bottom-to-top diagonal in-a-row
     * @return boolean of whether or not there is a bottom-to-top diagonal of in-a-row tokens
     */
    private boolean isDiagonalBTWin(){
        if(this.rows < this.inarow || this.cols < this.inarow){
            return false;
        }
        for(int i = this.inarow - 1; i < this.rows; i++){
            for(int j = 0; j < this.cols - this.inarow; j++){
                int rowC = i;
                int colC = j;
                int counter = 1;
                while(true){
                    if(counter == this.inarow){
                        return true;
                    }
                    if(this.getBoard()[rowC][colC].equals(this.getBoard()[rowC - 1][colC + 1])
                    && !this.getBoard()[rowC][colC].equals(".")){
                        counter ++;
                        rowC --;
                        colC ++;
                    }
                    else{
                        break;
                    }
                }

            }
        }
        return false;
    }

    /**
     * displays the board in printed form
     */
    public void displayBoard(){
        String pr = "";
        for(int i = 1; i <= this.cols; i++){
            pr += (i + " ");
        }
        pr += "\n";

        for(int i = 0; i < this.rows; i ++){
            for(int j = 0; j < this.cols; j ++){
                pr += (this.getBoard()[i][j] 
                + " ".repeat(Integer.toString(j + 1).length()));
            }
            pr += "\n";
        }
        System.out.println(pr);
    }
}