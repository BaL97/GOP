/* Author: 	Davide Balestra
 * 		Andrea D'Arpa
 * Description: Header file of class Menu
 */

class Menu{
protected:
    int Player_n;       //Number of players (>1)
    int Map_l;          //MAP LENGHT (>=63)
    bool Sound;         //Active sound
    bool Mode;          //difficulty parameter false = EASY || true = HARD
    
public:
    
    /* Default Constructor: default configuration:
     * Player_n=2;
     * sound = true;
     * Map_l = 63;
     * Mode = false;
     */
     Menu();
    
    //set methods
    void setPlayer_n(int n);
    void setSound(bool n);
    void setMapLenght(int n);
    void setMode(bool n);
    
    //get methods
    int getPlayer_n();
    bool getSound();
    int getMapLenght();
    bool getMode();
    
     //display the menu options
     char display();
	 
     //switch the choice of user
     Menu choice(char x);
	 
     //setting options inside the menu
     void ChoiceOptions();
};
