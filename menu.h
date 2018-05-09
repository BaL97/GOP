/* Author: 	Davide Balestra
 * 		Andrea D'Arpa
 * Description: Header file of class Menu
 */

class Menu{
protected:
    char x;
    int Player_n;       //Number of players (>1)
    int Map_l;          //MAP LENGHT (>=63)
    bool Sound;         //Active sound
    bool Mode;          //difficulty parameter false = EASY || true = HARD
    
public:
    
    /* Default Constructor: default configuration:
     * x=
     * Player_n=2;                  will be setted in NewGame menu option
     * sound = true;
     * Map_l = 63;
     * Mode = false;
     */
     Menu();
    
    //set methods
    void setX(char x);
    void setPlayer_n(int n);
    void setSound(bool n);
    void setMapLenght(int n);
    void setMode(bool n);
    
    //get methods
    char getX();
    int getPlayer_n();
    bool getSound();
    int getMapLenght();
    bool getMode();
    void displayAll();
    
     //display the menu options
     void display();
	 
     //switch the choice of user
     void choice();
	 
     //setting options inside the menu
     void setOptions();
};
