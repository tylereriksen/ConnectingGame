/**
 * builder class is used to build the boardgame
 * used a builder design pattern in case the default values were wanted
 * and were not specified to make the board and game
 */
public class BoardBuilder{

    /**
     * instance variables of the class
     */
    private int rows;
    private int cols;
    private int inarow;
    private int players;

    /**
     * Constructor for the default board and game
     */
    public BoardBuilder(){
        this.rows = 6;
        this.cols = 7;
        this.inarow = 4;
        this.players = 2;
    }

    /**
     * build a board with a particular number of rows
     * @param r - number of rows
     * @return board and game builder
     */
    public BoardBuilder withRows(int r){
        this.rows = r;
        return this;
    }

    /**
     * build a board with a particular number of columns
     * @param c - number of columns
     * @return board and game builder
     */
    public BoardBuilder withCols(int c){
        this.cols = c;
        return this;
    }

    /**
     * build a game with a particular number of tokens in a row to win
     * @param i - number of tokens in a row to win
     * @return board and game builder
     */
    public BoardBuilder withInarow(int i){
        this.inarow = i;
        return this;
    }

    /**
     * build a game with a particular number of players to play
     * @param p - number of players needed to play the game
     * @return board and game builder
     */
    public BoardBuilder withPlayers(int p){
        this.players = p;
        return this;
    }

    /**
     * build the game and board with the current state of instance variables
     * @return BoardGame class built with the current parameters
     */
    public BoardGame build(){
        return new BoardGame(this.rows, this.cols, this.inarow, this.players);
    }
}
