/* Author: 	Davide Balestra
 * 		Andrea D'Arpa
 * Description: Header file of class Menu
 */

class Menu{
protected:
    int Option;
public:
        int getOption();
		//display the menu options
		char display();
		//switch the choice of user
		Menu choice(char x);
		//setting options inside the menu
		void ChoiceOptions();
};
