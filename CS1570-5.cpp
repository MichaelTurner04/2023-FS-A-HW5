//Michael Turner
//Duedate: 10/25/2023
//file: CS1570-5.cpp
//Assignment: HW5
//Purpose: This program walks a anxious character through their visit at the dentist

#include <iostream>
#include <iomanip>
using namespace std;
//This function completes the activity chosen by the user for the Waiting Room and updates the anxiety value and adds to the bill.
//pre: none
//Completes waiting room activity and updates anxiety and bill
void performWaitingRoomActivity(int &anxiety, double &bill, string &services);

//This function completes the activity chosen by the user for the Receptionist and updates the anxiety value and adds to the bill.
//pre: none
//Completes receptionist activity and updates anxiety and bill
void performReceptionistInteraction(int &anxiety,double &bill, string &services);

//This function completes the activity chosen by the user for the Dentist room and updates the anxiety value and adds to the bill.
//pre: none
//Completes activity and updates anxiety and bill
void performDentistRoomAction(int &anxiety, double &bill, string &services, int &mainMenuChoice);

//This function raises or lowers the anxiety and makes sure the value is always between 0-10
//pre: takes anxiety and the value you want to increase or decrease
//returns new anxiety value
int updateAnxietyLevel(int& anxiety, double x);

//This function uses the anxiety and bill values to output the final bill
//pre: anxiety, bill, and services
//outputs bill and ends program
int displayFinalSummary(int anxiety, double bill, string services);

//This function is a running total of all activity cost's
//pre: takes bill and price you want to add
//returns new bill value
int updateCost(double &bill, double x);

int main()
{
    int mainMenuChoice;
    double bill = 0.00;
    int anxiety;
    int waitingRoom;
    int recceptionist;
    int dentistRoom;
    int candy;
    double x;
    string services;
    cout << "set Jamie's initial anxiety level with a value between 0-10: ";
    cin >> anxiety;
    while (anxiety < 0 || anxiety >10) {//check valid input
        cout << "Invalid range. Please enter value 0-10 " << endl;
        cin >> anxiety;
    }
    do {
        cout << "1. Choose a waiting room activity \n2. Speak with the receptionist \n3. Enter the dentist's room \n4. Consider leaving (Jamie's nerves might get the better of him!)" << endl;
        cin >> mainMenuChoice;
        while (mainMenuChoice < 0 || mainMenuChoice >4) {//Input validation
            cout << "Invalid range. Please enter value 0-4 " << endl;
            cout << "1. Choose a waiting room activity \n2. Speak with the receptionist \n3. Enter the dentist's room \n4. Consider leaving (Jamie's nerves might get the better of him!)" << endl;
            cin >> mainMenuChoice;
        }
        switch (mainMenuChoice) {
        case 1:
            performWaitingRoomActivity( anxiety, bill, services);
            break;
        case 2://speaking with the receptionist
            performReceptionistInteraction(anxiety, bill, services);
            break;
        case 3://Entering the dentists room
            performDentistRoomAction(anxiety, bill, services, mainMenuChoice);
            break;
        case 4: // Exit the office
            cout << "If Jamie's anxiety is too high, he might decide he's not ready to see the dentist. This decreases Jamie's anxiety by 3, as leaving brings immediate relief, even if it's only a temporary solution. However, Jamie will incur a “Missed Appointment Fee” for not proceeding with the scheduled visit($250)." << endl;
            updateAnxietyLevel(anxiety, -3);
            updateCost(bill, 250.00);
            services += "\nMissed apointment fee: $250.00";
            break;
        default:
            cout << "Invalid input" << endl;
        }
    } while (mainMenuChoice != 4);
    cout << "Jamie left the dentist office" << endl;
    displayFinalSummary(anxiety, bill, services);
}

