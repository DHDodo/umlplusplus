/*
  Filename   : CLI.hpp
  Description: File which generates the command line interface
  for the user to create UML diagrams
*/

/************************************************************/
// Macro guard
#ifndef CLI_HPP
#define CLI_HPP
/************************************************************/

//--------------------------------------------------------------------
// System includes
#include <string>
#include "UMLClass.hpp"
#include "UMLAttribute.hpp"
#include "UMLRelationship.hpp"
#include "UMLData.hpp"
#include "UMLFile.hpp"
#include <vector>
#include <iostream>
//--------------------------------------------------------------------

//--------------------------------------------------------------------
// Using declarations
 using std::cin;
 using std::cout;
 using std::endl;
 using std::string;
 using std::vector;
 using std::invalid_argument;
//--------------------------------------------------------------------

class CLI
{
    private:
        // stores choice input by user
        string userChoice;
        // loop boolean that maintains CLI routine
        bool mainLoop;
        // loop boolean that maintains CLI subrountines
        bool subLoop;
        // main UML data object storing UML stuff
        UMLData data;
    public:
        // displays command line interface
        void displayCLI();
};

void CLI::displayCLI ()
{
    // loop boolean that maintains CLI routine
    mainLoop = true;
    // loop boolean that maintains CLI subrountines
    subLoop = false;

    while (mainLoop) {
        // Main prompt: prompts user for options.
        cout << "Choose an option:"<< endl;
        cout << "Class [0]" << endl;
        cout << "Attribute [1]" << endl;
        cout << "Relationship [2]" << endl;
        cout << "List [3]" << endl;
        cout << "Save [4]" << endl;
        cout << "Load [5]" << endl;
        cout << "Help [6]" << endl;
        cout << "Exit [7]" << endl;

        // store user option
        cout << endl << "Choice: ";
        cin >> userChoice;
        cout << endl;

        // start subloop
        subLoop = true;

        while (subLoop) { 
            // Class
            if(userChoice == "0") {
                // Lists operations for modifying classes
                cout << "Choose an option:"<< endl;
                cout << "Add [0]" << endl;
                cout << "Remove [1]" << endl;
                cout << "Rename [2]" << endl;
                cout << "Back [3]" << endl;

                // store user option
                cout << endl << "Choice: ";
                cin >> userChoice;
                cout << endl;

                // Add class
                if (userChoice == "0") {
                    // prompt name of class then add class
                    cout << "Enter name of class:" << endl;
                    string name;
                    cin >> name;
                    data.addClass(name);
                    subLoop = false;
                }
                // Remove class
                else if (userChoice == "1") {
                    // prompt name of class then remove class
                    cout << "Enter name of class:" << endl;
                    string name;
                    cin >> name;
                    data.deleteClass(name);
                    subLoop = false;
                } 
                // Rename class
                else if (userChoice == "2") {
                    // prompt name of class then rename class
                    cout << "Enter old name of class:" << endl;
                    string name;
                    cin >> name;
                    cout << "Enter new name of class:" << endl;
                    string name2;
                    cin >> name2;
                    data.changeClassName(name, name2);
                    subLoop = false;
                }
                // Go back
                else if (userChoice == "3") {
                    // exits loop, goes back
                    subLoop = false;
                }
                // Invalid choice
                else {
                    // show error, reset user choice
                    cout << "Invalid choice!" << endl << endl;
                    userChoice = "0";
                }
            }

            // Attribute
            else if(userChoice == "1") {
                // Lists operations for modifying attributes
                cout << "Choose an option:"<< endl;
                cout << "Add [0]" << endl;
                cout << "Remove [1]" << endl;
                cout << "Rename [2]" << endl;
                cout << "Back [3]" << endl;

                // store user option
                cout << endl << "Choice: ";
                cin >> userChoice;
                cout << endl;

                // Add attribute
                if (userChoice == "0") {
                    // prompt name of class and attribute then add attribute
                    subLoop = false;
                }
                // Remove class
                else if (userChoice == "1") {
                    // prompt name of class and attribute then remove attribute
                    subLoop = false;
                } 
                // Rename class
                else if (userChoice == "2") {
                    // prompt name of class and attribute then rename attribute
                    subLoop = false;
                }
                // Go back
                else if (userChoice == "3") {
                    // exits loop, goes back
                    subLoop = false;
                }
                // Invalid choice
                else {
                    // show error, reset user choice
                    cout << "Invalid choice!" << endl << endl;
                    userChoice = "1";
                }
            }

            // Relationship
            else if(userChoice == "2") {
                // Lists operations for modifying relationships
                cout << "Choose an option:"<< endl;
                cout << "Add [0]" << endl;
                cout << "Remove [1]" << endl;
                cout << "Back [2]" << endl;

                // store user option
                cout << endl << "Choice: ";
                cin >> userChoice;
                cout << endl;

                // class name representing source and destination
                string source, destination;

                // Add relationship
                if (userChoice == "0") {
                    cout << "Enter the name of the source: "<< endl;
                    cin >> source;
                    cout << "Enter the name of the destination: "<< endl;
                    cin >> destination;
                    data.addRelationship(source, destination);
                    cout << "Relationship added between " << source << " and " << destination << endl;
                    subLoop = false;
                }
                // Remove relationship
                else if (userChoice == "1") {
                    // prompt name of source and destination and removes relationship
                    cout << "Enter the name of the source: "<< endl;
                    cin >> source;
                    cout << "Enter the name of the destination: "<< endl;
                    cin >> destination;
                    data.deleteRelationship(source, destination);
                    cout << "Relationship deleted between " << source << " and " << destination << endl;
                    subLoop = false;
                } 
                // Go back
                else if (userChoice == "2") {
                    // exits loop, goes back
                    subLoop = false;
                }
                // Invalid choice
                else {
                    // show error, reset user choice
                    cout << "Invalid choice!" << endl << endl;
                    userChoice = "2";
                }
            }

            // Diagram
            else if(userChoice == "3") {
                // Lists operations for viewing information within the diagram
                cout << "Choose an option:"<< endl;
                cout << "Class [0]" << endl;
                cout << "Diagram [1]" << endl;
                cout << "Back [2]" << endl;

                // store user option
                cout << endl << "Choice: ";
                cin >> userChoice;
                cout << endl;

                // Display single class
                if (userChoice == "0") {
                    // prompt class name, shows information about class
                    cout << "Enter name of class:" << endl;
                    string name;
                    cin >> name;
                    cout << "Attributes:" << endl;
                    UMLClass c = data.getClassCopy(name);
                    vector<UMLAttribute> attributeList = c.getAttributes();
                    for(UMLAttribute attribute : attributeList)
                    {
                        cout << attribute.getAttributeName() << endl;
                    }
                    cout << "Relationships:" << endl;
                    vector<UMLRelationship> relationshipList = data.getRelationshipsByClass(name);
                    for(UMLRelationship relationship : relationshipList)
                    {
                        cout << relationship.getSource().getName() << " <=> " << relationship.getDestination().getName() << endl;
                    }
                    cout << endl << "Enter anything to continue..." << endl;
                    cin >> name; //just to have a pause so user can have time to view attributes and relationships
                    subLoop = false;
                }
                // Display all information
                else if (userChoice == "1") {
                    // show all information and return back to base loop                    
                    subLoop = false;
                } 
                // Go back
                else if (userChoice == "2") {
                    // exits loop, goes back
                    subLoop = false;
                }
                // Invalid choice
                else {
                    // show error, reset user choice
                    cout << "Invalid choice!" << endl << endl;
                    userChoice = "3";
                }
            }

            // Save UML
            else if (userChoice == "4") {
                // Saves UML diagram to a JSON file in the same directory as the executable
                subLoop = false;
            }

            // Load UML
            else if (userChoice == "5") {
                // Prompts for a directory. If the directory exists, UML diagram info is displayed
                subLoop = false;
            }

            // Help
            else if (userChoice == "6") {
                // Loads this help file into the console
                subLoop = false;
            }

            // Exits the program
            else if (userChoice == "7") {
                subLoop = false;
                mainLoop = false;
            }

            // Invalid choice
            else {
                // show error, reset user choice and break loop
                cout << "Invalid choice!" << endl << endl;
                userChoice = "";
                subLoop = false;
            }
        }  
    } 
}

/************************************************************/
#endif
/************************************************************/