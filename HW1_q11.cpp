/*
By Yevgeniy Sumaryev
3/20/21
*/
#include <iostream>
#include <string>
#include <math.h>
#include <fstream>
#include <time.h>
#include <iomanip>

/*
A restaraunt class that uses polymorphism to 
pick between 3 different restaraunts
*/

using namespace std;


//A main class from which others are derived
class Restaraunt {
    protected:
        string r_restaraunt;

    public:
        //constructor
        Restaraunt(string rest): r_restaraunt(rest){
        }

    //method to be overriden
    //virtual requires this 
    virtual string menu() = 0;

    string GetRest()
    {
        return r_restaraunt;
    }


};

//Italian class that inherits from Restaraunt
class Italian_Restaraunt : public Restaraunt {
    public:
        //Forward constructor arguments
        Italian_Restaraunt(string rest) : Restaraunt(rest) {}
        
        // Copy assignment operator overloading
        void operator = (const Italian_Restaraunt &It)
        {
            r_restaraunt = It.r_restaraunt;
        }

        //overriden method 
        string menu() override
        {
            string menuString = "Italian Menu\n----Appetizers----\nmozarella caprese----------------$10.95\nclams oregenata------------------$12.00\ncrab cake-----------------------$11.00\neggplant rollatine----------------$12.00\ncalamari friti----------------$11.00\n\n----The Pasta----\npenne alla vodka---------------$19.00\nRavioli Della Casa-------------$20.00\nLinguine Alle Vongole----------$23.00\nGnocchi Al Gorgonzola----------$19.00\n\n----Le Carni----\nCostata Di Vintello----------$40.00\nFileto Di Manzo--------------$32.00\nCostolette Di Agnello--------$33.00\n\n----Drinks And Beverages----\ncan of soda----------------$1.50\nbottle of water-------------$1.50\njuice ----------------------$1.50\nwine-------------------------$10.00\n";
            return menuString;
        } 
};

//Greek class that inherits from Restaraunt
class Greek_Restaraunt : public Restaraunt {
    public:
        //Forward constructor arguments
        Greek_Restaraunt(string rest) : Restaraunt(rest) {}
        
        // Copy assignment operator overloading
        void operator = (const Greek_Restaraunt &Gr)
        {
            r_restaraunt = Gr.r_restaraunt;
        }

        //overriden method 
        string menu() override
        {
            string menuString = "Greek Menu\n---------Appetizers----\nmozarella sticks----------------$7.95\nfalafel ----------------$8.95\ngarlic bread----------------$5.95\nhummus dip----------------$5.95\nbiftekia----------------$4.95\n\n----Platters----\nlamb gyro----------------$12.95\nchicken gyro----------------$12.95\nchicken souvlaki----------------$10.95\nfalafel----------------$10.95\nspinach pie----------------$14.95\n\n\n----Drinks And Beverages----\ncan of soda----------------$1.50\njuice----------------------$1.75\nbottled water--------------$1.25\n";
            return menuString;
        } 
};

//Chinese class that inherits from Restaraunt
class Chinese_Restaraunt : public Restaraunt {
    public:
        //Forward constructor arguments
        Chinese_Restaraunt(string rest) : Restaraunt(rest) {}
        
        // Copy assignment operator overloading
        void operator = (const Chinese_Restaraunt &Ch)
        {
            r_restaraunt = Ch.r_restaraunt;
        }

        //overriden method 
        string menu() override
        {
            string menuString = "Chinese menu\n----Appetizers----\nShrimp egg roll ------------$5.00\nMixed veg roll-----$4.50\nshrimp toast--$5.50\n\n-------soup----------\nChicken Chow Soup ------$8.45\nChicken Yat Gaw Mein --- $9.00\n\n-------Chow Mein-------\nVegetable------------$12.00\nChicken-------------$14.00\n\n-------Lo Mein----------\nBeef------------$12.00\nChicken---------$12.00\nShrimp-----------$14.00\n\n--------Seafood----------\nshrimp with lobster sauce----$15.00\nShrimp w. Pepper & Tomatoes---$14.00\nShrimp w. Broccoli-----------$15.00\n\n--------Drinks and Beverages-------\nbottled water------------------$1.50\nsoda---------------------------$1.25\njuice--------------------------$1.90\ntea----------------------------$2.00\n\n";
            return menuString;
        } 
};

//A templated Reader Robot method
template<typename T>
void Reader_Robot(T& theRestaraunt)
{
    cout <<"Welcome to: " << theRestaraunt.GetRest() << endl;
    cout << theRestaraunt.menu() << endl;
}


//a templated class called Restaraunt Template
//that uses function Reader Robot that reads the menu
template <typename T>
class RestarauntTemplate
{
private:
    T r_restaraunt;

public:
    RestarauntTemplate(T rest) : r_restaraunt(rest) {}

    void Reader_Robot()
    {
        cout <<"Welcome to: " << r_restaraunt.GetRest() << endl;
        cout << r_restaraunt.menu() << endl;
    }
};



int main()
{
    int n;
    string selection;

    //declaration of 3 different restaraunts
    Italian_Restaraunt it = Italian_Restaraunt("Italian Restaraunt");
    RestarauntTemplate<Italian_Restaraunt> ItTemplate(it);

    Greek_Restaraunt Gr = Greek_Restaraunt("Greek Restaraunt");
    RestarauntTemplate<Greek_Restaraunt> GrTemplate(Gr);

    Chinese_Restaraunt Ch = Chinese_Restaraunt("Chinese Restaraunt");
    RestarauntTemplate<Chinese_Restaraunt> ChTemplate(Ch);

    selection = "Please pick from the following restaraunts:\n1.Italian\n2.Greek\n3.Chinese\n\nPlease enter the number of the restaraunt:\n";
    cout<< selection<<endl;

    cin >> n;
    //a switch statement that chooses between 3 different restaraunts 
    //depending on what user chose 
    switch (n)
    {
    case 1:  
        ItTemplate.Reader_Robot();
        break;
    case 2:
        GrTemplate.Reader_Robot();
        break;
    case 3:
         ChTemplate.Reader_Robot();
        break;
    default:
        cout<<"Invalid choice"<<endl;
        break;
    }
    

    

    
}