int displayFinalSummary(int anxiety, double bill, string services) {
    if (anxiety >= 6) {//IF ELSE statements to display Jamie's final emotional state
        cout << "Jamie's emotional state is Very Anxious" << endl;
    }
    else if (anxiety >= 1) {
        cout << "Jamie's emotional state is Nervous" << endl;
    }
    else if (anxiety == 0) {
        cout << "Jamie's emotional state is calm" << endl;
    }
    cout << "Billing Details: \n-------------------" << endl;
    cout << services << endl;
    cout << "----------------------\nTotal Amount Due: $" << fixed << setprecision(2) << bill << endl;
    return 0;
}
int updateCost(double &bill, double x) {
    bill += x;
    return bill;

}
int updateAnxietyLevel(int &anxiety,double x) {
    anxiety += x;
    if (anxiety > 10) {
        anxiety = 10;
    }
    else if (anxiety < 0) {
        anxiety = 0;
    }
    return anxiety;


}
void performWaitingRoomActivity(int &anxiety, double &bill, string &services) {
    int waitingRoom;
    cout << "1. Read a comic book \n2. Play a handheld video game \n3. Watch a cartoon on TV \n4. Doodle on a piece of paper \n5. Do nothing" << endl;
    cin >> waitingRoom;
    while (waitingRoom < 0 || waitingRoom >5) {//Input validation
        cout << "Invalid range. Please enter value 0-5 " << endl;
        cout << "1. Read a comic book \n2. Play a handheld video game \n3. Watch a cartoon on TV \n4. Doodle on a piece of paper \n5. Do nothing" << endl;
        cin >> waitingRoom;
    }
    switch (waitingRoom) {
    case 1: //comic book
        cout << "Jamie picks up a colorful comic book from the waiting area. The adventure-filled pages are complimentary for waiting patients, adding no additional charge to the final bill. This option decreases anxiety by 2, as reading distracts and calms Jamie." << endl;
        updateAnxietyLevel(anxiety, -2);
        break;
    case 2://video game
        cout << "Jamie rents a gameboy from the receptionist, unaware that this comfort comes with a minor cost of $50 fee to his bill. This option decreases anxiety by 3, as the game provides a deep diversion." << endl;
        updateAnxietyLevel(anxiety, -3);
        updateCost(bill, 50.00);
        services += "\nGameboy: $50.00";
        break;
    case 3://Cartoon
        cout << "Jamie comfortably settles into a chair, immersing himself in the cartoon, thankful for the complimentary entertainment. This option decreases anxiety by 2, as the light-hearted content eases his nerves." << endl;
        updateAnxietyLevel(anxiety, -2);
        break;
    case 4://Doodle
        cout << "Jamie grabs a drawing kit from the receptionist, informed that there's a small $20 charge for using the kit. This option increases anxiety by 1, as the unexpected charge causes a minor spike in his anxiety." << endl;
        updateAnxietyLevel(anxiety, 1);
        updateCost(bill, 20.00);
        services += "\nDrawing kit: $20.00";
        break;
    case 5://nothing
        cout << "Jamie decides to sit quietly in a plush armchair, lost in his thoughts, without engaging in any activity. This option incurs a comfort fee of $7.20. Also, Jamie's anxiety increases by 1. The tranquility, although relaxing, forces Jamie to ruminate on the impending visit, making him slightly more anxious." << endl;
        updateAnxietyLevel(anxiety, 1);
        updateCost(bill, 7.20);
        services += "\nComfort fee: $7.20";
        break;
    default:
        cout << "Invalid option" << endl;
    }
    return;
}
void performReceptionistInteraction( int &anxiety,double &bill, string &services) {
    int recceptionist;
    int candy = 0;
    cout << "1. What will the dentist do? \n2. How long will it take? \n3. Can I have a candy after?" << endl;
    cin >> recceptionist;
    while (recceptionist < 0 || recceptionist >3) { //Input validation
        cout << "Invalid range. Please enter value 0-3 " << endl;
        cout << "1. What will the dentist do? \n2. How long will it take? \n3. Can I have a candy after?" << endl;
        cin >> recceptionist;
    }
    switch (recceptionist) {
    case 1: ////what will the denstist do
        cout << "The receptionist explains the standard procedures. No direct charge for this information. Jamie's anxiety increases by 1, as hearing about procedures makes him slightly nervous." << endl;
        updateAnxietyLevel(anxiety, 1);
        break;
    case 2://How long will it take
        cout << "The receptionist informs Jamie that the procedure usually takes about 30 minutes at no additional cost. This decreases Jamie's anxiety by 1, as knowing this info eases Jamie's worries a bit." << endl;
        updateAnxietyLevel(anxiety, -1);
        break;
    case 3://Can I have a candy after?
        cout << "The receptionist smiles and shows Jamie a jar of assorted candies. " << endl;
        cout << "How many candies would you like ? (0 - 5)";
        cin >> candy;
        while (candy > 5 || candy < 0) {
            cout << "Invalid number. Please enter number (0-5): ";
            cin >> candy;
        }for (int i = 0; i < candy; ++i) {
            updateCost(bill, 10.00);
            services += "\nCandy: $10.00";
        }
        anxiety = candy >= 3 ? anxiety -= 4 : (candy == 2 ? anxiety -= 2 : anxiety = anxiety); // ternary operator for candy and anxiety
        updateAnxietyLevel(anxiety, 0);
        break;
    default:
        cout << "Invalid option" << endl;
    }
    return;
}
void performDentistRoomAction(int &anxiety, double &bill, string& services, int &mainMenuChoice) {
    int dentistRoom;
    cout << "1. speak with the dentist \n2. Choose a toy to hold during the visit \n3. Start the dental procedure" << endl;
    cin >> dentistRoom;
    while (dentistRoom < 0 || dentistRoom >3) {//Input validation
        cout << "Invalid range. Please enter value 0-3 " << endl;
        cout << "1. speak with the dentist \n2. Choose a toy to hold during the visit \n3. Start the dental procedure" << endl;
        cin >> dentistRoom;
    }
    switch (dentistRoom) {
    case 1: //Speak with the dentist
        cout << "Jamie and the dentist engage in a light conversation, with the dentist explaining what will happen during the visit. This action costs Jamie $40 but lowers his anxiety by 2, as understanding the process can be reassuring." << endl;
        updateAnxietyLevel(anxiety, -2);;
        updateCost(bill, 40.00);
        services += "\nSpeaking with the dentist: $40.00";
        break;
    case 2://Choose a toy
        cout << "Jamie chooses a soft plush toy which makes him feel safer. This costs him $32 but lowers his anxiety by 3." << endl;
        updateAnxietyLevel(anxiety, -3);
        updateCost(bill, 32.00);
        services += "\nSoft plush toy: $32.00";
        break;
    case 3://start operation
        break;
    default:
        cout << "Invalid option" << endl;
    }
    if (anxiety > 5) { //go back to main menu if Jamie is too anxious
        cout << "Jamie is too anxious, go back to the lobby." << endl;
        return;
    }
    cout << "1. Standard checkup \n2. Teeth Cleaning \n3. Cavity filling \n4. Specialist consultation " << endl;
    cin >> dentistRoom;
    while (dentistRoom < 0 || dentistRoom >4) {//Input validation
        cout << "Invalid range. Please enter value 0-4 " << endl;
        cout << "1. Standard checkup \n2. Teeth Cleaning \n3. Cavity filling \n4. Specialist consultation " << endl;
        cin >> dentistRoom;
    }
    switch (dentistRoom) {
    case 1: //Standard check up
        cout << "Jamie gets a standard dental checkup for $50.  This increases Jamie's anxiety by 1 since a standard checkup is fairly routine." << endl;
        updateAnxietyLevel(anxiety, 1);
        updateCost(bill, 50.00);
        services += "\nStandard dental checkup: $50.00";
        mainMenuChoice = 4;
        break;
    case 2://Teeth Cleaning
        cout << "Jamie opts for teeth cleaning for $75. This increases Jamie's anxiety by 2 since the sensation and sound of the cleaning tools slightly raise his anxiety. " << endl;
        updateAnxietyLevel(anxiety, 2);
        updateCost(bill, 75.00);
        services += "\nTeeth Clening: $75.00";
        mainMenuChoice = 4;
        break;
    case 3://Cavity filling
        cout << "Cavity filling: A cavity is detected and filled during the visit for $100. This increases Jamie's anxiety by 3 since the filling procedure can be quite nerve-wracking." << endl;
        updateCost(bill, 100.00);
        services += "\nCavity filling: $100.00";
        updateAnxietyLevel(anxiety, 3);
        mainMenuChoice = 4;
        break;
    case 4://Specialist consultation:
        cout << "Jamie needs advice from a specialist and gets a consultation for $300. This increases Jamie's anxiety by 2 since consulting a specialist implies a potential issue, which can make Jamie more anxious about his dental health." << endl;
        updateAnxietyLevel(anxiety, 2);
        updateCost(bill, 300.00);
        services += "\nSpecialist consultation: $300.00";
        mainMenuChoice = 4;
        break;
    default:
        cout << "Invalid option" << endl;
    }
    return;


}